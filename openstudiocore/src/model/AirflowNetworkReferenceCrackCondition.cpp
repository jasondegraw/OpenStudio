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

#include <model/AirflowNetworkReferenceCrackCondition.hpp>
#include <model/AirflowNetworkReferenceCrackCondition_Impl.hpp>

#include <utilities/idd/OS_AirflowNetworkReferenceCrackConditions_FieldEnums.hxx>

#include <utilities/units/Unit.hpp>

#include <utilities/core/Assert.hpp>

namespace openstudio {
namespace model {

namespace detail {

  AirflowNetworkReferenceCrackCondition_Impl::AirflowNetworkReferenceCrackCondition_Impl(const IdfObject& idfObject,
                                                                                         Model_Impl* model,
                                                                                         bool keepHandle)
    : ModelObject_Impl(idfObject,model,keepHandle)
  {
    OS_ASSERT(idfObject.iddObject().type() == AirflowNetworkReferenceCrackCondition::iddObjectType());
  }

  AirflowNetworkReferenceCrackCondition_Impl::AirflowNetworkReferenceCrackCondition_Impl(const openstudio::detail::WorkspaceObject_Impl& other,
                                                                                         Model_Impl* model,
                                                                                         bool keepHandle)
    : ModelObject_Impl(other,model,keepHandle)
  {
    OS_ASSERT(other.iddObject().type() == AirflowNetworkReferenceCrackCondition::iddObjectType());
  }

  AirflowNetworkReferenceCrackCondition_Impl::AirflowNetworkReferenceCrackCondition_Impl(const AirflowNetworkReferenceCrackCondition_Impl& other,
                                                                                         Model_Impl* model,
                                                                                         bool keepHandle)
    : ModelObject_Impl(other,model,keepHandle)
  {}

  const std::vector<std::string>& AirflowNetworkReferenceCrackCondition_Impl::outputVariableNames() const
  {
    static std::vector<std::string> result;
    if (result.empty()){
    }
    return result;
  }

  IddObjectType AirflowNetworkReferenceCrackCondition_Impl::iddObjectType() const {
    return AirflowNetworkReferenceCrackCondition::iddObjectType();
  }

  double AirflowNetworkReferenceCrackCondition_Impl::referenceTemperature() const {
    boost::optional<double> value = getDouble(OS_AirflowNetworkReferenceCrackConditionsFields::ReferenceTemperature,true);
    OS_ASSERT(value);
    return value.get();
  }

  bool AirflowNetworkReferenceCrackCondition_Impl::isReferenceTemperatureDefaulted() const {
    return isEmpty(OS_AirflowNetworkReferenceCrackConditionsFields::ReferenceTemperature);
  }

  double AirflowNetworkReferenceCrackCondition_Impl::referenceBarometricPressure() const {
    boost::optional<double> value = getDouble(OS_AirflowNetworkReferenceCrackConditionsFields::ReferenceBarometricPressure,true);
    OS_ASSERT(value);
    return value.get();
  }

  bool AirflowNetworkReferenceCrackCondition_Impl::isReferenceBarometricPressureDefaulted() const {
    return isEmpty(OS_AirflowNetworkReferenceCrackConditionsFields::ReferenceBarometricPressure);
  }

  double AirflowNetworkReferenceCrackCondition_Impl::referenceHumidityRatio() const {
    boost::optional<double> value = getDouble(OS_AirflowNetworkReferenceCrackConditionsFields::ReferenceHumidityRatio,true);
    OS_ASSERT(value);
    return value.get();
  }

  bool AirflowNetworkReferenceCrackCondition_Impl::isReferenceHumidityRatioDefaulted() const {
    return isEmpty(OS_AirflowNetworkReferenceCrackConditionsFields::ReferenceHumidityRatio);
  }

  void AirflowNetworkReferenceCrackCondition_Impl::setReferenceTemperature(double referenceTemperature) {
    bool result = setDouble(OS_AirflowNetworkReferenceCrackConditionsFields::ReferenceTemperature, referenceTemperature);
    OS_ASSERT(result);
  }

  void AirflowNetworkReferenceCrackCondition_Impl::resetReferenceTemperature() {
    bool result = setString(OS_AirflowNetworkReferenceCrackConditionsFields::ReferenceTemperature, "");
    OS_ASSERT(result);
  }

  bool AirflowNetworkReferenceCrackCondition_Impl::setReferenceBarometricPressure(double referenceBarometricPressure) {
    bool result = setDouble(OS_AirflowNetworkReferenceCrackConditionsFields::ReferenceBarometricPressure, referenceBarometricPressure);
    return result;
  }

