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

#include "ForwardTranslator.hpp"

// These can't all be needed - need to clean up
#include <model/Model.hpp>
#include <model/ModelObject.hpp>
#include <model/ModelObject_Impl.hpp>
#include <model/Facility.hpp>
#include <model/Facility_Impl.hpp>
#include <model/Building.hpp>
#include <model/Building_Impl.hpp>
#include <model/ThermalZone.hpp>
#include <model/ThermalZone_Impl.hpp>
#include <model/Space.hpp>
#include <model/Space_Impl.hpp>
#include <model/Surface.hpp>
#include <model/Surface_Impl.hpp>
#include <model/SubSurface.hpp>
#include <model/SubSurface_Impl.hpp>
#include <model/ShadingSurface.hpp>
#include <model/ShadingSurface_Impl.hpp>
#include <model/ShadingSurfaceGroup.hpp>
#include <model/ShadingSurfaceGroup_Impl.hpp>
#include <model/SizingZone.hpp>
#include <model/BuildingStory.hpp>
#include <model/BuildingStory_Impl.hpp>
#include <model/AirLoopHVAC.hpp>
#include <model/AirLoopHVAC_Impl.hpp>
#include <model/HVACTemplates.hpp>

#include <model/SpaceInfiltrationDesignFlowRate.hpp>
#include <model/SpaceInfiltrationDesignFlowRate_Impl.hpp>
#include <model/SpaceInfiltrationEffectiveLeakageArea.hpp>
#include <model/SpaceInfiltrationEffectiveLeakageArea_Impl.hpp>

#include <utilities/core/Assert.hpp>
#include <utilities/units/UnitFactory.hpp>
#include <utilities/units/QuantityConverter.hpp>
#include <utilities/plot/ProgressBar.hpp>

#include <energyplus/ForwardTranslator.hpp>

#include <QFile>
#include <QSharedPointer>

