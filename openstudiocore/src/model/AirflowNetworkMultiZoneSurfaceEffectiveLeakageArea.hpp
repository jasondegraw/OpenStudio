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

  explicit AirflowNetworkMultiZoneSurfaceEffectiveLeakageArea(const Model& model);

  virtual ~AirflowNetworkMultiZoneSurfaceEffectiveLeakageArea() {}

  //@}

  static IddObjectType iddObjectType();

  /** @name Getters */
  //@{

  double effectiveLeakageArea() const;

  double dischargeCoefficient() const;

  bool isDischargeCoefficientDefaulted() const;

  double referencePressureDifference() const;

  bool isReferencePressureDifferenceDefaulted() const;

  double airMassFlowExponent() const;

  bool isAirMassFlowExponentDefaulted() const;

  //@}
  /** @name Setters */
  //@{

  bool setEffectiveLeakageArea(double effectiveLeakageArea);

  bool setDischargeCoefficient(double dischargeCoefficient);

  void resetDischargeCoefficient();

  bool setReferencePressureDifference(double referencePressureDifference);

  void resetReferencePressureDifference();

  bool setAirMassFlowExponent(double airMassFlowExponent);

  void resetAirMassFlowExponent();

  //@}
  /** @name Other */
  //@{

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

