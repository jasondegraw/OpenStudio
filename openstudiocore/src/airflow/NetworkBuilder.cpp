/**********************************************************************
 *  Copyright (c) 2008-2014, Alliance for Sustainable Energy.
 *  All rights reserved.
 *
 *  This library is free software; you can redistribute it and/or
 *  modify it under the terms of the GNU Lesser General Public
 *  License as published by the Free Software Foundation; either
 *  version 2.1 of the License, or (at your option) any later version.
 *
 *  This library is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 *  Lesser General Public License for more details.
 *
 *  You should have received a copy of the GNU Lesser General Public
 *  License along with this library; if not, write to the Free Software
 *  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 **********************************************************************/

#include "NetworkBuilder.hpp"

#include <model/Model.hpp>
#include <model/Building.hpp>
#include <model/Building_Impl.hpp>
#include <model/BuildingStory.hpp>
#include <model/BuildingStory_Impl.hpp>
#include <model/ThermalZone.hpp>
#include <model/ThermalZone_Impl.hpp>
#include <model/Space.hpp>
#include <model/Space_Impl.hpp>
#include <model/Surface.hpp>
#include <model/Surface_Impl.hpp>
#include <model/SubSurface.hpp>
#include <model/SubSurface_Impl.hpp>
#include <model/AirLoopHVAC.hpp>
#include <model/AirLoopHVAC_Impl.hpp>
#include <model/Node.hpp>
#include <model/Node_Impl.hpp>
#include <model/PortList.hpp>
#include <model/WeatherFile.hpp>
#include <model/RunPeriod.hpp>

#include <utilities/time/Date.hpp>

#include <utilities/sql/SqlFile.hpp>
#include <utilities/core/Logger.hpp>
#include <utilities/geometry/Geometry.hpp>
#include <utilities/plot/ProgressBar.hpp>

#include <boost/foreach.hpp>
#include <boost/math/constants/constants.hpp>

#include <QFile>
#include <QTextStream>
#include <QList>
#include <QStringList>
#include <QMap>
#include <QThread>

#include <algorithm>

