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
    std::vector<DetailedOpeningFactorData>& openingFactors);

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

  std::vector<DetailedOpeningFactorData> openingFactors() const;

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

  bool setOpeningFactors(std::vector<DetailedOpeningFactorData>& factors);

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

