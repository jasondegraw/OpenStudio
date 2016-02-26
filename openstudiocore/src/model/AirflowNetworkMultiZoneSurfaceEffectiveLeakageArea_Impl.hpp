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

#ifndef MODEL_AIRFLOWNETWORKMULTIZONESURFACEEFFECTIVELEAKAGEAREA_IMPL_HPP
#define MODEL_AIRFLOWNETWORKMULTIZONESURFACEEFFECTIVELEAKAGEAREA_IMPL_HPP

#include <model/ModelAPI.hpp>
#include <model/ModelObject_Impl.hpp>

namespace openstudio {
namespace model {

namespace detail {

/** AirflowNetworkMultiZoneSurfaceEffectiveLeakageArea_Impl is a ModelObject_Impl that is the implementation class for AirflowNetworkMultiZoneSurfaceEffectiveLeakageArea.*/
class MODEL_API AirflowNetworkMultiZoneSurfaceEffectiveLeakageArea_Impl : public ModelObject_Impl
{
public:
  /** @name Constructors and Destructors */
  //@{

  AirflowNetworkMultiZoneSurfaceEffectiveLeakageArea_Impl(const IdfObject& idfObject,
    Model_Impl* model,
    bool keepHandle);

  AirflowNetworkMultiZoneSurfaceEffectiveLeakageArea_Impl(const openstudio::detail::WorkspaceObject_Impl& other,
    Model_Impl* model,
    bool keepHandle);

  AirflowNetworkMultiZoneSurfaceEffectiveLeakageArea_Impl(const AirflowNetworkMultiZoneSurfaceEffectiveLeakageArea_Impl& other,
    Model_Impl* model,
    bool keepHandle);

  virtual ~AirflowNetworkMultiZoneSurfaceEffectiveLeakageArea_Impl() {}

  //@}
  /** @name Virtual Methods */
  //@{

  virtual const std::vector<std::string>& outputVariableNames() const;

  virtual IddObjectType iddObjectType() const;

  //@}
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
private:
  REGISTER_LOGGER("openstudio.model.AirflowNetworkMultiZoneSurfaceEffectiveLeakageArea");
};

} // detail

} // model
} // openstudio

#endif // MODEL_AIRFLOWNETWORKMULTIZONESURFACEEFFECTIVELEAKAGEAREA_IMPL_HPP

