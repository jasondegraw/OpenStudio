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

#ifndef MODEL_AIRFLOWNETWORKMULTIZONECOMPONENTDETAILEDOPENING_IMPL_HPP
#define MODEL_AIRFLOWNETWORKMULTIZONECOMPONENTDETAILEDOPENING_IMPL_HPP

#include <model/ModelAPI.hpp>
#include <model/ModelObject_Impl.hpp>

namespace openstudio {
namespace model {

namespace detail {

/** AirflowNetworkMultiZoneComponentDetailedOpening_Impl is a ModelObject_Impl that is the implementation class for AirflowNetworkMultiZoneComponentDetailedOpening.*/
class MODEL_API AirflowNetworkMultiZoneComponentDetailedOpening_Impl : public ModelObject_Impl
{
public:
  /** @name Constructors and Destructors */
  //@{

  AirflowNetworkMultiZoneComponentDetailedOpening_Impl(const IdfObject& idfObject,
    Model_Impl* model,
    bool keepHandle);

  AirflowNetworkMultiZoneComponentDetailedOpening_Impl(const openstudio::detail::WorkspaceObject_Impl& other,
    Model_Impl* model,
    bool keepHandle);

  AirflowNetworkMultiZoneComponentDetailedOpening_Impl(const AirflowNetworkMultiZoneComponentDetailedOpening_Impl& other,
    Model_Impl* model,
    bool keepHandle);

  virtual ~AirflowNetworkMultiZoneComponentDetailedOpening_Impl() {}

  //@}
  /** @name Virtual Methods */
  //@{

  virtual const std::vector<std::string>& outputVariableNames() const;

  virtual IddObjectType iddObjectType() const;

  //@}
  /** @name Getters */
  //@{

  double airMassFlowCoefficientWhenOpeningisClosed() const;

  double airMassFlowExponentWhenOpeningisClosed() const;

  bool isAirMassFlowExponentWhenOpeningisClosedDefaulted() const;

  std::string typeofRectangulerLargeVerticalOpening() const;

  bool isTypeofRectangulerLargeVerticalOpeningDefaulted() const;

  double extraCrackLengthorHeightofPivotingAxis() const;

  bool isExtraCrackLengthorHeightofPivotingAxisDefaulted() const;

  int numberofSetsofOpeningFactorData() const;

  double openingFactor1() const;

  bool isOpeningFactor1Defaulted() const;

  double dischargeCoefficientforOpeningFactor1() const;

  bool isDischargeCoefficientforOpeningFactor1Defaulted() const;

  double widthFactorforOpeningFactor1() const;

  bool isWidthFactorforOpeningFactor1Defaulted() const;

  double heightFactorforOpeningFactor1() const;

  bool isHeightFactorforOpeningFactor1Defaulted() const;

  double startHeightFactorforOpeningFactor1() const;

  bool isStartHeightFactorforOpeningFactor1Defaulted() const;

  double openingFactor2() const;

  double dischargeCoefficientforOpeningFactor2() const;

  bool isDischargeCoefficientforOpeningFactor2Defaulted() const;

  double widthFactorforOpeningFactor2() const;

  bool isWidthFactorforOpeningFactor2Defaulted() const;

  double heightFactorforOpeningFactor2() const;

  bool isHeightFactorforOpeningFactor2Defaulted() const;

  double startHeightFactorforOpeningFactor2() const;

  bool isStartHeightFactorforOpeningFactor2Defaulted() const;

  boost::optional<double> openingFactor3() const;

  double dischargeCoefficientforOpeningFactor3() const;

  bool isDischargeCoefficientforOpeningFactor3Defaulted() const;

  double widthFactorforOpeningFactor3() const;

  bool isWidthFactorforOpeningFactor3Defaulted() const;

  double heightFactorforOpeningFactor3() const;

  bool isHeightFactorforOpeningFactor3Defaulted() const;

  double startHeightFactorforOpeningFactor3() const;

  bool isStartHeightFactorforOpeningFactor3Defaulted() const;

  boost::optional<double> openingFactor4() const;

  double dischargeCoefficientforOpeningFactor4() const;

  bool isDischargeCoefficientforOpeningFactor4Defaulted() const;

  double widthFactorforOpeningFactor4() const;

  bool isWidthFactorforOpeningFactor4Defaulted() const;

