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

#include <model/AirflowNetworkSimulationControl.hpp>
#include <model/AirflowNetworkSimulationControl_Impl.hpp>

#include <model/Model.hpp>
#include <model/ConvergenceLimits.hpp>
#include <model/ConvergenceLimits_Impl.hpp>
#include <model/HeatBalanceAlgorithm.hpp>
#include <model/HeatBalanceAlgorithm_Impl.hpp>
#include <model/InsideSurfaceConvectionAlgorithm.hpp>
#include <model/InsideSurfaceConvectionAlgorithm_Impl.hpp>
#include <model/OutsideSurfaceConvectionAlgorithm.hpp>
#include <model/OutsideSurfaceConvectionAlgorithm_Impl.hpp>
#include <model/RunPeriod.hpp>
#include <model/RunPeriod_Impl.hpp>
#include <model/ShadowCalculation.hpp>
#include <model/ShadowCalculation_Impl.hpp>
#include <model/SizingPeriod.hpp>
#include <model/SizingPeriod_Impl.hpp>
#include <model/SizingParameters.hpp>
#include <model/SizingParameters_Impl.hpp>
#include <model/Timestep.hpp>
#include <model/Timestep_Impl.hpp>
#include <model/WeatherFile.hpp>
#include <model/WeatherFile_Impl.hpp>
#include <model/ZoneAirContaminantBalance.hpp>
#include <model/ZoneAirContaminantBalance_Impl.hpp>
#include <model/ZoneAirHeatBalanceAlgorithm.hpp>
#include <model/ZoneAirHeatBalanceAlgorithm_Impl.hpp>
#include <model/ZoneCapacitanceMultiplierResearchSpecial.hpp>
#include <model/ZoneCapacitanceMultiplierResearchSpecial_Impl.hpp>

#include <utilities/idd/IddFactory.hxx>
#include <utilities/idd/OS_AirflowNetworkSimulationControl_FieldEnums.hxx>

#include <utilities/sql/SqlFile.hpp>
#include <utilities/core/Assert.hpp>
#include <utilities/core/Compare.hpp>
#include <utilities/units/Unit.hpp>

#include <boost/bind.hpp>

