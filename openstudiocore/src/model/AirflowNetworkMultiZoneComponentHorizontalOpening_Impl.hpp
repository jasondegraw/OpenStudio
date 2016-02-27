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

#ifndef MODEL_AIRFLOWNETWORKMULTIZONECOMPONENTHORIZONTALOPENING_IMPL_HPP
#define MODEL_AIRFLOWNETWORKMULTIZONECOMPONENTHORIZONTALOPENING_IMPL_HPP

#include <model/ModelAPI.hpp>
#include <model/ModelObject_Impl.hpp>

namespace openstudio {
namespace model {

namespace detail {

/** AirflowNetworkMultiZoneComponentHorizontalOpening_Impl is a ModelObject_Impl that is the implementation class for AirflowNetworkMultiZoneComponentHorizontalOpening.*/
class MODEL_API AirflowNetworkMultiZoneComponentHorizontalOpening_Impl : public ModelObject_Impl
{
public:
  /** @name Constructors and Destructors */
  //@{

  AirflowNetworkMultiZoneComponentHorizontalOpening_Impl(const IdfObject& idfObject,
    Model_Impl* model,
    bool keepHandle);

  AirflowNetworkMultiZoneComponentHorizontalOpening_Impl(const openstudio::detail::WorkspaceObject_Impl& other,
    Model_Impl* model,
    bool keepHandle);

  AirflowNetworkMultiZoneComponentHorizontalOpening_Impl(const AirflowNetworkMultiZoneComponentHorizontalOpening_Impl& other,
    Model_Impl* model,
    bool keepHandle);

  virtual ~AirflowNetworkMultiZoneComponentHorizontalOpening_Impl() {}

  //@}
  /** @name Virtual Methods */
  //@{

  virtual const std::vector<std::string>& outputVariableNames() const;

  virtual IddObjectType iddObjectType() const;

  //@}
  /** @name Getters */
  //@{

  double airMassFlowCoefficientWhenOpeningisClosed() const;

  double airMassFlowExponentWhenOpeningisClosed() const;

  bool isAirMassFlowExponentWhenOpeningisClosedDefaulted() const;

  double slopingPlaneAngle() const;

  bool isSlopingPlaneAngleDefaulted() const;

  double dischargeCoefficient() const;

  //@}
  /** @name Setters */
  //@{

  bool setAirMassFlowCoefficientWhenOpeningisClosed(double airMassFlowCoefficientWhenOpeningisClosed);

  bool setAirMassFlowExponentWhenOpeningisClosed(double airMassFlowExponentWhenOpeningisClosed);

  void resetAirMassFlowExponentWhenOpeningisClosed();

  bool setSlopingPlaneAngle(double slopingPlaneAngle);

  void resetSlopingPlaneAngle();

  bool setDischargeCoefficient(double dischargeCoefficient);

  //@}
protected:
private:
  REGISTER_LOGGER("openstudio.model.AirflowNetworkMultiZoneComponentHorizontalOpening");
};

} // detail

} // model
} // openstudio

#endif // MODEL_AIRFLOWNETWORKMULTIZONECOMPONENTHORIZONTALOPENING_IMPL_HPP

