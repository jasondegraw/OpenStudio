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

#include <model/AirflowNetworkMultiZoneComponentSimpleOpening.hpp>
#include <model/AirflowNetworkMultiZoneComponentSimpleOpening_Impl.hpp>

#include <utilities/idd/IddEnums.hxx>
#include <utilities/idd/OS_AirflowNetworkMultiZoneComponentSimpleOpening_FieldEnums.hxx>

#include <utilities/units/Unit.hpp>

#include <utilities/core/Assert.hpp>

namespace openstudio {
namespace model {

namespace detail {

  AirflowNetworkMultiZoneComponentSimpleOpening_Impl::AirflowNetworkMultiZoneComponentSimpleOpening_Impl(const IdfObject& idfObject,
                                                                                                         Model_Impl* model,
                                                                                                         bool keepHandle)
    : ModelObject_Impl(idfObject,model,keepHandle)
  {
    OS_ASSERT(idfObject.iddObject().type() == AirflowNetworkMultiZoneComponentSimpleOpening::iddObjectType());
  }

  AirflowNetworkMultiZoneComponentSimpleOpening_Impl::AirflowNetworkMultiZoneComponentSimpleOpening_Impl(const openstudio::detail::WorkspaceObject_Impl& other,
                                                                                                         Model_Impl* model,
                                                                                                         bool keepHandle)
    : ModelObject_Impl(other,model,keepHandle)
  {
    OS_ASSERT(other.iddObject().type() == AirflowNetworkMultiZoneComponentSimpleOpening::iddObjectType());
  }

  AirflowNetworkMultiZoneComponentSimpleOpening_Impl::AirflowNetworkMultiZoneComponentSimpleOpening_Impl(const AirflowNetworkMultiZoneComponentSimpleOpening_Impl& other,
                                                                                                         Model_Impl* model,
                                                                                                         bool keepHandle)
    : ModelObject_Impl(other,model,keepHandle)
  {}

  const std::vector<std::string>& AirflowNetworkMultiZoneComponentSimpleOpening_Impl::outputVariableNames() const
  {
    static std::vector<std::string> result;
    if (result.empty()){
    }
    return result;
  }

  IddObjectType AirflowNetworkMultiZoneComponentSimpleOpening_Impl::iddObjectType() const {
    return AirflowNetworkMultiZoneComponentSimpleOpening::iddObjectType();
  }

  double AirflowNetworkMultiZoneComponentSimpleOpening_Impl::airMassFlowCoefficientWhenOpeningisClosed() const {
    boost::optional<double> value = getDouble(OS_AirflowNetworkMultiZoneComponentSimpleOpeningFields::AirMassFlowCoefficientWhenOpeningisClosed,true);
    OS_ASSERT(value);
    return value.get();
  }

  double AirflowNetworkMultiZoneComponentSimpleOpening_Impl::airMassFlowExponentWhenOpeningisClosed() const {
    boost::optional<double> value = getDouble(OS_AirflowNetworkMultiZoneComponentSimpleOpeningFields::AirMassFlowExponentWhenOpeningisClosed,true);
    OS_ASSERT(value);
    return value.get();
  }

  bool AirflowNetworkMultiZoneComponentSimpleOpening_Impl::isAirMassFlowExponentWhenOpeningisClosedDefaulted() const {
    return isEmpty(OS_AirflowNetworkMultiZoneComponentSimpleOpeningFields::AirMassFlowExponentWhenOpeningisClosed);
  }

  double AirflowNetworkMultiZoneComponentSimpleOpening_Impl::minimumDensityDifferenceforTwoWayFlow() const {
    boost::optional<double> value = getDouble(OS_AirflowNetworkMultiZoneComponentSimpleOpeningFields::MinimumDensityDifferenceforTwoWayFlow,true);
    OS_ASSERT(value);
    return value.get();
  }

  double AirflowNetworkMultiZoneComponentSimpleOpening_Impl::dischargeCoefficient() const {
    boost::optional<double> value = getDouble(OS_AirflowNetworkMultiZoneComponentSimpleOpeningFields::DischargeCoefficient,true);
    OS_ASSERT(value);
    return value.get();
  }

