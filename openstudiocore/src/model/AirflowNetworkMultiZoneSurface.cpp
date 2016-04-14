/**********************************************************************
 *  Copyright (c) 2008-2016, Alliance for Sustainable Energy.
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

#include "AirflowNetworkMultiZoneSurface.hpp"
#include "AirflowNetworkMultiZoneSurface_Impl.hpp"

// TODO: Check the following class names against object getters and setters.
#include "SurfAndSubSurf.hpp"
#include "SurfAndSubSurf_Impl.hpp"
#include "SurfaceAirflowLeakage.hpp"
#include "SurfaceAirflowLeakage_Impl.hpp"
#include "ExternalNode.hpp"
#include "ExternalNode_Impl.hpp"
#include "Schedule.hpp"
#include "Schedule_Impl.hpp"
#include "Schedule.hpp"
#include "Schedule_Impl.hpp"
#include "AirflowNetworkOccupantVentilationControl.hpp"
#include "AirflowNetworkOccupantVentilationControl_Impl.hpp"
#include "../../model/ScheduleTypeLimits.hpp"
#include "../../model/ScheduleTypeRegistry.hpp"

#include <utilities/idd/IddFactory.hxx>
#include <utilities/idd/IddEnums.hxx>
#include <utilities/idd/OS_AirflowNetwork_MultiZoneSurface_FieldEnums.hxx>

#include "../utilities/units/Unit.hpp"

#include "../utilities/core/Assert.hpp"

namespace openstudio {
namespace model {

namespace detail {

  AirflowNetworkMultiZoneSurface_Impl::AirflowNetworkMultiZoneSurface_Impl(const IdfObject& idfObject,
                                                                           Model_Impl* model,
                                                                           bool keepHandle)
    : ModelObject_Impl(idfObject,model,keepHandle)
  {
    OS_ASSERT(idfObject.iddObject().type() == AirflowNetworkMultiZoneSurface::iddObjectType());
  }

  AirflowNetworkMultiZoneSurface_Impl::AirflowNetworkMultiZoneSurface_Impl(const openstudio::detail::WorkspaceObject_Impl& other,
                                                                           Model_Impl* model,
                                                                           bool keepHandle)
    : ModelObject_Impl(other,model,keepHandle)
  {
    OS_ASSERT(other.iddObject().type() == AirflowNetworkMultiZoneSurface::iddObjectType());
  }

  AirflowNetworkMultiZoneSurface_Impl::AirflowNetworkMultiZoneSurface_Impl(const AirflowNetworkMultiZoneSurface_Impl& other,
                                                                           Model_Impl* model,
                                                                           bool keepHandle)
    : ModelObject_Impl(other,model,keepHandle)
  {}

  const std::vector<std::string>& AirflowNetworkMultiZoneSurface_Impl::outputVariableNames() const
  {
    static std::vector<std::string> result;
    if (result.empty()){
    }
    return result;
  }

  IddObjectType AirflowNetworkMultiZoneSurface_Impl::iddObjectType() const {
    return AirflowNetworkMultiZoneSurface::iddObjectType();
  }

  std::vector<ScheduleTypeKey> AirflowNetworkMultiZoneSurface_Impl::getScheduleTypeKeys(const Schedule& schedule) const
  {
    // TODO: Check schedule display names.
    std::vector<ScheduleTypeKey> result;
    UnsignedVector fieldIndices = getSourceIndices(schedule.handle());
    UnsignedVector::const_iterator b(fieldIndices.begin()), e(fieldIndices.end());
    if (std::find(b,e,OS_AirflowNetwork_MultiZoneSurfaceFields::VentilationControlZoneTemperatureSetpointScheduleName) != e)
    {
      result.push_back(ScheduleTypeKey("AirflowNetworkMultiZoneSurface","Ventilation Control Zone Temperature Setpoint"));
    }
    if (std::find(b,e,OS_AirflowNetwork_MultiZoneSurfaceFields::VentingAvailabilityScheduleName) != e)
    {
      result.push_back(ScheduleTypeKey("AirflowNetworkMultiZoneSurface","Venting Availability"));
    }
    return result;
  }

  SurfAndSubSurf AirflowNetworkMultiZoneSurface_Impl::surface() const {
    boost::optional<SurfAndSubSurf> value = optionalSurface();
    if (!value) {
      LOG_AND_THROW(briefDescription() << " does not have an Surface attached.");
    }
    return value.get();
  }

  SurfaceAirflowLeakage AirflowNetworkMultiZoneSurface_Impl::leakageComponent() const {
    boost::optional<SurfaceAirflowLeakage> value = optionalLeakageComponent();
    if (!value) {
      LOG_AND_THROW(briefDescription() << " does not have an Leakage Component attached.");
    }
    return value.get();
  }

  boost::optional<ExternalNode> AirflowNetworkMultiZoneSurface_Impl::externalNode() const {
    return getObject<ModelObject>().getModelObjectTarget<ExternalNode>(OS_AirflowNetwork_MultiZoneSurfaceFields::ExternalNodeName);
  }

  double AirflowNetworkMultiZoneSurface_Impl::windowDoorOpeningFactorOrCrackFactor() const {
    boost::optional<double> value = getDouble(OS_AirflowNetwork_MultiZoneSurfaceFields::Window_DoorOpeningFactor_orCrackFactor,true);
    OS_ASSERT(value);
    return value.get();
  }

  bool AirflowNetworkMultiZoneSurface_Impl::isWindowDoorOpeningFactorOrCrackFactorDefaulted() const {
    return isEmpty(OS_AirflowNetwork_MultiZoneSurfaceFields::Window_DoorOpeningFactor_orCrackFactor);
  }

  std::string AirflowNetworkMultiZoneSurface_Impl::ventilationControlMode() const {
    boost::optional<std::string> value = getString(OS_AirflowNetwork_MultiZoneSurfaceFields::VentilationControlMode,true);
    OS_ASSERT(value);
    return value.get();
  }

  bool AirflowNetworkMultiZoneSurface_Impl::isVentilationControlModeDefaulted() const {
    return isEmpty(OS_AirflowNetwork_MultiZoneSurfaceFields::VentilationControlMode);
  }

  boost::optional<Schedule> AirflowNetworkMultiZoneSurface_Impl::ventilationControlZoneTemperatureSetpointSchedule() const {
    return getObject<ModelObject>().getModelObjectTarget<Schedule>(OS_AirflowNetwork_MultiZoneSurfaceFields::VentilationControlZoneTemperatureSetpointScheduleName);
  }

  double AirflowNetworkMultiZoneSurface_Impl::minimumVentingOpenFactor() const {
    boost::optional<double> value = getDouble(OS_AirflowNetwork_MultiZoneSurfaceFields::MinimumVentingOpenFactor,true);
    OS_ASSERT(value);
    return value.get();
  }

  bool AirflowNetworkMultiZoneSurface_Impl::isMinimumVentingOpenFactorDefaulted() const {
    return isEmpty(OS_AirflowNetwork_MultiZoneSurfaceFields::MinimumVentingOpenFactor);
  }

  double AirflowNetworkMultiZoneSurface_Impl::indoorandOutdoorTemperatureDifferenceLowerLimitForMaximumVentingOpenFactor() const {
    boost::optional<double> value = getDouble(OS_AirflowNetwork_MultiZoneSurfaceFields::IndoorandOutdoorTemperatureDifferenceLowerLimitForMaximumVentingOpenFactor,true);
    OS_ASSERT(value);
    return value.get();
  }

  bool AirflowNetworkMultiZoneSurface_Impl::isIndoorandOutdoorTemperatureDifferenceLowerLimitForMaximumVentingOpenFactorDefaulted() const {
    return isEmpty(OS_AirflowNetwork_MultiZoneSurfaceFields::IndoorandOutdoorTemperatureDifferenceLowerLimitForMaximumVentingOpenFactor);
  }

  double AirflowNetworkMultiZoneSurface_Impl::indoorandOutdoorTemperatureDifferenceUpperLimitforMinimumVentingOpenFactor() const {
    boost::optional<double> value = getDouble(OS_AirflowNetwork_MultiZoneSurfaceFields::IndoorandOutdoorTemperatureDifferenceUpperLimitforMinimumVentingOpenFactor,true);
    OS_ASSERT(value);
    return value.get();
  }

  bool AirflowNetworkMultiZoneSurface_Impl::isIndoorandOutdoorTemperatureDifferenceUpperLimitforMinimumVentingOpenFactorDefaulted() const {
    return isEmpty(OS_AirflowNetwork_MultiZoneSurfaceFields::IndoorandOutdoorTemperatureDifferenceUpperLimitforMinimumVentingOpenFactor);
  }

  double AirflowNetworkMultiZoneSurface_Impl::indoorandOutdoorEnthalpyDifferenceLowerLimitForMaximumVentingOpenFactor() const {
    boost::optional<double> value = getDouble(OS_AirflowNetwork_MultiZoneSurfaceFields::IndoorandOutdoorEnthalpyDifferenceLowerLimitForMaximumVentingOpenFactor,true);
    OS_ASSERT(value);
    return value.get();
  }

  bool AirflowNetworkMultiZoneSurface_Impl::isIndoorandOutdoorEnthalpyDifferenceLowerLimitForMaximumVentingOpenFactorDefaulted() const {
    return isEmpty(OS_AirflowNetwork_MultiZoneSurfaceFields::IndoorandOutdoorEnthalpyDifferenceLowerLimitForMaximumVentingOpenFactor);
  }

  double AirflowNetworkMultiZoneSurface_Impl::indoorandOutdoorEnthalpyDifferenceUpperLimitforMinimumVentingOpenFactor() const {
    boost::optional<double> value = getDouble(OS_AirflowNetwork_MultiZoneSurfaceFields::IndoorandOutdoorEnthalpyDifferenceUpperLimitforMinimumVentingOpenFactor,true);
    OS_ASSERT(value);
    return value.get();
  }

  bool AirflowNetworkMultiZoneSurface_Impl::isIndoorandOutdoorEnthalpyDifferenceUpperLimitforMinimumVentingOpenFactorDefaulted() const {
    return isEmpty(OS_AirflowNetwork_MultiZoneSurfaceFields::IndoorandOutdoorEnthalpyDifferenceUpperLimitforMinimumVentingOpenFactor);
  }

  boost::optional<Schedule> AirflowNetworkMultiZoneSurface_Impl::ventingAvailabilitySchedule() const {
    return getObject<ModelObject>().getModelObjectTarget<Schedule>(OS_AirflowNetwork_MultiZoneSurfaceFields::VentingAvailabilityScheduleName);
  }

  boost::optional<AirflowNetworkOccupantVentilationControl> AirflowNetworkMultiZoneSurface_Impl::occupantVentilationControl() const {
    return getObject<ModelObject>().getModelObjectTarget<AirflowNetworkOccupantVentilationControl>(OS_AirflowNetwork_MultiZoneSurfaceFields::OccupantVentilationControlName);
  }

  bool AirflowNetworkMultiZoneSurface_Impl::setSurface(const SurfAndSubSurf& surfAndSubSurf) {
    bool result = setPointer(OS_AirflowNetwork_MultiZoneSurfaceFields::SurfaceName, surfAndSubSurf.handle());
    return result;
  }

  bool AirflowNetworkMultiZoneSurface_Impl::setLeakageComponent(const SurfaceAirflowLeakage& surfaceAirflowLeakage) {
    bool result = setPointer(OS_AirflowNetwork_MultiZoneSurfaceFields::LeakageComponentName, surfaceAirflowLeakage.handle());
    return result;
  }

  bool AirflowNetworkMultiZoneSurface_Impl::setExternalNode(const boost::optional<ExternalNode>& externalNode) {
    bool result(false);
    if (externalNode) {
      result = setPointer(OS_AirflowNetwork_MultiZoneSurfaceFields::ExternalNodeName, externalNode.get().handle());
    }
    else {
      resetExternalNode();
      result = true;
    }
    return result;
  }

  void AirflowNetworkMultiZoneSurface_Impl::resetExternalNode() {
    bool result = setString(OS_AirflowNetwork_MultiZoneSurfaceFields::ExternalNodeName, "");
    OS_ASSERT(result);
  }

  bool AirflowNetworkMultiZoneSurface_Impl::setWindowDoorOpeningFactorOrCrackFactor(double windowDoorOpeningFactorOrCrackFactor) {
    bool result = setDouble(OS_AirflowNetwork_MultiZoneSurfaceFields::Window_DoorOpeningFactor_orCrackFactor, windowDoorOpeningFactorOrCrackFactor);
    return result;
  }

  void AirflowNetworkMultiZoneSurface_Impl::resetWindowDoorOpeningFactorOrCrackFactor() {
    bool result = setString(OS_AirflowNetwork_MultiZoneSurfaceFields::Window_DoorOpeningFactor_orCrackFactor, "");
    OS_ASSERT(result);
  }

  bool AirflowNetworkMultiZoneSurface_Impl::setVentilationControlMode(std::string ventilationControlMode) {
    bool result = setString(OS_AirflowNetwork_MultiZoneSurfaceFields::VentilationControlMode, ventilationControlMode);
    return result;
  }

  void AirflowNetworkMultiZoneSurface_Impl::resetVentilationControlMode() {
    bool result = setString(OS_AirflowNetwork_MultiZoneSurfaceFields::VentilationControlMode, "");
    OS_ASSERT(result);
  }

  bool AirflowNetworkMultiZoneSurface_Impl::setVentilationControlZoneTemperatureSetpointSchedule(Schedule& schedule) {
    bool result = setSchedule(OS_AirflowNetwork_MultiZoneSurfaceFields::VentilationControlZoneTemperatureSetpointScheduleName,
                              "AirflowNetworkMultiZoneSurface",
                              "Ventilation Control Zone Temperature Setpoint",
                              schedule);
    return result;
  }

  void AirflowNetworkMultiZoneSurface_Impl::resetVentilationControlZoneTemperatureSetpointSchedule() {
    bool result = setString(OS_AirflowNetwork_MultiZoneSurfaceFields::VentilationControlZoneTemperatureSetpointScheduleName, "");
    OS_ASSERT(result);
  }

  bool AirflowNetworkMultiZoneSurface_Impl::setMinimumVentingOpenFactor(double minimumVentingOpenFactor) {
    bool result = setDouble(OS_AirflowNetwork_MultiZoneSurfaceFields::MinimumVentingOpenFactor, minimumVentingOpenFactor);
    return result;
  }

  void AirflowNetworkMultiZoneSurface_Impl::resetMinimumVentingOpenFactor() {
    bool result = setString(OS_AirflowNetwork_MultiZoneSurfaceFields::MinimumVentingOpenFactor, "");
    OS_ASSERT(result);
  }

  bool AirflowNetworkMultiZoneSurface_Impl::setIndoorandOutdoorTemperatureDifferenceLowerLimitForMaximumVentingOpenFactor(double indoorandOutdoorTemperatureDifferenceLowerLimitForMaximumVentingOpenFactor) {
    bool result = setDouble(OS_AirflowNetwork_MultiZoneSurfaceFields::IndoorandOutdoorTemperatureDifferenceLowerLimitForMaximumVentingOpenFactor, indoorandOutdoorTemperatureDifferenceLowerLimitForMaximumVentingOpenFactor);
    return result;
  }

  void AirflowNetworkMultiZoneSurface_Impl::resetIndoorandOutdoorTemperatureDifferenceLowerLimitForMaximumVentingOpenFactor() {
    bool result = setString(OS_AirflowNetwork_MultiZoneSurfaceFields::IndoorandOutdoorTemperatureDifferenceLowerLimitForMaximumVentingOpenFactor, "");
    OS_ASSERT(result);
  }

  bool AirflowNetworkMultiZoneSurface_Impl::setIndoorandOutdoorTemperatureDifferenceUpperLimitforMinimumVentingOpenFactor(double indoorandOutdoorTemperatureDifferenceUpperLimitforMinimumVentingOpenFactor) {
    bool result = setDouble(OS_AirflowNetwork_MultiZoneSurfaceFields::IndoorandOutdoorTemperatureDifferenceUpperLimitforMinimumVentingOpenFactor, indoorandOutdoorTemperatureDifferenceUpperLimitforMinimumVentingOpenFactor);
    return result;
  }

  void AirflowNetworkMultiZoneSurface_Impl::resetIndoorandOutdoorTemperatureDifferenceUpperLimitforMinimumVentingOpenFactor() {
    bool result = setString(OS_AirflowNetwork_MultiZoneSurfaceFields::IndoorandOutdoorTemperatureDifferenceUpperLimitforMinimumVentingOpenFactor, "");
    OS_ASSERT(result);
  }

  bool AirflowNetworkMultiZoneSurface_Impl::setIndoorandOutdoorEnthalpyDifferenceLowerLimitForMaximumVentingOpenFactor(double indoorandOutdoorEnthalpyDifferenceLowerLimitForMaximumVentingOpenFactor) {
    bool result = setDouble(OS_AirflowNetwork_MultiZoneSurfaceFields::IndoorandOutdoorEnthalpyDifferenceLowerLimitForMaximumVentingOpenFactor, indoorandOutdoorEnthalpyDifferenceLowerLimitForMaximumVentingOpenFactor);
    return result;
  }

  void AirflowNetworkMultiZoneSurface_Impl::resetIndoorandOutdoorEnthalpyDifferenceLowerLimitForMaximumVentingOpenFactor() {
    bool result = setString(OS_AirflowNetwork_MultiZoneSurfaceFields::IndoorandOutdoorEnthalpyDifferenceLowerLimitForMaximumVentingOpenFactor, "");
    OS_ASSERT(result);
  }

  bool AirflowNetworkMultiZoneSurface_Impl::setIndoorandOutdoorEnthalpyDifferenceUpperLimitforMinimumVentingOpenFactor(double indoorandOutdoorEnthalpyDifferenceUpperLimitforMinimumVentingOpenFactor) {
    bool result = setDouble(OS_AirflowNetwork_MultiZoneSurfaceFields::IndoorandOutdoorEnthalpyDifferenceUpperLimitforMinimumVentingOpenFactor, indoorandOutdoorEnthalpyDifferenceUpperLimitforMinimumVentingOpenFactor);
    return result;
  }

  void AirflowNetworkMultiZoneSurface_Impl::resetIndoorandOutdoorEnthalpyDifferenceUpperLimitforMinimumVentingOpenFactor() {
    bool result = setString(OS_AirflowNetwork_MultiZoneSurfaceFields::IndoorandOutdoorEnthalpyDifferenceUpperLimitforMinimumVentingOpenFactor, "");
    OS_ASSERT(result);
  }

  bool AirflowNetworkMultiZoneSurface_Impl::setVentingAvailabilitySchedule(Schedule& schedule) {
    bool result = setSchedule(OS_AirflowNetwork_MultiZoneSurfaceFields::VentingAvailabilityScheduleName,
                              "AirflowNetworkMultiZoneSurface",
                              "Venting Availability",
                              schedule);
    return result;
  }

  void AirflowNetworkMultiZoneSurface_Impl::resetVentingAvailabilitySchedule() {
    bool result = setString(OS_AirflowNetwork_MultiZoneSurfaceFields::VentingAvailabilityScheduleName, "");
    OS_ASSERT(result);
  }

  bool AirflowNetworkMultiZoneSurface_Impl::setOccupantVentilationControl(const boost::optional<AirflowNetworkOccupantVentilationControl>& airflowNetworkOccupantVentilationControl) {
    bool result(false);
    if (airflowNetworkOccupantVentilationControl) {
      result = setPointer(OS_AirflowNetwork_MultiZoneSurfaceFields::OccupantVentilationControlName, airflowNetworkOccupantVentilationControl.get().handle());
    }
    else {
      resetOccupantVentilationControl();
      result = true;
    }
    return result;
  }

  void AirflowNetworkMultiZoneSurface_Impl::resetOccupantVentilationControl() {
    bool result = setString(OS_AirflowNetwork_MultiZoneSurfaceFields::OccupantVentilationControlName, "");
    OS_ASSERT(result);
  }

  boost::optional<SurfAndSubSurf> AirflowNetworkMultiZoneSurface_Impl::optionalSurface() const {
    return getObject<ModelObject>().getModelObjectTarget<SurfAndSubSurf>(OS_AirflowNetwork_MultiZoneSurfaceFields::SurfaceName);
  }

  boost::optional<SurfaceAirflowLeakage> AirflowNetworkMultiZoneSurface_Impl::optionalLeakageComponent() const {
    return getObject<ModelObject>().getModelObjectTarget<SurfaceAirflowLeakage>(OS_AirflowNetwork_MultiZoneSurfaceFields::LeakageComponentName);
  }

} // detail

AirflowNetworkMultiZoneSurface::AirflowNetworkMultiZoneSurface(const Model& model)
  : ModelObject(AirflowNetworkMultiZoneSurface::iddObjectType(),model)
{
  OS_ASSERT(getImpl<detail::AirflowNetworkMultiZoneSurface_Impl>());

  // TODO: Appropriately handle the following required object-list fields.
  //     OS_AirflowNetwork_MultiZoneSurfaceFields::SurfaceName
  //     OS_AirflowNetwork_MultiZoneSurfaceFields::LeakageComponentName
  bool ok = true;
  // ok = setHandle();
  OS_ASSERT(ok);
  // ok = setSurface();
  OS_ASSERT(ok);
  // ok = setLeakageComponent();
  OS_ASSERT(ok);
}

IddObjectType AirflowNetworkMultiZoneSurface::iddObjectType() {
  return IddObjectType(IddObjectType::OS_AirflowNetwork_MultiZoneSurface);
}

std::vector<std::string> AirflowNetworkMultiZoneSurface::ventilationControlModeValues() {
  return getIddKeyNames(IddFactory::instance().getObject(iddObjectType()).get(),
                        OS_AirflowNetwork_MultiZoneSurfaceFields::VentilationControlMode);
}

SurfAndSubSurf AirflowNetworkMultiZoneSurface::surface() const {
  return getImpl<detail::AirflowNetworkMultiZoneSurface_Impl>()->surface();
}

SurfaceAirflowLeakage AirflowNetworkMultiZoneSurface::leakageComponent() const {
  return getImpl<detail::AirflowNetworkMultiZoneSurface_Impl>()->leakageComponent();
}

boost::optional<ExternalNode> AirflowNetworkMultiZoneSurface::externalNode() const {
  return getImpl<detail::AirflowNetworkMultiZoneSurface_Impl>()->externalNode();
}

double AirflowNetworkMultiZoneSurface::windowDoorOpeningFactorOrCrackFactor() const {
  return getImpl<detail::AirflowNetworkMultiZoneSurface_Impl>()->windowDoorOpeningFactorOrCrackFactor();
}

bool AirflowNetworkMultiZoneSurface::isWindowDoorOpeningFactorOrCrackFactorDefaulted() const {
  return getImpl<detail::AirflowNetworkMultiZoneSurface_Impl>()->isWindowDoorOpeningFactorOrCrackFactorDefaulted();
}

std::string AirflowNetworkMultiZoneSurface::ventilationControlMode() const {
  return getImpl<detail::AirflowNetworkMultiZoneSurface_Impl>()->ventilationControlMode();
}

bool AirflowNetworkMultiZoneSurface::isVentilationControlModeDefaulted() const {
  return getImpl<detail::AirflowNetworkMultiZoneSurface_Impl>()->isVentilationControlModeDefaulted();
}

boost::optional<Schedule> AirflowNetworkMultiZoneSurface::ventilationControlZoneTemperatureSetpointSchedule() const {
  return getImpl<detail::AirflowNetworkMultiZoneSurface_Impl>()->ventilationControlZoneTemperatureSetpointSchedule();
}

double AirflowNetworkMultiZoneSurface::minimumVentingOpenFactor() const {
  return getImpl<detail::AirflowNetworkMultiZoneSurface_Impl>()->minimumVentingOpenFactor();
}

bool AirflowNetworkMultiZoneSurface::isMinimumVentingOpenFactorDefaulted() const {
  return getImpl<detail::AirflowNetworkMultiZoneSurface_Impl>()->isMinimumVentingOpenFactorDefaulted();
}

double AirflowNetworkMultiZoneSurface::indoorandOutdoorTemperatureDifferenceLowerLimitForMaximumVentingOpenFactor() const {
  return getImpl<detail::AirflowNetworkMultiZoneSurface_Impl>()->indoorandOutdoorTemperatureDifferenceLowerLimitForMaximumVentingOpenFactor();
}

bool AirflowNetworkMultiZoneSurface::isIndoorandOutdoorTemperatureDifferenceLowerLimitForMaximumVentingOpenFactorDefaulted() const {
  return getImpl<detail::AirflowNetworkMultiZoneSurface_Impl>()->isIndoorandOutdoorTemperatureDifferenceLowerLimitForMaximumVentingOpenFactorDefaulted();
}

double AirflowNetworkMultiZoneSurface::indoorandOutdoorTemperatureDifferenceUpperLimitforMinimumVentingOpenFactor() const {
  return getImpl<detail::AirflowNetworkMultiZoneSurface_Impl>()->indoorandOutdoorTemperatureDifferenceUpperLimitforMinimumVentingOpenFactor();
}

bool AirflowNetworkMultiZoneSurface::isIndoorandOutdoorTemperatureDifferenceUpperLimitforMinimumVentingOpenFactorDefaulted() const {
  return getImpl<detail::AirflowNetworkMultiZoneSurface_Impl>()->isIndoorandOutdoorTemperatureDifferenceUpperLimitforMinimumVentingOpenFactorDefaulted();
}

double AirflowNetworkMultiZoneSurface::indoorandOutdoorEnthalpyDifferenceLowerLimitForMaximumVentingOpenFactor() const {
  return getImpl<detail::AirflowNetworkMultiZoneSurface_Impl>()->indoorandOutdoorEnthalpyDifferenceLowerLimitForMaximumVentingOpenFactor();
}

bool AirflowNetworkMultiZoneSurface::isIndoorandOutdoorEnthalpyDifferenceLowerLimitForMaximumVentingOpenFactorDefaulted() const {
  return getImpl<detail::AirflowNetworkMultiZoneSurface_Impl>()->isIndoorandOutdoorEnthalpyDifferenceLowerLimitForMaximumVentingOpenFactorDefaulted();
}

double AirflowNetworkMultiZoneSurface::indoorandOutdoorEnthalpyDifferenceUpperLimitforMinimumVentingOpenFactor() const {
  return getImpl<detail::AirflowNetworkMultiZoneSurface_Impl>()->indoorandOutdoorEnthalpyDifferenceUpperLimitforMinimumVentingOpenFactor();
}

bool AirflowNetworkMultiZoneSurface::isIndoorandOutdoorEnthalpyDifferenceUpperLimitforMinimumVentingOpenFactorDefaulted() const {
  return getImpl<detail::AirflowNetworkMultiZoneSurface_Impl>()->isIndoorandOutdoorEnthalpyDifferenceUpperLimitforMinimumVentingOpenFactorDefaulted();
}

boost::optional<Schedule> AirflowNetworkMultiZoneSurface::ventingAvailabilitySchedule() const {
  return getImpl<detail::AirflowNetworkMultiZoneSurface_Impl>()->ventingAvailabilitySchedule();
}

boost::optional<AirflowNetworkOccupantVentilationControl> AirflowNetworkMultiZoneSurface::occupantVentilationControl() const {
  return getImpl<detail::AirflowNetworkMultiZoneSurface_Impl>()->occupantVentilationControl();
}

bool AirflowNetworkMultiZoneSurface::setSurface(const SurfAndSubSurf& surfAndSubSurf) {
  return getImpl<detail::AirflowNetworkMultiZoneSurface_Impl>()->setSurface(surfAndSubSurf);
}

bool AirflowNetworkMultiZoneSurface::setLeakageComponent(const SurfaceAirflowLeakage& surfaceAirflowLeakage) {
  return getImpl<detail::AirflowNetworkMultiZoneSurface_Impl>()->setLeakageComponent(surfaceAirflowLeakage);
}

bool AirflowNetworkMultiZoneSurface::setExternalNode(const ExternalNode& externalNode) {
  return getImpl<detail::AirflowNetworkMultiZoneSurface_Impl>()->setExternalNode(externalNode);
}

void AirflowNetworkMultiZoneSurface::resetExternalNode() {
  getImpl<detail::AirflowNetworkMultiZoneSurface_Impl>()->resetExternalNode();
}

bool AirflowNetworkMultiZoneSurface::setWindowDoorOpeningFactorOrCrackFactor(double windowDoorOpeningFactorOrCrackFactor) {
  return getImpl<detail::AirflowNetworkMultiZoneSurface_Impl>()->setWindowDoorOpeningFactorOrCrackFactor(windowDoorOpeningFactorOrCrackFactor);
}

void AirflowNetworkMultiZoneSurface::resetWindowDoorOpeningFactorOrCrackFactor() {
  getImpl<detail::AirflowNetworkMultiZoneSurface_Impl>()->resetWindowDoorOpeningFactorOrCrackFactor();
}

bool AirflowNetworkMultiZoneSurface::setVentilationControlMode(std::string ventilationControlMode) {
  return getImpl<detail::AirflowNetworkMultiZoneSurface_Impl>()->setVentilationControlMode(ventilationControlMode);
}

void AirflowNetworkMultiZoneSurface::resetVentilationControlMode() {
  getImpl<detail::AirflowNetworkMultiZoneSurface_Impl>()->resetVentilationControlMode();
}

bool AirflowNetworkMultiZoneSurface::setVentilationControlZoneTemperatureSetpointSchedule(Schedule& schedule) {
  return getImpl<detail::AirflowNetworkMultiZoneSurface_Impl>()->setVentilationControlZoneTemperatureSetpointSchedule(schedule);
}

void AirflowNetworkMultiZoneSurface::resetVentilationControlZoneTemperatureSetpointSchedule() {
  getImpl<detail::AirflowNetworkMultiZoneSurface_Impl>()->resetVentilationControlZoneTemperatureSetpointSchedule();
}

bool AirflowNetworkMultiZoneSurface::setMinimumVentingOpenFactor(double minimumVentingOpenFactor) {
  return getImpl<detail::AirflowNetworkMultiZoneSurface_Impl>()->setMinimumVentingOpenFactor(minimumVentingOpenFactor);
}

void AirflowNetworkMultiZoneSurface::resetMinimumVentingOpenFactor() {
  getImpl<detail::AirflowNetworkMultiZoneSurface_Impl>()->resetMinimumVentingOpenFactor();
}

bool AirflowNetworkMultiZoneSurface::setIndoorandOutdoorTemperatureDifferenceLowerLimitForMaximumVentingOpenFactor(double indoorandOutdoorTemperatureDifferenceLowerLimitForMaximumVentingOpenFactor) {
  return getImpl<detail::AirflowNetworkMultiZoneSurface_Impl>()->setIndoorandOutdoorTemperatureDifferenceLowerLimitForMaximumVentingOpenFactor(indoorandOutdoorTemperatureDifferenceLowerLimitForMaximumVentingOpenFactor);
}

void AirflowNetworkMultiZoneSurface::resetIndoorandOutdoorTemperatureDifferenceLowerLimitForMaximumVentingOpenFactor() {
  getImpl<detail::AirflowNetworkMultiZoneSurface_Impl>()->resetIndoorandOutdoorTemperatureDifferenceLowerLimitForMaximumVentingOpenFactor();
}

bool AirflowNetworkMultiZoneSurface::setIndoorandOutdoorTemperatureDifferenceUpperLimitforMinimumVentingOpenFactor(double indoorandOutdoorTemperatureDifferenceUpperLimitforMinimumVentingOpenFactor) {
  return getImpl<detail::AirflowNetworkMultiZoneSurface_Impl>()->setIndoorandOutdoorTemperatureDifferenceUpperLimitforMinimumVentingOpenFactor(indoorandOutdoorTemperatureDifferenceUpperLimitforMinimumVentingOpenFactor);
}

void AirflowNetworkMultiZoneSurface::resetIndoorandOutdoorTemperatureDifferenceUpperLimitforMinimumVentingOpenFactor() {
  getImpl<detail::AirflowNetworkMultiZoneSurface_Impl>()->resetIndoorandOutdoorTemperatureDifferenceUpperLimitforMinimumVentingOpenFactor();
}

bool AirflowNetworkMultiZoneSurface::setIndoorandOutdoorEnthalpyDifferenceLowerLimitForMaximumVentingOpenFactor(double indoorandOutdoorEnthalpyDifferenceLowerLimitForMaximumVentingOpenFactor) {
  return getImpl<detail::AirflowNetworkMultiZoneSurface_Impl>()->setIndoorandOutdoorEnthalpyDifferenceLowerLimitForMaximumVentingOpenFactor(indoorandOutdoorEnthalpyDifferenceLowerLimitForMaximumVentingOpenFactor);
}

void AirflowNetworkMultiZoneSurface::resetIndoorandOutdoorEnthalpyDifferenceLowerLimitForMaximumVentingOpenFactor() {
  getImpl<detail::AirflowNetworkMultiZoneSurface_Impl>()->resetIndoorandOutdoorEnthalpyDifferenceLowerLimitForMaximumVentingOpenFactor();
}

bool AirflowNetworkMultiZoneSurface::setIndoorandOutdoorEnthalpyDifferenceUpperLimitforMinimumVentingOpenFactor(double indoorandOutdoorEnthalpyDifferenceUpperLimitforMinimumVentingOpenFactor) {
  return getImpl<detail::AirflowNetworkMultiZoneSurface_Impl>()->setIndoorandOutdoorEnthalpyDifferenceUpperLimitforMinimumVentingOpenFactor(indoorandOutdoorEnthalpyDifferenceUpperLimitforMinimumVentingOpenFactor);
}

void AirflowNetworkMultiZoneSurface::resetIndoorandOutdoorEnthalpyDifferenceUpperLimitforMinimumVentingOpenFactor() {
  getImpl<detail::AirflowNetworkMultiZoneSurface_Impl>()->resetIndoorandOutdoorEnthalpyDifferenceUpperLimitforMinimumVentingOpenFactor();
}

bool AirflowNetworkMultiZoneSurface::setVentingAvailabilitySchedule(Schedule& schedule) {
  return getImpl<detail::AirflowNetworkMultiZoneSurface_Impl>()->setVentingAvailabilitySchedule(schedule);
}

void AirflowNetworkMultiZoneSurface::resetVentingAvailabilitySchedule() {
  getImpl<detail::AirflowNetworkMultiZoneSurface_Impl>()->resetVentingAvailabilitySchedule();
}

bool AirflowNetworkMultiZoneSurface::setOccupantVentilationControl(const AirflowNetworkOccupantVentilationControl& airflowNetworkOccupantVentilationControl) {
  return getImpl<detail::AirflowNetworkMultiZoneSurface_Impl>()->setOccupantVentilationControl(airflowNetworkOccupantVentilationControl);
}

void AirflowNetworkMultiZoneSurface::resetOccupantVentilationControl() {
  getImpl<detail::AirflowNetworkMultiZoneSurface_Impl>()->resetOccupantVentilationControl();
}

/// @cond
AirflowNetworkMultiZoneSurface::AirflowNetworkMultiZoneSurface(std::shared_ptr<detail::AirflowNetworkMultiZoneSurface_Impl> impl)
  : ModelObject(impl)
{}
/// @endcond

} // model
} // openstudio

