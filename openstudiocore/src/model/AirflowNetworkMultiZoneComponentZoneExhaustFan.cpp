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

#include "AirflowNetworkMultiZoneComponentZoneExhaustFan.hpp"
#include "AirflowNetworkMultiZoneComponentZoneExhaustFan_Impl.hpp"

// TODO: Check the following class names against object getters and setters.
#include "FanZoneExhaust.hpp"
#include "FanZoneExhaust_Impl.hpp"
#include "AirflowNetworkMultiZoneReferenceCrackConditions.hpp"
#include "AirflowNetworkMultiZoneReferenceCrackConditions_Impl.hpp"

#include <utilities/idd/IddEnums.hxx>
#include <utilities/idd/OS_AirflowNetwork_MultiZoneComponentZoneExhaustFan_FieldEnums.hxx>

#include "../utilities/units/Unit.hpp"

#include "../utilities/core/Assert.hpp"

namespace openstudio {
namespace model {

namespace detail {

  AirflowNetworkMultiZoneComponentZoneExhaustFan_Impl::AirflowNetworkMultiZoneComponentZoneExhaustFan_Impl(const IdfObject& idfObject,
                                                                                                           Model_Impl* model,
                                                                                                           bool keepHandle)
    : ModelObject_Impl(idfObject,model,keepHandle)
  {
    OS_ASSERT(idfObject.iddObject().type() == AirflowNetworkMultiZoneComponentZoneExhaustFan::iddObjectType());
  }

  AirflowNetworkMultiZoneComponentZoneExhaustFan_Impl::AirflowNetworkMultiZoneComponentZoneExhaustFan_Impl(const openstudio::detail::WorkspaceObject_Impl& other,
                                                                                                           Model_Impl* model,
                                                                                                           bool keepHandle)
    : ModelObject_Impl(other,model,keepHandle)
  {
    OS_ASSERT(other.iddObject().type() == AirflowNetworkMultiZoneComponentZoneExhaustFan::iddObjectType());
  }

  AirflowNetworkMultiZoneComponentZoneExhaustFan_Impl::AirflowNetworkMultiZoneComponentZoneExhaustFan_Impl(const AirflowNetworkMultiZoneComponentZoneExhaustFan_Impl& other,
                                                                                                           Model_Impl* model,
                                                                                                           bool keepHandle)
    : ModelObject_Impl(other,model,keepHandle)
  {}

  const std::vector<std::string>& AirflowNetworkMultiZoneComponentZoneExhaustFan_Impl::outputVariableNames() const
  {
    static std::vector<std::string> result;
    if (result.empty()){
    }
    return result;
  }

  IddObjectType AirflowNetworkMultiZoneComponentZoneExhaustFan_Impl::iddObjectType() const {
    return AirflowNetworkMultiZoneComponentZoneExhaustFan::iddObjectType();
  }

  FanZoneExhaust AirflowNetworkMultiZoneComponentZoneExhaustFan_Impl::fanZoneExhaust() const {
    boost::optional<FanZoneExhaust> value = getObject<ModelObject>().getModelObjectTarget<FanZoneExhaust>(OS_AirflowNetwork_MultiZoneComponentZoneExhaustFanFields::Name);
    if (!value) {
      LOG_AND_THROW(briefDescription() << " does not have a FanZoneExhaust attached.");
    }
    return value.get();
  }

  double AirflowNetworkMultiZoneComponentZoneExhaustFan_Impl::airMassFlowCoefficientWhentheZoneExhaustFanisOffatReferenceConditions() const {
    boost::optional<double> value = getDouble(OS_AirflowNetwork_MultiZoneComponentZoneExhaustFanFields::AirMassFlowCoefficientWhentheZoneExhaustFanisOffatReferenceConditions,true);
    OS_ASSERT(value);
    return value.get();
  }

  double AirflowNetworkMultiZoneComponentZoneExhaustFan_Impl::airMassFlowExponentWhentheZoneExhaustFanisOff() const {
    boost::optional<double> value = getDouble(OS_AirflowNetwork_MultiZoneComponentZoneExhaustFanFields::AirMassFlowExponentWhentheZoneExhaustFanisOff,true);
    OS_ASSERT(value);
    return value.get();
  }

