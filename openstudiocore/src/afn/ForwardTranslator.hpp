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

#include "AfnAPI.hpp"

#include <utilities/idf/Handle.hpp>
//#include <utilities/core/Path.hpp>
#include <utilities/core/Logger.hpp>
#include <QMap>

//#include "PrjData.hpp"

namespace openstudio {
  class Workspace;
  class ProgressBar;

  namespace model {
    class Model;
    class ModelObject;
    class Surface;
  }

  namespace afn {

    class AFN_API ForwardTranslator
    {
    public:

      ForwardTranslator();

      virtual ~ForwardTranslator();

      boost::optional<openstudio::Workspace> translateModel(openstudio::model::Model & model, ProgressBar* progressBar = NULL);

    private:
      //void translateLevels(openstudio::model::Model &model, const prj::Data &data);
      //bool translateZones(openstudio::model::Model &model, const prj::Data &data);
      //bool translateSimpleAHS(openstudio::model::Model &model, const prj::Data &data);

      //ProgressBar* m_progressBar;
      //QMap<int,Handle> m_levelMap;
      //QMap<int,Handle> m_zoneMap;
      //QMap<int,Handle> m_ahsMap;
      //QMap<int,int> m_connections;

      REGISTER_LOGGER("openstudio.afn.ForwardTranslator");
    };

  } // afn
} // openstudio

#endif // AFN_FORWARDTRANSLATOR_HPP
