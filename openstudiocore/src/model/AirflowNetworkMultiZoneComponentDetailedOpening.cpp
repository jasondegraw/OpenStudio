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

#include <model/AirflowNetworkMultiZoneComponentDetailedOpening.hpp>
#include <model/AirflowNetworkMultiZoneComponentDetailedOpening_Impl.hpp>

#include <utilities/idd/IddEnums.hxx>
#include <utilities/idd/IddFactory.hxx>
#include <utilities/idd/OS_AirflowNetwork_MultiZoneComponentDetailedOpening_FieldEnums.hxx>

#include <utilities/units/Unit.hpp>
#include "ModelExtensibleGroup.hpp"
#include <utilities/core/Assert.hpp>

namespace openstudio {
namespace model {

DetailedOpeningFactorData::DetailedOpeningFactorData(double openingFactor, double dischargeCoefficient, double widthFactor,
  double heightFactor, double startHeightFactor) : m_openingFactor(openingFactor), m_dischargeCoefficient(dischargeCoefficient),
  m_widthFactor(widthFactor), m_heightFactor(heightFactor), m_startHeightFactor(startHeightFactor)
{}

double DetailedOpeningFactorData::openingFactor() const
{
  return m_openingFactor;
}

double DetailedOpeningFactorData::dischargeCoefficient() const
{
  return m_dischargeCoefficient;
}

double DetailedOpeningFactorData::widthFactor() const
{
  return m_widthFactor;
};

double DetailedOpeningFactorData::heightFactor() const
{
  return m_heightFactor;
}

double DetailedOpeningFactorData::startHeightFactor() const
{
  return m_startHeightFactor;
}

bool DetailedOpeningFactorData::setOpeningFactor(double openingFactor)
{
  if (openingFactor >= 0.0 && openingFactor <= 1.0) {
    m_openingFactor = openingFactor;
    return true;
  }
  LOG_FREE(Warn, "openstudio.model.AirflowNetworkMultiZoneComponentDetailedOpening",
    "Opening factor must be greater than or equal to 0 and less than or equal to 1, value remains " << m_openingFactor);
  return false;
}

bool DetailedOpeningFactorData::setDischargeCoefficient(double dischargeCoefficient)
{
  if (dischargeCoefficient > 0.0 && dischargeCoefficient <= 1.0) {
    m_dischargeCoefficient = dischargeCoefficient;
    return true;
  }
  LOG_FREE(Warn, "openstudio.model.AirflowNetworkMultiZoneComponentDetailedOpening",
    "Discharge coefficient must be greater than 0 and less than or equal to 1, value remains " << m_dischargeCoefficient);
  return false;
}

bool DetailedOpeningFactorData::setWidthFactor(double widthFactor)
{
  if (widthFactor >= 0.0 && widthFactor <= 1.0) {
    m_widthFactor = widthFactor;
    return true;
  }
  LOG_FREE(Warn, "openstudio.model.AirflowNetworkMultiZoneComponentDetailedOpening",
    "Width factor must be greater than or equal to 0 and less than or equal to 1, value remains " << m_widthFactor);
  return false;
}

bool DetailedOpeningFactorData::setHeightFactor(double heightFactor)
{
  if (heightFactor >= 0.0 && heightFactor <= 1.0) {
    m_heightFactor = heightFactor;
    return true;
  }
  LOG_FREE(Warn, "openstudio.model.AirflowNetworkMultiZoneComponentDetailedOpening",
    "Height factor must be greater than or equal to 0 and less than or equal to 1, value remains " << m_heightFactor);
  return false;
}

bool DetailedOpeningFactorData::setStartHeightFactor(double startHeightFactor)
{
  if (startHeightFactor >= 0.0 && startHeightFactor <= 1.0) {
    m_startHeightFactor = startHeightFactor;
    return true;
  }
  LOG_FREE(Warn, "openstudio.model.AirflowNetworkMultiZoneComponentDetailedOpening",
    "Start height factor must be greater than or equal to 0 and less than or equal to 1, value remains " << m_startHeightFactor);
  return false;
}

namespace detail {

AirflowNetworkMultiZoneComponentDetailedOpening_Impl::AirflowNetworkMultiZoneComponentDetailedOpening_Impl(const IdfObject& idfObject,
  Model_Impl* model,
  bool keepHandle)
  : ModelObject_Impl(idfObject, model, keepHandle)
{
  OS_ASSERT(idfObject.iddObject().type() == AirflowNetworkMultiZoneComponentDetailedOpening::iddObjectType());
}

AirflowNetworkMultiZoneComponentDetailedOpening_Impl::AirflowNetworkMultiZoneComponentDetailedOpening_Impl(const openstudio::detail::WorkspaceObject_Impl& other,
  Model_Impl* model,
  bool keepHandle)
  : ModelObject_Impl(other, model, keepHandle)
{
  OS_ASSERT(other.iddObject().type() == AirflowNetworkMultiZoneComponentDetailedOpening::iddObjectType());
}

AirflowNetworkMultiZoneComponentDetailedOpening_Impl::AirflowNetworkMultiZoneComponentDetailedOpening_Impl(const AirflowNetworkMultiZoneComponentDetailedOpening_Impl& other,
  Model_Impl* model,
  bool keepHandle)
  : ModelObject_Impl(other, model, keepHandle)
{}

const std::vector<std::string>& AirflowNetworkMultiZoneComponentDetailedOpening_Impl::outputVariableNames() const
{
  static std::vector<std::string> result;
  if(result.empty()){
  }
  return result;
}

IddObjectType AirflowNetworkMultiZoneComponentDetailedOpening_Impl::iddObjectType() const
{
  return AirflowNetworkMultiZoneComponentDetailedOpening::iddObjectType();
}

double AirflowNetworkMultiZoneComponentDetailedOpening_Impl::airMassFlowCoefficientWhenOpeningisClosed() const
{
  boost::optional<double> value = getDouble(OS_AirflowNetwork_MultiZoneComponentDetailedOpeningFields::AirMassFlowCoefficientWhenOpeningisClosed, true);
  OS_ASSERT(value);
  return value.get();
}

double AirflowNetworkMultiZoneComponentDetailedOpening_Impl::airMassFlowExponentWhenOpeningisClosed() const
{
  boost::optional<double> value = getDouble(OS_AirflowNetwork_MultiZoneComponentDetailedOpeningFields::AirMassFlowExponentWhenOpeningisClosed, true);
  OS_ASSERT(value);
  return value.get();
}

bool AirflowNetworkMultiZoneComponentDetailedOpening_Impl::isAirMassFlowExponentWhenOpeningisClosedDefaulted() const
{
  return isEmpty(OS_AirflowNetwork_MultiZoneComponentDetailedOpeningFields::AirMassFlowExponentWhenOpeningisClosed);
}

std::string AirflowNetworkMultiZoneComponentDetailedOpening_Impl::typeofRectangularLargeVerticalOpening() const
{
  boost::optional<std::string> value = getString(OS_AirflowNetwork_MultiZoneComponentDetailedOpeningFields::TypeofRectangularLargeVerticalOpening, true);
  OS_ASSERT(value);
  return value.get();
}

bool AirflowNetworkMultiZoneComponentDetailedOpening_Impl::isTypeofRectangularLargeVerticalOpeningDefaulted() const
{
  return isEmpty(OS_AirflowNetwork_MultiZoneComponentDetailedOpeningFields::TypeofRectangularLargeVerticalOpening);
}

double AirflowNetworkMultiZoneComponentDetailedOpening_Impl::extraCrackLengthorHeightofPivotingAxis() const
{
  boost::optional<double> value = getDouble(OS_AirflowNetwork_MultiZoneComponentDetailedOpeningFields::ExtraCrackLengthorHeightofPivotingAxis, true);
  OS_ASSERT(value);
  return value.get();
}

bool AirflowNetworkMultiZoneComponentDetailedOpening_Impl::isExtraCrackLengthorHeightofPivotingAxisDefaulted() const
{
  return isEmpty(OS_AirflowNetwork_MultiZoneComponentDetailedOpeningFields::ExtraCrackLengthorHeightofPivotingAxis);
}

std::vector<DetailedOpeningFactorData> AirflowNetworkMultiZoneComponentDetailedOpening_Impl::openingFactors() const
{
  std::vector<DetailedOpeningFactorData> results;
  for (const ModelExtensibleGroup& group : castVector<ModelExtensibleGroup>(extensibleGroups())) {
    OptionalDouble openingFactor = group.getDouble(0);
    OptionalDouble dischargeCoefficient = group.getDouble(1);
    OptionalDouble widthFactor = group.getDouble(2);
    OptionalDouble heightFactor = group.getDouble(3);
    OptionalDouble startHeightFactor = group.getDouble(4);

    if (openingFactor && dischargeCoefficient && widthFactor && heightFactor && startHeightFactor) {
      results.push_back(DetailedOpeningFactorData(*openingFactor, *dischargeCoefficient, *widthFactor, *heightFactor,
        *startHeightFactor));
    } else {
      LOG(Error, "Could not read opening factor " << group.groupIndex() << " in " << briefDescription() << ".");
    }
  }
  return results;
}

bool AirflowNetworkMultiZoneComponentDetailedOpening_Impl::setAirMassFlowCoefficientWhenOpeningisClosed(double airMassFlowCoefficientWhenOpeningisClosed)
{
  bool result = setDouble(OS_AirflowNetwork_MultiZoneComponentDetailedOpeningFields::AirMassFlowCoefficientWhenOpeningisClosed, airMassFlowCoefficientWhenOpeningisClosed);
  return result;
}

bool AirflowNetworkMultiZoneComponentDetailedOpening_Impl::setAirMassFlowExponentWhenOpeningisClosed(double airMassFlowExponentWhenOpeningisClosed)
{
  bool result = setDouble(OS_AirflowNetwork_MultiZoneComponentDetailedOpeningFields::AirMassFlowExponentWhenOpeningisClosed, airMassFlowExponentWhenOpeningisClosed);
  return result;
}

void AirflowNetworkMultiZoneComponentDetailedOpening_Impl::resetAirMassFlowExponentWhenOpeningisClosed()
{
  bool result = setString(OS_AirflowNetwork_MultiZoneComponentDetailedOpeningFields::AirMassFlowExponentWhenOpeningisClosed, "");
  OS_ASSERT(result);
}

bool AirflowNetworkMultiZoneComponentDetailedOpening_Impl::setTypeofRectangularLargeVerticalOpening(std::string typeofRectangularLargeVerticalOpening)
{
  bool result = setString(OS_AirflowNetwork_MultiZoneComponentDetailedOpeningFields::TypeofRectangularLargeVerticalOpening, typeofRectangularLargeVerticalOpening);
  return result;
}

void AirflowNetworkMultiZoneComponentDetailedOpening_Impl::resetTypeofRectangularLargeVerticalOpening()
{
  bool result = setString(OS_AirflowNetwork_MultiZoneComponentDetailedOpeningFields::TypeofRectangularLargeVerticalOpening, "");
  OS_ASSERT(result);
}

bool AirflowNetworkMultiZoneComponentDetailedOpening_Impl::setExtraCrackLengthorHeightofPivotingAxis(double extraCrackLengthorHeightofPivotingAxis)
{
  bool result = setDouble(OS_AirflowNetwork_MultiZoneComponentDetailedOpeningFields::ExtraCrackLengthorHeightofPivotingAxis, extraCrackLengthorHeightofPivotingAxis);
  return result;
}

void AirflowNetworkMultiZoneComponentDetailedOpening_Impl::resetExtraCrackLengthorHeightofPivotingAxis()
{
  bool result = setString(OS_AirflowNetwork_MultiZoneComponentDetailedOpeningFields::ExtraCrackLengthorHeightofPivotingAxis, "");
  OS_ASSERT(result);
}

bool AirflowNetworkMultiZoneComponentDetailedOpening_Impl::setOpeningFactors(std::vector<DetailedOpeningFactorData>& factors)
{
  if (factors.size() < 2) {
    LOG(Error, "Insufficient data in opening factors vector, minimum number of factors is 2");
    return false;
  } else if (factors.size() > 4) {
    LOG(Error, "Additional data in opening factors vector, maximum number of factors is 4");
    return false;
  }
  if (factors[0].openingFactor() != 0.0) {
    LOG(Error, "First opening factor must be 0");
    return false;
  }
  if (factors.back().openingFactor() != 1.0) {
    LOG(Error, "Last opening factor must be 1");
    return false;
  }
  clearExtensibleGroups(false);
  for (auto factor : factors) {
    std::vector<std::string> values;
    values.push_back(toString(factor.openingFactor()));
    values.push_back(toString(factor.dischargeCoefficient()));
    values.push_back(toString(factor.widthFactor()));
    values.push_back(toString(factor.heightFactor()));
    values.push_back(toString(factor.startHeightFactor()));
    ModelExtensibleGroup group = pushExtensibleGroup(values, false).cast<ModelExtensibleGroup>();
    OS_ASSERT(!group.empty());
  }
  return true;
}

} // detail

AirflowNetworkMultiZoneComponentDetailedOpening::AirflowNetworkMultiZoneComponentDetailedOpening(const Model& model,
  double massFlowCoefficientWhenOpeningisClosed,
  double massFlowExponentWhenOpeningisClosed,
  std::string typeofRectangularLargeVerticalOpening,
  double extraCrackLengthorHeightofPivotingAxis,
  std::vector<DetailedOpeningFactorData>& openingFactors)
  : ModelObject(AirflowNetworkMultiZoneComponentDetailedOpening::iddObjectType(), model)
{
  OS_ASSERT(getImpl<detail::AirflowNetworkMultiZoneComponentDetailedOpening_Impl>());

  // OS_ASSERT(setHandle());
  OS_ASSERT(setAirMassFlowCoefficientWhenOpeningisClosed(massFlowCoefficientWhenOpeningisClosed));
  OS_ASSERT(setAirMassFlowExponentWhenOpeningisClosed(massFlowExponentWhenOpeningisClosed));
  OS_ASSERT(setTypeofRectangularLargeVerticalOpening(typeofRectangularLargeVerticalOpening));
  OS_ASSERT(setOpeningFactors(openingFactors));
}

IddObjectType AirflowNetworkMultiZoneComponentDetailedOpening::iddObjectType()
{
  return IddObjectType(IddObjectType::OS_AirflowNetwork_MultiZoneComponentDetailedOpening);
}

std::vector<std::string> AirflowNetworkMultiZoneComponentDetailedOpening::typeofRectangularLargeVerticalOpeningValues()
{
  return getIddKeyNames(IddFactory::instance().getObject(iddObjectType()).get(),
    OS_AirflowNetwork_MultiZoneComponentDetailedOpeningFields::TypeofRectangularLargeVerticalOpening);
}

double AirflowNetworkMultiZoneComponentDetailedOpening::airMassFlowCoefficientWhenOpeningisClosed() const
{
  return getImpl<detail::AirflowNetworkMultiZoneComponentDetailedOpening_Impl>()->airMassFlowCoefficientWhenOpeningisClosed();
}

double AirflowNetworkMultiZoneComponentDetailedOpening::airMassFlowExponentWhenOpeningisClosed() const
{
  return getImpl<detail::AirflowNetworkMultiZoneComponentDetailedOpening_Impl>()->airMassFlowExponentWhenOpeningisClosed();
}

bool AirflowNetworkMultiZoneComponentDetailedOpening::isAirMassFlowExponentWhenOpeningisClosedDefaulted() const
{
  return getImpl<detail::AirflowNetworkMultiZoneComponentDetailedOpening_Impl>()->isAirMassFlowExponentWhenOpeningisClosedDefaulted();
}

std::string AirflowNetworkMultiZoneComponentDetailedOpening::typeofRectangularLargeVerticalOpening() const
{
  return getImpl<detail::AirflowNetworkMultiZoneComponentDetailedOpening_Impl>()->typeofRectangularLargeVerticalOpening();
}

bool AirflowNetworkMultiZoneComponentDetailedOpening::isTypeofRectangularLargeVerticalOpeningDefaulted() const
{
  return getImpl<detail::AirflowNetworkMultiZoneComponentDetailedOpening_Impl>()->isTypeofRectangularLargeVerticalOpeningDefaulted();
}

double AirflowNetworkMultiZoneComponentDetailedOpening::extraCrackLengthorHeightofPivotingAxis() const
{
  return getImpl<detail::AirflowNetworkMultiZoneComponentDetailedOpening_Impl>()->extraCrackLengthorHeightofPivotingAxis();
}

bool AirflowNetworkMultiZoneComponentDetailedOpening::isExtraCrackLengthorHeightofPivotingAxisDefaulted() const
{
  return getImpl<detail::AirflowNetworkMultiZoneComponentDetailedOpening_Impl>()->isExtraCrackLengthorHeightofPivotingAxisDefaulted();
}

std::vector<DetailedOpeningFactorData> AirflowNetworkMultiZoneComponentDetailedOpening::openingFactors() const
{
  return getImpl<detail::AirflowNetworkMultiZoneComponentDetailedOpening_Impl>()->openingFactors();
}

bool AirflowNetworkMultiZoneComponentDetailedOpening::setAirMassFlowCoefficientWhenOpeningisClosed(double airMassFlowCoefficientWhenOpeningisClosed)
{
  return getImpl<detail::AirflowNetworkMultiZoneComponentDetailedOpening_Impl>()->setAirMassFlowCoefficientWhenOpeningisClosed(airMassFlowCoefficientWhenOpeningisClosed);
}

bool AirflowNetworkMultiZoneComponentDetailedOpening::setAirMassFlowExponentWhenOpeningisClosed(double airMassFlowExponentWhenOpeningisClosed)
{
  return getImpl<detail::AirflowNetworkMultiZoneComponentDetailedOpening_Impl>()->setAirMassFlowExponentWhenOpeningisClosed(airMassFlowExponentWhenOpeningisClosed);
}

void AirflowNetworkMultiZoneComponentDetailedOpening::resetAirMassFlowExponentWhenOpeningisClosed()
{
  getImpl<detail::AirflowNetworkMultiZoneComponentDetailedOpening_Impl>()->resetAirMassFlowExponentWhenOpeningisClosed();
}

bool AirflowNetworkMultiZoneComponentDetailedOpening::setTypeofRectangularLargeVerticalOpening(std::string typeofRectangularLargeVerticalOpening)
{
  return getImpl<detail::AirflowNetworkMultiZoneComponentDetailedOpening_Impl>()->setTypeofRectangularLargeVerticalOpening(typeofRectangularLargeVerticalOpening);
}

void AirflowNetworkMultiZoneComponentDetailedOpening::resetTypeofRectangularLargeVerticalOpening()
{
  getImpl<detail::AirflowNetworkMultiZoneComponentDetailedOpening_Impl>()->resetTypeofRectangularLargeVerticalOpening();
}

bool AirflowNetworkMultiZoneComponentDetailedOpening::setExtraCrackLengthorHeightofPivotingAxis(double extraCrackLengthorHeightofPivotingAxis)
{
  return getImpl<detail::AirflowNetworkMultiZoneComponentDetailedOpening_Impl>()->setExtraCrackLengthorHeightofPivotingAxis(extraCrackLengthorHeightofPivotingAxis);
}

void AirflowNetworkMultiZoneComponentDetailedOpening::resetExtraCrackLengthorHeightofPivotingAxis()
{
  getImpl<detail::AirflowNetworkMultiZoneComponentDetailedOpening_Impl>()->resetExtraCrackLengthorHeightofPivotingAxis();
}

bool AirflowNetworkMultiZoneComponentDetailedOpening::setOpeningFactors(std::vector<DetailedOpeningFactorData>& factors)
{
  return getImpl<detail::AirflowNetworkMultiZoneComponentDetailedOpening_Impl>()->setOpeningFactors(factors);
}

/// @cond
AirflowNetworkMultiZoneComponentDetailedOpening::AirflowNetworkMultiZoneComponentDetailedOpening(std::shared_ptr<detail::AirflowNetworkMultiZoneComponentDetailedOpening_Impl> impl)
  : ModelObject(impl)
{}
/// @endcond

} // model
} // openstudio

