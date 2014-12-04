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

#include <model/AirflowNetworkMultiZoneSurfaceCrack.hpp>
#include <model/AirflowNetworkMultiZoneSurfaceCrack_Impl.hpp>
#include <model/Model.hpp>

#include <model/AirflowNetworkMultiZoneReferenceCrackConditions.hpp>
#include <model/AirflowNetworkMultiZoneReferenceCrackConditions_Impl.hpp>

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

double AirflowNetworkMultiZoneSurfaceCrack_Impl::airMassFlowCoefficientatReferenceConditions() const
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

boost::optional<AirflowNetworkMultiZoneReferenceCrackConditions> AirflowNetworkMultiZoneSurfaceCrack_Impl::referenceCrackConditions() const
{
  return getObject<ModelObject>().getModelObjectTarget<AirflowNetworkMultiZoneReferenceCrackConditions>(OS_AirflowNetworkMultiZoneSurfaceCrackFields::ReferenceCrackConditions);
}

bool AirflowNetworkMultiZoneSurfaceCrack_Impl::isReferenceCrackConditionsObjectDefaulted() const
{
  // If there is a reference crack conditions object, then it is not defaulted
  if(!isEmpty(OS_AirflowNetworkMultiZoneSurfaceCrackFields::ReferenceCrackConditions)) {
    return false;
  }
  // Check to see if there are any reference crack conditions objects in the model
  auto refCondObjs = this->model().getConcreteModelObjects<AirflowNetworkMultiZoneReferenceCrackConditions>();
  // If there are 0 or 2 or more reference condition objects, it is defaulted
  return !(refCondObjs.size() == 1);
}

bool AirflowNetworkMultiZoneSurfaceCrack_Impl::setAirMassFlowCoefficientatReferenceConditions(double airMassFlowCoefficientatReferenceConditions)
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

bool AirflowNetworkMultiZoneSurfaceCrack_Impl::setReferenceCrackConditions(const AirflowNetworkMultiZoneReferenceCrackConditions &referenceCrackConditions)
{
  bool result = setPointer(OS_AirflowNetworkMultiZoneSurfaceCrackFields::ReferenceCrackConditions, referenceCrackConditions.handle());
  return result;
}

void AirflowNetworkMultiZoneSurfaceCrack_Impl::resetReferenceCrackConditions() {
  bool result = setString(OS_AirflowNetworkMultiZoneSurfaceCrackFields::ReferenceCrackConditions, "");
  OS_ASSERT(result);
}

} // detail

AirflowNetworkMultiZoneSurfaceCrack::AirflowNetworkMultiZoneSurfaceCrack(const Model& model, double massFlowCoefficient)
  : ModelObject(AirflowNetworkMultiZoneSurfaceCrack::iddObjectType(),model)
{
  OS_ASSERT(getImpl<detail::AirflowNetworkMultiZoneSurfaceCrack_Impl>());

  // TODO: Appropriately handle the following required object-list fields.
  // OS_ASSERT(setHandle());
  OS_ASSERT(setAirMassFlowCoefficientatReferenceConditions(massFlowCoefficient));
}

AirflowNetworkMultiZoneSurfaceCrack::AirflowNetworkMultiZoneSurfaceCrack(const Model& model, double massFlowCoefficient,
  double massFlowExponent)
  : ModelObject(AirflowNetworkMultiZoneSurfaceCrack::iddObjectType(), model)
{
  OS_ASSERT(getImpl<detail::AirflowNetworkMultiZoneSurfaceCrack_Impl>());

  // TODO: Appropriately handle the following required object-list fields.
  // OS_ASSERT(setHandle());
  OS_ASSERT(setAirMassFlowCoefficientatReferenceConditions(massFlowCoefficient));
  OS_ASSERT(setAirMassFlowExponent(massFlowExponent));
}

