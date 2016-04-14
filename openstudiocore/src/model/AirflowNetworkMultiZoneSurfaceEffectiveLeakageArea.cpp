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

#include <model/AirflowNetworkMultiZoneSurfaceEffectiveLeakageArea.hpp>
#include <model/AirflowNetworkMultiZoneSurfaceEffectiveLeakageArea_Impl.hpp>

#include <utilities/idd/OS_AirflowNetworkMultiZoneSurfaceEffectiveLeakageArea_FieldEnums.hxx>
#include <utilities/idd/IddEnums.hxx>

#include <utilities/units/Unit.hpp>

#include <utilities/core/Assert.hpp>

namespace openstudio {
namespace model {

namespace detail {

AirflowNetworkMultiZoneSurfaceEffectiveLeakageArea_Impl::AirflowNetworkMultiZoneSurfaceEffectiveLeakageArea_Impl(const IdfObject& idfObject,
  Model_Impl* model,
  bool keepHandle)
  : ModelObject_Impl(idfObject, model, keepHandle)
{
  OS_ASSERT(idfObject.iddObject().type() == AirflowNetworkMultiZoneSurfaceEffectiveLeakageArea::iddObjectType());
}

AirflowNetworkMultiZoneSurfaceEffectiveLeakageArea_Impl::AirflowNetworkMultiZoneSurfaceEffectiveLeakageArea_Impl(const openstudio::detail::WorkspaceObject_Impl& other,
  Model_Impl* model,
  bool keepHandle)
  : ModelObject_Impl(other, model, keepHandle)
{
  OS_ASSERT(other.iddObject().type() == AirflowNetworkMultiZoneSurfaceEffectiveLeakageArea::iddObjectType());
}

AirflowNetworkMultiZoneSurfaceEffectiveLeakageArea_Impl::AirflowNetworkMultiZoneSurfaceEffectiveLeakageArea_Impl(const AirflowNetworkMultiZoneSurfaceEffectiveLeakageArea_Impl& other,
  Model_Impl* model,
  bool keepHandle)
  : ModelObject_Impl(other, model, keepHandle)
{}

const std::vector<std::string>& AirflowNetworkMultiZoneSurfaceEffectiveLeakageArea_Impl::outputVariableNames() const
{
  static std::vector<std::string> result;
  if(result.empty()){
  }
  return result;
}

IddObjectType AirflowNetworkMultiZoneSurfaceEffectiveLeakageArea_Impl::iddObjectType() const
{
  return AirflowNetworkMultiZoneSurfaceEffectiveLeakageArea::iddObjectType();
}

double AirflowNetworkMultiZoneSurfaceEffectiveLeakageArea_Impl::effectiveLeakageArea() const
{
  boost::optional<double> value = getDouble(OS_AirflowNetworkMultiZoneSurfaceEffectiveLeakageAreaFields::EffectiveLeakageArea, true);
  OS_ASSERT(value);
  return value.get();
}

double AirflowNetworkMultiZoneSurfaceEffectiveLeakageArea_Impl::dischargeCoefficient() const
{
  boost::optional<double> value = getDouble(OS_AirflowNetworkMultiZoneSurfaceEffectiveLeakageAreaFields::DischargeCoefficient, true);
  OS_ASSERT(value);
  return value.get();
}

bool AirflowNetworkMultiZoneSurfaceEffectiveLeakageArea_Impl::isDischargeCoefficientDefaulted() const
{
  return isEmpty(OS_AirflowNetworkMultiZoneSurfaceEffectiveLeakageAreaFields::DischargeCoefficient);
}

double AirflowNetworkMultiZoneSurfaceEffectiveLeakageArea_Impl::referencePressureDifference() const
{
  boost::optional<double> value = getDouble(OS_AirflowNetworkMultiZoneSurfaceEffectiveLeakageAreaFields::ReferencePressureDifference, true);
  OS_ASSERT(value);
  return value.get();
}

bool AirflowNetworkMultiZoneSurfaceEffectiveLeakageArea_Impl::isReferencePressureDifferenceDefaulted() const
{
  return isEmpty(OS_AirflowNetworkMultiZoneSurfaceEffectiveLeakageAreaFields::ReferencePressureDifference);
}

double AirflowNetworkMultiZoneSurfaceEffectiveLeakageArea_Impl::airMassFlowExponent() const
{
  boost::optional<double> value = getDouble(OS_AirflowNetworkMultiZoneSurfaceEffectiveLeakageAreaFields::AirMassFlowExponent, true);
  OS_ASSERT(value);
  return value.get();
}

bool AirflowNetworkMultiZoneSurfaceEffectiveLeakageArea_Impl::isAirMassFlowExponentDefaulted() const
{
  return isEmpty(OS_AirflowNetworkMultiZoneSurfaceEffectiveLeakageAreaFields::AirMassFlowExponent);
}

bool AirflowNetworkMultiZoneSurfaceEffectiveLeakageArea_Impl::setEffectiveLeakageArea(double effectiveLeakageArea)
{
  bool result = setDouble(OS_AirflowNetworkMultiZoneSurfaceEffectiveLeakageAreaFields::EffectiveLeakageArea, effectiveLeakageArea);
  return result;
}

bool AirflowNetworkMultiZoneSurfaceEffectiveLeakageArea_Impl::setDischargeCoefficient(double dischargeCoefficient)
{
  bool result = setDouble(OS_AirflowNetworkMultiZoneSurfaceEffectiveLeakageAreaFields::DischargeCoefficient, dischargeCoefficient);
  return result;
}

void AirflowNetworkMultiZoneSurfaceEffectiveLeakageArea_Impl::resetDischargeCoefficient()
{
  bool result = setString(OS_AirflowNetworkMultiZoneSurfaceEffectiveLeakageAreaFields::DischargeCoefficient, "");
  OS_ASSERT(result);
}

bool AirflowNetworkMultiZoneSurfaceEffectiveLeakageArea_Impl::setReferencePressureDifference(double referencePressureDifference)
{
  bool result = setDouble(OS_AirflowNetworkMultiZoneSurfaceEffectiveLeakageAreaFields::ReferencePressureDifference, referencePressureDifference);
  return result;
}

void AirflowNetworkMultiZoneSurfaceEffectiveLeakageArea_Impl::resetReferencePressureDifference()
{
  bool result = setString(OS_AirflowNetworkMultiZoneSurfaceEffectiveLeakageAreaFields::ReferencePressureDifference, "");
  OS_ASSERT(result);
}

bool AirflowNetworkMultiZoneSurfaceEffectiveLeakageArea_Impl::setAirMassFlowExponent(double airMassFlowExponent)
{
  bool result = setDouble(OS_AirflowNetworkMultiZoneSurfaceEffectiveLeakageAreaFields::AirMassFlowExponent, airMassFlowExponent);
  return result;
}

void AirflowNetworkMultiZoneSurfaceEffectiveLeakageArea_Impl::resetAirMassFlowExponent()
{
  bool result = setString(OS_AirflowNetworkMultiZoneSurfaceEffectiveLeakageAreaFields::AirMassFlowExponent, "");
  OS_ASSERT(result);
}

} // detail

AirflowNetworkMultiZoneSurfaceEffectiveLeakageArea::AirflowNetworkMultiZoneSurfaceEffectiveLeakageArea(const Model& model,
  double effectiveLeakageArea)
  : ModelObject(AirflowNetworkMultiZoneSurfaceEffectiveLeakageArea::iddObjectType(), model)
{
  OS_ASSERT(getImpl<detail::AirflowNetworkMultiZoneSurfaceEffectiveLeakageArea_Impl>());

  // TODO: Appropriately handle the following required object-list fields.
  // OS_ASSERT(setHandle());
  OS_ASSERT(setEffectiveLeakageArea(effectiveLeakageArea));
}

AirflowNetworkMultiZoneSurfaceEffectiveLeakageArea::AirflowNetworkMultiZoneSurfaceEffectiveLeakageArea(const Model& model, 
  double effectiveLeakageArea, double dischargeCoefficient, double referencePressureDifference, double massFlowExponent)
  : ModelObject(AirflowNetworkMultiZoneSurfaceEffectiveLeakageArea::iddObjectType(), model)
{
  OS_ASSERT(getImpl<detail::AirflowNetworkMultiZoneSurfaceEffectiveLeakageArea_Impl>());

  // TODO: Appropriately handle the following required object-list fields.
  // OS_ASSERT(setHandle());
  OS_ASSERT(setEffectiveLeakageArea(effectiveLeakageArea));
  OS_ASSERT(setDischargeCoefficient(dischargeCoefficient));
  OS_ASSERT(setReferencePressureDifference(referencePressureDifference));
  OS_ASSERT(setAirMassFlowExponent(massFlowExponent));
}

IddObjectType AirflowNetworkMultiZoneSurfaceEffectiveLeakageArea::iddObjectType()
{
  return IddObjectType(IddObjectType::OS_AirflowNetwork_MultiZoneSurfaceEffectiveLeakageArea);
}

double AirflowNetworkMultiZoneSurfaceEffectiveLeakageArea::effectiveLeakageArea() const
{
  return getImpl<detail::AirflowNetworkMultiZoneSurfaceEffectiveLeakageArea_Impl>()->effectiveLeakageArea();
}

double AirflowNetworkMultiZoneSurfaceEffectiveLeakageArea::dischargeCoefficient() const
{
  return getImpl<detail::AirflowNetworkMultiZoneSurfaceEffectiveLeakageArea_Impl>()->dischargeCoefficient();
}

bool AirflowNetworkMultiZoneSurfaceEffectiveLeakageArea::isDischargeCoefficientDefaulted() const
{
  return getImpl<detail::AirflowNetworkMultiZoneSurfaceEffectiveLeakageArea_Impl>()->isDischargeCoefficientDefaulted();
}

double AirflowNetworkMultiZoneSurfaceEffectiveLeakageArea::referencePressureDifference() const
{
  return getImpl<detail::AirflowNetworkMultiZoneSurfaceEffectiveLeakageArea_Impl>()->referencePressureDifference();
}

bool AirflowNetworkMultiZoneSurfaceEffectiveLeakageArea::isReferencePressureDifferenceDefaulted() const
{
  return getImpl<detail::AirflowNetworkMultiZoneSurfaceEffectiveLeakageArea_Impl>()->isReferencePressureDifferenceDefaulted();
}

double AirflowNetworkMultiZoneSurfaceEffectiveLeakageArea::airMassFlowExponent() const
{
  return getImpl<detail::AirflowNetworkMultiZoneSurfaceEffectiveLeakageArea_Impl>()->airMassFlowExponent();
}

bool AirflowNetworkMultiZoneSurfaceEffectiveLeakageArea::isAirMassFlowExponentDefaulted() const
{
  return getImpl<detail::AirflowNetworkMultiZoneSurfaceEffectiveLeakageArea_Impl>()->isAirMassFlowExponentDefaulted();
}

bool AirflowNetworkMultiZoneSurfaceEffectiveLeakageArea::setEffectiveLeakageArea(double effectiveLeakageArea)
{
  return getImpl<detail::AirflowNetworkMultiZoneSurfaceEffectiveLeakageArea_Impl>()->setEffectiveLeakageArea(effectiveLeakageArea);
}

bool AirflowNetworkMultiZoneSurfaceEffectiveLeakageArea::setDischargeCoefficient(double dischargeCoefficient)
{
  return getImpl<detail::AirflowNetworkMultiZoneSurfaceEffectiveLeakageArea_Impl>()->setDischargeCoefficient(dischargeCoefficient);
}

void AirflowNetworkMultiZoneSurfaceEffectiveLeakageArea::resetDischargeCoefficient()
{
  getImpl<detail::AirflowNetworkMultiZoneSurfaceEffectiveLeakageArea_Impl>()->resetDischargeCoefficient();
}

bool AirflowNetworkMultiZoneSurfaceEffectiveLeakageArea::setReferencePressureDifference(double referencePressureDifference)
{
  return getImpl<detail::AirflowNetworkMultiZoneSurfaceEffectiveLeakageArea_Impl>()->setReferencePressureDifference(referencePressureDifference);
}

void AirflowNetworkMultiZoneSurfaceEffectiveLeakageArea::resetReferencePressureDifference()
{
  getImpl<detail::AirflowNetworkMultiZoneSurfaceEffectiveLeakageArea_Impl>()->resetReferencePressureDifference();
}

bool AirflowNetworkMultiZoneSurfaceEffectiveLeakageArea::setAirMassFlowExponent(double airMassFlowExponent)
{
  return getImpl<detail::AirflowNetworkMultiZoneSurfaceEffectiveLeakageArea_Impl>()->setAirMassFlowExponent(airMassFlowExponent);
}

void AirflowNetworkMultiZoneSurfaceEffectiveLeakageArea::resetAirMassFlowExponent()
{
  getImpl<detail::AirflowNetworkMultiZoneSurfaceEffectiveLeakageArea_Impl>()->resetAirMassFlowExponent();
}

/// @cond
AirflowNetworkMultiZoneSurfaceEffectiveLeakageArea::AirflowNetworkMultiZoneSurfaceEffectiveLeakageArea(std::shared_ptr<detail::AirflowNetworkMultiZoneSurfaceEffectiveLeakageArea_Impl> impl)
  : ModelObject(impl)
{}
/// @endcond

} // model
} // openstudio

