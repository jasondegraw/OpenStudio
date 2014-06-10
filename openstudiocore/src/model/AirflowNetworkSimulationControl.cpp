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

boost::optional<std::string> AirflowNetworkSimulationControl_Impl::airflowNetworkControl() const 
{
  return getString(OS_AirflowNetworkSimulationControlFields::AirflowNetworkControl,true);
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

} // detail

AirflowNetworkSimulationControl::AirflowNetworkSimulationControl( const Model& model ):
ParentObject(iddObjectType(),model)
{
  OS_ASSERT(getImpl<detail::AirflowNetworkSimulationControl_Impl>());
}

AirflowNetworkSimulationControl::AirflowNetworkSimulationControl(boost::shared_ptr<detail::AirflowNetworkSimulationControl_Impl> impl)
: ParentObject(impl)
{}

IddObjectType AirflowNetworkSimulationControl::iddObjectType() {
  return IddObjectType(IddObjectType::OS_AirflowNetworkSimulationControl);
}

boost::optional<std::string> AirflowNetworkSimulationControl::airflowNetworkControl() const 
{
  return getImpl<detail::AirflowNetworkSimulationControl_Impl>()->airflowNetworkControl();
}

bool AirflowNetworkSimulationControl::setAirflowNetworkControl(boost::optional<std::string> control)
{
  return getImpl<detail::AirflowNetworkSimulationControl_Impl>()->setAirflowNetworkControl(control);
}

bool AirflowNetworkSimulationControl::setAirflowNetworkControl(std::string control)
{
  return getImpl<detail::AirflowNetworkSimulationControl_Impl>()->setAirflowNetworkControl(control);
}

} // model
} // openstudio
