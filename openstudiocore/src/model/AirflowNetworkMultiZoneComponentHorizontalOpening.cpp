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

#include <model/AirflowNetworkMultiZoneComponentHorizontalOpening.hpp>
#include <model/AirflowNetworkMultiZoneComponentHorizontalOpening_Impl.hpp>

#include <utilities/idd/IddEnums.hxx>
#include <utilities/idd/OS_AirflowNetworkMultiZoneComponentHorizontalOpening_FieldEnums.hxx>

#include <utilities/units/Unit.hpp>

#include <utilities/core/Assert.hpp>

namespace openstudio {
namespace model {

namespace detail {

  AirflowNetworkMultiZoneComponentHorizontalOpening_Impl::AirflowNetworkMultiZoneComponentHorizontalOpening_Impl(const IdfObject& idfObject,
                                                                                                                 Model_Impl* model,
                                                                                                                 bool keepHandle)
    : ModelObject_Impl(idfObject,model,keepHandle)
  {
    OS_ASSERT(idfObject.iddObject().type() == AirflowNetworkMultiZoneComponentHorizontalOpening::iddObjectType());
  }

  AirflowNetworkMultiZoneComponentHorizontalOpening_Impl::AirflowNetworkMultiZoneComponentHorizontalOpening_Impl(const openstudio::detail::WorkspaceObject_Impl& other,
                                                                                                                 Model_Impl* model,
                                                                                                                 bool keepHandle)
    : ModelObject_Impl(other,model,keepHandle)
  {
    OS_ASSERT(other.iddObject().type() == AirflowNetworkMultiZoneComponentHorizontalOpening::iddObjectType());
  }

  AirflowNetworkMultiZoneComponentHorizontalOpening_Impl::AirflowNetworkMultiZoneComponentHorizontalOpening_Impl(const AirflowNetworkMultiZoneComponentHorizontalOpening_Impl& other,
                                                                                                                 Model_Impl* model,
                                                                                                                 bool keepHandle)
    : ModelObject_Impl(other,model,keepHandle)
  {}

  const std::vector<std::string>& AirflowNetworkMultiZoneComponentHorizontalOpening_Impl::outputVariableNames() const
  {
    static std::vector<std::string> result;
    if (result.empty()){
    }
    return result;
  }

  IddObjectType AirflowNetworkMultiZoneComponentHorizontalOpening_Impl::iddObjectType() const {
    return AirflowNetworkMultiZoneComponentHorizontalOpening::iddObjectType();
  }

  double AirflowNetworkMultiZoneComponentHorizontalOpening_Impl::airMassFlowCoefficientWhenOpeningisClosed() const {
    boost::optional<double> value = getDouble(OS_AirflowNetworkMultiZoneComponentHorizontalOpeningFields::AirMassFlowCoefficientWhenOpeningisClosed,true);
    OS_ASSERT(value);
    return value.get();
  }

  double AirflowNetworkMultiZoneComponentHorizontalOpening_Impl::airMassFlowExponentWhenOpeningisClosed() const {
    boost::optional<double> value = getDouble(OS_AirflowNetworkMultiZoneComponentHorizontalOpeningFields::AirMassFlowExponentWhenOpeningisClosed,true);
    OS_ASSERT(value);
    return value.get();
  }

  bool AirflowNetworkMultiZoneComponentHorizontalOpening_Impl::isAirMassFlowExponentWhenOpeningisClosedDefaulted() const {
    return isEmpty(OS_AirflowNetworkMultiZoneComponentHorizontalOpeningFields::AirMassFlowExponentWhenOpeningisClosed);
  }

  double AirflowNetworkMultiZoneComponentHorizontalOpening_Impl::slopingPlaneAngle() const {
    boost::optional<double> value = getDouble(OS_AirflowNetworkMultiZoneComponentHorizontalOpeningFields::SlopingPlaneAngle,true);
    OS_ASSERT(value);
    return value.get();
  }

  bool AirflowNetworkMultiZoneComponentHorizontalOpening_Impl::isSlopingPlaneAngleDefaulted() const {
    return isEmpty(OS_AirflowNetworkMultiZoneComponentHorizontalOpeningFields::SlopingPlaneAngle);
  }

