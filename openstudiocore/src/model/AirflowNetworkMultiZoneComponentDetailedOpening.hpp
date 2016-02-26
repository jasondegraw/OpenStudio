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

#ifndef MODEL_AIRFLOWNETWORKMULTIZONECOMPONENTDETAILEDOPENING_HPP
#define MODEL_AIRFLOWNETWORKMULTIZONECOMPONENTDETAILEDOPENING_HPP

#include <model/ModelAPI.hpp>
#include <model/ModelObject.hpp>

namespace openstudio {

namespace model {

namespace detail {

class AirflowNetworkMultiZoneComponentDetailedOpening_Impl;

} // detail

/** AirflowNetworkMultiZoneComponentDetailedOpening is a ModelObject that wraps the OpenStudio IDD object 'OS:AirflowNetworkMultiZoneComponentDetailedOpening'. */
class MODEL_API AirflowNetworkMultiZoneComponentDetailedOpening : public ModelObject 
{
public:
  /** @name Constructors and Destructors */
  //@{

  AirflowNetworkMultiZoneComponentDetailedOpening(const Model& model,
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
    double startHeightFactorforOpeningFactor2);

  AirflowNetworkMultiZoneComponentDetailedOpening(const Model& model,
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
    double startHeightFactorforOpeningFactor3);

  AirflowNetworkMultiZoneComponentDetailedOpening(const Model& model,
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
    double startHeightFactorforOpeningFactor4);

  virtual ~AirflowNetworkMultiZoneComponentDetailedOpening() {}

  //@}

  static IddObjectType iddObjectType();

  static std::vector<std::string> typeofRectangulerLargeVerticalOpeningValues();

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

  bool setOpeningFactor3(double openingFactor3);

  void resetOpeningFactor3();

  bool setDischargeCoefficientforOpeningFactor3(double dischargeCoefficientforOpeningFactor3);

  void resetDischargeCoefficientforOpeningFactor3();

  bool setWidthFactorforOpeningFactor3(double widthFactorforOpeningFactor3);

  void resetWidthFactorforOpeningFactor3();

  bool setHeightFactorforOpeningFactor3(double heightFactorforOpeningFactor3);

  void resetHeightFactorforOpeningFactor3();

  bool setStartHeightFactorforOpeningFactor3(double startHeightFactorforOpeningFactor3);

  void resetStartHeightFactorforOpeningFactor3();

  bool setOpeningFactor4(double openingFactor4);

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
  /// @cond
  typedef detail::AirflowNetworkMultiZoneComponentDetailedOpening_Impl ImplType;

  explicit AirflowNetworkMultiZoneComponentDetailedOpening(std::shared_ptr<detail::AirflowNetworkMultiZoneComponentDetailedOpening_Impl> impl);

  friend class detail::AirflowNetworkMultiZoneComponentDetailedOpening_Impl;
  friend class Model;
  friend class IdfObject;
  friend class openstudio::detail::IdfObject_Impl;
  /// @endcond
private:
  REGISTER_LOGGER("openstudio.model.AirflowNetworkMultiZoneComponentDetailedOpening");
};

/** \relates AirflowNetworkMultiZoneComponentDetailedOpening*/
typedef boost::optional<AirflowNetworkMultiZoneComponentDetailedOpening> OptionalAirflowNetworkMultiZoneComponentDetailedOpening;

/** \relates AirflowNetworkMultiZoneComponentDetailedOpening*/
typedef std::vector<AirflowNetworkMultiZoneComponentDetailedOpening> AirflowNetworkMultiZoneComponentDetailedOpeningVector;

} // model
} // openstudio

#endif // MODEL_AIRFLOWNETWORKMULTIZONECOMPONENTDETAILEDOPENING_HPP

