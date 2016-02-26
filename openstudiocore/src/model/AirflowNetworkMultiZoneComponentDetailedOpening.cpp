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

#include <model/AirflowNetworkMultiZoneComponentDetailedOpening.hpp>
#include <model/AirflowNetworkMultiZoneComponentDetailedOpening_Impl.hpp>

#include <utilities/idd/IddEnums.hxx>
#include <utilities/idd/IddFactory.hxx>
#include <utilities/idd/OS_AirflowNetworkMultiZoneComponentDetailedOpening_FieldEnums.hxx>

#include <utilities/units/Unit.hpp>

#include <utilities/core/Assert.hpp>

namespace openstudio {
namespace model {

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
  boost::optional<double> value = getDouble(OS_AirflowNetworkMultiZoneComponentDetailedOpeningFields::AirMassFlowCoefficientWhenOpeningisClosed, true);
  OS_ASSERT(value);
  return value.get();
}

double AirflowNetworkMultiZoneComponentDetailedOpening_Impl::airMassFlowExponentWhenOpeningisClosed() const
{
  boost::optional<double> value = getDouble(OS_AirflowNetworkMultiZoneComponentDetailedOpeningFields::AirMassFlowExponentWhenOpeningisClosed, true);
  OS_ASSERT(value);
  return value.get();
}

bool AirflowNetworkMultiZoneComponentDetailedOpening_Impl::isAirMassFlowExponentWhenOpeningisClosedDefaulted() const
{
  return isEmpty(OS_AirflowNetworkMultiZoneComponentDetailedOpeningFields::AirMassFlowExponentWhenOpeningisClosed);
}

std::string AirflowNetworkMultiZoneComponentDetailedOpening_Impl::typeofRectangulerLargeVerticalOpening() const
{
  boost::optional<std::string> value = getString(OS_AirflowNetworkMultiZoneComponentDetailedOpeningFields::TypeofRectangulerLargeVerticalOpening, true);
  OS_ASSERT(value);
  return value.get();
}

bool AirflowNetworkMultiZoneComponentDetailedOpening_Impl::isTypeofRectangulerLargeVerticalOpeningDefaulted() const
{
  return isEmpty(OS_AirflowNetworkMultiZoneComponentDetailedOpeningFields::TypeofRectangulerLargeVerticalOpening);
}

double AirflowNetworkMultiZoneComponentDetailedOpening_Impl::extraCrackLengthorHeightofPivotingAxis() const
{
  boost::optional<double> value = getDouble(OS_AirflowNetworkMultiZoneComponentDetailedOpeningFields::ExtraCrackLengthorHeightofPivotingAxis, true);
  OS_ASSERT(value);
  return value.get();
}

bool AirflowNetworkMultiZoneComponentDetailedOpening_Impl::isExtraCrackLengthorHeightofPivotingAxisDefaulted() const
{
  return isEmpty(OS_AirflowNetworkMultiZoneComponentDetailedOpeningFields::ExtraCrackLengthorHeightofPivotingAxis);
}

int AirflowNetworkMultiZoneComponentDetailedOpening_Impl::numberofSetsofOpeningFactorData() const
{
  boost::optional<int> value = getInt(OS_AirflowNetworkMultiZoneComponentDetailedOpeningFields::NumberofSetsofOpeningFactorData, true);
  OS_ASSERT(value);
  return value.get();
}

double AirflowNetworkMultiZoneComponentDetailedOpening_Impl::openingFactor1() const
{
  boost::optional<double> value = getDouble(OS_AirflowNetworkMultiZoneComponentDetailedOpeningFields::OpeningFactor1, true);
  OS_ASSERT(value);
  return value.get();
}

bool AirflowNetworkMultiZoneComponentDetailedOpening_Impl::isOpeningFactor1Defaulted() const
{
  return isEmpty(OS_AirflowNetworkMultiZoneComponentDetailedOpeningFields::OpeningFactor1);
}

double AirflowNetworkMultiZoneComponentDetailedOpening_Impl::dischargeCoefficientforOpeningFactor1() const
{
  boost::optional<double> value = getDouble(OS_AirflowNetworkMultiZoneComponentDetailedOpeningFields::DischargeCoefficientforOpeningFactor1, true);
  OS_ASSERT(value);
  return value.get();
}

bool AirflowNetworkMultiZoneComponentDetailedOpening_Impl::isDischargeCoefficientforOpeningFactor1Defaulted() const
{
  return isEmpty(OS_AirflowNetworkMultiZoneComponentDetailedOpeningFields::DischargeCoefficientforOpeningFactor1);
}

double AirflowNetworkMultiZoneComponentDetailedOpening_Impl::widthFactorforOpeningFactor1() const
{
  boost::optional<double> value = getDouble(OS_AirflowNetworkMultiZoneComponentDetailedOpeningFields::WidthFactorforOpeningFactor1, true);
  OS_ASSERT(value);
  return value.get();
}

bool AirflowNetworkMultiZoneComponentDetailedOpening_Impl::isWidthFactorforOpeningFactor1Defaulted() const
{
  return isEmpty(OS_AirflowNetworkMultiZoneComponentDetailedOpeningFields::WidthFactorforOpeningFactor1);
}

double AirflowNetworkMultiZoneComponentDetailedOpening_Impl::heightFactorforOpeningFactor1() const
{
  boost::optional<double> value = getDouble(OS_AirflowNetworkMultiZoneComponentDetailedOpeningFields::HeightFactorforOpeningFactor1, true);
  OS_ASSERT(value);
  return value.get();
}

bool AirflowNetworkMultiZoneComponentDetailedOpening_Impl::isHeightFactorforOpeningFactor1Defaulted() const
{
  return isEmpty(OS_AirflowNetworkMultiZoneComponentDetailedOpeningFields::HeightFactorforOpeningFactor1);
}

double AirflowNetworkMultiZoneComponentDetailedOpening_Impl::startHeightFactorforOpeningFactor1() const
{
  boost::optional<double> value = getDouble(OS_AirflowNetworkMultiZoneComponentDetailedOpeningFields::StartHeightFactorforOpeningFactor1, true);
  OS_ASSERT(value);
  return value.get();
}

bool AirflowNetworkMultiZoneComponentDetailedOpening_Impl::isStartHeightFactorforOpeningFactor1Defaulted() const
{
  return isEmpty(OS_AirflowNetworkMultiZoneComponentDetailedOpeningFields::StartHeightFactorforOpeningFactor1);
}

double AirflowNetworkMultiZoneComponentDetailedOpening_Impl::openingFactor2() const
{
  boost::optional<double> value = getDouble(OS_AirflowNetworkMultiZoneComponentDetailedOpeningFields::OpeningFactor2, true);
  OS_ASSERT(value);
  return value.get();
}

double AirflowNetworkMultiZoneComponentDetailedOpening_Impl::dischargeCoefficientforOpeningFactor2() const
{
  boost::optional<double> value = getDouble(OS_AirflowNetworkMultiZoneComponentDetailedOpeningFields::DischargeCoefficientforOpeningFactor2, true);
  OS_ASSERT(value);
  return value.get();
}

bool AirflowNetworkMultiZoneComponentDetailedOpening_Impl::isDischargeCoefficientforOpeningFactor2Defaulted() const
{
  return isEmpty(OS_AirflowNetworkMultiZoneComponentDetailedOpeningFields::DischargeCoefficientforOpeningFactor2);
}

double AirflowNetworkMultiZoneComponentDetailedOpening_Impl::widthFactorforOpeningFactor2() const
{
  boost::optional<double> value = getDouble(OS_AirflowNetworkMultiZoneComponentDetailedOpeningFields::WidthFactorforOpeningFactor2, true);
  OS_ASSERT(value);
  return value.get();
}

bool AirflowNetworkMultiZoneComponentDetailedOpening_Impl::isWidthFactorforOpeningFactor2Defaulted() const
{
  return isEmpty(OS_AirflowNetworkMultiZoneComponentDetailedOpeningFields::WidthFactorforOpeningFactor2);
}

double AirflowNetworkMultiZoneComponentDetailedOpening_Impl::heightFactorforOpeningFactor2() const
{
  boost::optional<double> value = getDouble(OS_AirflowNetworkMultiZoneComponentDetailedOpeningFields::HeightFactorforOpeningFactor2, true);
  OS_ASSERT(value);
  return value.get();
}

bool AirflowNetworkMultiZoneComponentDetailedOpening_Impl::isHeightFactorforOpeningFactor2Defaulted() const
{
  return isEmpty(OS_AirflowNetworkMultiZoneComponentDetailedOpeningFields::HeightFactorforOpeningFactor2);
}

double AirflowNetworkMultiZoneComponentDetailedOpening_Impl::startHeightFactorforOpeningFactor2() const
{
  boost::optional<double> value = getDouble(OS_AirflowNetworkMultiZoneComponentDetailedOpeningFields::StartHeightFactorforOpeningFactor2, true);
  OS_ASSERT(value);
  return value.get();
}

bool AirflowNetworkMultiZoneComponentDetailedOpening_Impl::isStartHeightFactorforOpeningFactor2Defaulted() const
{
  return isEmpty(OS_AirflowNetworkMultiZoneComponentDetailedOpeningFields::StartHeightFactorforOpeningFactor2);
}

boost::optional<double> AirflowNetworkMultiZoneComponentDetailedOpening_Impl::openingFactor3() const
{
  return getDouble(OS_AirflowNetworkMultiZoneComponentDetailedOpeningFields::OpeningFactor3, true);
}

double AirflowNetworkMultiZoneComponentDetailedOpening_Impl::dischargeCoefficientforOpeningFactor3() const
{
  boost::optional<double> value = getDouble(OS_AirflowNetworkMultiZoneComponentDetailedOpeningFields::DischargeCoefficientforOpeningFactor3, true);
  OS_ASSERT(value);
  return value.get();
}

bool AirflowNetworkMultiZoneComponentDetailedOpening_Impl::isDischargeCoefficientforOpeningFactor3Defaulted() const
{
  return isEmpty(OS_AirflowNetworkMultiZoneComponentDetailedOpeningFields::DischargeCoefficientforOpeningFactor3);
}

double AirflowNetworkMultiZoneComponentDetailedOpening_Impl::widthFactorforOpeningFactor3() const
{
  boost::optional<double> value = getDouble(OS_AirflowNetworkMultiZoneComponentDetailedOpeningFields::WidthFactorforOpeningFactor3, true);
  OS_ASSERT(value);
  return value.get();
}

bool AirflowNetworkMultiZoneComponentDetailedOpening_Impl::isWidthFactorforOpeningFactor3Defaulted() const
{
  return isEmpty(OS_AirflowNetworkMultiZoneComponentDetailedOpeningFields::WidthFactorforOpeningFactor3);
}

double AirflowNetworkMultiZoneComponentDetailedOpening_Impl::heightFactorforOpeningFactor3() const
{
  boost::optional<double> value = getDouble(OS_AirflowNetworkMultiZoneComponentDetailedOpeningFields::HeightFactorforOpeningFactor3, true);
  OS_ASSERT(value);
  return value.get();
}

bool AirflowNetworkMultiZoneComponentDetailedOpening_Impl::isHeightFactorforOpeningFactor3Defaulted() const
{
  return isEmpty(OS_AirflowNetworkMultiZoneComponentDetailedOpeningFields::HeightFactorforOpeningFactor3);
}

double AirflowNetworkMultiZoneComponentDetailedOpening_Impl::startHeightFactorforOpeningFactor3() const
{
  boost::optional<double> value = getDouble(OS_AirflowNetworkMultiZoneComponentDetailedOpeningFields::StartHeightFactorforOpeningFactor3, true);
  OS_ASSERT(value);
  return value.get();
}

bool AirflowNetworkMultiZoneComponentDetailedOpening_Impl::isStartHeightFactorforOpeningFactor3Defaulted() const
{
  return isEmpty(OS_AirflowNetworkMultiZoneComponentDetailedOpeningFields::StartHeightFactorforOpeningFactor3);
}

boost::optional<double> AirflowNetworkMultiZoneComponentDetailedOpening_Impl::openingFactor4() const
{
  return getDouble(OS_AirflowNetworkMultiZoneComponentDetailedOpeningFields::OpeningFactor4, true);
}

double AirflowNetworkMultiZoneComponentDetailedOpening_Impl::dischargeCoefficientforOpeningFactor4() const
{
  boost::optional<double> value = getDouble(OS_AirflowNetworkMultiZoneComponentDetailedOpeningFields::DischargeCoefficientforOpeningFactor4, true);
  OS_ASSERT(value);
  return value.get();
}

bool AirflowNetworkMultiZoneComponentDetailedOpening_Impl::isDischargeCoefficientforOpeningFactor4Defaulted() const
{
  return isEmpty(OS_AirflowNetworkMultiZoneComponentDetailedOpeningFields::DischargeCoefficientforOpeningFactor4);
}

double AirflowNetworkMultiZoneComponentDetailedOpening_Impl::widthFactorforOpeningFactor4() const
{
  boost::optional<double> value = getDouble(OS_AirflowNetworkMultiZoneComponentDetailedOpeningFields::WidthFactorforOpeningFactor4, true);
  OS_ASSERT(value);
  return value.get();
}

bool AirflowNetworkMultiZoneComponentDetailedOpening_Impl::isWidthFactorforOpeningFactor4Defaulted() const
{
  return isEmpty(OS_AirflowNetworkMultiZoneComponentDetailedOpeningFields::WidthFactorforOpeningFactor4);
}

double AirflowNetworkMultiZoneComponentDetailedOpening_Impl::heightFactorforOpeningFactor4() const
{
  boost::optional<double> value = getDouble(OS_AirflowNetworkMultiZoneComponentDetailedOpeningFields::HeightFactorforOpeningFactor4, true);
  OS_ASSERT(value);
  return value.get();
}

bool AirflowNetworkMultiZoneComponentDetailedOpening_Impl::isHeightFactorforOpeningFactor4Defaulted() const
{
  return isEmpty(OS_AirflowNetworkMultiZoneComponentDetailedOpeningFields::HeightFactorforOpeningFactor4);
}

double AirflowNetworkMultiZoneComponentDetailedOpening_Impl::startHeightFactorforOpeningFactor4() const
{
  boost::optional<double> value = getDouble(OS_AirflowNetworkMultiZoneComponentDetailedOpeningFields::StartHeightFactorforOpeningFactor4, true);
  OS_ASSERT(value);
  return value.get();
}

bool AirflowNetworkMultiZoneComponentDetailedOpening_Impl::isStartHeightFactorforOpeningFactor4Defaulted() const
{
  return isEmpty(OS_AirflowNetworkMultiZoneComponentDetailedOpeningFields::StartHeightFactorforOpeningFactor4);
}

bool AirflowNetworkMultiZoneComponentDetailedOpening_Impl::setAirMassFlowCoefficientWhenOpeningisClosed(double airMassFlowCoefficientWhenOpeningisClosed)
{
  bool result = setDouble(OS_AirflowNetworkMultiZoneComponentDetailedOpeningFields::AirMassFlowCoefficientWhenOpeningisClosed, airMassFlowCoefficientWhenOpeningisClosed);
  return result;
}

bool AirflowNetworkMultiZoneComponentDetailedOpening_Impl::setAirMassFlowExponentWhenOpeningisClosed(double airMassFlowExponentWhenOpeningisClosed)
{
  bool result = setDouble(OS_AirflowNetworkMultiZoneComponentDetailedOpeningFields::AirMassFlowExponentWhenOpeningisClosed, airMassFlowExponentWhenOpeningisClosed);
  return result;
}

void AirflowNetworkMultiZoneComponentDetailedOpening_Impl::resetAirMassFlowExponentWhenOpeningisClosed()
{
  bool result = setString(OS_AirflowNetworkMultiZoneComponentDetailedOpeningFields::AirMassFlowExponentWhenOpeningisClosed, "");
  OS_ASSERT(result);
}

bool AirflowNetworkMultiZoneComponentDetailedOpening_Impl::setTypeofRectangulerLargeVerticalOpening(std::string typeofRectangulerLargeVerticalOpening)
{
  bool result = setString(OS_AirflowNetworkMultiZoneComponentDetailedOpeningFields::TypeofRectangulerLargeVerticalOpening, typeofRectangulerLargeVerticalOpening);
  return result;
}

void AirflowNetworkMultiZoneComponentDetailedOpening_Impl::resetTypeofRectangulerLargeVerticalOpening()
{
  bool result = setString(OS_AirflowNetworkMultiZoneComponentDetailedOpeningFields::TypeofRectangulerLargeVerticalOpening, "");
  OS_ASSERT(result);
}

bool AirflowNetworkMultiZoneComponentDetailedOpening_Impl::setExtraCrackLengthorHeightofPivotingAxis(double extraCrackLengthorHeightofPivotingAxis)
{
  bool result = setDouble(OS_AirflowNetworkMultiZoneComponentDetailedOpeningFields::ExtraCrackLengthorHeightofPivotingAxis, extraCrackLengthorHeightofPivotingAxis);
  return result;
}

void AirflowNetworkMultiZoneComponentDetailedOpening_Impl::resetExtraCrackLengthorHeightofPivotingAxis()
{
  bool result = setString(OS_AirflowNetworkMultiZoneComponentDetailedOpeningFields::ExtraCrackLengthorHeightofPivotingAxis, "");
  OS_ASSERT(result);
}

bool AirflowNetworkMultiZoneComponentDetailedOpening_Impl::setNumberofSetsofOpeningFactorData(int numberofSetsofOpeningFactorData)
{
  bool result = setInt(OS_AirflowNetworkMultiZoneComponentDetailedOpeningFields::NumberofSetsofOpeningFactorData, numberofSetsofOpeningFactorData);
  return result;
}

bool AirflowNetworkMultiZoneComponentDetailedOpening_Impl::setOpeningFactor1(double openingFactor1)
{
  bool result = setDouble(OS_AirflowNetworkMultiZoneComponentDetailedOpeningFields::OpeningFactor1, openingFactor1);
  return result;
}

void AirflowNetworkMultiZoneComponentDetailedOpening_Impl::resetOpeningFactor1()
{
  bool result = setString(OS_AirflowNetworkMultiZoneComponentDetailedOpeningFields::OpeningFactor1, "");
  OS_ASSERT(result);
}

bool AirflowNetworkMultiZoneComponentDetailedOpening_Impl::setDischargeCoefficientforOpeningFactor1(double dischargeCoefficientforOpeningFactor1)
{
  bool result = setDouble(OS_AirflowNetworkMultiZoneComponentDetailedOpeningFields::DischargeCoefficientforOpeningFactor1, dischargeCoefficientforOpeningFactor1);
  return result;
}

void AirflowNetworkMultiZoneComponentDetailedOpening_Impl::resetDischargeCoefficientforOpeningFactor1()
{
  bool result = setString(OS_AirflowNetworkMultiZoneComponentDetailedOpeningFields::DischargeCoefficientforOpeningFactor1, "");
  OS_ASSERT(result);
}

bool AirflowNetworkMultiZoneComponentDetailedOpening_Impl::setWidthFactorforOpeningFactor1(double widthFactorforOpeningFactor1)
{
  bool result = setDouble(OS_AirflowNetworkMultiZoneComponentDetailedOpeningFields::WidthFactorforOpeningFactor1, widthFactorforOpeningFactor1);
  return result;
}

void AirflowNetworkMultiZoneComponentDetailedOpening_Impl::resetWidthFactorforOpeningFactor1()
{
  bool result = setString(OS_AirflowNetworkMultiZoneComponentDetailedOpeningFields::WidthFactorforOpeningFactor1, "");
  OS_ASSERT(result);
}

bool AirflowNetworkMultiZoneComponentDetailedOpening_Impl::setHeightFactorforOpeningFactor1(double heightFactorforOpeningFactor1)
{
  bool result = setDouble(OS_AirflowNetworkMultiZoneComponentDetailedOpeningFields::HeightFactorforOpeningFactor1, heightFactorforOpeningFactor1);
  return result;
}

void AirflowNetworkMultiZoneComponentDetailedOpening_Impl::resetHeightFactorforOpeningFactor1()
{
  bool result = setString(OS_AirflowNetworkMultiZoneComponentDetailedOpeningFields::HeightFactorforOpeningFactor1, "");
  OS_ASSERT(result);
}

bool AirflowNetworkMultiZoneComponentDetailedOpening_Impl::setStartHeightFactorforOpeningFactor1(double startHeightFactorforOpeningFactor1)
{
  bool result = setDouble(OS_AirflowNetworkMultiZoneComponentDetailedOpeningFields::StartHeightFactorforOpeningFactor1, startHeightFactorforOpeningFactor1);
  return result;
}

void AirflowNetworkMultiZoneComponentDetailedOpening_Impl::resetStartHeightFactorforOpeningFactor1()
{
  bool result = setString(OS_AirflowNetworkMultiZoneComponentDetailedOpeningFields::StartHeightFactorforOpeningFactor1, "");
  OS_ASSERT(result);
}

bool AirflowNetworkMultiZoneComponentDetailedOpening_Impl::setOpeningFactor2(double openingFactor2)
{
  bool result = setDouble(OS_AirflowNetworkMultiZoneComponentDetailedOpeningFields::OpeningFactor2, openingFactor2);
  return result;
}

bool AirflowNetworkMultiZoneComponentDetailedOpening_Impl::setDischargeCoefficientforOpeningFactor2(double dischargeCoefficientforOpeningFactor2)
{
  bool result = setDouble(OS_AirflowNetworkMultiZoneComponentDetailedOpeningFields::DischargeCoefficientforOpeningFactor2, dischargeCoefficientforOpeningFactor2);
  return result;
}

void AirflowNetworkMultiZoneComponentDetailedOpening_Impl::resetDischargeCoefficientforOpeningFactor2()
{
  bool result = setString(OS_AirflowNetworkMultiZoneComponentDetailedOpeningFields::DischargeCoefficientforOpeningFactor2, "");
  OS_ASSERT(result);
}

bool AirflowNetworkMultiZoneComponentDetailedOpening_Impl::setWidthFactorforOpeningFactor2(double widthFactorforOpeningFactor2)
{
  bool result = setDouble(OS_AirflowNetworkMultiZoneComponentDetailedOpeningFields::WidthFactorforOpeningFactor2, widthFactorforOpeningFactor2);
  return result;
}

void AirflowNetworkMultiZoneComponentDetailedOpening_Impl::resetWidthFactorforOpeningFactor2()
{
  bool result = setString(OS_AirflowNetworkMultiZoneComponentDetailedOpeningFields::WidthFactorforOpeningFactor2, "");
  OS_ASSERT(result);
}

bool AirflowNetworkMultiZoneComponentDetailedOpening_Impl::setHeightFactorforOpeningFactor2(double heightFactorforOpeningFactor2)
{
  bool result = setDouble(OS_AirflowNetworkMultiZoneComponentDetailedOpeningFields::HeightFactorforOpeningFactor2, heightFactorforOpeningFactor2);
  return result;
}

void AirflowNetworkMultiZoneComponentDetailedOpening_Impl::resetHeightFactorforOpeningFactor2()
{
  bool result = setString(OS_AirflowNetworkMultiZoneComponentDetailedOpeningFields::HeightFactorforOpeningFactor2, "");
  OS_ASSERT(result);
}

bool AirflowNetworkMultiZoneComponentDetailedOpening_Impl::setStartHeightFactorforOpeningFactor2(double startHeightFactorforOpeningFactor2)
{
  bool result = setDouble(OS_AirflowNetworkMultiZoneComponentDetailedOpeningFields::StartHeightFactorforOpeningFactor2, startHeightFactorforOpeningFactor2);
  return result;
}

void AirflowNetworkMultiZoneComponentDetailedOpening_Impl::resetStartHeightFactorforOpeningFactor2()
{
  bool result = setString(OS_AirflowNetworkMultiZoneComponentDetailedOpeningFields::StartHeightFactorforOpeningFactor2, "");
  OS_ASSERT(result);
}

bool AirflowNetworkMultiZoneComponentDetailedOpening_Impl::setOpeningFactor3(boost::optional<double> openingFactor3)
{
  bool result(false);
  if(openingFactor3) {
    result = setDouble(OS_AirflowNetworkMultiZoneComponentDetailedOpeningFields::OpeningFactor3, openingFactor3.get());
  } else {
    resetOpeningFactor3();
    result = true;
  }
  return result;
}

void AirflowNetworkMultiZoneComponentDetailedOpening_Impl::resetOpeningFactor3()
{
  bool result = setString(OS_AirflowNetworkMultiZoneComponentDetailedOpeningFields::OpeningFactor3, "");
  OS_ASSERT(result);
}

bool AirflowNetworkMultiZoneComponentDetailedOpening_Impl::setDischargeCoefficientforOpeningFactor3(double dischargeCoefficientforOpeningFactor3)
{
  bool result = setDouble(OS_AirflowNetworkMultiZoneComponentDetailedOpeningFields::DischargeCoefficientforOpeningFactor3, dischargeCoefficientforOpeningFactor3);
  return result;
}

void AirflowNetworkMultiZoneComponentDetailedOpening_Impl::resetDischargeCoefficientforOpeningFactor3()
{
  bool result = setString(OS_AirflowNetworkMultiZoneComponentDetailedOpeningFields::DischargeCoefficientforOpeningFactor3, "");
  OS_ASSERT(result);
}

bool AirflowNetworkMultiZoneComponentDetailedOpening_Impl::setWidthFactorforOpeningFactor3(double widthFactorforOpeningFactor3)
{
  bool result = setDouble(OS_AirflowNetworkMultiZoneComponentDetailedOpeningFields::WidthFactorforOpeningFactor3, widthFactorforOpeningFactor3);
  return result;
}

void AirflowNetworkMultiZoneComponentDetailedOpening_Impl::resetWidthFactorforOpeningFactor3()
{
  bool result = setString(OS_AirflowNetworkMultiZoneComponentDetailedOpeningFields::WidthFactorforOpeningFactor3, "");
  OS_ASSERT(result);
}

bool AirflowNetworkMultiZoneComponentDetailedOpening_Impl::setHeightFactorforOpeningFactor3(double heightFactorforOpeningFactor3)
{
  bool result = setDouble(OS_AirflowNetworkMultiZoneComponentDetailedOpeningFields::HeightFactorforOpeningFactor3, heightFactorforOpeningFactor3);
  return result;
}

void AirflowNetworkMultiZoneComponentDetailedOpening_Impl::resetHeightFactorforOpeningFactor3()
{
  bool result = setString(OS_AirflowNetworkMultiZoneComponentDetailedOpeningFields::HeightFactorforOpeningFactor3, "");
  OS_ASSERT(result);
}

bool AirflowNetworkMultiZoneComponentDetailedOpening_Impl::setStartHeightFactorforOpeningFactor3(double startHeightFactorforOpeningFactor3)
{
  bool result = setDouble(OS_AirflowNetworkMultiZoneComponentDetailedOpeningFields::StartHeightFactorforOpeningFactor3, startHeightFactorforOpeningFactor3);
  return result;
}

void AirflowNetworkMultiZoneComponentDetailedOpening_Impl::resetStartHeightFactorforOpeningFactor3()
{
  bool result = setString(OS_AirflowNetworkMultiZoneComponentDetailedOpeningFields::StartHeightFactorforOpeningFactor3, "");
  OS_ASSERT(result);
}

bool AirflowNetworkMultiZoneComponentDetailedOpening_Impl::setOpeningFactor4(boost::optional<double> openingFactor4)
{
  bool result(false);
  if(openingFactor4) {
    result = setDouble(OS_AirflowNetworkMultiZoneComponentDetailedOpeningFields::OpeningFactor4, openingFactor4.get());
  } else {
    resetOpeningFactor4();
    result = true;
  }
  return result;
}

void AirflowNetworkMultiZoneComponentDetailedOpening_Impl::resetOpeningFactor4()
{
  bool result = setString(OS_AirflowNetworkMultiZoneComponentDetailedOpeningFields::OpeningFactor4, "");
  OS_ASSERT(result);
}

bool AirflowNetworkMultiZoneComponentDetailedOpening_Impl::setDischargeCoefficientforOpeningFactor4(double dischargeCoefficientforOpeningFactor4)
{
  bool result = setDouble(OS_AirflowNetworkMultiZoneComponentDetailedOpeningFields::DischargeCoefficientforOpeningFactor4, dischargeCoefficientforOpeningFactor4);
  return result;
}

void AirflowNetworkMultiZoneComponentDetailedOpening_Impl::resetDischargeCoefficientforOpeningFactor4()
{
  bool result = setString(OS_AirflowNetworkMultiZoneComponentDetailedOpeningFields::DischargeCoefficientforOpeningFactor4, "");
  OS_ASSERT(result);
}

bool AirflowNetworkMultiZoneComponentDetailedOpening_Impl::setWidthFactorforOpeningFactor4(double widthFactorforOpeningFactor4)
{
  bool result = setDouble(OS_AirflowNetworkMultiZoneComponentDetailedOpeningFields::WidthFactorforOpeningFactor4, widthFactorforOpeningFactor4);
  return result;
}

void AirflowNetworkMultiZoneComponentDetailedOpening_Impl::resetWidthFactorforOpeningFactor4()
{
  bool result = setString(OS_AirflowNetworkMultiZoneComponentDetailedOpeningFields::WidthFactorforOpeningFactor4, "");
  OS_ASSERT(result);
}

bool AirflowNetworkMultiZoneComponentDetailedOpening_Impl::setHeightFactorforOpeningFactor4(double heightFactorforOpeningFactor4)
{
  bool result = setDouble(OS_AirflowNetworkMultiZoneComponentDetailedOpeningFields::HeightFactorforOpeningFactor4, heightFactorforOpeningFactor4);
  return result;
}

void AirflowNetworkMultiZoneComponentDetailedOpening_Impl::resetHeightFactorforOpeningFactor4()
{
  bool result = setString(OS_AirflowNetworkMultiZoneComponentDetailedOpeningFields::HeightFactorforOpeningFactor4, "");
  OS_ASSERT(result);
}

bool AirflowNetworkMultiZoneComponentDetailedOpening_Impl::setStartHeightFactorforOpeningFactor4(double startHeightFactorforOpeningFactor4)
{
  bool result = setDouble(OS_AirflowNetworkMultiZoneComponentDetailedOpeningFields::StartHeightFactorforOpeningFactor4, startHeightFactorforOpeningFactor4);
  return result;
}

void AirflowNetworkMultiZoneComponentDetailedOpening_Impl::resetStartHeightFactorforOpeningFactor4()
{
  bool result = setString(OS_AirflowNetworkMultiZoneComponentDetailedOpeningFields::StartHeightFactorforOpeningFactor4, "");
  OS_ASSERT(result);
}

} // detail

