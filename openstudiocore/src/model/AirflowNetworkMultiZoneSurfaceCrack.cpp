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

#include <model/AirflowNetworkMultiZoneSurfaceCrack.hpp>
#include <model/AirflowNetworkMultiZoneSurfaceCrack_Impl.hpp>
#include <model/Model.hpp>

#include <utilities/idd/IddEnums.hxx>
#include <utilities/idd/OS_AirflowNetworkMultiZoneSurfaceCrack_FieldEnums.hxx>

#include <utilities/units/Unit.hpp>

#include <utilities/core/Assert.hpp>

namespace openstudio {
namespace model {

namespace detail {

AirflowNetworkMultiZoneSurfaceCrack_Impl::AirflowNetworkMultiZoneSurfaceCrack_Impl(const IdfObject& idfObject,
  Model_Impl* model,
  bool keepHandle)
  : ModelObject_Impl(idfObject, model, keepHandle)
{
  OS_ASSERT(idfObject.iddObject().type() == AirflowNetworkMultiZoneSurfaceCrack::iddObjectType());
}

AirflowNetworkMultiZoneSurfaceCrack_Impl::AirflowNetworkMultiZoneSurfaceCrack_Impl(const openstudio::detail::WorkspaceObject_Impl& other,
  Model_Impl* model,
  bool keepHandle)
  : ModelObject_Impl(other, model, keepHandle)
{
  OS_ASSERT(other.iddObject().type() == AirflowNetworkMultiZoneSurfaceCrack::iddObjectType());
}

AirflowNetworkMultiZoneSurfaceCrack_Impl::AirflowNetworkMultiZoneSurfaceCrack_Impl(const AirflowNetworkMultiZoneSurfaceCrack_Impl& other,
  Model_Impl* model,
  bool keepHandle)
  : ModelObject_Impl(other, model, keepHandle)
{}

const std::vector<std::string>& AirflowNetworkMultiZoneSurfaceCrack_Impl::outputVariableNames() const
{
  static std::vector<std::string> result;
  if(result.empty()){
  }
  return result;
}

IddObjectType AirflowNetworkMultiZoneSurfaceCrack_Impl::iddObjectType() const
{
  return AirflowNetworkMultiZoneSurfaceCrack::iddObjectType();
}

double AirflowNetworkMultiZoneSurfaceCrack_Impl::airMassFlowCoefficient() const
{
  boost::optional<double> value = getDouble(OS_AirflowNetworkMultiZoneSurfaceCrackFields::AirMassFlowCoefficientatReferenceConditions, true);
  OS_ASSERT(value);
  return value.get();
}

double AirflowNetworkMultiZoneSurfaceCrack_Impl::airMassFlowExponent() const
{
  boost::optional<double> value = getDouble(OS_AirflowNetworkMultiZoneSurfaceCrackFields::AirMassFlowExponent, true);
  OS_ASSERT(value);
  return value.get();
}

bool AirflowNetworkMultiZoneSurfaceCrack_Impl::isAirMassFlowExponentDefaulted() const
{
  return isEmpty(OS_AirflowNetworkMultiZoneSurfaceCrackFields::AirMassFlowExponent);
}

bool AirflowNetworkMultiZoneSurfaceCrack_Impl::setAirMassFlowCoefficient(double airMassFlowCoefficientatReferenceConditions)
{
  bool result = setDouble(OS_AirflowNetworkMultiZoneSurfaceCrackFields::AirMassFlowCoefficientatReferenceConditions, airMassFlowCoefficientatReferenceConditions);
  return result;
}

bool AirflowNetworkMultiZoneSurfaceCrack_Impl::setAirMassFlowExponent(double airMassFlowExponent)
{
  bool result = setDouble(OS_AirflowNetworkMultiZoneSurfaceCrackFields::AirMassFlowExponent, airMassFlowExponent);
  return result;
}

void AirflowNetworkMultiZoneSurfaceCrack_Impl::resetAirMassFlowExponent()
{
  bool result = setString(OS_AirflowNetworkMultiZoneSurfaceCrackFields::AirMassFlowExponent, "");
  OS_ASSERT(result);
}

double AirflowNetworkMultiZoneSurfaceCrack_Impl::referenceTemperature() const
{
	boost::optional<double> value = getDouble(OS_AirflowNetworkMultiZoneSurfaceCrackFields::ReferenceTemperature, true);
	OS_ASSERT(value);
	return value.get();
}

bool AirflowNetworkMultiZoneSurfaceCrack_Impl::isReferenceTemperatureDefaulted() const
{
	return isEmpty(OS_AirflowNetworkMultiZoneSurfaceCrackFields::ReferenceTemperature);
}

double AirflowNetworkMultiZoneSurfaceCrack_Impl::referenceBarometricPressure() const
{
	boost::optional<double> value = getDouble(OS_AirflowNetworkMultiZoneSurfaceCrackFields::ReferenceBarometricPressure, true);
	OS_ASSERT(value);
	return value.get();
}

bool AirflowNetworkMultiZoneSurfaceCrack_Impl::isReferenceBarometricPressureDefaulted() const
{
	return isEmpty(OS_AirflowNetworkMultiZoneSurfaceCrackFields::ReferenceBarometricPressure);
}

double AirflowNetworkMultiZoneSurfaceCrack_Impl::referenceHumidityRatio() const
{
	boost::optional<double> value = getDouble(OS_AirflowNetworkMultiZoneSurfaceCrackFields::ReferenceHumidityRatio, true);
	OS_ASSERT(value);
	return value.get();
}

bool AirflowNetworkMultiZoneSurfaceCrack_Impl::isReferenceHumidityRatioDefaulted() const
{
	return isEmpty(OS_AirflowNetworkMultiZoneSurfaceCrackFields::ReferenceHumidityRatio);
}

void AirflowNetworkMultiZoneSurfaceCrack_Impl::setReferenceTemperature(double referenceTemperature)
{
	bool result = setDouble(OS_AirflowNetworkMultiZoneSurfaceCrackFields::ReferenceTemperature, referenceTemperature);
	OS_ASSERT(result);
}

void AirflowNetworkMultiZoneSurfaceCrack_Impl::resetReferenceTemperature()
{
	bool result = setString(OS_AirflowNetworkMultiZoneSurfaceCrackFields::ReferenceTemperature, "");
	OS_ASSERT(result);
}

bool AirflowNetworkMultiZoneSurfaceCrack_Impl::setReferenceBarometricPressure(double referenceBarometricPressure)
{
	bool result = setDouble(OS_AirflowNetworkMultiZoneSurfaceCrackFields::ReferenceBarometricPressure, referenceBarometricPressure);
	return result;
}

void AirflowNetworkMultiZoneSurfaceCrack_Impl::resetReferenceBarometricPressure()
{
	bool result = setString(OS_AirflowNetworkMultiZoneSurfaceCrackFields::ReferenceBarometricPressure, "");
	OS_ASSERT(result);
}

void AirflowNetworkMultiZoneSurfaceCrack_Impl::setReferenceHumidityRatio(double referenceHumidityRatio)
{
	bool result = setDouble(OS_AirflowNetworkMultiZoneSurfaceCrackFields::ReferenceHumidityRatio, referenceHumidityRatio);
	OS_ASSERT(result);
}

void AirflowNetworkMultiZoneSurfaceCrack_Impl::resetReferenceHumidityRatio()
{
	bool result = setString(OS_AirflowNetworkMultiZoneSurfaceCrackFields::ReferenceHumidityRatio, "");
	OS_ASSERT(result);
}

} // detail

AirflowNetworkMultiZoneSurfaceCrack::AirflowNetworkMultiZoneSurfaceCrack(const Model& model, double massFlowCoefficient)
  : ModelObject(AirflowNetworkMultiZoneSurfaceCrack::iddObjectType(),model)
{
  OS_ASSERT(getImpl<detail::AirflowNetworkMultiZoneSurfaceCrack_Impl>());

  // TODO: Appropriately handle the following required object-list fields.
  // OS_ASSERT(setHandle());
  OS_ASSERT(setAirMassFlowCoefficient(massFlowCoefficient));
}

AirflowNetworkMultiZoneSurfaceCrack::AirflowNetworkMultiZoneSurfaceCrack(const Model& model, double massFlowCoefficient,
  double massFlowExponent)
  : ModelObject(AirflowNetworkMultiZoneSurfaceCrack::iddObjectType(), model)
{
  OS_ASSERT(getImpl<detail::AirflowNetworkMultiZoneSurfaceCrack_Impl>());

  // TODO: Appropriately handle the following required object-list fields.
  // OS_ASSERT(setHandle());
  OS_ASSERT(setAirMassFlowCoefficient(massFlowCoefficient));
  OS_ASSERT(setAirMassFlowExponent(massFlowExponent));
}

AirflowNetworkMultiZoneSurfaceCrack::AirflowNetworkMultiZoneSurfaceCrack(const Model& model, double massFlowCoefficient,
	double massFlowExponent, double referenceTemperature, double referenceBarometricPressure, double referenceHumidityRatio)
  : ModelObject(AirflowNetworkMultiZoneSurfaceCrack::iddObjectType(), model)
{
  OS_ASSERT(getImpl<detail::AirflowNetworkMultiZoneSurfaceCrack_Impl>());

  // TODO: Appropriately handle the following required object-list fields.
  // OS_ASSERT(setHandle());
  OS_ASSERT(setAirMassFlowCoefficient(massFlowCoefficient));
  OS_ASSERT(setAirMassFlowExponent(massFlowExponent));
  setReferenceTemperature(referenceTemperature);
  OS_ASSERT(setReferenceBarometricPressure(referenceBarometricPressure));
  setReferenceHumidityRatio(referenceHumidityRatio);
}

IddObjectType AirflowNetworkMultiZoneSurfaceCrack::iddObjectType()
{
  return IddObjectType(IddObjectType::OS_AirflowNetwork_MultiZoneSurfaceCrack);
}

double AirflowNetworkMultiZoneSurfaceCrack::airMassFlowCoefficient() const
{
  return getImpl<detail::AirflowNetworkMultiZoneSurfaceCrack_Impl>()->airMassFlowCoefficient();
}

double AirflowNetworkMultiZoneSurfaceCrack::airMassFlowExponent() const
{
  return getImpl<detail::AirflowNetworkMultiZoneSurfaceCrack_Impl>()->airMassFlowExponent();
}

bool AirflowNetworkMultiZoneSurfaceCrack::isAirMassFlowExponentDefaulted() const
{
  return getImpl<detail::AirflowNetworkMultiZoneSurfaceCrack_Impl>()->isAirMassFlowExponentDefaulted();
}

bool AirflowNetworkMultiZoneSurfaceCrack::setAirMassFlowCoefficient(double airMassFlowCoefficientatReferenceConditions)
{
  return getImpl<detail::AirflowNetworkMultiZoneSurfaceCrack_Impl>()->setAirMassFlowCoefficient(airMassFlowCoefficientatReferenceConditions);
}

bool AirflowNetworkMultiZoneSurfaceCrack::setAirMassFlowExponent(double airMassFlowExponent)
{
  return getImpl<detail::AirflowNetworkMultiZoneSurfaceCrack_Impl>()->setAirMassFlowExponent(airMassFlowExponent);
}

void AirflowNetworkMultiZoneSurfaceCrack::resetAirMassFlowExponent()
{
  getImpl<detail::AirflowNetworkMultiZoneSurfaceCrack_Impl>()->resetAirMassFlowExponent();
}

double AirflowNetworkMultiZoneSurfaceCrack::referenceTemperature() const
{
	return getImpl<detail::AirflowNetworkMultiZoneSurfaceCrack_Impl>()->referenceTemperature();
}

bool AirflowNetworkMultiZoneSurfaceCrack::isReferenceTemperatureDefaulted() const
{
	return getImpl<detail::AirflowNetworkMultiZoneSurfaceCrack_Impl>()->isReferenceTemperatureDefaulted();
}

double AirflowNetworkMultiZoneSurfaceCrack::referenceBarometricPressure() const
{
	return getImpl<detail::AirflowNetworkMultiZoneSurfaceCrack_Impl>()->referenceBarometricPressure();
}

bool AirflowNetworkMultiZoneSurfaceCrack::isReferenceBarometricPressureDefaulted() const
{
	return getImpl<detail::AirflowNetworkMultiZoneSurfaceCrack_Impl>()->isReferenceBarometricPressureDefaulted();
}

double AirflowNetworkMultiZoneSurfaceCrack::referenceHumidityRatio() const
{
	return getImpl<detail::AirflowNetworkMultiZoneSurfaceCrack_Impl>()->referenceHumidityRatio();
}

bool AirflowNetworkMultiZoneSurfaceCrack::isReferenceHumidityRatioDefaulted() const
{
	return getImpl<detail::AirflowNetworkMultiZoneSurfaceCrack_Impl>()->isReferenceHumidityRatioDefaulted();
}

void AirflowNetworkMultiZoneSurfaceCrack::setReferenceTemperature(double referenceTemperature)
{
	getImpl<detail::AirflowNetworkMultiZoneSurfaceCrack_Impl>()->setReferenceTemperature(referenceTemperature);
}

void AirflowNetworkMultiZoneSurfaceCrack::resetReferenceTemperature()
{
	getImpl<detail::AirflowNetworkMultiZoneSurfaceCrack_Impl>()->resetReferenceTemperature();
}

bool AirflowNetworkMultiZoneSurfaceCrack::setReferenceBarometricPressure(double referenceBarometricPressure)
{
	return getImpl<detail::AirflowNetworkMultiZoneSurfaceCrack_Impl>()->setReferenceBarometricPressure(referenceBarometricPressure);
}

void AirflowNetworkMultiZoneSurfaceCrack::resetReferenceBarometricPressure()
{
	getImpl<detail::AirflowNetworkMultiZoneSurfaceCrack_Impl>()->resetReferenceBarometricPressure();
}

void AirflowNetworkMultiZoneSurfaceCrack::setReferenceHumidityRatio(double referenceHumidityRatio)
{
	getImpl<detail::AirflowNetworkMultiZoneSurfaceCrack_Impl>()->setReferenceHumidityRatio(referenceHumidityRatio);
}

void AirflowNetworkMultiZoneSurfaceCrack::resetReferenceHumidityRatio()
{
	getImpl<detail::AirflowNetworkMultiZoneSurfaceCrack_Impl>()->resetReferenceHumidityRatio();
}

/// @cond
AirflowNetworkMultiZoneSurfaceCrack::AirflowNetworkMultiZoneSurfaceCrack(std::shared_ptr<detail::AirflowNetworkMultiZoneSurfaceCrack_Impl> impl)
  : ModelObject(impl)
{}
/// @endcond

} // model
} // openstudio

