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

class MODEL_API DetailedOpeningFactorData
{
public:
  /** @name Constructor */
  //@{
  DetailedOpeningFactorData(double openingFactor, double dischargeCoefficient, double widthFactor, double heightFactor,
    double startHeightFactor);

  //@}
  /** @name Getters */
  //@{
  /** For a rectangular non-pivoted window or door (LVO Type 1), the opening factor corresponds to the fraction of the 
   * window or door that is opened. For rectangular horizontally-pivoted windows (LVO Type 2), the opening factor is
   * the angular fraction that window is open. For example, an opening angle of 45 degrees corresponds to an opening
   * factor of 0.50 since the maximum opening angle is 90 degrees.
   */
  double openingFactor() const;
  /** The discharge coefficient indicates the fractional effectiveness for air flow through a window or door at
   * that Opening Factor.
   */
  double dischargeCoefficient() const;
  /** The width factor is the opening width divided by the window or door width. */
  double widthFactor() const;
  /** The height factor is the opening height divided by the window or door height. */
  double heightFactor() const;
  /** The start height factor is the start height divided by the window or door height.
   * Start height is the distance between the bottom of the window or door and the
   * bottom of the window or door opening. The sum of the height factor and the start height
   * factor must be less than 1.0 in order to have the opening within the window or door dimensions.
   */
  double startHeightFactor() const;

  //@}
  /** @name Setters */
  //@{
  /** Sets the opening factor. */
  bool setOpeningFactor(double openingFactor);
  /** Sets the discharge coefficient. */
  bool setDischargeCoefficient(double dischargeCoefficient);
  /** Sets the width factor. */
  bool setWidthFactor(double widthFactor);
  /** Sets the height factor. */
  bool setHeightFactor(double heightFactor);
  /** Sets the start height factor. */
  bool setStartHeightFactor(double startHeightFactor);
  //@}
private:
  double m_openingFactor;
  double m_dischargeCoefficient;
  double m_widthFactor;
  double m_heightFactor;
  double m_startHeightFactor;

};

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
    std::string typeofRectangularLargeVerticalOpening,
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
    std::string typeofRectangularLargeVerticalOpening,
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
    std::string typeofRectangularLargeVerticalOpening,
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

  AirflowNetworkMultiZoneComponentDetailedOpening(const Model& model,
    double massFlowCoefficientWhenOpeningisClosed,
    double massFlowExponentWhenOpeningisClosed,
    std::string typeofRectangularLargeVerticalOpening,
    double extraCrackLengthorHeightofPivotingAxis,
    std::vector<DetailedOpeningFactorData> data);

  virtual ~AirflowNetworkMultiZoneComponentDetailedOpening() {}

  //@}

  static IddObjectType iddObjectType();

  static std::vector<std::string> typeofRectangularLargeVerticalOpeningValues();

  /** @name Getters */
  //@{

  double airMassFlowCoefficientWhenOpeningisClosed() const;

  double airMassFlowExponentWhenOpeningisClosed() const;

  bool isAirMassFlowExponentWhenOpeningisClosedDefaulted() const;

  std::string typeofRectangularLargeVerticalOpening() const;

  bool isTypeofRectangularLargeVerticalOpeningDefaulted() const;

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

  bool setTypeofRectangularLargeVerticalOpening(std::string typeofRectangularLargeVerticalOpening);

  void resetTypeofRectangularLargeVerticalOpening();

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

