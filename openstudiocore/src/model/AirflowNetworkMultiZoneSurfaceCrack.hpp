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

#ifndef MODEL_AIRFLOWNETWORKMULTIZONESURFACECRACK_HPP
#define MODEL_AIRFLOWNETWORKMULTIZONESURFACECRACK_HPP

#include <model/ModelAPI.hpp>
#include <model/ModelObject.hpp>

namespace openstudio {

namespace model {

namespace detail {

class AirflowNetworkMultiZoneSurfaceCrack_Impl;

} // detail

/** AirflowNetworkMultiZoneSurfaceCrack is a ModelObject that wraps the OpenStudio IDD object 'OS:AirflowNetworkMultiZoneSurfaceCrack'. */
class MODEL_API AirflowNetworkMultiZoneSurfaceCrack : public ModelObject
{
public:
  /** @name Constructors and Destructors */
  //@{
  /** Construct a surface crack object with default values and a specified mass flow coefficient. */
  AirflowNetworkMultiZoneSurfaceCrack(const Model& model, double massFlowCoefficient);
  /** Construct a surface crack object without a reference conditions object. */
  AirflowNetworkMultiZoneSurfaceCrack(const Model& model, double massFlowCoefficient,
    double massFlowExponent);
  /** Construct a surface crack object. */
  AirflowNetworkMultiZoneSurfaceCrack(const Model& model, double massFlowCoefficient, double massFlowExponent,
    double referenceTemperature, double referenceBarometricPressure, double referenceHumidityRatio);

  virtual ~AirflowNetworkMultiZoneSurfaceCrack() {}

  //@}

  static IddObjectType iddObjectType();

  /** @name Getters */
  //@{
  /** Returns the mass flow coefficient in kg/s at 1 Pa. */
  double airMassFlowCoefficientatReferenceConditions() const;
  /** Returns the mass flow exponent. */
  double airMassFlowExponent() const;
  /** Returns true if the mass flow exponent is defaulted. */
  bool isAirMassFlowExponentDefaulted() const;
  /** Returns the reference temperature in degrees C. */
  double referenceTemperature() const;
  /** Returns true if the reference temperature is defaulted. */
  bool isReferenceTemperatureDefaulted() const;
  /** Returns the reference barometric pressure in Pa. */
  double referenceBarometricPressure() const;
  /** Returns true if the reference barometric pressure is defaulted. */
  bool isReferenceBarometricPressureDefaulted() const;
  /** Returns the reference humidity ratio in kgWater/kgDryAir. */
  double referenceHumidityRatio() const;
  /** Returns true if the reference humidity ratio is defaulted. */
  bool isReferenceHumidityRatioDefaulted() const;

  //@}
  /** @name Setters */
  //@{
  /** Sets the mass flow coefficient in kg/s at 1 Pa.  */
  bool setAirMassFlowCoefficientatReferenceConditions(double airMassFlowCoefficientatReferenceConditions);
  /** Sets the mass flow exponent. */
  bool setAirMassFlowExponent(double airMassFlowExponent);
  /** Returns the mass flow exponent to the default value. */
  void resetAirMassFlowExponent();
  /** Sets the reference temperature in degrees C. */
  void setReferenceTemperature(double referenceTemperature);
  /** Resets the reference temperature to the default. */
  void resetReferenceTemperature();
  /** Sets the the reference barometric pressure in Pa. */
  bool setReferenceBarometricPressure(double referenceBarometricPressure);
  /** Resets the reference barometric pressure to the default. */
  void resetReferenceBarometricPressure();
  /** Sets the reference humidity ratio in kgWater/kgDryAir. */
  void setReferenceHumidityRatio(double referenceHumidityRatio);
  /** Resets the reference humidity ratio to the default. */
  void resetReferenceHumidityRatio();

  //@}
protected:
  /// @cond
  typedef detail::AirflowNetworkMultiZoneSurfaceCrack_Impl ImplType;

  explicit AirflowNetworkMultiZoneSurfaceCrack(std::shared_ptr<detail::AirflowNetworkMultiZoneSurfaceCrack_Impl> impl);

  friend class detail::AirflowNetworkMultiZoneSurfaceCrack_Impl;
  friend class Model;
  friend class IdfObject;
  friend class openstudio::detail::IdfObject_Impl;
  /// @endcond
private:
  REGISTER_LOGGER("openstudio.model.AirflowNetworkMultiZoneSurfaceCrack");
};

/** \relates AirflowNetworkMultiZoneSurfaceCrack*/
typedef boost::optional<AirflowNetworkMultiZoneSurfaceCrack> OptionalAirflowNetworkMultiZoneSurfaceCrack;

/** \relates AirflowNetworkMultiZoneSurfaceCrack*/
typedef std::vector<AirflowNetworkMultiZoneSurfaceCrack> AirflowNetworkMultiZoneSurfaceCrackVector;

} // model
} // openstudio

#endif // MODEL_AIRFLOWNETWORKMULTIZONESURFACECRACK_HPP

