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

#include <energyplus/ForwardTranslator.hpp>
#include <model/Model.hpp>

#include <model/AirflowNetworkSimulationControl.hpp>
#include <model/AirflowNetworkSimulationControl_Impl.hpp>

#include <utilities/geometry/Geometry.hpp>
#include <utilities/geometry/Point3d.hpp>
#include <utilities/geometry/Vector3d.hpp>
#include <utilities/geometry/EulerAngles.hpp>
#include <utilities/geometry/Transformation.hpp>
#include <utilities/idd/AirLoopHVAC_FieldEnums.hxx>
#include <utilities/idd/AirLoopHVAC_ControllerList_FieldEnums.hxx>
#include <utilities/idd/AirLoopHVAC_OutdoorAirSystem_FieldEnums.hxx>
#include <utilities/idd/AirLoopHVAC_SupplyPath_FieldEnums.hxx>
#include <utilities/idd/AirLoopHVAC_ReturnPath_FieldEnums.hxx>
#include <utilities/idd/AirLoopHVAC_ZoneMixer_FieldEnums.hxx>
#include <utilities/idd/AirLoopHVAC_ZoneSplitter_FieldEnums.hxx>
#include <utilities/idd/AirTerminal_SingleDuct_Uncontrolled_FieldEnums.hxx>
#include <utilities/idd/AvailabilityManagerAssignmentList_FieldEnums.hxx>
#include <utilities/idd/AvailabilityManager_Scheduled_FieldEnums.hxx>
#include <utilities/idd/BranchList_FieldEnums.hxx>
#include <utilities/idd/Branch_FieldEnums.hxx>
#include <utilities/idd/Building_FieldEnums.hxx>
#include <utilities/idd/Coil_Cooling_DX_SingleSpeed_FieldEnums.hxx>
#include <utilities/idd/Coil_Heating_Gas_FieldEnums.hxx>
#include <utilities/idd/Construction_FieldEnums.hxx>
#include <utilities/idd/Controller_OutdoorAir_FieldEnums.hxx>
#include <utilities/idd/Curve_Biquadratic_FieldEnums.hxx>
#include <utilities/idd/Curve_Quadratic_FieldEnums.hxx>
#include <utilities/idd/ElectricEquipment_FieldEnums.hxx>
#include <utilities/idd/Fan_ConstantVolume_FieldEnums.hxx>
#include <utilities/idd/Fan_VariableVolume_FieldEnums.hxx>
#include <utilities/idd/GasEquipment_FieldEnums.hxx>
#include <utilities/idd/Lights_FieldEnums.hxx>
#include <utilities/idd/Material_NoMass_FieldEnums.hxx>
#include <utilities/idd/Material_FieldEnums.hxx>
#include <utilities/idd/OutdoorAir_Mixer_FieldEnums.hxx>
#include <utilities/idd/People_FieldEnums.hxx>
#include <utilities/idd/RunPeriod_FieldEnums.hxx>
#include <utilities/idd/Schedule_Compact_FieldEnums.hxx>
#include <utilities/idd/SetpointManager_MixedAir_FieldEnums.hxx>
#include <utilities/idd/SetpointManager_SingleZone_Reheat_FieldEnums.hxx>

//#include <utilities/idd/AirflowNetworkSimulationControl_FieldEnums.hxx>

#include <utilities/idd/IddEnums.hxx>
#include <utilities/idd/IddFactory.hxx>

using namespace openstudio::model;

using namespace std;

namespace openstudio {

namespace energyplus {

boost::optional<IdfObject> ForwardTranslator::translateAirflowNetworkSimulationControl( AirflowNetworkSimulationControl& modelObject )
{
  /*
  IdfObject simCon( openstudio::IddObjectType::AirflowNetworkSimulationControl );

  m_idfObjects.push_back(simCon);

  OptionalString s = modelObject.name();
  if( s ) {
    simCon.setName(*s);
  }
  */

  /*
  unsigned numSizingPeriods = modelObject.model().getModelObjects<SizingPeriod>().size();

  if( modelObject.doZoneSizingCalculation() )
  {
    simCon.setString(openstudio::SimulationControlFields::DoZoneSizingCalculation,"Yes");
  }
  else if( (numSizingPeriods > 0) && (modelObject.model().getConcreteModelObjects<ThermalZone>().size() > 0) )
  {
    simCon.setString(openstudio::SimulationControlFields::DoZoneSizingCalculation,"Yes");
  }
  else
  {
    simCon.setString(openstudio::SimulationControlFields::DoZoneSizingCalculation,"No");
  }

  if( modelObject.doSystemSizingCalculation() )
  {
    simCon.setString(openstudio::SimulationControlFields::DoSystemSizingCalculation,"Yes");
  }
  else if( (numSizingPeriods > 0) && (modelObject.model().getConcreteModelObjects<AirLoopHVAC>().size() > 0) )
  {
    simCon.setString(openstudio::SimulationControlFields::DoSystemSizingCalculation,"Yes");
  }
  else
  {
    simCon.setString(openstudio::SimulationControlFields::DoSystemSizingCalculation,"No");
  }

  if( modelObject.doPlantSizingCalculation() )
  {
    simCon.setString(openstudio::SimulationControlFields::DoPlantSizingCalculation,"Yes");
  }
  else if( (numSizingPeriods > 0) && (modelObject.model().getConcreteModelObjects<PlantLoop>().size() > 0) )
  {
    simCon.setString(openstudio::SimulationControlFields::DoPlantSizingCalculation,"Yes");
  }
  else
  {
    simCon.setString(openstudio::SimulationControlFields::DoPlantSizingCalculation,"No");
  }

  if( modelObject.runSimulationforSizingPeriods() )
  {
    simCon.setString(openstudio::SimulationControlFields::RunSimulationforSizingPeriods,"Yes");
  }
  else
  {
    simCon.setString(openstudio::SimulationControlFields::RunSimulationforSizingPeriods,"No");
  }

  // DLM: might want to check for weather file object?
  if( modelObject.runSimulationforWeatherFileRunPeriods() )
  {
    simCon.setString(openstudio::SimulationControlFields::RunSimulationforWeatherFileRunPeriods,"Yes");
  }
  else
  {
    simCon.setString(openstudio::SimulationControlFields::RunSimulationforWeatherFileRunPeriods,"No");
  }
  */

  // other fields mapped to Building

  //return boost::optional<IdfObject>(simCon);
  return boost::none;
}

} // energyplus

} // openstudio

