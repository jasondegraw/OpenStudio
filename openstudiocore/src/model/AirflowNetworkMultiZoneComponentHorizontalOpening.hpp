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

#ifndef MODEL_AIRFLOWNETWORKMULTIZONECOMPONENTHORIZONTALOPENING_HPP
#define MODEL_AIRFLOWNETWORKMULTIZONECOMPONENTHORIZONTALOPENING_HPP

#include <model/ModelAPI.hpp>
#include <model/ModelObject.hpp>

namespace openstudio {

namespace model {

namespace detail {

class AirflowNetworkMultiZoneComponentHorizontalOpening_Impl;

} // detail

/** AirflowNetworkMultiZoneComponentHorizontalOpening is a ModelObject that wraps the OpenStudio IDD object 'OS:AirflowNetworkMultiZoneComponentHorizontalOpening'. */
class MODEL_API AirflowNetworkMultiZoneComponentHorizontalOpening : public ModelObject
{
public:
  /** @name Constructors and Destructors */
  //@{
  /** Construct a horizontal opening object with default mass flow exponent and sloping plane angle. */
  AirflowNetworkMultiZoneComponentHorizontalOpening(const Model& model,
    double massFlowCoefficientWhenOpeningisClosed,
    double dischargeCoefficient);
  /** Construct a horizontal opening object. */
  AirflowNetworkMultiZoneComponentHorizontalOpening(const Model& model,
    double massFlowCoefficientWhenOpeningisClosed,
    double massFlowExponentWhenOpeningisClosed,
    double slopingPlaneAngle,
    double dischargeCoefficient);

  virtual ~AirflowNetworkMultiZoneComponentHorizontalOpening() {}

  //@}

  static IddObjectType iddObjectType();

  /** @name Getters */
  //@{
  /** Returns the mass flow coefficient when the opening is closed in kg/s-m at 1 Pa pressure difference. */
  double airMassFlowCoefficientWhenOpeningisClosed() const;
  /** Returns the mass flow exponent when the opening is closed. */
  double airMassFlowExponentWhenOpeningisClosed() const;
  /** Returns true if the  mass flow exponent is defaulted. */
  bool isAirMassFlowExponentWhenOpeningisClosedDefaulted() const;
  /** Returns the angle of the horizontal opening to a sloping plane beneath it (reducing the effective opening area)
      in degrees, 90 degrees corresponds to fully open. */
  double slopingPlaneAngle() const;
  /** Returns true if the sloping plane angle is defaulted. */
  bool isSlopingPlaneAngleDefaulted() const;
  /** Returns the discharge coefficient. */
  double dischargeCoefficient() const;

  //@}
  /** @name Setters */
  //@{
  /** Sets the mass flow coefficient when the opening is closed in kg/s-m at 1 Pa pressure difference. */
  bool setAirMassFlowCoefficientWhenOpeningisClosed(double airMassFlowCoefficientWhenOpeningisClosed);
  /** Sets the mass flow exponent when the opening is closed. */
  bool setAirMassFlowExponentWhenOpeningisClosed(double airMassFlowExponentWhenOpeningisClosed);
  /** Resets the mass flow exponent when the opening is closed to the default value. */
  void resetAirMassFlowExponentWhenOpeningisClosed();
  /** Sets the angle of the horizontal opening to a sloping plane beneath it (reducing the effective opening area)
  in degrees, 90 degrees corresponds to fully open. */
  bool setSlopingPlaneAngle(double slopingPlaneAngle);
  /** Resets the sloping plane to the default value. */
  void resetSlopingPlaneAngle();
  /** Sets the discharge coefficient. */
  bool setDischargeCoefficient(double dischargeCoefficient);

  //@}
protected:
  /// @cond
  typedef detail::AirflowNetworkMultiZoneComponentHorizontalOpening_Impl ImplType;

  explicit AirflowNetworkMultiZoneComponentHorizontalOpening(std::shared_ptr<detail::AirflowNetworkMultiZoneComponentHorizontalOpening_Impl> impl);

  friend class detail::AirflowNetworkMultiZoneComponentHorizontalOpening_Impl;
  friend class Model;
  friend class IdfObject;
  friend class openstudio::detail::IdfObject_Impl;
  /// @endcond
private:
  REGISTER_LOGGER("openstudio.model.AirflowNetworkMultiZoneComponentHorizontalOpening");
};

/** \relates AirflowNetworkMultiZoneComponentHorizontalOpening*/
typedef boost::optional<AirflowNetworkMultiZoneComponentHorizontalOpening> OptionalAirflowNetworkMultiZoneComponentHorizontalOpening;

/** \relates AirflowNetworkMultiZoneComponentHorizontalOpening*/
typedef std::vector<AirflowNetworkMultiZoneComponentHorizontalOpening> AirflowNetworkMultiZoneComponentHorizontalOpeningVector;

} // model
} // openstudio

#endif // MODEL_AIRFLOWNETWORKMULTIZONECOMPONENTHORIZONTALOPENING_HPP

