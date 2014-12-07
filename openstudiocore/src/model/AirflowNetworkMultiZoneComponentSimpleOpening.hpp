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

  explicit AirflowNetworkMultiZoneComponentSimpleOpening(const Model& model);

  virtual ~AirflowNetworkMultiZoneComponentSimpleOpening() {}

  //@}

  static IddObjectType iddObjectType();

  /** @name Getters */
  //@{

  double airMassFlowCoefficientWhenOpeningisClosed() const;

  double airMassFlowExponentWhenOpeningisClosed() const;

  bool isAirMassFlowExponentWhenOpeningisClosedDefaulted() const;

  double minimumDensityDifferenceforTwoWayFlow() const;

  double dischargeCoefficient() const;

  //@}
  /** @name Setters */
  //@{

  bool setAirMassFlowCoefficientWhenOpeningisClosed(double airMassFlowCoefficientWhenOpeningisClosed);

  bool setAirMassFlowExponentWhenOpeningisClosed(double airMassFlowExponentWhenOpeningisClosed);

  void resetAirMassFlowExponentWhenOpeningisClosed();

  bool setMinimumDensityDifferenceforTwoWayFlow(double minimumDensityDifferenceforTwoWayFlow);

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