namespace openstudio {
namespace afn {

ForwardTranslator::ForwardTranslator(ProgressBar *progressBar) : NetworkBuilder(progressBar)
{
}

ForwardTranslator::~ForwardTranslator()
{
}

boost::optional<openstudio::Workspace> ForwardTranslator::translateModel(openstudio::model::Model & model, ProgressBar* progressBar)
{
  // Remove previous infiltration objects
  std::vector<openstudio::model::SpaceInfiltrationDesignFlowRate> dfrInf = model.getConcreteModelObjects<openstudio::model::SpaceInfiltrationDesignFlowRate>();
  BOOST_FOREACH(openstudio::model::SpaceInfiltrationDesignFlowRate inf, dfrInf) {
    inf.remove();
  }
  std::vector<openstudio::model::SpaceInfiltrationEffectiveLeakageArea> elaInf = model.getConcreteModelObjects<openstudio::model::SpaceInfiltrationEffectiveLeakageArea>();
  BOOST_FOREACH(openstudio::model::SpaceInfiltrationEffectiveLeakageArea inf, elaInf) {
    inf.remove();
  }

  // Get an E+ workspace
  energyplus::ForwardTranslator translator;
  m_workspace = translator.translateModel(model,progressBar);

  // Find the largest surface between zones
  m_maxAreas = largestSurfaceAreas(model);

  QStringList idfStrings;
  // Create a simulation control object
  idfStrings << "AirflowNetwork:SimulationControl"
    << "Automatic_AirflowNetwork"  // !- Name
    << "MultiZoneWithoutDistribution"  // !- AirflowNetwork Control
    << "SurfaceAverageCalculation"  // !- Wind Pressure Coefficient Type
    << ""  // !- AirflowNetwork Wind Pressure Coefficient Array Name
    << "OpeningHeight"  // !- Height Selection for Local Wind Speed Calculation
    << "LowRise"  // !- Building Type
    << "500"  // !- Maximum Number of Iterations {dimensionless}
    << "ZeroNodePressures" // !- Initialization Type
    << "1.0E-05"  // !- Relative Airflow Convergence Tolerance {dimensionless}
    << "1.0E-06"  // !- Absolute Airflow Convergence Tolerance {kg/s}
    << "-0.5"  // !- Convergence Acceleration Limit {dimensionless}
    << "0.0"  // !- Azimuth Angle of Long Axis of Building {deg}
    << "1.0";  // !- Ratio of Building Width Along Short Axis to Width Along Long Axis
  m_workspace.addObject(openstudio::IdfObject::load((idfStrings.join(",")+";").toStdString()).get());
  /*
  << Input,                   !- Wind Pressure Coefficient Type
  Every 30 Degrees,        !- AirflowNetwork Wind Pressure Coefficient Array Name
  OpeningHeight,           !- Height Selection for Local Wind Speed Calculation
  LowRise,                 !- Building Type
  500,                     !- Maximum Number of Iterations {dimensionless}
  ZeroNodePressures,       !- Initialization Type
  1.0E-05,                 !- Relative Airflow Convergence Tolerance {dimensionless}
  1.0E-06,                 !- Absolute Airflow Convergence Tolerance {kg/s}
  -0.5,                    !- Convergence Acceleration Limit {dimensionless}
  0.0,                     !- Azimuth Angle of Long Axis of Building {deg}
  1.0;                     !- Ratio of Building Width Along Short Axis to Width Along Long Axis
  */
  // Create an airflow zone for each thermal zone
  BOOST_FOREACH(openstudio::model::ThermalZone thermalZone,
    model.getConcreteModelObjects<openstudio::model::ThermalZone>())
  {
    boost::optional<std::string> name = thermalZone.name();
    if(!name)
    {
      LOG(Error, "Thermal zone '" << thermalZone.handle() << "' has no name, translation aborted");
      return false;
    }
    idfStrings.clear();
    idfStrings << "AirflowNetwork:Multizone:Zone"
      << openstudio::toQString(*name) // !- Name of Associated Thermal Zone
      << "NoVent" // !- Ventilation Control Mode
      << ""  // !- Vent Temperature Schedule Name
      << ""  // !- Limit Value on Multiplier for Modulating Venting Open Factor {dimensionless}
      << ""  // !- Lower Value on Inside/Outside Temperature Difference for
      // !- Modulating the Venting Open Factor {deltaC}
      << ""  // !- Upper Value on Inside/Outside Temperature Difference for
      // !- Modulating the Venting Open Factor {deltaC}
      << ""  // !- Lower Value on Inside/Outside Enthalpy Difference for Modulating
      // !- the Venting Open Factor {J/kg}
      << ""  // !- Upper Value on Inside/Outside Enthalpy Difference for Modulating
      // !- the Venting Open Factor {J/kg}
      << ""; // !- Venting Availability Schedule Name
    m_workspace.addObject(openstudio::IdfObject::load((idfStrings.join(",")+";").toStdString()).get());
  }
  // Add some leakage components
  idfStrings.clear();
  idfStrings << "AirflowNetwork:MultiZone:ReferenceCrackConditions"
    << "ReferenceCrackConditions"  // !- Name of Reference Crack Conditions
    << "20.0"  // !- Reference Temperature for Crack Data {C}
    << "101325"  // !- Reference Barometric Pressure for Crack Data {Pa}
    << "0.0"; // !- Reference Humidity Ratio for Crack Data {kgWater/kgDryAir}
  m_workspace.addObject(openstudio::IdfObject::load((idfStrings.join(",")+";").toStdString()).get());

  // Generate exterior leakage element
  idfStrings.clear();
  idfStrings << "AirflowNetwork:MultiZone:Surface:Crack"
    << "ExteriorComponent"  // !- Name of Surface Crack Component
    << QString().sprintf("%g",m_maxAreas["Exterior"]*4.99082e-4) // !- Air Mass Flow Coefficient at Reference Conditions {kg/s}
    << "0.65"  // !- Air Mass Flow Exponent {dimensionless}
    << "ReferenceCrackConditions"; // !- Reference Crack Conditions
  m_workspace.addObject(openstudio::IdfObject::load((idfStrings.join(",")+";").toStdString()).get());

  // Generate interior leakage element
  idfStrings.clear();
  idfStrings << "AirflowNetwork:MultiZone:Surface:Crack"
    << "InteriorComponent"  // !- Name of Surface Crack Component
    << QString().sprintf("%g",m_maxAreas["Interior"]*2.0*4.99082e-4) // !- Air Mass Flow Coefficient at Reference Conditions {kg/s}
    << "0.65"  // !- Air Mass Flow Exponent {dimensionless}
    << "ReferenceCrackConditions"; // !- Reference Crack Conditions
  m_workspace.addObject(openstudio::IdfObject::load((idfStrings.join(",")+";").toStdString()).get());

  /*
  idfStrings.clear();
  idfStrings << "AirflowNetwork:MultiZone:Surface:Crack"
  << "ExteriorComponent"  // !- Name of Surface Crack Component
  << "0.01"  // !- Air Mass Flow Coefficient at Reference Conditions {kg/s}
  << "0.65"  // !- Air Mass Flow Exponent {dimensionless}
  << "ReferenceCrackConditions"; // !- Reference Crack Conditions
  workspace.addObject(openstudio::IdfObject::load((idfStrings.join(",")+";").toStdString()).get());

  idfStrings.clear();
  idfStrings << "AirflowNetwork:MultiZone:Surface:Crack"
  << "InteriorComponent"  // !- Name of Surface Crack Component
  << "0.02"  // !- Air Mass Flow Coefficient at Reference Conditions {kg/s}
  << "0.65"  // !- Air Mass Flow Exponent {dimensionless}
  << "ReferenceCrackConditions"; // !- Reference Crack Conditions
  workspace.addObject(openstudio::IdfObject::load((idfStrings.join(",")+";").toStdString()).get());
  */

  // Loop over surfaces and generate AFN surfaces
  // Args need to be surface name, external node name, crack factor
  /*
  QString idfFormat("AirflowNetwork:MultiZone:Surface,%1,ExteriorComponent,%2,%3;");
  BOOST_FOREACH(openstudio::model::Surface surface, exteriorSurfaces)
  {
    boost::optional<std::string> name = surface.name();
    if(!name)
    {
      LOG(Error, "Surface '" << surface.handle() << "' has no name, translation aborted.");
      return false;
    }
    QString idfString = idfFormat.arg(openstudio::toQString(*name)).arg("").arg(surface.grossArea()/maxAreas["Exterior"]);
    workspace.addObject(openstudio::IdfObject::load(idfString.toStdString()).get());
  }

  // Args need to be surface name, external node name, crack factor
  idfFormat=QString("AirflowNetwork:MultiZone:Surface,%1,InteriorComponent,%2,%3;");
  BOOST_FOREACH(openstudio::model::Surface surface, interiorSurfaces)
  {
    boost::optional<std::string> name = surface.name();
    if(!name)
    {
      LOG(Error, "Surface '" << surface.handle() << "' has no name, translation aborted.");
      return false;
    }
    QString idfString = idfFormat.arg(openstudio::toQString(*name)).arg("").arg(surface.grossArea()/maxAreas["Interior"]);
    workspace.addObject(openstudio::IdfObject::load(idfString.toStdString()).get());
  }
  */

  /*
  QList <openstudio::Handle>used;
  QString exterior("AirflowNetwork:MultiZone:Surface,%1,ExteriorComponent,%2,1.0;");
  QString interior("AirflowNetwork:MultiZone:Surface,%1,InteriorComponent,%2,1.0;");
  BOOST_FOREACH(openstudio::model::Surface surface, 
  model.getConcreteModelObjects<openstudio::model::Surface>())
  {
  std::string bc = surface.outsideBoundaryCondition();
  if(!used.contains(surface.handle()) && bc != "Ground")
  {
  std::string type = surface.surfaceType();
  boost::optional<std::string> name = surface.name();
  if(!name)
  {
  LOG(Error, "Surface '" << surface.handle() << "' has no name, translation aborted");
  return false;
  }
  boost::optional<openstudio::model::Space> space = surface.space();
  if(!space)
  {
  LOG(Error, "Unattached surface '" << *name << "', translation aborted");
  return false;
  }
  boost::optional<openstudio::model::ThermalZone> thermalZone = space->thermalZone();
  if(!thermalZone)
  {
  LOG(Error, "Unattached space '" << space->handle() << "', translation aborted");
  return false;
  }
  // Now for the type specific work
  QString idfString;
  if(bc == "Outdoors")
  {
  // Make an exterior surface
  if(type == "RoofCeiling")
  idfString = exterior.arg(openstudio::toQString(*name)).arg("");
  else
  idfString = exterior.arg(openstudio::toQString(*name)).arg("");
  }
  else if (bc == "Surface")
  {
  boost::optional<openstudio::model::Surface> adjacentSurface = surface.adjacentSurface();
  if(!adjacentSurface)
  {
  LOG(Error, "Unable to find adjacent surface for surface '" << name << "', translation aborted");
  return false;
  }
  boost::optional<openstudio::model::Space> adjacentSpace = adjacentSurface->space();
  if(!adjacentSpace)
  {
  LOG(Error, "Unattached adjacent surface '" << adjacentSurface->handle() << "', translation aborted");
  return false;
  }
  boost::optional<openstudio::model::ThermalZone> adjacentZone = adjacentSpace->thermalZone();
  if(!adjacentZone)
  {
  LOG(Error, "Unattached adjacent space '" << adjacentSpace->handle() << "', translation aborted");
  return false;
  }
  if(adjacentZone.get() != thermalZone.get()) // I don't really like doing this
  {
  // Make an interior surface
  if(type == "RoofCeiling")
  idfString = interior.arg(openstudio::toQString(*name)).arg("");
  else
  idfString = interior.arg(openstudio::toQString(*name)).arg("");
  }
  used << adjacentSurface->handle();
  }
  else
  {
  LOG(Error, "Unknown boundary condition '" << bc << "'");
  return false;
  }
  workspace.addObject(openstudio::IdfObject::load(idfString.toStdString()).get());
  }
  }
  */
  return boost::optional<openstudio::Workspace>(m_workspace);
}

void ForwardTranslator::linkExteriorSurface(openstudio::model::ThermalZone zone, openstudio::model::Space space, openstudio::model::Surface surface)
{
  QString idfFormat("AirflowNetwork:MultiZone:Surface,%1,ExteriorComponent,%2,%3;");
  boost::optional<std::string> name = surface.name();
  if(!name) {
    LOG(Warn, "Surface '" << surface.handle() << "' has no name, will not be present in airflow network.");
    return;
  }
  double surfaceArea = surface.grossArea();
  if(interiorSubSurfacesLinked()) {
    surfaceArea = surface.netArea();
  }
  QString idfString = idfFormat.arg(openstudio::toQString(*name)).arg("").arg(surfaceArea/m_maxAreas["Exterior"]);
  m_workspace.addObject(openstudio::IdfObject::load(idfString.toStdString()).get());
}

void ForwardTranslator::linkInteriorSurface(openstudio::model::ThermalZone zone, openstudio::model::Space space, openstudio::model::Surface surface, 
  openstudio::model::Surface adjacentSurface, openstudio::model::Space adjacentSpace, openstudio::model::ThermalZone adjacentZone)
{
  QString idfFormat("AirflowNetwork:MultiZone:Surface,%1,InteriorComponent,%2,%3;");
  boost::optional<std::string> name = surface.name();
  if(!name){
    LOG(Warn, "Surface '" << surface.handle() << "' has no name, will not be present in airflow network.");
    return;
  }
  double surfaceArea = surface.grossArea();
  if(interiorSubSurfacesLinked()) {
    surfaceArea = surface.netArea();
  }
  QString idfString = idfFormat.arg(openstudio::toQString(*name)).arg("").arg(surfaceArea/m_maxAreas["Interior"]);
  m_workspace.addObject(openstudio::IdfObject::load(idfString.toStdString()).get());
}

void ForwardTranslator::linkExteriorSubSurface(openstudio::model::ThermalZone zone, openstudio::model::Space space, openstudio::model::Surface surface,
  openstudio::model::SubSurface subSurface)
{
  // Nothing to see here
}

void ForwardTranslator::linkInteriorSubSurface(openstudio::model::ThermalZone zone, openstudio::model::Space space, openstudio::model::Surface surface, 
  openstudio::model::SubSurface subSurface,openstudio::model::SubSurface adjacentSubSurface, openstudio::model::Surface adjacentSurface, openstudio::model::Space adjacentSpace,
  openstudio::model::ThermalZone adjacentZone)
{
  // Nothing to see here
}

std::map<std::string,double> ForwardTranslator::largestSurfaceAreas(openstudio::model::Model & model)
{
  double areaMax=0.0;
  std::map<std::string,double> maxAreas;
  maxAreas["Exterior"] = 0.0;
  maxAreas["Interior"] = 0.0;
  std::vector<openstudio::model::Surface> extSurfs = getExteriorZoneSurfaces(model);
  std::vector<openstudio::model::Surface> intSurfs = getInteriorZoneSurfaces(model);
  BOOST_FOREACH(openstudio::model::Surface surface, extSurfs)
  {
    double area = surface.grossArea(); // Will need to account for openings at some point
    if(area > maxAreas["Exterior"])
    {
      maxAreas["Exterior"] = area;
    }
  }
  BOOST_FOREACH(openstudio::model::Surface surface, intSurfs)
  {
    double area = surface.grossArea(); // Will need to account for openings at some point
    if(area > maxAreas["Interior"])
    {
      maxAreas["Interior"] = area;
    }
  }
  return maxAreas;
}
} // afn
} // openstudio
