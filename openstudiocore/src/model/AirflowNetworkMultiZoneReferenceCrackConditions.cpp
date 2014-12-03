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

#include <model/AirflowNetworkMultiZoneReferenceCrackConditions.hpp>
#include <model/AirflowNetworkMultiZoneReferenceCrackConditions_Impl.hpp>

#include <utilities/idd/IddFactory.hxx>
#include <utilities/idd/OS_AirflowNetworkMultiZoneReferenceCrackConditions_FieldEnums.hxx>

#include <utilities/units/Unit.hpp>

#include <utilities/core/Assert.hpp>

namespace openstudio {
namespace model {

namespace detail {

AirflowNetworkMultiZoneReferenceCrackConditions_Impl::AirflowNetworkMultiZoneReferenceCrackConditions_Impl(const IdfObject& idfObject,
  Model_Impl* model,
  bool keepHandle)
  : ModelObject_Impl(idfObject, model, keepHandle)
{
  OS_ASSERT(idfObject.iddObject().type() == AirflowNetworkMultiZoneReferenceCrackConditions::iddObjectType());
}

AirflowNetworkMultiZoneReferenceCrackConditions_Impl::AirflowNetworkMultiZoneReferenceCrackConditions_Impl(const openstudio::detail::WorkspaceObject_Impl& other,
  Model_Impl* model,
  bool keepHandle)
  : ModelObject_Impl(other, model, keepHandle)
{
  OS_ASSERT(other.iddObject().type() == AirflowNetworkMultiZoneReferenceCrackConditions::iddObjectType());
}

AirflowNetworkMultiZoneReferenceCrackConditions_Impl::AirflowNetworkMultiZoneReferenceCrackConditions_Impl(const AirflowNetworkMultiZoneReferenceCrackConditions_Impl& other,
  Model_Impl* model,
  bool keepHandle)
  : ModelObject_Impl(other, model, keepHandle)
{}

const std::vector<std::string>& AirflowNetworkMultiZoneReferenceCrackConditions_Impl::outputVariableNames() const
{
  static std::vector<std::string> result;
  if(result.empty()){
  }
  return result;
}

IddObjectType AirflowNetworkMultiZoneReferenceCrackConditions_Impl::iddObjectType() const
{
  return AirflowNetworkMultiZoneReferenceCrackConditions::iddObjectType();
}

double AirflowNetworkMultiZoneReferenceCrackConditions_Impl::referenceTemperature() const
{
  boost::optional<double> value = getDouble(OS_AirflowNetworkMultiZoneReferenceCrackConditionsFields::ReferenceTemperature, true);
  OS_ASSERT(value);
  return value.get();
}

bool AirflowNetworkMultiZoneReferenceCrackConditions_Impl::isReferenceTemperatureDefaulted() const
{
  return isEmpty(OS_AirflowNetworkMultiZoneReferenceCrackConditionsFields::ReferenceTemperature);
}

double AirflowNetworkMultiZoneReferenceCrackConditions_Impl::referenceBarometricPressure() const
{
  boost::optional<double> value = getDouble(OS_AirflowNetworkMultiZoneReferenceCrackConditionsFields::ReferenceBarometricPressure, true);
  OS_ASSERT(value);
  return value.get();
}

bool AirflowNetworkMultiZoneReferenceCrackConditions_Impl::isReferenceBarometricPressureDefaulted() const
{
  return isEmpty(OS_AirflowNetworkMultiZoneReferenceCrackConditionsFields::ReferenceBarometricPressure);
}

double AirflowNetworkMultiZoneReferenceCrackConditions_Impl::referenceHumidityRatio() const
{
  boost::optional<double> value = getDouble(OS_AirflowNetworkMultiZoneReferenceCrackConditionsFields::ReferenceHumidityRatio, true);
  OS_ASSERT(value);
  return value.get();
}

bool AirflowNetworkMultiZoneReferenceCrackConditions_Impl::isReferenceHumidityRatioDefaulted() const
{
  return isEmpty(OS_AirflowNetworkMultiZoneReferenceCrackConditionsFields::ReferenceHumidityRatio);
}

void AirflowNetworkMultiZoneReferenceCrackConditions_Impl::setReferenceTemperature(double referenceTemperature)
{
  bool result = setDouble(OS_AirflowNetworkMultiZoneReferenceCrackConditionsFields::ReferenceTemperature, referenceTemperature);
  OS_ASSERT(result);
}

void AirflowNetworkMultiZoneReferenceCrackConditions_Impl::resetReferenceTemperature()
{
  bool result = setString(OS_AirflowNetworkMultiZoneReferenceCrackConditionsFields::ReferenceTemperature, "");
  OS_ASSERT(result);
}

bool AirflowNetworkMultiZoneReferenceCrackConditions_Impl::setReferenceBarometricPressure(double referenceBarometricPressure)
{
  bool result = setDouble(OS_AirflowNetworkMultiZoneReferenceCrackConditionsFields::ReferenceBarometricPressure, referenceBarometricPressure);
  return result;
}

void AirflowNetworkMultiZoneReferenceCrackConditions_Impl::resetReferenceBarometricPressure()
{
  bool result = setString(OS_AirflowNetworkMultiZoneReferenceCrackConditionsFields::ReferenceBarometricPressure, "");
  OS_ASSERT(result);
}

void AirflowNetworkMultiZoneReferenceCrackConditions_Impl::setReferenceHumidityRatio(double referenceHumidityRatio)
{
  bool result = setDouble(OS_AirflowNetworkMultiZoneReferenceCrackConditionsFields::ReferenceHumidityRatio, referenceHumidityRatio);
  OS_ASSERT(result);
}

void AirflowNetworkMultiZoneReferenceCrackConditions_Impl::resetReferenceHumidityRatio()
{
  bool result = setString(OS_AirflowNetworkMultiZoneReferenceCrackConditionsFields::ReferenceHumidityRatio, "");
  OS_ASSERT(result);
}

} // detail

AirflowNetworkMultiZoneReferenceCrackConditions::AirflowNetworkMultiZoneReferenceCrackConditions(const Model& model)
  : ModelObject(AirflowNetworkMultiZoneReferenceCrackConditions::iddObjectType(), model)
{
  OS_ASSERT(getImpl<detail::AirflowNetworkMultiZoneReferenceCrackConditions_Impl>());

  // TODO: Appropriately handle the following required object-list fields.
  bool ok = true;
  // ok = setHandle();
  OS_ASSERT(ok);
}

IddObjectType AirflowNetworkMultiZoneReferenceCrackConditions::iddObjectType()
{
  return IddObjectType(IddObjectType::OS_AirflowNetworkMultiZoneReferenceCrackConditions);
}

double AirflowNetworkMultiZoneReferenceCrackConditions::referenceTemperature() const
{
  return getImpl<detail::AirflowNetworkMultiZoneReferenceCrackConditions_Impl>()->referenceTemperature();
}

bool AirflowNetworkMultiZoneReferenceCrackConditions::isReferenceTemperatureDefaulted() const
{
  return getImpl<detail::AirflowNetworkMultiZoneReferenceCrackConditions_Impl>()->isReferenceTemperatureDefaulted();
}

double AirflowNetworkMultiZoneReferenceCrackConditions::referenceBarometricPressure() const
{
  return getImpl<detail::AirflowNetworkMultiZoneReferenceCrackConditions_Impl>()->referenceBarometricPressure();
}

bool AirflowNetworkMultiZoneReferenceCrackConditions::isReferenceBarometricPressureDefaulted() const
{
  return getImpl<detail::AirflowNetworkMultiZoneReferenceCrackConditions_Impl>()->isReferenceBarometricPressureDefaulted();
}

double AirflowNetworkMultiZoneReferenceCrackConditions::referenceHumidityRatio() const
{
  return getImpl<detail::AirflowNetworkMultiZoneReferenceCrackConditions_Impl>()->referenceHumidityRatio();
}

bool AirflowNetworkMultiZoneReferenceCrackConditions::isReferenceHumidityRatioDefaulted() const
{
  return getImpl<detail::AirflowNetworkMultiZoneReferenceCrackConditions_Impl>()->isReferenceHumidityRatioDefaulted();
}

void AirflowNetworkMultiZoneReferenceCrackConditions::setReferenceTemperature(double referenceTemperature)
{
  getImpl<detail::AirflowNetworkMultiZoneReferenceCrackConditions_Impl>()->setReferenceTemperature(referenceTemperature);
}

void AirflowNetworkMultiZoneReferenceCrackConditions::resetReferenceTemperature()
{
  getImpl<detail::AirflowNetworkMultiZoneReferenceCrackConditions_Impl>()->resetReferenceTemperature();
}

bool AirflowNetworkMultiZoneReferenceCrackConditions::setReferenceBarometricPressure(double referenceBarometricPressure)
{
  return getImpl<detail::AirflowNetworkMultiZoneReferenceCrackConditions_Impl>()->setReferenceBarometricPressure(referenceBarometricPressure);
}

void AirflowNetworkMultiZoneReferenceCrackConditions::resetReferenceBarometricPressure()
{
  getImpl<detail::AirflowNetworkMultiZoneReferenceCrackConditions_Impl>()->resetReferenceBarometricPressure();
}

void AirflowNetworkMultiZoneReferenceCrackConditions::setReferenceHumidityRatio(double referenceHumidityRatio)
{
  getImpl<detail::AirflowNetworkMultiZoneReferenceCrackConditions_Impl>()->setReferenceHumidityRatio(referenceHumidityRatio);
}

void AirflowNetworkMultiZoneReferenceCrackConditions::resetReferenceHumidityRatio()
{
  getImpl<detail::AirflowNetworkMultiZoneReferenceCrackConditions_Impl>()->resetReferenceHumidityRatio();
}

/// @cond
AirflowNetworkMultiZoneReferenceCrackConditions::AirflowNetworkMultiZoneReferenceCrackConditions(std::shared_ptr<detail::AirflowNetworkMultiZoneReferenceCrackConditions_Impl> impl)
  : ModelObject(impl)
{}
/// @endcond

} // model
} // openstudio