AirflowNetworkMultiZoneSurfaceCrack::AirflowNetworkMultiZoneSurfaceCrack(const Model& model, double massFlowCoefficient,
  double massFlowExponent, const AirflowNetworkMultiZoneReferenceCrackConditions &referenceCrackConditions)
  : ModelObject(AirflowNetworkMultiZoneSurfaceCrack::iddObjectType(), model)
{
  OS_ASSERT(getImpl<detail::AirflowNetworkMultiZoneSurfaceCrack_Impl>());

  // TODO: Appropriately handle the following required object-list fields.
  // OS_ASSERT(setHandle());
  OS_ASSERT(setAirMassFlowCoefficientatReferenceConditions(massFlowCoefficient));
  OS_ASSERT(setAirMassFlowExponent(massFlowExponent));
  OS_ASSERT(setReferenceCrackConditions(referenceCrackConditions));
}

IddObjectType AirflowNetworkMultiZoneSurfaceCrack::iddObjectType()
{
  return IddObjectType(IddObjectType::OS_AirflowNetworkMultiZoneSurfaceCrack);
}

double AirflowNetworkMultiZoneSurfaceCrack::airMassFlowCoefficientatReferenceConditions() const
{
  return getImpl<detail::AirflowNetworkMultiZoneSurfaceCrack_Impl>()->airMassFlowCoefficientatReferenceConditions();
}

double AirflowNetworkMultiZoneSurfaceCrack::airMassFlowExponent() const
{
  return getImpl<detail::AirflowNetworkMultiZoneSurfaceCrack_Impl>()->airMassFlowExponent();
}

bool AirflowNetworkMultiZoneSurfaceCrack::isAirMassFlowExponentDefaulted() const
{
  return getImpl<detail::AirflowNetworkMultiZoneSurfaceCrack_Impl>()->isAirMassFlowExponentDefaulted();
}

boost::optional<AirflowNetworkMultiZoneReferenceCrackConditions> AirflowNetworkMultiZoneSurfaceCrack::referenceCrackConditions() const
{
  return getImpl<detail::AirflowNetworkMultiZoneSurfaceCrack_Impl>()->referenceCrackConditions();
}

bool AirflowNetworkMultiZoneSurfaceCrack::setAirMassFlowCoefficientatReferenceConditions(double airMassFlowCoefficientatReferenceConditions)
{
  return getImpl<detail::AirflowNetworkMultiZoneSurfaceCrack_Impl>()->setAirMassFlowCoefficientatReferenceConditions(airMassFlowCoefficientatReferenceConditions);
}

bool AirflowNetworkMultiZoneSurfaceCrack::isReferenceCrackConditionsObjectDefaulted() const
{
  return getImpl<detail::AirflowNetworkMultiZoneSurfaceCrack_Impl>()->isReferenceCrackConditionsObjectDefaulted();
}

bool AirflowNetworkMultiZoneSurfaceCrack::setAirMassFlowExponent(double airMassFlowExponent)
{
  return getImpl<detail::AirflowNetworkMultiZoneSurfaceCrack_Impl>()->setAirMassFlowExponent(airMassFlowExponent);
}

void AirflowNetworkMultiZoneSurfaceCrack::resetAirMassFlowExponent()
{
  getImpl<detail::AirflowNetworkMultiZoneSurfaceCrack_Impl>()->resetAirMassFlowExponent();
}

bool AirflowNetworkMultiZoneSurfaceCrack::setReferenceCrackConditions(const AirflowNetworkMultiZoneReferenceCrackConditions& referenceCrackConditions) {
  return getImpl<detail::AirflowNetworkMultiZoneSurfaceCrack_Impl>()->setReferenceCrackConditions(referenceCrackConditions);
}

void AirflowNetworkMultiZoneSurfaceCrack::resetReferenceCrackConditions()
{
  getImpl<detail::AirflowNetworkMultiZoneSurfaceCrack_Impl>()->resetReferenceCrackConditions();
}

/// @cond
AirflowNetworkMultiZoneSurfaceCrack::AirflowNetworkMultiZoneSurfaceCrack(std::shared_ptr<detail::AirflowNetworkMultiZoneSurfaceCrack_Impl> impl)
  : ModelObject(impl)
{}
/// @endcond

} // model
} // openstudio