  bool AirflowNetworkMultiZoneComponentZoneExhaustFan_Impl::isAirMassFlowExponentWhentheZoneExhaustFanisOffDefaulted() const {
    return isEmpty(OS_AirflowNetwork_MultiZoneComponentZoneExhaustFanFields::AirMassFlowExponentWhentheZoneExhaustFanisOff);
  }

  boost::optional<AirflowNetworkMultiZoneReferenceCrackConditions> AirflowNetworkMultiZoneComponentZoneExhaustFan_Impl::referenceCrackConditions() const {
    return getObject<ModelObject>().getModelObjectTarget<AirflowNetworkMultiZoneReferenceCrackConditions>(OS_AirflowNetwork_MultiZoneComponentZoneExhaustFanFields::ReferenceCrackConditions);
  }

  bool AirflowNetworkMultiZoneComponentZoneExhaustFan_Impl::setFanZoneExhaust(const FanZoneExhaust& fanZoneExhaust) {
    bool result = setPointer(OS_AirflowNetwork_MultiZoneComponentZoneExhaustFanFields::Name, fanZoneExhaust.handle());
    return result;
  }

  bool AirflowNetworkMultiZoneComponentZoneExhaustFan_Impl::setAirMassFlowCoefficientWhentheZoneExhaustFanisOffatReferenceConditions(double airMassFlowCoefficientWhentheZoneExhaustFanisOffatReferenceConditions) {
    bool result = setDouble(OS_AirflowNetwork_MultiZoneComponentZoneExhaustFanFields::AirMassFlowCoefficientWhentheZoneExhaustFanisOffatReferenceConditions, airMassFlowCoefficientWhentheZoneExhaustFanisOffatReferenceConditions);
    return result;
  }

  bool AirflowNetworkMultiZoneComponentZoneExhaustFan_Impl::setAirMassFlowExponentWhentheZoneExhaustFanisOff(double airMassFlowExponentWhentheZoneExhaustFanisOff) {
    bool result = setDouble(OS_AirflowNetwork_MultiZoneComponentZoneExhaustFanFields::AirMassFlowExponentWhentheZoneExhaustFanisOff, airMassFlowExponentWhentheZoneExhaustFanisOff);
    return result;
  }

  void AirflowNetworkMultiZoneComponentZoneExhaustFan_Impl::resetAirMassFlowExponentWhentheZoneExhaustFanisOff() {
    bool result = setString(OS_AirflowNetwork_MultiZoneComponentZoneExhaustFanFields::AirMassFlowExponentWhentheZoneExhaustFanisOff, "");
    OS_ASSERT(result);
  }

  bool AirflowNetworkMultiZoneComponentZoneExhaustFan_Impl::setReferenceCrackConditions(const AirflowNetworkMultiZoneReferenceCrackConditions& referenceCrackConditions) {
    bool result = setPointer(OS_AirflowNetwork_MultiZoneComponentZoneExhaustFanFields::ReferenceCrackConditions, referenceCrackConditions.handle());
    return result;
  }