AirflowNetworkMultiZoneComponentDetailedOpening::AirflowNetworkMultiZoneComponentDetailedOpening(const Model& model,
  double massFlowCoefficientWhenOpeningisClosed,
  double massFlowExponentWhenOpeningisClosed,
  std::string typeofRectangulerLargeVerticalOpening,
  double extraCrackLengthorHeightofPivotingAxis,
  double openingFactor1,
  double dischargeCoefficientforOpeningFactor1,
  double widthFactorforOpeningFactor1,
  double heightFactorforOpeningFactor1,
  double startHeightFactorforOpeningFactor1,
  double openingFactor2,
  double dischargeCoefficientforOpeningFactor2,
  double widthFactorforOpeningFactor2,
  double heightFactorforOpeningFactor2,
  double startHeightFactorforOpeningFactor2)
  : ModelObject(AirflowNetworkMultiZoneComponentDetailedOpening::iddObjectType(), model)
{
  OS_ASSERT(getImpl<detail::AirflowNetworkMultiZoneComponentDetailedOpening_Impl>());

  // OS_ASSERT(setHandle());
  OS_ASSERT(setAirMassFlowCoefficientWhenOpeningisClosed(massFlowCoefficientWhenOpeningisClosed));
  OS_ASSERT(setAirMassFlowExponentWhenOpeningisClosed(massFlowExponentWhenOpeningisClosed));
  OS_ASSERT(setTypeofRectangulerLargeVerticalOpening(typeofRectangulerLargeVerticalOpening));
  OS_ASSERT(setNumberofSetsofOpeningFactorData(2));
  // Set 1
  OS_ASSERT(setOpeningFactor1(openingFactor1));
  OS_ASSERT(setDischargeCoefficientforOpeningFactor1(dischargeCoefficientforOpeningFactor1));
  OS_ASSERT(setWidthFactorforOpeningFactor1(widthFactorforOpeningFactor1));
  OS_ASSERT(setHeightFactorforOpeningFactor1(heightFactorforOpeningFactor1));
  OS_ASSERT(setStartHeightFactorforOpeningFactor1(startHeightFactorforOpeningFactor1));
  // Set 2
  OS_ASSERT(setOpeningFactor2(openingFactor2));
  OS_ASSERT(setDischargeCoefficientforOpeningFactor2(dischargeCoefficientforOpeningFactor2));
  OS_ASSERT(setWidthFactorforOpeningFactor2(widthFactorforOpeningFactor2));
  OS_ASSERT(setHeightFactorforOpeningFactor2(heightFactorforOpeningFactor2));
  OS_ASSERT(setStartHeightFactorforOpeningFactor2(startHeightFactorforOpeningFactor2));
}