  double AirflowNetworkMultiZoneComponentHorizontalOpening_Impl::dischargeCoefficient() const {
    boost::optional<double> value = getDouble(OS_AirflowNetworkMultiZoneComponentHorizontalOpeningFields::DischargeCoefficient,true);
    OS_ASSERT(value);
    return value.get();
  }

  bool AirflowNetworkMultiZoneComponentHorizontalOpening_Impl::setAirMassFlowCoefficientWhenOpeningisClosed(double airMassFlowCoefficientWhenOpeningisClosed) {
    bool result = setDouble(OS_AirflowNetworkMultiZoneComponentHorizontalOpeningFields::AirMassFlowCoefficientWhenOpeningisClosed, airMassFlowCoefficientWhenOpeningisClosed);
    return result;
  }

  bool AirflowNetworkMultiZoneComponentHorizontalOpening_Impl::setAirMassFlowExponentWhenOpeningisClosed(double airMassFlowExponentWhenOpeningisClosed) {
    bool result = setDouble(OS_AirflowNetworkMultiZoneComponentHorizontalOpeningFields::AirMassFlowExponentWhenOpeningisClosed, airMassFlowExponentWhenOpeningisClosed);
    return result;
  }

  void AirflowNetworkMultiZoneComponentHorizontalOpening_Impl::resetAirMassFlowExponentWhenOpeningisClosed() {
    bool result = setString(OS_AirflowNetworkMultiZoneComponentHorizontalOpeningFields::AirMassFlowExponentWhenOpeningisClosed, "");
    OS_ASSERT(result);
  }

  bool AirflowNetworkMultiZoneComponentHorizontalOpening_Impl::setSlopingPlaneAngle(double slopingPlaneAngle) {
    bool result = setDouble(OS_AirflowNetworkMultiZoneComponentHorizontalOpeningFields::SlopingPlaneAngle, slopingPlaneAngle);
    return result;
  }

  void AirflowNetworkMultiZoneComponentHorizontalOpening_Impl::resetSlopingPlaneAngle() {
    bool result = setString(OS_AirflowNetworkMultiZoneComponentHorizontalOpeningFields::SlopingPlaneAngle, "");
    OS_ASSERT(result);
  }

