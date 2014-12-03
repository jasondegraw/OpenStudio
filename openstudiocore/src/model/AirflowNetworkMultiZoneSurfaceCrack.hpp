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

class AirflowNetworkMultiZoneReferenceCrackConditions;

namespace detail {

class AirflowNetworkMultiZoneSurfaceCrack_Impl;

} // detail

/** AirflowNetworkMultiZoneSurfaceCrack is a ModelObject that wraps the OpenStudio IDD object 'OS:AirflowNetworkMultiZoneSurfaceCrack'. */
class MODEL_API AirflowNetworkMultiZoneSurfaceCrack : public ModelObject
{
public:
  /** @name Constructors and Destructors */
  //@{

  explicit AirflowNetworkMultiZoneSurfaceCrack(const Model& model);

  virtual ~AirflowNetworkMultiZoneSurfaceCrack() {}

  //@}

  static IddObjectType iddObjectType();

  /** @name Getters */
  //@{

  double airMassFlowCoefficientatReferenceConditions() const;

  double airMassFlowExponent() const;

  bool isAirMassFlowExponentDefaulted() const;

  boost::optional<AirflowNetworkMultiZoneReferenceCrackConditions> referenceCrackConditions() const;

  //@}
  /** @name Setters */
  //@{

  bool setAirMassFlowCoefficientatReferenceConditions(double airMassFlowCoefficientatReferenceConditions);

  bool setAirMassFlowExponent(double airMassFlowExponent);

  void resetAirMassFlowExponent();

  bool setReferenceCrackConditions(const AirflowNetworkMultiZoneReferenceCrackConditions& referenceCrackConditions);

  void resetReferenceCrackConditions();

  //@}
  /** @name Other */
  //@{

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