AirflowNetworkMultiZoneComponentDetailedOpening::AirflowNetworkMultiZoneComponentDetailedOpening(const Model& model,
  double massFlowCoefficientWhenOpeningisClosed,
  double massFlowExponentWhenOpeningisClosed,
  std::string typeofRectangulerLargeVerticalOpening,
  double extraCrackLengthorHeightofPivotingAxis,
  double openingFactor1,
  double dischargeCoefficientforOpeningFactor1,
  double widthFactorforOpeningFactor1,
  double heightFactorforOpeningFactor1,
  double startHeightFactorforOpeningFactor1,
  double openingFactor2,
  double dischargeCoefficientforOpeningFactor2,
  double widthFactorforOpeningFactor2,
  double heightFactorforOpeningFactor2,
  double startHeightFactorforOpeningFactor2,
  double openingFactor3,
  double dischargeCoefficientforOpeningFactor3,
  double widthFactorforOpeningFactor3,
  double heightFactorforOpeningFactor3,
  double startHeightFactorforOpeningFactor3)
  : ModelObject(AirflowNetworkMultiZoneComponentDetailedOpening::iddObjectType(), model)
{
  OS_ASSERT(getImpl<detail::AirflowNetworkMultiZoneComponentDetailedOpening_Impl>());

  // OS_ASSERT(setHandle());
  OS_ASSERT(setAirMassFlowCoefficientWhenOpeningisClosed(massFlowCoefficientWhenOpeningisClosed));
  OS_ASSERT(setAirMassFlowExponentWhenOpeningisClosed(massFlowExponentWhenOpeningisClosed));
  OS_ASSERT(setTypeofRectangulerLargeVerticalOpening(typeofRectangulerLargeVerticalOpening));
  OS_ASSERT(setNumberofSetsofOpeningFactorData(3));
  // Set 1
  OS_ASSERT(setOpeningFactor1(openingFactor1));
  OS_ASSERT(setDischargeCoefficientforOpeningFactor1(dischargeCoefficientforOpeningFactor1));
  OS_ASSERT(setWidthFactorforOpeningFactor1(widthFactorforOpeningFactor1));
  OS_ASSERT(setHeightFactorforOpeningFactor1(heightFactorforOpeningFactor1));
  OS_ASSERT(setStartHeightFactorforOpeningFactor1(startHeightFactorforOpeningFactor1));
  // Set 2
  OS_ASSERT(setOpeningFactor2(openingFactor2));
  OS_ASSERT(setDischargeCoefficientforOpeningFactor2(dischargeCoefficientforOpeningFactor2));
  OS_ASSERT(setWidthFactorforOpeningFactor2(widthFactorforOpeningFactor2));
  OS_ASSERT(setHeightFactorforOpeningFactor2(heightFactorforOpeningFactor2));
  OS_ASSERT(setStartHeightFactorforOpeningFactor2(startHeightFactorforOpeningFactor2));
  // Set 3
  OS_ASSERT(setOpeningFactor3(openingFactor3));
  OS_ASSERT(setDischargeCoefficientforOpeningFactor3(dischargeCoefficientforOpeningFactor3));
  OS_ASSERT(setWidthFactorforOpeningFactor3(widthFactorforOpeningFactor3));
  OS_ASSERT(setHeightFactorforOpeningFactor3(heightFactorforOpeningFactor3));
  OS_ASSERT(setStartHeightFactorforOpeningFactor3(startHeightFactorforOpeningFactor3));
}

