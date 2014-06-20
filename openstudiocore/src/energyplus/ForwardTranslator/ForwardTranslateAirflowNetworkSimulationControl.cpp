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

/*
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
*/

#include <utilities/idd/AirflowNetwork_SimulationControl_FieldEnums.hxx>
//#include <utilities/idd/OS_AirflowNetworkSimulationControl_FieldEnums.hxx>

#include <utilities/idd/IddEnums.hxx>
#include <utilities/idd/IddFactory.hxx>

using namespace openstudio::model;

using namespace std;

namespace openstudio {

namespace energyplus {

boost::optional<IdfObject> ForwardTranslator::translateAirflowNetworkSimulationControl( AirflowNetworkSimulationControl& modelObject )
{
  IdfObject idfObject( IddObjectType::AirflowNetwork_SimulationControl );

  m_idfObjects.push_back(idfObject);

  OptionalString s = modelObject.name();
  if( s ) {
    idfObject.setName(*s);
  }

  boost::optional<std::string> optString;
  boost::optional<int> optInt;
  boost::optional<double> optDouble;

  // A2 , \field AirflowNetwork Control
  optString = modelObject.airflowNetworkControl();
  if(optString) {
    idfObject.setString(AirflowNetwork_SimulationControlFields::AirflowNetworkControl,optString.get());
  }

  // A3 , \field Wind Pressure Coefficient Type
  optString = modelObject.windPressureCoefficientType();
  if(optString) {
    idfObject.setString(AirflowNetwork_SimulationControlFields::WindPressureCoefficientType,optString.get());
  }
  
  // A4 , \field AirflowNetwork Wind Pressure Coefficient Array Name
  /*
      \type object-list
      \object-list WPCSetNames
      \note Used only if Wind Pressure Coefficient Type = Input, otherwise this field may be left blank.
  */

  // A5 , \field Height Selection for Local Wind Pressure Calculation
  optString = modelObject.heightSelectionforLocalWindPressureCalculation();
  if(optString) {
    idfObject.setString(AirflowNetwork_SimulationControlFields::HeightSelectionforLocalWindPressureCalculation,optString.get());
  }

  // A6 , \field Building Type
  optString = modelObject.buildingType();
  if(optString) {
    idfObject.setString(AirflowNetwork_SimulationControlFields::HeightSelectionforLocalWindPressureCalculation,optString.get());
  }

  // N1 , \field Maximum Number of Iterations
  optInt = modelObject.maximumNumberofIterations();
  if(optInt) {
    idfObject.setInt(AirflowNetwork_SimulationControlFields::MaximumNumberofIterations,optInt.get());
  }

  // A7 , \field Initialization Type
  optString = modelObject.initializationType();
  if(optString) {
    idfObject.setString(AirflowNetwork_SimulationControlFields::InitializationType,optString.get());
  }
  
  // N2 , \field Relative Airflow Convergence Tolerance
  optDouble = modelObject.relativeAirflowConvergenceTolerance();
  if(optInt) {
    idfObject.setDouble(AirflowNetwork_SimulationControlFields::RelativeAirflowConvergenceTolerance,optDouble.get());
  }

  // N3 , \field Absolute Airflow Convergence Tolerance
  optDouble = modelObject.absoluteAirflowConvergenceTolerance();
  if(optInt) {
    idfObject.setDouble(AirflowNetwork_SimulationControlFields::AbsoluteAirflowConvergenceTolerance,optDouble.get());
  }

  // N4 , \field Convergence Acceleration Limit
  optDouble = modelObject.convergenceAccelerationLimit();
  if(optInt) {
    idfObject.setDouble(AirflowNetwork_SimulationControlFields::ConvergenceAccelerationLimit,optDouble.get());
  }

  // N5 , \field Azimuth Angle of Long Axis of Building
  optDouble = modelObject.azimuthAngleofLongAxisofBuilding();
  if(optInt) {
    idfObject.setDouble(AirflowNetwork_SimulationControlFields::AzimuthAngleofLongAxisofBuilding,optDouble.get());
  }   

  // N6 ; \field Ratio of Building Width Along Short Axis to Width Along Long Axis
  optDouble = modelObject.ratioofBuildingWidthAlongShortAxistoWidthAlongLongAxis();
  if(optInt) {
    idfObject.setDouble(AirflowNetwork_SimulationControlFields::RatioofBuildingWidthAlongShortAxistoWidthAlongLongAxis,optDouble.get());
  }

  return boost::optional<IdfObject>(idfObject);
}

} // energyplus

} // openstudio

