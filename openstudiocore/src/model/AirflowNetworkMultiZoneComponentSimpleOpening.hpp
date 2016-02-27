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

#ifndef MODEL_AIRFLOWNETWORKMULTIZONECOMPONENTSIMPLEOPENING_HPP
#define MODEL_AIRFLOWNETWORKMULTIZONECOMPONENTSIMPLEOPENING_HPP

#include <model/ModelAPI.hpp>
#include <model/ModelObject.hpp>

namespace openstudio {

namespace model {

namespace detail {

class AirflowNetworkMultiZoneComponentSimpleOpening_Impl;

} // detail

/** AirflowNetworkMultiZoneComponentSimpleOpening is a ModelObject that wraps the OpenStudio IDD object 'OS:AirflowNetworkMultiZoneComponentSimpleOpening'. */
class MODEL_API AirflowNetworkMultiZoneComponentSimpleOpening : public ModelObject
{
public:
  /** @name Constructors and Destructors */
  //@{
  /** Construct a simple opening object with default mass flow exponent. */
  AirflowNetworkMultiZoneComponentSimpleOpening(const Model& model,
    double massFlowCoefficientWhenOpeningisClosed,
    double minimumDensityDifferenceforTwoWayFlow,
    double dischargeCoefficient);
  /** Construct a simple opening object. */
  AirflowNetworkMultiZoneComponentSimpleOpening(const Model& model,
    double massFlowCoefficientWhenOpeningisClosed,
    double massFlowExponentWhenOpeningisClosed,
    double minimumDensityDifferenceforTwoWayFlow,
    double dischargeCoefficient);

  virtual ~AirflowNetworkMultiZoneComponentSimpleOpening() {}

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
  /** Returns the minimum density difference above which two-way flow may occur due to stack effect in kg/m3. */
  double minimumDensityDifferenceforTwoWayFlow() const;
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
  /** Sets the minimum density difference above which two-way flow may occur due to stack effect in kg/m3. */
  bool setMinimumDensityDifferenceforTwoWayFlow(double minimumDensityDifferenceforTwoWayFlow);
  /** Sets the discharge coefficient. */
  bool setDischargeCoefficient(double dischargeCoefficient);

  //@}
protected:
  /// @cond
  typedef detail::AirflowNetworkMultiZoneComponentSimpleOpening_Impl ImplType;

  explicit AirflowNetworkMultiZoneComponentSimpleOpening(std::shared_ptr<detail::AirflowNetworkMultiZoneComponentSimpleOpening_Impl> impl);

  friend class detail::AirflowNetworkMultiZoneComponentSimpleOpening_Impl;
  friend class Model;
  friend class IdfObject;
  friend class openstudio::detail::IdfObject_Impl;
  /// @endcond
private:
  REGISTER_LOGGER("openstudio.model.AirflowNetworkMultiZoneComponentSimpleOpening");
};

/** \relates AirflowNetworkMultiZoneComponentSimpleOpening*/
typedef boost::optional<AirflowNetworkMultiZoneComponentSimpleOpening> OptionalAirflowNetworkMultiZoneComponentSimpleOpening;

/** \relates AirflowNetworkMultiZoneComponentSimpleOpening*/
typedef std::vector<AirflowNetworkMultiZoneComponentSimpleOpening> AirflowNetworkMultiZoneComponentSimpleOpeningVector;

} // model
} // openstudio

#endif // MODEL_AIRFLOWNETWORKMULTIZONECOMPONENTSIMPLEOPENING_HPP