AirflowNetworkMultiZoneComponentDetailedOpening::AirflowNetworkMultiZoneComponentDetailedOpening(const Model& model,
  double massFlowCoefficientWhenOpeningisClosed,
  double massFlowExponentWhenOpeningisClosed,
  std::string typeofRectangulerLargeVerticalOpening,
  double extraCrackLengthorHeightofPivotingAxis,
  double openingFactor1,
  double dischargeCoefficientforOpeningFactor1,
  double widthFactorforOpeningFactor1,
  double heightFactorforOpeningFactor1,
  double startHeightFactorforOpeningFactor1,
  double openingFactor2,
  double dischargeCoefficientforOpeningFactor2,
  double widthFactorforOpeningFactor2,
  double heightFactorforOpeningFactor2,
  double startHeightFactorforOpeningFactor2,
  double openingFactor3,
  double dischargeCoefficientforOpeningFactor3,
  double widthFactorforOpeningFactor3,
  double heightFactorforOpeningFactor3,
  double startHeightFactorforOpeningFactor3,
  double openingFactor4,
  double dischargeCoefficientforOpeningFactor4,
  double widthFactorforOpeningFactor4,
  double heightFactorforOpeningFactor4,
  double startHeightFactorforOpeningFactor4)
  : ModelObject(AirflowNetworkMultiZoneComponentDetailedOpening::iddObjectType(), model)
{
  OS_ASSERT(getImpl<detail::AirflowNetworkMultiZoneComponentDetailedOpening_Impl>());

  // OS_ASSERT(setHandle());
  OS_ASSERT(setAirMassFlowCoefficientWhenOpeningisClosed(massFlowCoefficientWhenOpeningisClosed));
  OS_ASSERT(setAirMassFlowExponentWhenOpeningisClosed(massFlowExponentWhenOpeningisClosed));
  OS_ASSERT(setTypeofRectangulerLargeVerticalOpening(typeofRectangulerLargeVerticalOpening));
  OS_ASSERT(setNumberofSetsofOpeningFactorData(4));
  // Set 1
  OS_ASSERT(setOpeningFactor1(openingFactor1));
  OS_ASSERT(setDischargeCoefficientforOpeningFactor1(dischargeCoefficientforOpeningFactor1));
  OS_ASSERT(setWidthFactorforOpeningFactor1(widthFactorforOpeningFactor1));
  OS_ASSERT(setHeightFactorforOpeningFactor1(heightFactorforOpeningFactor1));
  OS_ASSERT(setStartHeightFactorforOpeningFactor1(startHeightFactorforOpeningFactor1));
  // Set 2
  OS_ASSERT(setOpeningFactor2(openingFactor2));
  OS_ASSERT(setDischargeCoefficientforOpeningFactor2(dischargeCoefficientforOpeningFactor2));
  OS_ASSERT(setWidthFactorforOpeningFactor2(widthFactorforOpeningFactor2));
  OS_ASSERT(setHeightFactorforOpeningFactor2(heightFactorforOpeningFactor2));
  OS_ASSERT(setStartHeightFactorforOpeningFactor2(startHeightFactorforOpeningFactor2));
  // Set 3
  OS_ASSERT(setOpeningFactor3(openingFactor3));
  OS_ASSERT(setDischargeCoefficientforOpeningFactor3(dischargeCoefficientforOpeningFactor3));
  OS_ASSERT(setWidthFactorforOpeningFactor3(widthFactorforOpeningFactor3));
  OS_ASSERT(setHeightFactorforOpeningFactor3(heightFactorforOpeningFactor3));
  OS_ASSERT(setStartHeightFactorforOpeningFactor3(startHeightFactorforOpeningFactor3));
  // Set 4
  OS_ASSERT(setOpeningFactor4(openingFactor4));
  OS_ASSERT(setDischargeCoefficientforOpeningFactor4(dischargeCoefficientforOpeningFactor4));
  OS_ASSERT(setWidthFactorforOpeningFactor4(widthFactorforOpeningFactor4));
  OS_ASSERT(setHeightFactorforOpeningFactor4(heightFactorforOpeningFactor4));
  OS_ASSERT(setStartHeightFactorforOpeningFactor4(startHeightFactorforOpeningFactor4));
}