  void AirflowNetworkReferenceCrackCondition_Impl::resetReferenceBarometricPressure() {
    bool result = setString(OS_AirflowNetworkReferenceCrackConditionsFields::ReferenceBarometricPressure, "");
    OS_ASSERT(result);
  }

  void AirflowNetworkReferenceCrackCondition_Impl::setReferenceHumidityRatio(double referenceHumidityRatio) {
    bool result = setDouble(OS_AirflowNetworkReferenceCrackConditionsFields::ReferenceHumidityRatio, referenceHumidityRatio);
    OS_ASSERT(result);
  }

  void AirflowNetworkReferenceCrackCondition_Impl::resetReferenceHumidityRatio() {
    bool result = setString(OS_AirflowNetworkReferenceCrackConditionsFields::ReferenceHumidityRatio, "");
    OS_ASSERT(result);
  }

} // detail

AirflowNetworkReferenceCrackCondition::AirflowNetworkReferenceCrackCondition(const Model& model)
  : ModelObject(AirflowNetworkReferenceCrackCondition::iddObjectType(),model)
{
  OS_ASSERT(getImpl<detail::AirflowNetworkReferenceCrackCondition_Impl>());

  // TODO: Appropriately handle the following required object-list fields.
  bool ok = true;
  // ok = setHandle();
  OS_ASSERT(ok);
}

IddObjectType AirflowNetworkReferenceCrackCondition::iddObjectType() {
  return IddObjectType(IddObjectType::OS_AirflowNetworkReferenceCrackConditions);
}

double AirflowNetworkReferenceCrackCondition::referenceTemperature() const {
  return getImpl<detail::AirflowNetworkReferenceCrackCondition_Impl>()->referenceTemperature();
}

bool AirflowNetworkReferenceCrackCondition::isReferenceTemperatureDefaulted() const {
  return getImpl<detail::AirflowNetworkReferenceCrackCondition_Impl>()->isReferenceTemperatureDefaulted();
}

double AirflowNetworkReferenceCrackCondition::referenceBarometricPressure() const {
  return getImpl<detail::AirflowNetworkReferenceCrackCondition_Impl>()->referenceBarometricPressure();
}

bool AirflowNetworkReferenceCrackCondition::isReferenceBarometricPressureDefaulted() const {
  return getImpl<detail::AirflowNetworkReferenceCrackCondition_Impl>()->isReferenceBarometricPressureDefaulted();
}

double AirflowNetworkReferenceCrackCondition::referenceHumidityRatio() const {
  return getImpl<detail::AirflowNetworkReferenceCrackCondition_Impl>()->referenceHumidityRatio();
}

bool AirflowNetworkReferenceCrackCondition::isReferenceHumidityRatioDefaulted() const {
  return getImpl<detail::AirflowNetworkReferenceCrackCondition_Impl>()->isReferenceHumidityRatioDefaulted();
}

void AirflowNetworkReferenceCrackCondition::setReferenceTemperature(double referenceTemperature) {
  getImpl<detail::AirflowNetworkReferenceCrackCondition_Impl>()->setReferenceTemperature(referenceTemperature);
}

void AirflowNetworkReferenceCrackCondition::resetReferenceTemperature() {
  getImpl<detail::AirflowNetworkReferenceCrackCondition_Impl>()->resetReferenceTemperature();
}

bool AirflowNetworkReferenceCrackCondition::setReferenceBarometricPressure(double referenceBarometricPressure) {
  return getImpl<detail::AirflowNetworkReferenceCrackCondition_Impl>()->setReferenceBarometricPressure(referenceBarometricPressure);
}

void AirflowNetworkReferenceCrackCondition::resetReferenceBarometricPressure() {
  getImpl<detail::AirflowNetworkReferenceCrackCondition_Impl>()->resetReferenceBarometricPressure();
}

void AirflowNetworkReferenceCrackCondition::setReferenceHumidityRatio(double referenceHumidityRatio) {
  getImpl<detail::AirflowNetworkReferenceCrackCondition_Impl>()->setReferenceHumidityRatio(referenceHumidityRatio);
}

void AirflowNetworkReferenceCrackCondition::resetReferenceHumidityRatio() {
  getImpl<detail::AirflowNetworkReferenceCrackCondition_Impl>()->resetReferenceHumidityRatio();
}

/// @cond
AirflowNetworkReferenceCrackCondition::AirflowNetworkReferenceCrackCondition(boost::shared_ptr<detail::AirflowNetworkReferenceCrackCondition_Impl> impl)
  : ModelObject(impl)
{}
/// @endcond

} // model
} // openstudio