namespace openstudio {
namespace airflow {

NetworkBuilder::NetworkBuilder(ProgressBar *progressBar) : m_progressBar(progressBar)
{
  m_logSink.setLogLevel(Info);
  m_logSink.setChannelRegex(boost::regex("openstudio\\.airflow\\.NetworkBuilder"));
  m_logSink.setThreadId(QThread::currentThread());
  m_progressBar = 0;
}

std::vector<openstudio::model::Surface> NetworkBuilder::getInteriorZoneSurfaces(openstudio::model::Model & model)
{
  QVector<openstudio::Handle> used;
  std::vector<openstudio::model::Surface> found;
  BOOST_FOREACH(openstudio::model::Surface surface, model.getConcreteModelObjects<openstudio::model::Surface>())
  {
    std::string bc = surface.outsideBoundaryCondition();
    if(!used.contains(surface.handle()) && bc == "Surface")
    {
      // Get the associated thermal zone
      boost::optional<openstudio::model::Space> space = surface.space();
      if(!space)
      {
        LOG(Warn, "Unattached surface '" << surface.handle() << "'");
        continue;
      }
      boost::optional<openstudio::model::ThermalZone> thermalZone = space->thermalZone();
      if(!thermalZone)
      {
        LOG(Warn, "Unzoned space '" << space->handle() << "'");
        continue;
      }
      boost::optional<openstudio::model::Surface> adjacentSurface = surface.adjacentSurface();
      if(!adjacentSurface)
      {
        LOG(Error, "Unable to find adjacent surface for surface '" << surface.handle() << "'");
        continue;
      }
      boost::optional<openstudio::model::Space> adjacentSpace = adjacentSurface->space();
      if(!adjacentSpace)
      {
        LOG(Error, "Unattached adjacent surface '" << adjacentSurface->handle() << "'");
        continue;
      }
      boost::optional<openstudio::model::ThermalZone> adjacentZone = adjacentSpace->thermalZone();
      if(!thermalZone)
      {
        LOG(Warn, "Unzoned adjacent space '" << adjacentSpace->handle() << "'");
        continue;
      }
      // Ok, now we a surface, a space, a zone, an adjacent surface, an adjacent space, and an adjacent zone. Finally.
      used.push_back(adjacentSurface->handle());
      if(thermalZone != adjacentZone)
      {
        found.push_back(surface);
      }
    }
  }
  return found;
}

std::vector<openstudio::model::Surface> NetworkBuilder::getExteriorZoneSurfaces(openstudio::model::Model & model)
{
  std::vector<openstudio::model::Surface> found;
  BOOST_FOREACH(openstudio::model::Surface surface, model.getConcreteModelObjects<openstudio::model::Surface>())
  {
    std::string bc = surface.outsideBoundaryCondition();
    if(bc == "Outdoors")
    {
      // Get the associated thermal zone
      boost::optional<openstudio::model::Space> space = surface.space();
      if(!space)
      {
        LOG(Warn, "Unattached surface '" << surface.handle() << "'");
        continue;
      }
      boost::optional<openstudio::model::ThermalZone> thermalZone = space->thermalZone();
      if(!thermalZone)
      {
        LOG(Warn, "Unzoned space '" << space->handle() << "'");
        continue;
      }
      found.push_back(surface);
    }
  }
  return found;
}

/*
bool NetworkBuilder::getSurfaces(openstudio::model::Model & model)
{
  bool nowarnings = true;
  QVector<openstudio::Handle> used;
  interiorSurfaces.clear();
  exteriorSurfaces.clear();
  BOOST_FOREACH(openstudio::model::Surface surface, model.getConcreteModelObjects<openstudio::model::Surface>())
  {
    std::string bc = surface.outsideBoundaryCondition();
    if(bc == "Outdoors")
    {
      // Get the associated thermal zone
      boost::optional<openstudio::model::Space> space = surface.space();
      if(!space)
      {
        LOG(Warn, "Unattached surface '" << surface.handle() << "'");
        nowarnings = false;
        continue;
      }
      boost::optional<openstudio::model::ThermalZone> thermalZone = space->thermalZone();
      if(!thermalZone)
      {
        LOG(Warn, "Unzoned space '" << space->handle() << "'");
        nowarnings = false;
        continue;
      }
      exteriorSurfaces.push_back(surface);
    }
    else if(!used.contains(surface.handle()) && bc == "Surface")
    {
      // Get the associated thermal zone
      boost::optional<openstudio::model::Space> space = surface.space();
      if(!space)
      {
        LOG(Warn, "Unattached surface '" << surface.handle() << "'");
        nowarnings = false;
        continue;
      }
      boost::optional<openstudio::model::ThermalZone> thermalZone = space->thermalZone();
      if(!thermalZone)
      {
        LOG(Warn, "Unzoned space '" << space->handle() << "'");
        nowarnings = false;
        continue;
      }
      boost::optional<openstudio::model::Surface> adjacentSurface = surface.adjacentSurface();
      if(!adjacentSurface)
      {
        LOG(Error, "Unable to find adjacent surface for surface '" << surface.handle() << "'");
        nowarnings = false;
        continue;
      }
      boost::optional<openstudio::model::Space> adjacentSpace = adjacentSurface->space();
      if(!adjacentSpace)
      {
        LOG(Error, "Unattached adjacent surface '" << adjacentSurface->handle() << "'");
        nowarnings = false;
        continue;
      }
      boost::optional<openstudio::model::ThermalZone> adjacentZone = adjacentSpace->thermalZone();
      if(!thermalZone)
      {
        LOG(Warn, "Unzoned adjacent space '" << adjacentSpace->handle() << "'");
        nowarnings = false;
        continue;
      }
      // We could punt the checking of subsurfaces until later, but it is best to get this out of the way now
      BOOST_FOREACH(model::SubSurface subSurface, surface.subSurfaces()) {
        boost::optional<model::SubSurface> adjacentSubSurface = subSurface.adjacentSubSurface();
        if(!adjacentSubSurface) {
          LOG(Warn, "Unable to find adjacent subsurface for subsurface of '" << surface.handle() << "'");
          nowarnings = false;
          continue;
        }
        if(adjacentSubSurface->surface() != adjacentSurface) {
          LOG(Warn, "Adjacent subsurface for subsurface of '" << surface.handle() << "' is not attached to the expected surface");
          nowarnings = false;
          continue;
        }
      }
      // Ok, now we a surface, a space, a zone, an adjacent surface, an adjacent space, and an adjacent zone. Finally.
      used.push_back(adjacentSurface->handle());
      if(thermalZone != adjacentZone)
      {
        interiorSurfaces.push_back(surface);
      }
    }
  }
  return nowarnings;
}
*/

void NetworkBuilder::progress()
{
  if (m_progressBar) {
    m_progressBar->setValue(m_progressBar->value() + 1);
  }
}

void NetworkBuilder::initProgress(int max, std::string label)
{
  if (m_progressBar) {
    m_progressBar->setWindowTitle(label);
    m_progressBar->setMinimum(0);
    m_progressBar->setMaximum(max);
    m_progressBar->setValue(0);
  }
}

bool NetworkBuilder::linkExteriorSurface(openstudio::model::ThermalZone zone, openstudio::model::Space space, openstudio::model::Surface surface)
{
  LOG(Info, "Surface '" << surface.name().get() << "' connects zone '" << zone.name().get() << "' to the ambient");
  std::cout << "Surface '" << surface.name().get() << "' connects zone '" << zone.name().get() << "' to the ambient" << std::endl;
  return true;
}

bool NetworkBuilder::linkInteriorSurface(openstudio::model::ThermalZone zone, openstudio::model::Space space, openstudio::model::Surface surface, 
  openstudio::model::Surface adjacentSurface, openstudio::model::Space adjacentSpace, openstudio::model::ThermalZone adjacentZone)
{
  LOG(Info, "Surfaces '" << surface.name().get() << "' and '" << adjacentSurface.name().get() << "' connect zone '" 
    << zone.name().get() << "' to zone '" << adjacentZone.name().get() << "'");
  std::cout << "Surfaces '" << surface.name().get() << "' and '" << adjacentSurface.name().get() << "' connect zone '" 
    << zone.name().get() << "' to zone '" << adjacentZone.name().get() << "'" << std::endl;
  return true;
}

bool NetworkBuilder::linkExteriorSubSurface(openstudio::model::ThermalZone zone, openstudio::model::Space space, openstudio::model::Surface surface,
  openstudio::model::SubSurface subSurface)
{
  LOG(Info, "Subsurface '" << subSurface.name().get() << "' connects zone '" << zone.name().get() << "' to the ambient");
  std::cout << "Subsurface '" << subSurface.name().get() << "' connects zone '" << zone.name().get() << "' to the ambient" << std::endl;
  return true;
}

bool NetworkBuilder::linkInteriorSubSurface(openstudio::model::ThermalZone zone, openstudio::model::Space space, openstudio::model::Surface surface, 
  openstudio::model::SubSurface subSurface,openstudio::model::SubSurface adjacentSubSurface, openstudio::model::Surface adjacentSurface, openstudio::model::Space adjacentSpace,
  openstudio::model::ThermalZone adjacentZone)
{
  LOG(Info, "Subsurfaces '" << subSurface.name().get() << "' and '" << adjacentSubSurface.name().get() << "' connect zone '" 
    << zone.name().get() << "' to zone '" << adjacentZone.name().get() << "'");
  std::cout << "Subsurfaces '" << subSurface.name().get() << "' and '" << adjacentSubSurface.name().get() << "' connect zone '" 
    << zone.name().get() << "' to zone '" << adjacentZone.name().get() << "'"  << std::endl;
  return true;
}

/*
bool NetworkBuilder::build1(model::Model model)
{
  m_logSink.setThreadId(QThread::currentThread());
  m_logSink.resetStringStream();

  // Loop over the exterior surfaces and create links
  BOOST_FOREACH(model::Surface surface,exteriorSurfaces) {
    openstudio::model::Space space = surface.space().get();
    openstudio::model::ThermalZone zone = space.thermalZone().get();
    linkExteriorSurface(zone,space,surface);

    if(exteriorSubSurfacesLinked()){
      std::vector<model::SubSurface> 	subSurfaces = surface.subSurfaces();
      std::cout << surface.grossArea() << " " << surface.netArea() << " " << subSurfaces.size() << std::endl;
      BOOST_FOREACH(model::SubSurface subSurface,subSurfaces) {
        
      }
    }
  }

  // Loop over the exterior surfaces and create links
  BOOST_FOREACH(model::Surface surface, interiorSurfaces) {
    openstudio::model::Space space = surface.space().get();
    openstudio::model::ThermalZone zone = space.thermalZone().get();
    openstudio::model::Surface adjacentSurface = surface.adjacentSurface().get();
    openstudio::model::Space adjacentSpace = adjacentSurface.space().get();
    openstudio::model::ThermalZone adjacentZone = adjacentSpace.thermalZone().get();
    linkInteriorSurface(zone,space,surface,adjacentSurface,adjacentSpace,adjacentZone);

    if(interiorSubSurfacesLinked()){
      std::vector<model::SubSurface> 	subSurfaces = surface.subSurfaces();
      BOOST_FOREACH(model::SubSurface subSurface, subSurfaces) {
        // The connections should have been previously checked, but we haven't stored the ones that are good...
        boost::optional<model::SubSurface> adjacentSubSurface = subSurface.adjacentSubSurface();
        if(!adjacentSubSurface) {
          LOG(Warn, "Unable to find adjacent subsurface for subsurface of '" << surface.handle() << "'");
          continue;
        }
        if(adjacentSubSurface->surface() != adjacentSurface) {
          LOG(Warn, "Adjacent subsurface for subsurface of '" << surface.handle() << "' is not attached to the expected surface");
          continue;
        }
      }
    }
  }

  return true;
}
*/

bool NetworkBuilder::build(openstudio::model::Model &model)
{
  bool first = true;
  bool nowarnings = true;
  QVector<openstudio::Handle> used;

  m_logSink.setThreadId(QThread::currentThread());
  m_logSink.resetStringStream();

  std::vector<openstudio::model::Surface> surfaces = model.getConcreteModelObjects<openstudio::model::Surface>();

  initProgress(surfaces.size(),"Processing surfaces for network creation");

  BOOST_FOREACH(openstudio::model::Surface surface, surfaces)
  {
    if(!first) {
      progress();
    }
    first=false;
    std::string bc = surface.outsideBoundaryCondition();
    if(bc == "Outdoors")
    {
      // Get the associated thermal zone
      boost::optional<openstudio::model::Space> space = surface.space();
      if(!space)
      {
        LOG(Warn, "Unattached surface '" << surface.handle() << "'");
        nowarnings = false;
        continue;
      }
      boost::optional<openstudio::model::ThermalZone> thermalZone = space->thermalZone();
      if(!thermalZone)
      {
        LOG(Warn, "Unzoned space '" << space->handle() << "'");
        nowarnings = false;
        continue;
      }
      // If we made it to here, then the exterior surface is good.
      linkExteriorSurface(thermalZone.get(),space.get(),surface);
      if(exteriorSubSurfacesLinked()){
        std::vector<model::SubSurface> 	subSurfaces = surface.subSurfaces();
        BOOST_FOREACH(model::SubSurface subSurface,subSurfaces) {
          linkExteriorSubSurface(thermalZone.get(),space.get(),surface,subSurface);
        }
      }
    }
    else if(!used.contains(surface.handle()) && bc == "Surface")
    {
      // Get the associated thermal zone
      boost::optional<openstudio::model::Space> space = surface.space();
      if(!space)
      {
        LOG(Warn, "Unattached surface '" << surface.handle() << "'");
        nowarnings = false;
        continue;
      }
      boost::optional<openstudio::model::ThermalZone> thermalZone = space->thermalZone();
      if(!thermalZone)
      {
        LOG(Warn, "Unzoned space '" << space->handle() << "'");
        nowarnings = false;
        continue;
      }
      boost::optional<openstudio::model::Surface> adjacentSurface = surface.adjacentSurface();
      if(!adjacentSurface)
      {
        LOG(Error, "Unable to find adjacent surface for surface '" << surface.handle() << "'");
        nowarnings = false;
        continue;
      }
      boost::optional<openstudio::model::Space> adjacentSpace = adjacentSurface->space();
      if(!adjacentSpace)
      {
        LOG(Error, "Unattached adjacent surface '" << adjacentSurface->handle() << "'");
        nowarnings = false;
        continue;
      }
      boost::optional<openstudio::model::ThermalZone> adjacentZone = adjacentSpace->thermalZone();
      if(!thermalZone)
      {
        LOG(Warn, "Unzoned adjacent space '" << adjacentSpace->handle() << "'");
        nowarnings = false;
        continue;
      }
      // We could punt the checking of subsurfaces until later, but it is best to get this out of the way now
      BOOST_FOREACH(model::SubSurface subSurface, surface.subSurfaces()) {
        boost::optional<model::SubSurface> adjacentSubSurface = subSurface.adjacentSubSurface();
        if(!adjacentSubSurface) {
          LOG(Warn, "Unable to find adjacent subsurface for subsurface of '" << surface.handle() << "'");
          nowarnings = false;
          continue;
        }
        if(adjacentSubSurface->surface() != adjacentSurface) {
          LOG(Warn, "Adjacent subsurface for subsurface of '" << surface.handle() << "' is not attached to the expected surface");
          nowarnings = false;
          continue;
        }
      }
      // Ok, now we a surface, a space, a zone, an adjacent surface, an adjacent space, and an adjacent zone. Finally.
      used.push_back(adjacentSurface->handle());
      if(thermalZone == adjacentZone) {
        continue;
      }
      // Now have a surface that is fully connected and separates two zones so it can be linked
      linkInteriorSurface(thermalZone.get(),space.get(),surface,adjacentSurface.get(),adjacentSpace.get(),adjacentZone.get());
      // Link subsurfaces if needed
      if(interiorSubSurfacesLinked()) {
        std::vector<model::SubSurface> 	subSurfaces = surface.subSurfaces();
        BOOST_FOREACH(model::SubSurface subSurface, subSurfaces) {
          // Now we need to check the connections as we did with the surface
          boost::optional<model::SubSurface> adjacentSubSurface = subSurface.adjacentSubSurface();
          if(!adjacentSubSurface) {
            LOG(Warn, "Unable to find adjacent subsurface for subsurface of '" << surface.handle() << "'");
            continue;
          }
          if(adjacentSubSurface->surface() != adjacentSurface) {
            LOG(Warn, "Adjacent subsurface for subsurface of '" << surface.handle() << "' is not attached to the expected surface");
            continue;
          }
          // If we made it here, then the subsurface is fully connected and can be linked
          linkInteriorSubSurface(thermalZone.get(),space.get(),surface,subSurface,adjacentSubSurface.get(),adjacentSurface.get(),
            adjacentSpace.get(),adjacentZone.get());
        }
      }
    }
  }
  if(surfaces.size()>0) {
    progress();
  }
  return nowarnings;
}

std::vector<LogMessage> NetworkBuilder::warnings() const
{
  std::vector<LogMessage> result;

  BOOST_FOREACH(LogMessage logMessage, m_logSink.logMessages())
  {
    if (logMessage.logLevel() == Warn)
    {
      result.push_back(logMessage);
    }
  }

  return result;
}

std::vector<LogMessage> NetworkBuilder::errors() const
{
  std::vector<LogMessage> result;

  BOOST_FOREACH(LogMessage logMessage, m_logSink.logMessages())
  {
    if (logMessage.logLevel() > Warn)
    {
      result.push_back(logMessage);
    }
  }

  return result;
}

std::vector<LogMessage> NetworkBuilder::logMessages() const
{
  return m_logSink.logMessages();
}

ProgressBar * NetworkBuilder::progressBar() const
{
  return m_progressBar;
}

void NetworkBuilder::setProgressBar(ProgressBar *progressBar)
{
  m_progressBar = progressBar;
}

} // airflow
} // openstudio