IddObjectType AirflowNetworkMultiZoneComponentDetailedOpening::iddObjectType()
{
  return IddObjectType(IddObjectType::OS_AirflowNetworkMultiZoneComponentDetailedOpening);
}

std::vector<std::string> AirflowNetworkMultiZoneComponentDetailedOpening::typeofRectangulerLargeVerticalOpeningValues()
{
  return getIddKeyNames(IddFactory::instance().getObject(iddObjectType()).get(),
    OS_AirflowNetworkMultiZoneComponentDetailedOpeningFields::TypeofRectangulerLargeVerticalOpening);
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

std::string AirflowNetworkMultiZoneComponentDetailedOpening::typeofRectangulerLargeVerticalOpening() const
{
  return getImpl<detail::AirflowNetworkMultiZoneComponentDetailedOpening_Impl>()->typeofRectangulerLargeVerticalOpening();
}

bool AirflowNetworkMultiZoneComponentDetailedOpening::isTypeofRectangulerLargeVerticalOpeningDefaulted() const
{
  return getImpl<detail::AirflowNetworkMultiZoneComponentDetailedOpening_Impl>()->isTypeofRectangulerLargeVerticalOpeningDefaulted();
}

double AirflowNetworkMultiZoneComponentDetailedOpening::extraCrackLengthorHeightofPivotingAxis() const
{
  return getImpl<detail::AirflowNetworkMultiZoneComponentDetailedOpening_Impl>()->extraCrackLengthorHeightofPivotingAxis();
}

bool AirflowNetworkMultiZoneComponentDetailedOpening::isExtraCrackLengthorHeightofPivotingAxisDefaulted() const
{
  return getImpl<detail::AirflowNetworkMultiZoneComponentDetailedOpening_Impl>()->isExtraCrackLengthorHeightofPivotingAxisDefaulted();
}

int AirflowNetworkMultiZoneComponentDetailedOpening::numberofSetsofOpeningFactorData() const
{
  return getImpl<detail::AirflowNetworkMultiZoneComponentDetailedOpening_Impl>()->numberofSetsofOpeningFactorData();
}

double AirflowNetworkMultiZoneComponentDetailedOpening::openingFactor1() const
{
  return getImpl<detail::AirflowNetworkMultiZoneComponentDetailedOpening_Impl>()->openingFactor1();
}

bool AirflowNetworkMultiZoneComponentDetailedOpening::isOpeningFactor1Defaulted() const
{
  return getImpl<detail::AirflowNetworkMultiZoneComponentDetailedOpening_Impl>()->isOpeningFactor1Defaulted();
}

double AirflowNetworkMultiZoneComponentDetailedOpening::dischargeCoefficientforOpeningFactor1() const
{
  return getImpl<detail::AirflowNetworkMultiZoneComponentDetailedOpening_Impl>()->dischargeCoefficientforOpeningFactor1();
}

bool AirflowNetworkMultiZoneComponentDetailedOpening::isDischargeCoefficientforOpeningFactor1Defaulted() const
{
  return getImpl<detail::AirflowNetworkMultiZoneComponentDetailedOpening_Impl>()->isDischargeCoefficientforOpeningFactor1Defaulted();
}

double AirflowNetworkMultiZoneComponentDetailedOpening::widthFactorforOpeningFactor1() const
{
  return getImpl<detail::AirflowNetworkMultiZoneComponentDetailedOpening_Impl>()->widthFactorforOpeningFactor1();
}

bool AirflowNetworkMultiZoneComponentDetailedOpening::isWidthFactorforOpeningFactor1Defaulted() const
{
  return getImpl<detail::AirflowNetworkMultiZoneComponentDetailedOpening_Impl>()->isWidthFactorforOpeningFactor1Defaulted();
}

double AirflowNetworkMultiZoneComponentDetailedOpening::heightFactorforOpeningFactor1() const
{
  return getImpl<detail::AirflowNetworkMultiZoneComponentDetailedOpening_Impl>()->heightFactorforOpeningFactor1();
}

bool AirflowNetworkMultiZoneComponentDetailedOpening::isHeightFactorforOpeningFactor1Defaulted() const
{
  return getImpl<detail::AirflowNetworkMultiZoneComponentDetailedOpening_Impl>()->isHeightFactorforOpeningFactor1Defaulted();
}

double AirflowNetworkMultiZoneComponentDetailedOpening::startHeightFactorforOpeningFactor1() const
{
  return getImpl<detail::AirflowNetworkMultiZoneComponentDetailedOpening_Impl>()->startHeightFactorforOpeningFactor1();
}

bool AirflowNetworkMultiZoneComponentDetailedOpening::isStartHeightFactorforOpeningFactor1Defaulted() const
{
  return getImpl<detail::AirflowNetworkMultiZoneComponentDetailedOpening_Impl>()->isStartHeightFactorforOpeningFactor1Defaulted();
}

double AirflowNetworkMultiZoneComponentDetailedOpening::openingFactor2() const
{
  return getImpl<detail::AirflowNetworkMultiZoneComponentDetailedOpening_Impl>()->openingFactor2();
}

double AirflowNetworkMultiZoneComponentDetailedOpening::dischargeCoefficientforOpeningFactor2() const
{
  return getImpl<detail::AirflowNetworkMultiZoneComponentDetailedOpening_Impl>()->dischargeCoefficientforOpeningFactor2();
}

bool AirflowNetworkMultiZoneComponentDetailedOpening::isDischargeCoefficientforOpeningFactor2Defaulted() const
{
  return getImpl<detail::AirflowNetworkMultiZoneComponentDetailedOpening_Impl>()->isDischargeCoefficientforOpeningFactor2Defaulted();
}

double AirflowNetworkMultiZoneComponentDetailedOpening::widthFactorforOpeningFactor2() const
{
  return getImpl<detail::AirflowNetworkMultiZoneComponentDetailedOpening_Impl>()->widthFactorforOpeningFactor2();
}

bool AirflowNetworkMultiZoneComponentDetailedOpening::isWidthFactorforOpeningFactor2Defaulted() const
{
  return getImpl<detail::AirflowNetworkMultiZoneComponentDetailedOpening_Impl>()->isWidthFactorforOpeningFactor2Defaulted();
}

double AirflowNetworkMultiZoneComponentDetailedOpening::heightFactorforOpeningFactor2() const
{
  return getImpl<detail::AirflowNetworkMultiZoneComponentDetailedOpening_Impl>()->heightFactorforOpeningFactor2();
}

bool AirflowNetworkMultiZoneComponentDetailedOpening::isHeightFactorforOpeningFactor2Defaulted() const
{
  return getImpl<detail::AirflowNetworkMultiZoneComponentDetailedOpening_Impl>()->isHeightFactorforOpeningFactor2Defaulted();
}

double AirflowNetworkMultiZoneComponentDetailedOpening::startHeightFactorforOpeningFactor2() const
{
  return getImpl<detail::AirflowNetworkMultiZoneComponentDetailedOpening_Impl>()->startHeightFactorforOpeningFactor2();
}

bool AirflowNetworkMultiZoneComponentDetailedOpening::isStartHeightFactorforOpeningFactor2Defaulted() const
{
  return getImpl<detail::AirflowNetworkMultiZoneComponentDetailedOpening_Impl>()->isStartHeightFactorforOpeningFactor2Defaulted();
}

boost::optional<double> AirflowNetworkMultiZoneComponentDetailedOpening::openingFactor3() const
{
  return getImpl<detail::AirflowNetworkMultiZoneComponentDetailedOpening_Impl>()->openingFactor3();
}

double AirflowNetworkMultiZoneComponentDetailedOpening::dischargeCoefficientforOpeningFactor3() const
{
  return getImpl<detail::AirflowNetworkMultiZoneComponentDetailedOpening_Impl>()->dischargeCoefficientforOpeningFactor3();
}

bool AirflowNetworkMultiZoneComponentDetailedOpening::isDischargeCoefficientforOpeningFactor3Defaulted() const
{
  return getImpl<detail::AirflowNetworkMultiZoneComponentDetailedOpening_Impl>()->isDischargeCoefficientforOpeningFactor3Defaulted();
}

double AirflowNetworkMultiZoneComponentDetailedOpening::widthFactorforOpeningFactor3() const
{
  return getImpl<detail::AirflowNetworkMultiZoneComponentDetailedOpening_Impl>()->widthFactorforOpeningFactor3();
}

bool AirflowNetworkMultiZoneComponentDetailedOpening::isWidthFactorforOpeningFactor3Defaulted() const
{
  return getImpl<detail::AirflowNetworkMultiZoneComponentDetailedOpening_Impl>()->isWidthFactorforOpeningFactor3Defaulted();
}

double AirflowNetworkMultiZoneComponentDetailedOpening::heightFactorforOpeningFactor3() const
{
  return getImpl<detail::AirflowNetworkMultiZoneComponentDetailedOpening_Impl>()->heightFactorforOpeningFactor3();
}

bool AirflowNetworkMultiZoneComponentDetailedOpening::isHeightFactorforOpeningFactor3Defaulted() const
{
  return getImpl<detail::AirflowNetworkMultiZoneComponentDetailedOpening_Impl>()->isHeightFactorforOpeningFactor3Defaulted();
}

double AirflowNetworkMultiZoneComponentDetailedOpening::startHeightFactorforOpeningFactor3() const
{
  return getImpl<detail::AirflowNetworkMultiZoneComponentDetailedOpening_Impl>()->startHeightFactorforOpeningFactor3();
}

bool AirflowNetworkMultiZoneComponentDetailedOpening::isStartHeightFactorforOpeningFactor3Defaulted() const
{
  return getImpl<detail::AirflowNetworkMultiZoneComponentDetailedOpening_Impl>()->isStartHeightFactorforOpeningFactor3Defaulted();
}

boost::optional<double> AirflowNetworkMultiZoneComponentDetailedOpening::openingFactor4() const
{
  return getImpl<detail::AirflowNetworkMultiZoneComponentDetailedOpening_Impl>()->openingFactor4();
}

double AirflowNetworkMultiZoneComponentDetailedOpening::dischargeCoefficientforOpeningFactor4() const
{
  return getImpl<detail::AirflowNetworkMultiZoneComponentDetailedOpening_Impl>()->dischargeCoefficientforOpeningFactor4();
}

bool AirflowNetworkMultiZoneComponentDetailedOpening::isDischargeCoefficientforOpeningFactor4Defaulted() const
{
  return getImpl<detail::AirflowNetworkMultiZoneComponentDetailedOpening_Impl>()->isDischargeCoefficientforOpeningFactor4Defaulted();
}

double AirflowNetworkMultiZoneComponentDetailedOpening::widthFactorforOpeningFactor4() const
{
  return getImpl<detail::AirflowNetworkMultiZoneComponentDetailedOpening_Impl>()->widthFactorforOpeningFactor4();
}

bool AirflowNetworkMultiZoneComponentDetailedOpening::isWidthFactorforOpeningFactor4Defaulted() const
{
  return getImpl<detail::AirflowNetworkMultiZoneComponentDetailedOpening_Impl>()->isWidthFactorforOpeningFactor4Defaulted();
}

double AirflowNetworkMultiZoneComponentDetailedOpening::heightFactorforOpeningFactor4() const
{
  return getImpl<detail::AirflowNetworkMultiZoneComponentDetailedOpening_Impl>()->heightFactorforOpeningFactor4();
}

bool AirflowNetworkMultiZoneComponentDetailedOpening::isHeightFactorforOpeningFactor4Defaulted() const
{
  return getImpl<detail::AirflowNetworkMultiZoneComponentDetailedOpening_Impl>()->isHeightFactorforOpeningFactor4Defaulted();
}

double AirflowNetworkMultiZoneComponentDetailedOpening::startHeightFactorforOpeningFactor4() const
{
  return getImpl<detail::AirflowNetworkMultiZoneComponentDetailedOpening_Impl>()->startHeightFactorforOpeningFactor4();
}

bool AirflowNetworkMultiZoneComponentDetailedOpening::isStartHeightFactorforOpeningFactor4Defaulted() const
{
  return getImpl<detail::AirflowNetworkMultiZoneComponentDetailedOpening_Impl>()->isStartHeightFactorforOpeningFactor4Defaulted();
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

bool AirflowNetworkMultiZoneComponentDetailedOpening::setTypeofRectangulerLargeVerticalOpening(std::string typeofRectangulerLargeVerticalOpening)
{
  return getImpl<detail::AirflowNetworkMultiZoneComponentDetailedOpening_Impl>()->setTypeofRectangulerLargeVerticalOpening(typeofRectangulerLargeVerticalOpening);
}

void AirflowNetworkMultiZoneComponentDetailedOpening::resetTypeofRectangulerLargeVerticalOpening()
{
  getImpl<detail::AirflowNetworkMultiZoneComponentDetailedOpening_Impl>()->resetTypeofRectangulerLargeVerticalOpening();
}

bool AirflowNetworkMultiZoneComponentDetailedOpening::setExtraCrackLengthorHeightofPivotingAxis(double extraCrackLengthorHeightofPivotingAxis)
{
  return getImpl<detail::AirflowNetworkMultiZoneComponentDetailedOpening_Impl>()->setExtraCrackLengthorHeightofPivotingAxis(extraCrackLengthorHeightofPivotingAxis);
}

void AirflowNetworkMultiZoneComponentDetailedOpening::resetExtraCrackLengthorHeightofPivotingAxis()
{
  getImpl<detail::AirflowNetworkMultiZoneComponentDetailedOpening_Impl>()->resetExtraCrackLengthorHeightofPivotingAxis();
}

bool AirflowNetworkMultiZoneComponentDetailedOpening::setNumberofSetsofOpeningFactorData(int numberofSetsofOpeningFactorData)
{
  return getImpl<detail::AirflowNetworkMultiZoneComponentDetailedOpening_Impl>()->setNumberofSetsofOpeningFactorData(numberofSetsofOpeningFactorData);
}

bool AirflowNetworkMultiZoneComponentDetailedOpening::setOpeningFactor1(double openingFactor1) {
  return getImpl<detail::AirflowNetworkMultiZoneComponentDetailedOpening_Impl>()->setOpeningFactor1(openingFactor1);
}

void AirflowNetworkMultiZoneComponentDetailedOpening::resetOpeningFactor1()
{
  getImpl<detail::AirflowNetworkMultiZoneComponentDetailedOpening_Impl>()->resetOpeningFactor1();
}

bool AirflowNetworkMultiZoneComponentDetailedOpening::setDischargeCoefficientforOpeningFactor1(double dischargeCoefficientforOpeningFactor1)
{
  return getImpl<detail::AirflowNetworkMultiZoneComponentDetailedOpening_Impl>()->setDischargeCoefficientforOpeningFactor1(dischargeCoefficientforOpeningFactor1);
}

void AirflowNetworkMultiZoneComponentDetailedOpening::resetDischargeCoefficientforOpeningFactor1()
{
  getImpl<detail::AirflowNetworkMultiZoneComponentDetailedOpening_Impl>()->resetDischargeCoefficientforOpeningFactor1();
}

bool AirflowNetworkMultiZoneComponentDetailedOpening::setWidthFactorforOpeningFactor1(double widthFactorforOpeningFactor1)
{
  return getImpl<detail::AirflowNetworkMultiZoneComponentDetailedOpening_Impl>()->setWidthFactorforOpeningFactor1(widthFactorforOpeningFactor1);
}

void AirflowNetworkMultiZoneComponentDetailedOpening::resetWidthFactorforOpeningFactor1()
{
  getImpl<detail::AirflowNetworkMultiZoneComponentDetailedOpening_Impl>()->resetWidthFactorforOpeningFactor1();
}

bool AirflowNetworkMultiZoneComponentDetailedOpening::setHeightFactorforOpeningFactor1(double heightFactorforOpeningFactor1)
{
  return getImpl<detail::AirflowNetworkMultiZoneComponentDetailedOpening_Impl>()->setHeightFactorforOpeningFactor1(heightFactorforOpeningFactor1);
}

void AirflowNetworkMultiZoneComponentDetailedOpening::resetHeightFactorforOpeningFactor1()
{
  getImpl<detail::AirflowNetworkMultiZoneComponentDetailedOpening_Impl>()->resetHeightFactorforOpeningFactor1();
}

bool AirflowNetworkMultiZoneComponentDetailedOpening::setStartHeightFactorforOpeningFactor1(double startHeightFactorforOpeningFactor1)
{
  return getImpl<detail::AirflowNetworkMultiZoneComponentDetailedOpening_Impl>()->setStartHeightFactorforOpeningFactor1(startHeightFactorforOpeningFactor1);
}

void AirflowNetworkMultiZoneComponentDetailedOpening::resetStartHeightFactorforOpeningFactor1()
{
  getImpl<detail::AirflowNetworkMultiZoneComponentDetailedOpening_Impl>()->resetStartHeightFactorforOpeningFactor1();
}

bool AirflowNetworkMultiZoneComponentDetailedOpening::setOpeningFactor2(double openingFactor2)
{
  return getImpl<detail::AirflowNetworkMultiZoneComponentDetailedOpening_Impl>()->setOpeningFactor2(openingFactor2);
}

bool AirflowNetworkMultiZoneComponentDetailedOpening::setDischargeCoefficientforOpeningFactor2(double dischargeCoefficientforOpeningFactor2)
{
  return getImpl<detail::AirflowNetworkMultiZoneComponentDetailedOpening_Impl>()->setDischargeCoefficientforOpeningFactor2(dischargeCoefficientforOpeningFactor2);
}

void AirflowNetworkMultiZoneComponentDetailedOpening::resetDischargeCoefficientforOpeningFactor2()
{
  getImpl<detail::AirflowNetworkMultiZoneComponentDetailedOpening_Impl>()->resetDischargeCoefficientforOpeningFactor2();
}

bool AirflowNetworkMultiZoneComponentDetailedOpening::setWidthFactorforOpeningFactor2(double widthFactorforOpeningFactor2)
{
  return getImpl<detail::AirflowNetworkMultiZoneComponentDetailedOpening_Impl>()->setWidthFactorforOpeningFactor2(widthFactorforOpeningFactor2);
}

void AirflowNetworkMultiZoneComponentDetailedOpening::resetWidthFactorforOpeningFactor2()
{
  getImpl<detail::AirflowNetworkMultiZoneComponentDetailedOpening_Impl>()->resetWidthFactorforOpeningFactor2();
}

bool AirflowNetworkMultiZoneComponentDetailedOpening::setHeightFactorforOpeningFactor2(double heightFactorforOpeningFactor2)
{
  return getImpl<detail::AirflowNetworkMultiZoneComponentDetailedOpening_Impl>()->setHeightFactorforOpeningFactor2(heightFactorforOpeningFactor2);
}

void AirflowNetworkMultiZoneComponentDetailedOpening::resetHeightFactorforOpeningFactor2()
{
  getImpl<detail::AirflowNetworkMultiZoneComponentDetailedOpening_Impl>()->resetHeightFactorforOpeningFactor2();
}

bool AirflowNetworkMultiZoneComponentDetailedOpening::setStartHeightFactorforOpeningFactor2(double startHeightFactorforOpeningFactor2)
{
  return getImpl<detail::AirflowNetworkMultiZoneComponentDetailedOpening_Impl>()->setStartHeightFactorforOpeningFactor2(startHeightFactorforOpeningFactor2);
}

void AirflowNetworkMultiZoneComponentDetailedOpening::resetStartHeightFactorforOpeningFactor2()
{
  getImpl<detail::AirflowNetworkMultiZoneComponentDetailedOpening_Impl>()->resetStartHeightFactorforOpeningFactor2();
}

bool AirflowNetworkMultiZoneComponentDetailedOpening::setOpeningFactor3(double openingFactor3)
{
  return getImpl<detail::AirflowNetworkMultiZoneComponentDetailedOpening_Impl>()->setOpeningFactor3(openingFactor3);
}

void AirflowNetworkMultiZoneComponentDetailedOpening::resetOpeningFactor3()
{
  getImpl<detail::AirflowNetworkMultiZoneComponentDetailedOpening_Impl>()->resetOpeningFactor3();
}

bool AirflowNetworkMultiZoneComponentDetailedOpening::setDischargeCoefficientforOpeningFactor3(double dischargeCoefficientforOpeningFactor3)
{
  return getImpl<detail::AirflowNetworkMultiZoneComponentDetailedOpening_Impl>()->setDischargeCoefficientforOpeningFactor3(dischargeCoefficientforOpeningFactor3);
}

void AirflowNetworkMultiZoneComponentDetailedOpening::resetDischargeCoefficientforOpeningFactor3()
{
  getImpl<detail::AirflowNetworkMultiZoneComponentDetailedOpening_Impl>()->resetDischargeCoefficientforOpeningFactor3();
}

bool AirflowNetworkMultiZoneComponentDetailedOpening::setWidthFactorforOpeningFactor3(double widthFactorforOpeningFactor3)
{
  return getImpl<detail::AirflowNetworkMultiZoneComponentDetailedOpening_Impl>()->setWidthFactorforOpeningFactor3(widthFactorforOpeningFactor3);
}

void AirflowNetworkMultiZoneComponentDetailedOpening::resetWidthFactorforOpeningFactor3()
{
  getImpl<detail::AirflowNetworkMultiZoneComponentDetailedOpening_Impl>()->resetWidthFactorforOpeningFactor3();
}

bool AirflowNetworkMultiZoneComponentDetailedOpening::setHeightFactorforOpeningFactor3(double heightFactorforOpeningFactor3)
{
  return getImpl<detail::AirflowNetworkMultiZoneComponentDetailedOpening_Impl>()->setHeightFactorforOpeningFactor3(heightFactorforOpeningFactor3);
}

void AirflowNetworkMultiZoneComponentDetailedOpening::resetHeightFactorforOpeningFactor3()
{
  getImpl<detail::AirflowNetworkMultiZoneComponentDetailedOpening_Impl>()->resetHeightFactorforOpeningFactor3();
}

bool AirflowNetworkMultiZoneComponentDetailedOpening::setStartHeightFactorforOpeningFactor3(double startHeightFactorforOpeningFactor3)
{
  return getImpl<detail::AirflowNetworkMultiZoneComponentDetailedOpening_Impl>()->setStartHeightFactorforOpeningFactor3(startHeightFactorforOpeningFactor3);
}

void AirflowNetworkMultiZoneComponentDetailedOpening::resetStartHeightFactorforOpeningFactor3()
{
  getImpl<detail::AirflowNetworkMultiZoneComponentDetailedOpening_Impl>()->resetStartHeightFactorforOpeningFactor3();
}

bool AirflowNetworkMultiZoneComponentDetailedOpening::setOpeningFactor4(double openingFactor4)
{
  return getImpl<detail::AirflowNetworkMultiZoneComponentDetailedOpening_Impl>()->setOpeningFactor4(openingFactor4);
}

void AirflowNetworkMultiZoneComponentDetailedOpening::resetOpeningFactor4()
{
  getImpl<detail::AirflowNetworkMultiZoneComponentDetailedOpening_Impl>()->resetOpeningFactor4();
}

bool AirflowNetworkMultiZoneComponentDetailedOpening::setDischargeCoefficientforOpeningFactor4(double dischargeCoefficientforOpeningFactor4)
{
  return getImpl<detail::AirflowNetworkMultiZoneComponentDetailedOpening_Impl>()->setDischargeCoefficientforOpeningFactor4(dischargeCoefficientforOpeningFactor4);
}

void AirflowNetworkMultiZoneComponentDetailedOpening::resetDischargeCoefficientforOpeningFactor4()
{
  getImpl<detail::AirflowNetworkMultiZoneComponentDetailedOpening_Impl>()->resetDischargeCoefficientforOpeningFactor4();
}

bool AirflowNetworkMultiZoneComponentDetailedOpening::setWidthFactorforOpeningFactor4(double widthFactorforOpeningFactor4)
{
  return getImpl<detail::AirflowNetworkMultiZoneComponentDetailedOpening_Impl>()->setWidthFactorforOpeningFactor4(widthFactorforOpeningFactor4);
}

void AirflowNetworkMultiZoneComponentDetailedOpening::resetWidthFactorforOpeningFactor4()
{
  getImpl<detail::AirflowNetworkMultiZoneComponentDetailedOpening_Impl>()->resetWidthFactorforOpeningFactor4();
}

bool AirflowNetworkMultiZoneComponentDetailedOpening::setHeightFactorforOpeningFactor4(double heightFactorforOpeningFactor4)
{
  return getImpl<detail::AirflowNetworkMultiZoneComponentDetailedOpening_Impl>()->setHeightFactorforOpeningFactor4(heightFactorforOpeningFactor4);
}

void AirflowNetworkMultiZoneComponentDetailedOpening::resetHeightFactorforOpeningFactor4()
{
  getImpl<detail::AirflowNetworkMultiZoneComponentDetailedOpening_Impl>()->resetHeightFactorforOpeningFactor4();
}

bool AirflowNetworkMultiZoneComponentDetailedOpening::setStartHeightFactorforOpeningFactor4(double startHeightFactorforOpeningFactor4)
{
  return getImpl<detail::AirflowNetworkMultiZoneComponentDetailedOpening_Impl>()->setStartHeightFactorforOpeningFactor4(startHeightFactorforOpeningFactor4);
}

void AirflowNetworkMultiZoneComponentDetailedOpening::resetStartHeightFactorforOpeningFactor4() {
  getImpl<detail::AirflowNetworkMultiZoneComponentDetailedOpening_Impl>()->resetStartHeightFactorforOpeningFactor4();
}

/// @cond
AirflowNetworkMultiZoneComponentDetailedOpening::AirflowNetworkMultiZoneComponentDetailedOpening(std::shared_ptr<detail::AirflowNetworkMultiZoneComponentDetailedOpening_Impl> impl)
  : ModelObject(impl)
{}
/// @endcond

} // model
} // openstudio

