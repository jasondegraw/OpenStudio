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

#ifndef MODEL_AIRFLOWNETWORKMULTIZONECOMPONENTZONEEXHAUSTFAN_HPP
#define MODEL_AIRFLOWNETWORKMULTIZONECOMPONENTZONEEXHAUSTFAN_HPP

#include <model/ModelAPI.hpp>
#include "ModelObject.hpp"

namespace openstudio {

namespace model {

class FanZoneExhaust;
class AirflowNetworkMultiZoneReferenceCrackConditions;

namespace detail {

class AirflowNetworkMultiZoneComponentZoneExhaustFan_Impl;

} // detail

/** AirflowNetworkMultiZoneComponentZoneExhaustFan is a ModelObject that wraps the OpenStudio IDD object 'OS:AirflowNetwork:MultiZoneComponentZoneExhaustFan'. */
class MODEL_API AirflowNetworkMultiZoneComponentZoneExhaustFan : public ModelObject {
 public:
  /** @name Constructors and Destructors */
  //@{

  AirflowNetworkMultiZoneComponentZoneExhaustFan(const Model& model, const FanZoneExhaust &fanZoneExhaust);

  virtual ~AirflowNetworkMultiZoneComponentZoneExhaustFan() {}

  //@}

  static IddObjectType iddObjectType();

  /** @name Getters */
  //@{
  /** Returns the FanZoneExhaust object associated with this object. */
  FanZoneExhaust fanZoneExhaust() const;
  /** Returns the mass flow coefficient in kg/s. */
  double airMassFlowCoefficientWhentheZoneExhaustFanisOffatReferenceConditions() const;
  /** Returns the mass flow exponent. */
  double airMassFlowExponentWhentheZoneExhaustFanisOff() const;
  /** Returns true if the mass flow exponent is defaulted. */
  bool isAirMassFlowExponentWhentheZoneExhaustFanisOffDefaulted() const;
  /** Returns a reference crack conditions object if available. */
  boost::optional<AirflowNetworkMultiZoneReferenceCrackConditions> referenceCrackConditions() const;

  //@}
  /** @name Setters */
  //@{
  /** Sets the FanZoneExhaust object associated with this object. */
  bool setFanZoneExhaust(const FanZoneExhaust& fanZoneExhaust);
  /** Sets the mass flow coefficient in kg/s.  */
  bool setAirMassFlowCoefficientWhentheZoneExhaustFanisOffatReferenceConditions(double airMassFlowCoefficientWhentheZoneExhaustFanisOffatReferenceConditions);
  /** Sets the mass flow exponent. */
  bool setAirMassFlowExponentWhentheZoneExhaustFanisOff(double airMassFlowExponentWhentheZoneExhaustFanisOff);
  /** Resets the mass flow exponent. */
  void resetAirMassFlowExponentWhentheZoneExhaustFanisOff();
  /** Sets the the reference crack conditions. */
  bool setReferenceCrackConditions(const AirflowNetworkMultiZoneReferenceCrackConditions& referenceCrackConditions);
  /** Resets the the reference crack conditions. */
  void resetReferenceCrackConditions();

  //@}
  /** @name Other */
  //@{

  //@}
 protected:
  /// @cond
  typedef detail::AirflowNetworkMultiZoneComponentZoneExhaustFan_Impl ImplType;

  explicit AirflowNetworkMultiZoneComponentZoneExhaustFan(std::shared_ptr<detail::AirflowNetworkMultiZoneComponentZoneExhaustFan_Impl> impl);

  friend class detail::AirflowNetworkMultiZoneComponentZoneExhaustFan_Impl;
  friend class Model;
  friend class IdfObject;
  friend class openstudio::detail::IdfObject_Impl;
  /// @endcond
 private:
  REGISTER_LOGGER("openstudio.model.AirflowNetworkMultiZoneComponentZoneExhaustFan");
};

/** \relates AirflowNetworkMultiZoneComponentZoneExhaustFan*/
typedef boost::optional<AirflowNetworkMultiZoneComponentZoneExhaustFan> OptionalAirflowNetworkMultiZoneComponentZoneExhaustFan;

/** \relates AirflowNetworkMultiZoneComponentZoneExhaustFan*/
typedef std::vector<AirflowNetworkMultiZoneComponentZoneExhaustFan> AirflowNetworkMultiZoneComponentZoneExhaustFanVector;

} // model
} // openstudio

#endif // MODEL_AIRFLOWNETWORKMULTIZONECOMPONENTZONEEXHAUSTFAN_HPP