  void AirflowNetworkMultiZoneComponentZoneExhaustFan_Impl::resetReferenceCrackConditions() {
    bool result = setString(OS_AirflowNetwork_MultiZoneComponentZoneExhaustFanFields::ReferenceCrackConditions, "");
    OS_ASSERT(result);
  }

} // detail

AirflowNetworkMultiZoneComponentZoneExhaustFan::AirflowNetworkMultiZoneComponentZoneExhaustFan(const Model& model,
  const FanZoneExhaust &fanZoneExhaust)
  : ModelObject(AirflowNetworkMultiZoneComponentZoneExhaustFan::iddObjectType(),model)
{
  OS_ASSERT(getImpl<detail::AirflowNetworkMultiZoneComponentZoneExhaustFan_Impl>());
  bool ok = getImpl<detail::AirflowNetworkMultiZoneComponentZoneExhaustFan_Impl>()->setFanZoneExhaust(fanZoneExhaust);
  OS_ASSERT(ok);
}

IddObjectType AirflowNetworkMultiZoneComponentZoneExhaustFan::iddObjectType() {
  return IddObjectType(IddObjectType::OS_AirflowNetwork_MultiZoneComponentZoneExhaustFan);
}

FanZoneExhaust AirflowNetworkMultiZoneComponentZoneExhaustFan::fanZoneExhaust() const {
  return getImpl<detail::AirflowNetworkMultiZoneComponentZoneExhaustFan_Impl>()->fanZoneExhaust();
}

double AirflowNetworkMultiZoneComponentZoneExhaustFan::airMassFlowCoefficientWhentheZoneExhaustFanisOffatReferenceConditions() const {
  return getImpl<detail::AirflowNetworkMultiZoneComponentZoneExhaustFan_Impl>()->airMassFlowCoefficientWhentheZoneExhaustFanisOffatReferenceConditions();
}

double AirflowNetworkMultiZoneComponentZoneExhaustFan::airMassFlowExponentWhentheZoneExhaustFanisOff() const {
  return getImpl<detail::AirflowNetworkMultiZoneComponentZoneExhaustFan_Impl>()->airMassFlowExponentWhentheZoneExhaustFanisOff();
}

bool AirflowNetworkMultiZoneComponentZoneExhaustFan::isAirMassFlowExponentWhentheZoneExhaustFanisOffDefaulted() const {
  return getImpl<detail::AirflowNetworkMultiZoneComponentZoneExhaustFan_Impl>()->isAirMassFlowExponentWhentheZoneExhaustFanisOffDefaulted();
}

boost::optional<AirflowNetworkMultiZoneReferenceCrackConditions> AirflowNetworkMultiZoneComponentZoneExhaustFan::referenceCrackConditions() const {
  return getImpl<detail::AirflowNetworkMultiZoneComponentZoneExhaustFan_Impl>()->referenceCrackConditions();
}

bool AirflowNetworkMultiZoneComponentZoneExhaustFan::setFanZoneExhaust(const FanZoneExhaust& fanZoneExhaust) {
  return getImpl<detail::AirflowNetworkMultiZoneComponentZoneExhaustFan_Impl>()->setFanZoneExhaust(fanZoneExhaust);
}

bool AirflowNetworkMultiZoneComponentZoneExhaustFan::setAirMassFlowCoefficientWhentheZoneExhaustFanisOffatReferenceConditions(double airMassFlowCoefficientWhentheZoneExhaustFanisOffatReferenceConditions) {
  return getImpl<detail::AirflowNetworkMultiZoneComponentZoneExhaustFan_Impl>()->setAirMassFlowCoefficientWhentheZoneExhaustFanisOffatReferenceConditions(airMassFlowCoefficientWhentheZoneExhaustFanisOffatReferenceConditions);
}

bool AirflowNetworkMultiZoneComponentZoneExhaustFan::setAirMassFlowExponentWhentheZoneExhaustFanisOff(double airMassFlowExponentWhentheZoneExhaustFanisOff) {
  return getImpl<detail::AirflowNetworkMultiZoneComponentZoneExhaustFan_Impl>()->setAirMassFlowExponentWhentheZoneExhaustFanisOff(airMassFlowExponentWhentheZoneExhaustFanisOff);
}

void AirflowNetworkMultiZoneComponentZoneExhaustFan::resetAirMassFlowExponentWhentheZoneExhaustFanisOff() {
  getImpl<detail::AirflowNetworkMultiZoneComponentZoneExhaustFan_Impl>()->resetAirMassFlowExponentWhentheZoneExhaustFanisOff();
}

bool AirflowNetworkMultiZoneComponentZoneExhaustFan::setReferenceCrackConditions(const AirflowNetworkMultiZoneReferenceCrackConditions& referenceCrackConditions) {
  return getImpl<detail::AirflowNetworkMultiZoneComponentZoneExhaustFan_Impl>()->setReferenceCrackConditions(referenceCrackConditions);
}

void AirflowNetworkMultiZoneComponentZoneExhaustFan::resetReferenceCrackConditions() {
  getImpl<detail::AirflowNetworkMultiZoneComponentZoneExhaustFan_Impl>()->resetReferenceCrackConditions();
}

/// @cond
AirflowNetworkMultiZoneComponentZoneExhaustFan::AirflowNetworkMultiZoneComponentZoneExhaustFan(std::shared_ptr<detail::AirflowNetworkMultiZoneComponentZoneExhaustFan_Impl> impl)
  : ModelObject(impl)
{}
/// @endcond

} // model
} // openstudio

