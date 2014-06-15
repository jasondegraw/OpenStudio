/**********************************************************************
 *  Copyright (c) 2008-2013, Alliance for Sustainable Energy.
 *  Copyright (c) 2013, The Pennsylvania State University.
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

#ifndef AFN_FORWARDTRANSLATOR_HPP
#define AFN_FORWARDTRANSLATOR_HPP

#include "../AirflowAPI.hpp"

#include "../NetworkBuilder.hpp"

#include "../../utilities/idf/Handle.hpp"
#include "../../utilities/core/Logger.hpp"
#include "../../utilities/idf/Workspace.hpp"
#include <QMap>

namespace openstudio {
class ProgressBar;

namespace model {
  class Model;
  class ModelObject;
  class Surface;
}

namespace afn {

class AIRFLOW_API ForwardTranslator : public airflow::NetworkBuilder
{
public:

  explicit ForwardTranslator(ProgressBar *progressBar = 0);

  virtual ~ForwardTranslator();

  boost::optional<openstudio::Workspace> translateModel(openstudio::model::Model & model, ProgressBar* progressBar = NULL);

    /** Returns true if interior subsurfaces will be linked. */
  virtual bool interiorSubSurfacesLinked()
  {
    return true;
  }

  /** Returns true if exterior subsurfaces will be linked. */
  virtual bool exteriorSubSurfacesLinked()
  {
    return false;
  }

protected:
  virtual void linkExteriorSurface(openstudio::model::ThermalZone zone, openstudio::model::Space space, openstudio::model::Surface surface);
  virtual void linkExteriorSubSurface(openstudio::model::ThermalZone zone, openstudio::model::Space space, openstudio::model::Surface surface, openstudio::model::SubSurface subSurface);
  virtual void linkInteriorSurface(openstudio::model::ThermalZone zone, openstudio::model::Space space, openstudio::model::Surface surface, 
    openstudio::model::Surface adjacentSurface, openstudio::model::Space adjacentSpace, openstudio::model::ThermalZone adjacentZone);
  virtual void linkInteriorSubSurface(openstudio::model::ThermalZone zone, openstudio::model::Space space, openstudio::model::Surface surface, openstudio::model::SubSurface subSurface,
    openstudio::model::SubSurface adjacentSubSurface, openstudio::model::Surface adjacentSurface, openstudio::model::Space adjacentSpace, openstudio::model::ThermalZone adjacentZone);

private:
  std::map<std::string,double> largestSurfaceAreas(openstudio::model::Model &model);

  REGISTER_LOGGER("openstudio.afn.ForwardTranslator");

  openstudio::Workspace m_workspace;
  std::map<std::string,double> m_maxAreas;
};

} // afn
} // openstudio

#endif // AFN_FORWARDTRANSLATOR_HPP