  bool AirflowNetworkMultiZoneComponentHorizontalOpening_Impl::setDischargeCoefficient(double dischargeCoefficient) {
    bool result = setDouble(OS_AirflowNetworkMultiZoneComponentHorizontalOpeningFields::DischargeCoefficient, dischargeCoefficient);
    return result;
  }

} // detail

AirflowNetworkMultiZoneComponentHorizontalOpening::AirflowNetworkMultiZoneComponentHorizontalOpening(const Model& model,
  double massFlowCoefficientWhenOpeningisClosed,
  double dischargeCoefficient)
  : ModelObject(AirflowNetworkMultiZoneComponentHorizontalOpening::iddObjectType(), model)
{
  OS_ASSERT(getImpl<detail::AirflowNetworkMultiZoneComponentHorizontalOpening_Impl>());

  // TODO: Appropriately handle the following required object-list fields.
  //OS_ASSERT(setHandle());
  OS_ASSERT(setAirMassFlowCoefficientWhenOpeningisClosed(massFlowCoefficientWhenOpeningisClosed));
  OS_ASSERT(setDischargeCoefficient(dischargeCoefficient));
}

AirflowNetworkMultiZoneComponentHorizontalOpening::AirflowNetworkMultiZoneComponentHorizontalOpening(const Model& model,
  double massFlowCoefficientWhenOpeningisClosed,
  double massFlowExponentWhenOpeningisClosed,
  double slopingPlaneAngle,
  double dischargeCoefficient)
  : ModelObject(AirflowNetworkMultiZoneComponentHorizontalOpening::iddObjectType(), model)
{
  OS_ASSERT(getImpl<detail::AirflowNetworkMultiZoneComponentHorizontalOpening_Impl>());

  // TODO: Appropriately handle the following required object-list fields.
  //OS_ASSERT(setHandle());
  OS_ASSERT(setAirMassFlowCoefficientWhenOpeningisClosed(massFlowCoefficientWhenOpeningisClosed));
  OS_ASSERT(setAirMassFlowExponentWhenOpeningisClosed(massFlowExponentWhenOpeningisClosed));
  OS_ASSERT(setSlopingPlaneAngle(slopingPlaneAngle));
  OS_ASSERT(setDischargeCoefficient(dischargeCoefficient));
}

IddObjectType AirflowNetworkMultiZoneComponentHorizontalOpening::iddObjectType() {
  return IddObjectType(IddObjectType::OS_AirflowNetworkMultiZoneComponentHorizontalOpening);
}

double AirflowNetworkMultiZoneComponentHorizontalOpening::airMassFlowCoefficientWhenOpeningisClosed() const {
  return getImpl<detail::AirflowNetworkMultiZoneComponentHorizontalOpening_Impl>()->airMassFlowCoefficientWhenOpeningisClosed();
}

double AirflowNetworkMultiZoneComponentHorizontalOpening::airMassFlowExponentWhenOpeningisClosed() const {
  return getImpl<detail::AirflowNetworkMultiZoneComponentHorizontalOpening_Impl>()->airMassFlowExponentWhenOpeningisClosed();
}

bool AirflowNetworkMultiZoneComponentHorizontalOpening::isAirMassFlowExponentWhenOpeningisClosedDefaulted() const {
  return getImpl<detail::AirflowNetworkMultiZoneComponentHorizontalOpening_Impl>()->isAirMassFlowExponentWhenOpeningisClosedDefaulted();
}

double AirflowNetworkMultiZoneComponentHorizontalOpening::slopingPlaneAngle() const {
  return getImpl<detail::AirflowNetworkMultiZoneComponentHorizontalOpening_Impl>()->slopingPlaneAngle();
}

bool AirflowNetworkMultiZoneComponentHorizontalOpening::isSlopingPlaneAngleDefaulted() const {
  return getImpl<detail::AirflowNetworkMultiZoneComponentHorizontalOpening_Impl>()->isSlopingPlaneAngleDefaulted();
}

double AirflowNetworkMultiZoneComponentHorizontalOpening::dischargeCoefficient() const {
  return getImpl<detail::AirflowNetworkMultiZoneComponentHorizontalOpening_Impl>()->dischargeCoefficient();
}

bool AirflowNetworkMultiZoneComponentHorizontalOpening::setAirMassFlowCoefficientWhenOpeningisClosed(double airMassFlowCoefficientWhenOpeningisClosed) {
  return getImpl<detail::AirflowNetworkMultiZoneComponentHorizontalOpening_Impl>()->setAirMassFlowCoefficientWhenOpeningisClosed(airMassFlowCoefficientWhenOpeningisClosed);
}

bool AirflowNetworkMultiZoneComponentHorizontalOpening::setAirMassFlowExponentWhenOpeningisClosed(double airMassFlowExponentWhenOpeningisClosed) {
  return getImpl<detail::AirflowNetworkMultiZoneComponentHorizontalOpening_Impl>()->setAirMassFlowExponentWhenOpeningisClosed(airMassFlowExponentWhenOpeningisClosed);
}

void AirflowNetworkMultiZoneComponentHorizontalOpening::resetAirMassFlowExponentWhenOpeningisClosed() {
  getImpl<detail::AirflowNetworkMultiZoneComponentHorizontalOpening_Impl>()->resetAirMassFlowExponentWhenOpeningisClosed();
}

bool AirflowNetworkMultiZoneComponentHorizontalOpening::setSlopingPlaneAngle(double slopingPlaneAngle) {
  return getImpl<detail::AirflowNetworkMultiZoneComponentHorizontalOpening_Impl>()->setSlopingPlaneAngle(slopingPlaneAngle);
}

void AirflowNetworkMultiZoneComponentHorizontalOpening::resetSlopingPlaneAngle() {
  getImpl<detail::AirflowNetworkMultiZoneComponentHorizontalOpening_Impl>()->resetSlopingPlaneAngle();
}

bool AirflowNetworkMultiZoneComponentHorizontalOpening::setDischargeCoefficient(double dischargeCoefficient) {
  return getImpl<detail::AirflowNetworkMultiZoneComponentHorizontalOpening_Impl>()->setDischargeCoefficient(dischargeCoefficient);
}

/// @cond
AirflowNetworkMultiZoneComponentHorizontalOpening::AirflowNetworkMultiZoneComponentHorizontalOpening(std::shared_ptr<detail::AirflowNetworkMultiZoneComponentHorizontalOpening_Impl> impl)
  : ModelObject(impl)
{}
/// @endcond

} // model
} // openstudio