namespace openstudio{
namespace model{

namespace detail{

AirflowNetworkSimulationControl_Impl::AirflowNetworkSimulationControl_Impl(const IdfObject& idfObject, Model_Impl* model, bool keepHandle)
: ParentObject_Impl(idfObject, model, keepHandle)
{
  OS_ASSERT(idfObject.iddObject().type() == AirflowNetworkSimulationControl::iddObjectType());
}

AirflowNetworkSimulationControl_Impl::AirflowNetworkSimulationControl_Impl(
  const openstudio::detail::WorkspaceObject_Impl& other,Model_Impl* model,bool keepHandle)
  : ParentObject_Impl(other,model,keepHandle)
{
  OS_ASSERT(other.iddObject().type() == AirflowNetworkSimulationControl::iddObjectType());
}

AirflowNetworkSimulationControl_Impl::AirflowNetworkSimulationControl_Impl(const AirflowNetworkSimulationControl_Impl& other,
                                                                           Model_Impl* model,
                                                                           bool keepHandle)
                                                                           : ParentObject_Impl(other,model,keepHandle)
{
}

AirflowNetworkSimulationControl_Impl::~AirflowNetworkSimulationControl_Impl()
{}

// return the parent object in the hierarchy
boost::optional<ParentObject> AirflowNetworkSimulationControl_Impl::parent() const
{
  // Simulation is highest level, there is no parent
  return boost::optional<ParentObject>();
}

// return any children objects in the hierarchy
std::vector<ModelObject> AirflowNetworkSimulationControl_Impl::children() const
{
  std::vector<ModelObject> result;

  /*
  OptionalConvergenceLimits ocl = convergenceLimits();
  if (ocl) { result.push_back(*ocl); }

  //OptionalDaylightSavingsTime odst = daylightSavingsTime();
  //if (odst) { result.push_back(*odst); }

  OptionalHeatBalanceAlgorithm ohba = heatBalanceAlgorithm();
  if (ohba) { result.push_back(*ohba); }

  OptionalInsideSurfaceConvectionAlgorithm oisca = insideSurfaceConvectionAlgorithm();
  if (oisca) { result.push_back(*oisca); }

  OptionalOutsideSurfaceConvectionAlgorithm oosca = outsideSurfaceConvectionAlgorithm();
  if (oosca) { result.push_back(*oosca); }

  RunPeriodVector rps = runPeriods();
  result.insert(result.end(),rps.begin(),rps.end());

  OptionalShadowCalculation osc = shadowCalculation();
  if (osc) { result.push_back(*osc); }

  //SpecialDaysVector sds = specialDays();
  //result.insert(result.end(),sds.begin(),sds.end());

  OptionalSizingParameters osp = sizingParameters();
  if (osp) { result.push_back(*osp); }

  OptionalTimestep ot = timestep();
  if (ot) { result.push_back(*ot); }

  OptionalZoneAirContaminantBalance ozacb = zoneAirContaminantBalance();
  if (ozacb) { result.push_back(*ozacb); }

  OptionalZoneAirHeatBalanceAlgorithm ozahba = zoneAirHeatBalanceAlgorithm();
  if (ozahba) { result.push_back(*ozahba); }

  OptionalZoneCapacitanceMultiplierResearchSpecial ozcmrs;
  ozcmrs = zoneCapacitanceMultiplierResearchSpecial();
  if (ozcmrs) { result.push_back(*ozcmrs); }
  */

  return result;
}

std::vector<IddObjectType> AirflowNetworkSimulationControl_Impl::allowableChildTypes() const {
  IddObjectTypeVector result;
  /*
  result.push_back(ConvergenceLimits::iddObjectType());
  result.push_back(HeatBalanceAlgorithm::iddObjectType());
  result.push_back(InsideSurfaceConvectionAlgorithm::iddObjectType());
  result.push_back(OutsideSurfaceConvectionAlgorithm::iddObjectType());
  result.push_back(RunPeriod::iddObjectType());
  result.push_back(ShadowCalculation::iddObjectType());
  result.push_back(SizingParameters::iddObjectType());
  result.push_back(Timestep::iddObjectType());
  result.push_back(ZoneAirContaminantBalance::iddObjectType());
  result.push_back(ZoneAirHeatBalanceAlgorithm::iddObjectType());
  result.push_back(ZoneCapacitanceMultiplierResearchSpecial::iddObjectType());
  */
  return result;
}

const std::vector<std::string>& AirflowNetworkSimulationControl_Impl::outputVariableNames() const
{
  static std::vector<std::string> result;
  if (result.empty()){
  }
  return result;
}

IddObjectType AirflowNetworkSimulationControl_Impl::iddObjectType() const {
  return AirflowNetworkSimulationControl::iddObjectType();
}

/*
boost::optional<std::string> AirflowNetworkSimulationControl_Impl::airflowNetworkControl() const 
{
  return getString(OS_AirflowNetworkSimulationControlFields::AirflowNetworkControl,true);
}

boost::optional<std::string> AirflowNetworkSimulationControl_Impl::windPressureCoefficientType() const 
{
  return getString(OS_AirflowNetworkSimulationControlFields::WindPressureCoefficientType,true);
}

boost::optional<std::string> AirflowNetworkSimulationControl_Impl::heightSelectionforLocalWindPressureCalculation() const 
{
  return getString(OS_AirflowNetworkSimulationControlFields::HeightSelectionforLocalWindPressureCalculation,true);
}

bool AirflowNetworkSimulationControl_Impl::setAirflowNetworkControl(boost::optional<std::string> control)
{
  bool result = false;
  if (control) {
    result = setString(OS_AirflowNetworkSimulationControlFields::AirflowNetworkControl, control.get());
  } else {
    result = setString(OS_AirflowNetworkSimulationControlFields::AirflowNetworkControl, "");
  }
  return result;
}

bool AirflowNetworkSimulationControl_Impl::setAirflowNetworkControl(std::string control)
{
  bool result = setString(OS_AirflowNetworkSimulationControlFields::AirflowNetworkControl, control);
  return result;
}

bool AirflowNetworkSimulationControl_Impl::setWindPressureCoefficientType(boost::optional<std::string> type)
{
  bool result = false;
  if (type) {
    result = setString(OS_AirflowNetworkSimulationControlFields::WindPressureCoefficientType, type.get());
  } else {
    result = setString(OS_AirflowNetworkSimulationControlFields::WindPressureCoefficientType, "");
  }
  return result;
}

bool AirflowNetworkSimulationControl_Impl::setWindPressureCoefficientType(std::string type)
{
  bool result = setString(OS_AirflowNetworkSimulationControlFields::WindPressureCoefficientType, type);
  return result;
}

bool AirflowNetworkSimulationControl_Impl::setHeightSelectionforLocalWindPressureCalculation(boost::optional<std::string> type)
{
  bool result = false;
  if (type) {
    result = setString(OS_AirflowNetworkSimulationControlFields::HeightSelectionforLocalWindPressureCalculation, type.get());
  } else {
    result = setString(OS_AirflowNetworkSimulationControlFields::HeightSelectionforLocalWindPressureCalculation, "");
  }
  return result;
}

bool AirflowNetworkSimulationControl_Impl::setHeightSelectionforLocalWindPressureCalculation(std::string type)
{
  bool result = setString(OS_AirflowNetworkSimulationControlFields::HeightSelectionforLocalWindPressureCalculation, type);
  return result;
}
*/

boost::optional<std::string> AirflowNetworkSimulationControl_Impl::airflowNetworkControl() const
{
  return getString(OS_AirflowNetworkSimulationControlFields::AirflowNetworkControl,true);
}

boost::optional<std::string> AirflowNetworkSimulationControl_Impl::windPressureCoefficientType() const
{
  return getString(OS_AirflowNetworkSimulationControlFields::WindPressureCoefficientType,true);
}

// Skipping AirflowNetworkWindPressureCoefficientArrayName

boost::optional<std::string> AirflowNetworkSimulationControl_Impl::heightSelectionforLocalWindPressureCalculation() const
{
  return getString(OS_AirflowNetworkSimulationControlFields::HeightSelectionforLocalWindPressureCalculation,true);
}

boost::optional<std::string> AirflowNetworkSimulationControl_Impl::buildingType() const
{
  return getString(OS_AirflowNetworkSimulationControlFields::BuildingType,true);
}

boost::optional<int> AirflowNetworkSimulationControl_Impl::maximumNumberofIterations() const
{
  return getInt(OS_AirflowNetworkSimulationControlFields::MaximumNumberofIterations,true);
}

boost::optional<std::string> AirflowNetworkSimulationControl_Impl::initializationType() const
{
  return getString(OS_AirflowNetworkSimulationControlFields::InitializationType,true);
}

boost::optional<double> AirflowNetworkSimulationControl_Impl::relativeAirflowConvergenceTolerance() const
{
  return getDouble(OS_AirflowNetworkSimulationControlFields::RelativeAirflowConvergenceTolerance,true);
}

boost::optional<double> AirflowNetworkSimulationControl_Impl::absoluteAirflowConvergenceTolerance() const
{
  return getDouble(OS_AirflowNetworkSimulationControlFields::AbsoluteAirflowConvergenceTolerance,true);
}

boost::optional<double> AirflowNetworkSimulationControl_Impl::convergenceAccelerationLimit() const
{
  return getDouble(OS_AirflowNetworkSimulationControlFields::ConvergenceAccelerationLimit,true);
}

boost::optional<double> AirflowNetworkSimulationControl_Impl::azimuthAngleofLongAxisofBuilding() const
{
  return getDouble(OS_AirflowNetworkSimulationControlFields::AzimuthAngleofLongAxisofBuilding,true);
}

boost::optional<double> AirflowNetworkSimulationControl_Impl::ratioofBuildingWidthAlongShortAxistoWidthAlongLongAxis() const
{
  return getDouble(OS_AirflowNetworkSimulationControlFields::RatioofBuildingWidthAlongShortAxistoWidthAlongLongAxis,true);
}

bool AirflowNetworkSimulationControl_Impl::setAirflowNetworkControl(boost::optional<std::string> airflowNetworkControl)
{
  bool result = false;
  if (airflowNetworkControl) {
    result = setString(OS_AirflowNetworkSimulationControlFields::AirflowNetworkControl, airflowNetworkControl.get());
  } else {
    result = setString(OS_AirflowNetworkSimulationControlFields::AirflowNetworkControl, "");
  }
  return result;
}

bool AirflowNetworkSimulationControl_Impl::setAirflowNetworkControl(std::string airflowNetworkControl)
{
  bool result = setString(OS_AirflowNetworkSimulationControlFields::AirflowNetworkControl, airflowNetworkControl);
  return result;
}

bool AirflowNetworkSimulationControl_Impl::setWindPressureCoefficientType(boost::optional<std::string> type)
{
  bool result = false;
  if (type) {
    result = setString(OS_AirflowNetworkSimulationControlFields::WindPressureCoefficientType, type.get());
  } else {
    result = setString(OS_AirflowNetworkSimulationControlFields::WindPressureCoefficientType, "");
  }
  return result;
}

bool AirflowNetworkSimulationControl_Impl::setWindPressureCoefficientType(std::string type)
{
  bool result = setString(OS_AirflowNetworkSimulationControlFields::WindPressureCoefficientType, type);
  return result;
}

// Skipping AirflowNetworkWindPressureCoefficientArrayName

bool AirflowNetworkSimulationControl_Impl::setHeightSelectionforLocalWindPressureCalculation(boost::optional<std::string> height)
{
  bool result = false;
  if (height) {
    result = setString(OS_AirflowNetworkSimulationControlFields::HeightSelectionforLocalWindPressureCalculation, height.get());
  } else {
    result = setString(OS_AirflowNetworkSimulationControlFields::HeightSelectionforLocalWindPressureCalculation, "");
  }
  return result;
}

bool AirflowNetworkSimulationControl_Impl::setHeightSelectionforLocalWindPressureCalculation(std::string height)
{
  bool result = setString(OS_AirflowNetworkSimulationControlFields::HeightSelectionforLocalWindPressureCalculation, height);
  return result;
}

bool AirflowNetworkSimulationControl_Impl::setBuildingType(boost::optional<std::string> type)
{
  bool result = false;
  if (type) {
    result = setString(OS_AirflowNetworkSimulationControlFields::BuildingType, type.get());
  } else {
    result = setString(OS_AirflowNetworkSimulationControlFields::BuildingType, "");
  }
  return result;
}

bool AirflowNetworkSimulationControl_Impl::setBuildingType(std::string type)
{
  bool result = setString(OS_AirflowNetworkSimulationControlFields::BuildingType, type);
  return result;
}

bool AirflowNetworkSimulationControl_Impl::setMaximumNumberofIterations(boost::optional<int> number)
{
  bool result = false;
  if (number) {
    result = setInt(OS_AirflowNetworkSimulationControlFields::MaximumNumberofIterations, number.get());
  } else {
    result = setInt(OS_AirflowNetworkSimulationControlFields::MaximumNumberofIterations, 500);
  }
  return result;
}

bool AirflowNetworkSimulationControl_Impl::setMaximumNumberofIterations(int number)
{
  bool result = setInt(OS_AirflowNetworkSimulationControlFields::MaximumNumberofIterations, number);
  return result;
}

bool AirflowNetworkSimulationControl_Impl::setInitializationType(boost::optional<std::string> type)
{
  bool result = false;
  if (type) {
    result = setString(OS_AirflowNetworkSimulationControlFields::InitializationType, type.get());
  } else {
    result = setString(OS_AirflowNetworkSimulationControlFields::InitializationType, "");
  }
  return result;
}

bool AirflowNetworkSimulationControl_Impl::setInitializationType(std::string type)
{
  bool result = setString(OS_AirflowNetworkSimulationControlFields::InitializationType, type);
  return result;
}

bool AirflowNetworkSimulationControl_Impl::setRelativeAirflowConvergenceTolerance(boost::optional<double> tolerance)
{
  bool result = false;
  if (tolerance) {
    result = setDouble(OS_AirflowNetworkSimulationControlFields::RelativeAirflowConvergenceTolerance, tolerance.get());
  } else {
    result = setDouble(OS_AirflowNetworkSimulationControlFields::RelativeAirflowConvergenceTolerance, 1.0e-4);
  }
  return result;
}

bool AirflowNetworkSimulationControl_Impl::setRelativeAirflowConvergenceTolerance(double tolerance)
{
  bool result = setDouble(OS_AirflowNetworkSimulationControlFields::RelativeAirflowConvergenceTolerance, tolerance);
  return result;
}

bool AirflowNetworkSimulationControl_Impl::setAbsoluteAirflowConvergenceTolerance(boost::optional<double> tolerance)
{
  bool result = false;
  if (tolerance) {
    result = setDouble(OS_AirflowNetworkSimulationControlFields::AbsoluteAirflowConvergenceTolerance, tolerance.get());
  } else {
    result = setDouble(OS_AirflowNetworkSimulationControlFields::AbsoluteAirflowConvergenceTolerance, 1.0e-6);
  }
  return result;
}

bool AirflowNetworkSimulationControl_Impl::setAbsoluteAirflowConvergenceTolerance(double tolerance)
{
  bool result = setDouble(OS_AirflowNetworkSimulationControlFields::AbsoluteAirflowConvergenceTolerance, tolerance);
  return result;
}

bool AirflowNetworkSimulationControl_Impl::setConvergenceAccelerationLimit(boost::optional<double> limit)
{
  bool result = false;
  if (limit) {
    result = setDouble(OS_AirflowNetworkSimulationControlFields::ConvergenceAccelerationLimit, limit.get());
  } else {
    result = setDouble(OS_AirflowNetworkSimulationControlFields::ConvergenceAccelerationLimit, -0.5);
  }
  return result;
}

bool AirflowNetworkSimulationControl_Impl::setConvergenceAccelerationLimit(double limit)
{
  bool result = setDouble(OS_AirflowNetworkSimulationControlFields::ConvergenceAccelerationLimit, limit);
  return result;
}

bool AirflowNetworkSimulationControl_Impl::setAzimuthAngleofLongAxisofBuilding(boost::optional<double> angle)
{
  bool result = false;
  if (angle) {
    result = setDouble(OS_AirflowNetworkSimulationControlFields::AzimuthAngleofLongAxisofBuilding, angle.get());
  } else {
    result = setDouble(OS_AirflowNetworkSimulationControlFields::AzimuthAngleofLongAxisofBuilding, 0.0);
  }
  return result;
}

bool AirflowNetworkSimulationControl_Impl::setAzimuthAngleofLongAxisofBuilding(double angle)
{
  bool result = setDouble(OS_AirflowNetworkSimulationControlFields::AzimuthAngleofLongAxisofBuilding, angle);
  return result;
}

bool AirflowNetworkSimulationControl_Impl::setRatioofBuildingWidthAlongShortAxistoWidthAlongLongAxis(boost::optional<double> ratio)
{
  bool result = false;
  if (ratio) {
    result = setDouble(OS_AirflowNetworkSimulationControlFields::RatioofBuildingWidthAlongShortAxistoWidthAlongLongAxis, ratio.get());
  } else {
    result = setDouble(OS_AirflowNetworkSimulationControlFields::RatioofBuildingWidthAlongShortAxistoWidthAlongLongAxis, 1.0);
  }
  return result;
}

bool AirflowNetworkSimulationControl_Impl::setRatioofBuildingWidthAlongShortAxistoWidthAlongLongAxis(double ratio)
{
  bool result = setDouble(OS_AirflowNetworkSimulationControlFields::RatioofBuildingWidthAlongShortAxistoWidthAlongLongAxis, ratio);
  return result;
}

} // detail

AirflowNetworkSimulationControl::AirflowNetworkSimulationControl( const Model& model ):
ParentObject(iddObjectType(),model)
{
  OS_ASSERT(getImpl<detail::AirflowNetworkSimulationControl_Impl>());
}

AirflowNetworkSimulationControl::AirflowNetworkSimulationControl(std::shared_ptr<detail::AirflowNetworkSimulationControl_Impl> impl)
: ParentObject(impl)
{}

IddObjectType AirflowNetworkSimulationControl::iddObjectType() {
  return IddObjectType(IddObjectType::OS_AirflowNetworkSimulationControl);
}

/*

boost::optional<std::string> AirflowNetworkSimulationControl::airflowNetworkControl() const 
{
  return getImpl<detail::AirflowNetworkSimulationControl_Impl>()->airflowNetworkControl();
}

boost::optional<std::string> AirflowNetworkSimulationControl::windPressureCoefficientType() const 
{
  return getImpl<detail::AirflowNetworkSimulationControl_Impl>()->windPressureCoefficientType();
}

boost::optional<std::string> AirflowNetworkSimulationControl::heightSelectionforLocalWindPressureCalculation() const 
{
  return getImpl<detail::AirflowNetworkSimulationControl_Impl>()->heightSelectionforLocalWindPressureCalculation();
}

bool AirflowNetworkSimulationControl::setAirflowNetworkControl(boost::optional<std::string> control)
{
  return getImpl<detail::AirflowNetworkSimulationControl_Impl>()->setAirflowNetworkControl(control);
}

bool AirflowNetworkSimulationControl::setAirflowNetworkControl(std::string control)
{
  return getImpl<detail::AirflowNetworkSimulationControl_Impl>()->setAirflowNetworkControl(control);
}

bool AirflowNetworkSimulationControl::setWindPressureCoefficientType(boost::optional<std::string> type)
{
  return getImpl<detail::AirflowNetworkSimulationControl_Impl>()->setWindPressureCoefficientType(type);
}

bool AirflowNetworkSimulationControl::setWindPressureCoefficientType(std::string type)
{
  return getImpl<detail::AirflowNetworkSimulationControl_Impl>()->setWindPressureCoefficientType(type);
}

bool AirflowNetworkSimulationControl::setHeightSelectionforLocalWindPressureCalculation(boost::optional<std::string> type)
{
  return getImpl<detail::AirflowNetworkSimulationControl_Impl>()->setHeightSelectionforLocalWindPressureCalculation(type);
}

bool AirflowNetworkSimulationControl::setHeightSelectionforLocalWindPressureCalculation(std::string type)
{
  return getImpl<detail::AirflowNetworkSimulationControl_Impl>()->setHeightSelectionforLocalWindPressureCalculation(type);
}

*/


boost::optional<std::string> AirflowNetworkSimulationControl::airflowNetworkControl() const
{
  return getImpl<detail::AirflowNetworkSimulationControl_Impl>()->airflowNetworkControl();
}

boost::optional<std::string> AirflowNetworkSimulationControl::windPressureCoefficientType() const
{
  return getImpl<detail::AirflowNetworkSimulationControl_Impl>()->windPressureCoefficientType();
}

// Skipping AirflowNetworkWindPressureCoefficientArrayName

boost::optional<std::string> AirflowNetworkSimulationControl::heightSelectionforLocalWindPressureCalculation() const
{
  return getImpl<detail::AirflowNetworkSimulationControl_Impl>()->heightSelectionforLocalWindPressureCalculation();
}

boost::optional<std::string> AirflowNetworkSimulationControl::buildingType() const
{
  return getImpl<detail::AirflowNetworkSimulationControl_Impl>()->buildingType();
}

boost::optional<int> AirflowNetworkSimulationControl::maximumNumberofIterations() const
{
  return getImpl<detail::AirflowNetworkSimulationControl_Impl>()->maximumNumberofIterations();
}

boost::optional<std::string> AirflowNetworkSimulationControl::initializationType() const
{
  return getImpl<detail::AirflowNetworkSimulationControl_Impl>()->initializationType();
}

boost::optional<double> AirflowNetworkSimulationControl::relativeAirflowConvergenceTolerance() const
{
  return getImpl<detail::AirflowNetworkSimulationControl_Impl>()->relativeAirflowConvergenceTolerance();
}

boost::optional<double> AirflowNetworkSimulationControl::absoluteAirflowConvergenceTolerance() const
{
  return getImpl<detail::AirflowNetworkSimulationControl_Impl>()->absoluteAirflowConvergenceTolerance();
}

boost::optional<double> AirflowNetworkSimulationControl::convergenceAccelerationLimit() const
{
  return getImpl<detail::AirflowNetworkSimulationControl_Impl>()->convergenceAccelerationLimit();
}

boost::optional<double> AirflowNetworkSimulationControl::azimuthAngleofLongAxisofBuilding() const
{
  return getImpl<detail::AirflowNetworkSimulationControl_Impl>()->azimuthAngleofLongAxisofBuilding();
}

boost::optional<double> AirflowNetworkSimulationControl::ratioofBuildingWidthAlongShortAxistoWidthAlongLongAxis() const
{
  return getImpl<detail::AirflowNetworkSimulationControl_Impl>()->ratioofBuildingWidthAlongShortAxistoWidthAlongLongAxis();
}

bool AirflowNetworkSimulationControl::setAirflowNetworkControl(std::string airflowNetworkControl)
{
  return getImpl<detail::AirflowNetworkSimulationControl_Impl>()->setAirflowNetworkControl(airflowNetworkControl);
}

bool AirflowNetworkSimulationControl::setAirflowNetworkControl(boost::optional<std::string> airflowNetworkControl)
{
  return getImpl<detail::AirflowNetworkSimulationControl_Impl>()->setAirflowNetworkControl(airflowNetworkControl);
}

bool AirflowNetworkSimulationControl::setWindPressureCoefficientType(std::string type)
{
  return getImpl<detail::AirflowNetworkSimulationControl_Impl>()->setWindPressureCoefficientType(type);
}

bool AirflowNetworkSimulationControl::setWindPressureCoefficientType(boost::optional<std::string> type)
{
  return getImpl<detail::AirflowNetworkSimulationControl_Impl>()->setWindPressureCoefficientType(type);
}

// Skipping AirflowNetworkWindPressureCoefficientArrayName

bool AirflowNetworkSimulationControl::setHeightSelectionforLocalWindPressureCalculation(std::string height)
{
  return getImpl<detail::AirflowNetworkSimulationControl_Impl>()->setHeightSelectionforLocalWindPressureCalculation(height);
}

bool AirflowNetworkSimulationControl::setHeightSelectionforLocalWindPressureCalculation(boost::optional<std::string> height)
{
  return getImpl<detail::AirflowNetworkSimulationControl_Impl>()->setHeightSelectionforLocalWindPressureCalculation(height);
}

bool AirflowNetworkSimulationControl::setBuildingType(std::string type)
{
  return getImpl<detail::AirflowNetworkSimulationControl_Impl>()->setBuildingType(type);
}

bool AirflowNetworkSimulationControl::setBuildingType(boost::optional<std::string> type)
{
  return getImpl<detail::AirflowNetworkSimulationControl_Impl>()->setBuildingType(type);
}

bool AirflowNetworkSimulationControl::setMaximumNumberofIterations(int number)
{
  return getImpl<detail::AirflowNetworkSimulationControl_Impl>()->setMaximumNumberofIterations(number);
}

bool AirflowNetworkSimulationControl::setMaximumNumberofIterations(boost::optional<int> number)
{
  return getImpl<detail::AirflowNetworkSimulationControl_Impl>()->setMaximumNumberofIterations(number);
}

bool AirflowNetworkSimulationControl::setInitializationType(std::string type)
{
  return getImpl<detail::AirflowNetworkSimulationControl_Impl>()->setInitializationType(type);
}

bool AirflowNetworkSimulationControl::setInitializationType(boost::optional<std::string> type)
{
  return getImpl<detail::AirflowNetworkSimulationControl_Impl>()->setInitializationType(type);
}

bool AirflowNetworkSimulationControl::setRelativeAirflowConvergenceTolerance(double tolerance)
{
  return getImpl<detail::AirflowNetworkSimulationControl_Impl>()->setRelativeAirflowConvergenceTolerance(tolerance);
}

bool AirflowNetworkSimulationControl::setRelativeAirflowConvergenceTolerance(boost::optional<double> tolerance)
{
  return getImpl<detail::AirflowNetworkSimulationControl_Impl>()->setRelativeAirflowConvergenceTolerance(tolerance);
}

bool AirflowNetworkSimulationControl::setAbsoluteAirflowConvergenceTolerance(double tolerance)
{
  return getImpl<detail::AirflowNetworkSimulationControl_Impl>()->setAbsoluteAirflowConvergenceTolerance(tolerance);
}

bool AirflowNetworkSimulationControl::setAbsoluteAirflowConvergenceTolerance(boost::optional<double> tolerance)
{
  return getImpl<detail::AirflowNetworkSimulationControl_Impl>()->setAbsoluteAirflowConvergenceTolerance(tolerance);
}

bool AirflowNetworkSimulationControl::setConvergenceAccelerationLimit(double limit)
{
  return getImpl<detail::AirflowNetworkSimulationControl_Impl>()->setConvergenceAccelerationLimit(limit);
}

bool AirflowNetworkSimulationControl::setConvergenceAccelerationLimit(boost::optional<double> limit)
{
  return getImpl<detail::AirflowNetworkSimulationControl_Impl>()->setConvergenceAccelerationLimit(limit);
}

bool AirflowNetworkSimulationControl::setAzimuthAngleofLongAxisofBuilding(double angle)
{
  return getImpl<detail::AirflowNetworkSimulationControl_Impl>()->setAzimuthAngleofLongAxisofBuilding(angle);
}

bool AirflowNetworkSimulationControl::setAzimuthAngleofLongAxisofBuilding(boost::optional<double> angle)
{
  return getImpl<detail::AirflowNetworkSimulationControl_Impl>()->setAzimuthAngleofLongAxisofBuilding(angle);
}

bool AirflowNetworkSimulationControl::setRatioofBuildingWidthAlongShortAxistoWidthAlongLongAxis(double ratio)
{
  return getImpl<detail::AirflowNetworkSimulationControl_Impl>()->setRatioofBuildingWidthAlongShortAxistoWidthAlongLongAxis(ratio);
}

bool AirflowNetworkSimulationControl::setRatioofBuildingWidthAlongShortAxistoWidthAlongLongAxis(boost::optional<double> ratio)
{
  return getImpl<detail::AirflowNetworkSimulationControl_Impl>()->setRatioofBuildingWidthAlongShortAxistoWidthAlongLongAxis(ratio);
}

} // model
} // openstudio
