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

#ifndef MODEL_AIRFLOWNETWORKMULTIZONESURFACEEFFECTIVELEAKAGEAREA_HPP
#define MODEL_AIRFLOWNETWORKMULTIZONESURFACEEFFECTIVELEAKAGEAREA_HPP

#include <model/ModelAPI.hpp>
#include <model/ModelObject.hpp>

namespace openstudio {

namespace model {

namespace detail {

class AirflowNetworkMultiZoneSurfaceEffectiveLeakageArea_Impl;

} // detail

/** AirflowNetworkMultiZoneSurfaceEffectiveLeakageArea is a ModelObject that wraps the OpenStudio IDD object 'OS:AirflowNetworkMultiZoneSurfaceEffectiveLeakageArea'. */
class MODEL_API AirflowNetworkMultiZoneSurfaceEffectiveLeakageArea : public ModelObject {
public:
  /** @name Constructors and Destructors */
  //@{
  /** Construct an effective leakage area object with default values and a specified effective leakage area. */
  AirflowNetworkMultiZoneSurfaceEffectiveLeakageArea(const Model& model, double effectiveLeakageArea);
  /** Construct an effective leakage area object. */
  AirflowNetworkMultiZoneSurfaceEffectiveLeakageArea(const Model& model, double effectiveLeakageArea,
    double dischargeCoefficient, double referencePressureDifference, double massFlowExponent);

  virtual ~AirflowNetworkMultiZoneSurfaceEffectiveLeakageArea() {}

  //@}

  static IddObjectType iddObjectType();

  /** @name Getters */
  //@{
  /** Returns the effective leakage area in square meters. */
  double effectiveLeakageArea() const;
  /** Returns the discharge coefficient. */
  double dischargeCoefficient() const;
  /** Returns true if the discharge coefficient is defaulted. */
  bool isDischargeCoefficientDefaulted() const;
  /** Returns the reference pressure difference in Pa. */
  double referencePressureDifference() const;
  /** Returns true if the reference pressure difference is defaulted. */
  bool isReferencePressureDifferenceDefaulted() const;
  /** Returns the mass flow exponent. */
  double airMassFlowExponent() const;
  /** Returns true if the mass flow exponent. */
  bool isAirMassFlowExponentDefaulted() const;

  //@}
  /** @name Setters */
  //@{
  /** Sets the effective leakage area in square meters. */
  bool setEffectiveLeakageArea(double effectiveLeakageArea);
  /** Sets the discharge coefficient. */
  bool setDischargeCoefficient(double dischargeCoefficient);
  /** Returns the discharge coefficient to the default value. */
  void resetDischargeCoefficient();
  /** Sets the reference pressure difference in Pa. */
  bool setReferencePressureDifference(double referencePressureDifference);
  /** Returns the reference pressure difference to the default value. */
  void resetReferencePressureDifference();
  /** Sets the mass flow exponent. */
  bool setAirMassFlowExponent(double airMassFlowExponent);
  /** Returns the mass flow exponent to the default value. */
  void resetAirMassFlowExponent();

  //@}
protected:
  /// @cond
  typedef detail::AirflowNetworkMultiZoneSurfaceEffectiveLeakageArea_Impl ImplType;

  explicit AirflowNetworkMultiZoneSurfaceEffectiveLeakageArea(std::shared_ptr<detail::AirflowNetworkMultiZoneSurfaceEffectiveLeakageArea_Impl> impl);

  friend class detail::AirflowNetworkMultiZoneSurfaceEffectiveLeakageArea_Impl;
  friend class Model;
  friend class IdfObject;
  friend class openstudio::detail::IdfObject_Impl;
  /// @endcond
private:
  REGISTER_LOGGER("openstudio.model.AirflowNetworkMultiZoneSurfaceEffectiveLeakageArea");
};

/** \relates AirflowNetworkMultiZoneSurfaceEffectiveLeakageArea*/
typedef boost::optional<AirflowNetworkMultiZoneSurfaceEffectiveLeakageArea> OptionalAirflowNetworkMultiZoneSurfaceEffectiveLeakageArea;

/** \relates AirflowNetworkMultiZoneSurfaceEffectiveLeakageArea*/
typedef std::vector<AirflowNetworkMultiZoneSurfaceEffectiveLeakageArea> AirflowNetworkMultiZoneSurfaceEffectiveLeakageAreaVector;

} // model
} // openstudio

#endif // MODEL_AIRFLOWNETWORKMULTIZONESURFACEEFFECTIVELEAKAGEAREA_HPP