  bool AirflowNetworkMultiZoneComponentSimpleOpening_Impl::setAirMassFlowCoefficientWhenOpeningisClosed(double airMassFlowCoefficientWhenOpeningisClosed) {
    bool result = setDouble(OS_AirflowNetworkMultiZoneComponentSimpleOpeningFields::AirMassFlowCoefficientWhenOpeningisClosed, airMassFlowCoefficientWhenOpeningisClosed);
    return result;
  }

  bool AirflowNetworkMultiZoneComponentSimpleOpening_Impl::setAirMassFlowExponentWhenOpeningisClosed(double airMassFlowExponentWhenOpeningisClosed) {
    bool result = setDouble(OS_AirflowNetworkMultiZoneComponentSimpleOpeningFields::AirMassFlowExponentWhenOpeningisClosed, airMassFlowExponentWhenOpeningisClosed);
    return result;
  }

  void AirflowNetworkMultiZoneComponentSimpleOpening_Impl::resetAirMassFlowExponentWhenOpeningisClosed() {
    bool result = setString(OS_AirflowNetworkMultiZoneComponentSimpleOpeningFields::AirMassFlowExponentWhenOpeningisClosed, "");
    OS_ASSERT(result);
  }

  bool AirflowNetworkMultiZoneComponentSimpleOpening_Impl::setMinimumDensityDifferenceforTwoWayFlow(double minimumDensityDifferenceforTwoWayFlow) {
    bool result = setDouble(OS_AirflowNetworkMultiZoneComponentSimpleOpeningFields::MinimumDensityDifferenceforTwoWayFlow, minimumDensityDifferenceforTwoWayFlow);
    return result;
  }

