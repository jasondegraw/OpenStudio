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

#include <utilities/idd/AirflowNetwork_SimulationControl_FieldEnums.hxx>

#include <utilities/idd/IddEnums.hxx>
#include <utilities/idd/IddFactory.hxx>

using namespace openstudio::model;

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
    idfObject.setString(AirflowNetwork_SimulationControlFields::BuildingType,optString.get());
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