  double heightFactorforOpeningFactor4() const;

  bool isHeightFactorforOpeningFactor4Defaulted() const;

  double startHeightFactorforOpeningFactor4() const;

  bool isStartHeightFactorforOpeningFactor4Defaulted() const;

  //@}
  /** @name Setters */
  //@{

  bool setAirMassFlowCoefficientWhenOpeningisClosed(double airMassFlowCoefficientWhenOpeningisClosed);

  bool setAirMassFlowExponentWhenOpeningisClosed(double airMassFlowExponentWhenOpeningisClosed);

  void resetAirMassFlowExponentWhenOpeningisClosed();

  bool setTypeofRectangulerLargeVerticalOpening(std::string typeofRectangulerLargeVerticalOpening);

  void resetTypeofRectangulerLargeVerticalOpening();

  bool setExtraCrackLengthorHeightofPivotingAxis(double extraCrackLengthorHeightofPivotingAxis);

  void resetExtraCrackLengthorHeightofPivotingAxis();

  bool setNumberofSetsofOpeningFactorData(int numberofSetsofOpeningFactorData);

  bool setOpeningFactor1(double openingFactor1);

  void resetOpeningFactor1();

  bool setDischargeCoefficientforOpeningFactor1(double dischargeCoefficientforOpeningFactor1);

  void resetDischargeCoefficientforOpeningFactor1();

  bool setWidthFactorforOpeningFactor1(double widthFactorforOpeningFactor1);

  void resetWidthFactorforOpeningFactor1();

  bool setHeightFactorforOpeningFactor1(double heightFactorforOpeningFactor1);

  void resetHeightFactorforOpeningFactor1();

  bool setStartHeightFactorforOpeningFactor1(double startHeightFactorforOpeningFactor1);

  void resetStartHeightFactorforOpeningFactor1();

  bool setOpeningFactor2(double openingFactor2);

  bool setDischargeCoefficientforOpeningFactor2(double dischargeCoefficientforOpeningFactor2);

  void resetDischargeCoefficientforOpeningFactor2();

  bool setWidthFactorforOpeningFactor2(double widthFactorforOpeningFactor2);

  void resetWidthFactorforOpeningFactor2();

  bool setHeightFactorforOpeningFactor2(double heightFactorforOpeningFactor2);

  void resetHeightFactorforOpeningFactor2();

  bool setStartHeightFactorforOpeningFactor2(double startHeightFactorforOpeningFactor2);

  void resetStartHeightFactorforOpeningFactor2();

  bool setOpeningFactor3(boost::optional<double> openingFactor3);

  void resetOpeningFactor3();

  bool setDischargeCoefficientforOpeningFactor3(double dischargeCoefficientforOpeningFactor3);

  void resetDischargeCoefficientforOpeningFactor3();

  bool setWidthFactorforOpeningFactor3(double widthFactorforOpeningFactor3);

  void resetWidthFactorforOpeningFactor3();

  bool setHeightFactorforOpeningFactor3(double heightFactorforOpeningFactor3);

  void resetHeightFactorforOpeningFactor3();

  bool setStartHeightFactorforOpeningFactor3(double startHeightFactorforOpeningFactor3);

  void resetStartHeightFactorforOpeningFactor3();

  bool setOpeningFactor4(boost::optional<double> openingFactor4);

  void resetOpeningFactor4();

  bool setDischargeCoefficientforOpeningFactor4(double dischargeCoefficientforOpeningFactor4);

  void resetDischargeCoefficientforOpeningFactor4();

  bool setWidthFactorforOpeningFactor4(double widthFactorforOpeningFactor4);

  void resetWidthFactorforOpeningFactor4();

  bool setHeightFactorforOpeningFactor4(double heightFactorforOpeningFactor4);

  void resetHeightFactorforOpeningFactor4();

  bool setStartHeightFactorforOpeningFactor4(double startHeightFactorforOpeningFactor4);

  void resetStartHeightFactorforOpeningFactor4();

  //@}
protected:
private:
  REGISTER_LOGGER("openstudio.model.AirflowNetworkMultiZoneComponentDetailedOpening");
};

} // detail

} // model
} // openstudio

#endif // MODEL_AIRFLOWNETWORKMULTIZONECOMPONENTDETAILEDOPENING_IMPL_HPP