  bool AirflowNetworkMultiZoneComponentSimpleOpening_Impl::setDischargeCoefficient(double dischargeCoefficient) {
    bool result = setDouble(OS_AirflowNetworkMultiZoneComponentSimpleOpeningFields::DischargeCoefficient, dischargeCoefficient);
    return result;
  }

} // detail

AirflowNetworkMultiZoneComponentSimpleOpening::AirflowNetworkMultiZoneComponentSimpleOpening(const Model& model,
  double massFlowCoefficientWhenOpeningisClosed,
  double minimumDensityDifferenceforTwoWayFlow,
  double dischargeCoefficient)
  : ModelObject(AirflowNetworkMultiZoneComponentSimpleOpening::iddObjectType(),model)
{
  OS_ASSERT(getImpl<detail::AirflowNetworkMultiZoneComponentSimpleOpening_Impl>());

  // TODO: Appropriately handle the following required object-list fields.
  //OS_ASSERT(setHandle());
  OS_ASSERT(setAirMassFlowCoefficientWhenOpeningisClosed(massFlowCoefficientWhenOpeningisClosed));
  OS_ASSERT(setMinimumDensityDifferenceforTwoWayFlow(minimumDensityDifferenceforTwoWayFlow));
  OS_ASSERT(setDischargeCoefficient(dischargeCoefficient));
}

AirflowNetworkMultiZoneComponentSimpleOpening::AirflowNetworkMultiZoneComponentSimpleOpening(const Model& model,
  double massFlowCoefficientWhenOpeningisClosed,
  double massFlowExponentWhenOpeningisClosed,
  double minimumDensityDifferenceforTwoWayFlow,
  double dischargeCoefficient)
  : ModelObject(AirflowNetworkMultiZoneComponentSimpleOpening::iddObjectType(), model)
{
  OS_ASSERT(getImpl<detail::AirflowNetworkMultiZoneComponentSimpleOpening_Impl>());

  // TODO: Appropriately handle the following required object-list fields.
  //OS_ASSERT(setHandle());
  OS_ASSERT(setAirMassFlowCoefficientWhenOpeningisClosed(massFlowCoefficientWhenOpeningisClosed));
  OS_ASSERT(setAirMassFlowExponentWhenOpeningisClosed(massFlowExponentWhenOpeningisClosed));
  OS_ASSERT(setMinimumDensityDifferenceforTwoWayFlow(minimumDensityDifferenceforTwoWayFlow));
  OS_ASSERT(setDischargeCoefficient(dischargeCoefficient));
}


IddObjectType AirflowNetworkMultiZoneComponentSimpleOpening::iddObjectType() {
  return IddObjectType(IddObjectType::OS_AirflowNetworkMultiZoneComponentSimpleOpening);
}

double AirflowNetworkMultiZoneComponentSimpleOpening::airMassFlowCoefficientWhenOpeningisClosed() const {
  return getImpl<detail::AirflowNetworkMultiZoneComponentSimpleOpening_Impl>()->airMassFlowCoefficientWhenOpeningisClosed();
}

double AirflowNetworkMultiZoneComponentSimpleOpening::airMassFlowExponentWhenOpeningisClosed() const {
  return getImpl<detail::AirflowNetworkMultiZoneComponentSimpleOpening_Impl>()->airMassFlowExponentWhenOpeningisClosed();
}

bool AirflowNetworkMultiZoneComponentSimpleOpening::isAirMassFlowExponentWhenOpeningisClosedDefaulted() const {
  return getImpl<detail::AirflowNetworkMultiZoneComponentSimpleOpening_Impl>()->isAirMassFlowExponentWhenOpeningisClosedDefaulted();
}

double AirflowNetworkMultiZoneComponentSimpleOpening::minimumDensityDifferenceforTwoWayFlow() const {
  return getImpl<detail::AirflowNetworkMultiZoneComponentSimpleOpening_Impl>()->minimumDensityDifferenceforTwoWayFlow();
}

double AirflowNetworkMultiZoneComponentSimpleOpening::dischargeCoefficient() const {
  return getImpl<detail::AirflowNetworkMultiZoneComponentSimpleOpening_Impl>()->dischargeCoefficient();
}

bool AirflowNetworkMultiZoneComponentSimpleOpening::setAirMassFlowCoefficientWhenOpeningisClosed(double airMassFlowCoefficientWhenOpeningisClosed) {
  return getImpl<detail::AirflowNetworkMultiZoneComponentSimpleOpening_Impl>()->setAirMassFlowCoefficientWhenOpeningisClosed(airMassFlowCoefficientWhenOpeningisClosed);
}

bool AirflowNetworkMultiZoneComponentSimpleOpening::setAirMassFlowExponentWhenOpeningisClosed(double airMassFlowExponentWhenOpeningisClosed) {
  return getImpl<detail::AirflowNetworkMultiZoneComponentSimpleOpening_Impl>()->setAirMassFlowExponentWhenOpeningisClosed(airMassFlowExponentWhenOpeningisClosed);
}

void AirflowNetworkMultiZoneComponentSimpleOpening::resetAirMassFlowExponentWhenOpeningisClosed() {
  getImpl<detail::AirflowNetworkMultiZoneComponentSimpleOpening_Impl>()->resetAirMassFlowExponentWhenOpeningisClosed();
}

bool AirflowNetworkMultiZoneComponentSimpleOpening::setMinimumDensityDifferenceforTwoWayFlow(double minimumDensityDifferenceforTwoWayFlow) {
  return getImpl<detail::AirflowNetworkMultiZoneComponentSimpleOpening_Impl>()->setMinimumDensityDifferenceforTwoWayFlow(minimumDensityDifferenceforTwoWayFlow);
}

bool AirflowNetworkMultiZoneComponentSimpleOpening::setDischargeCoefficient(double dischargeCoefficient) {
  return getImpl<detail::AirflowNetworkMultiZoneComponentSimpleOpening_Impl>()->setDischargeCoefficient(dischargeCoefficient);
}

/// @cond
AirflowNetworkMultiZoneComponentSimpleOpening::AirflowNetworkMultiZoneComponentSimpleOpening(std::shared_ptr<detail::AirflowNetworkMultiZoneComponentSimpleOpening_Impl> impl)
  : ModelObject(impl)
{}
/// @endcond

} // model
} // openstudio

