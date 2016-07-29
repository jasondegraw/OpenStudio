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

#ifndef MODEL_AIRFLOWNETWORKMULTIZONEREFERENCECRACKCONDITIONS_IMPL_HPP
#define MODEL_AIRFLOWNETWORKMULTIZONEREFERENCECRACKCONDITIONS_IMPL_HPP

#include <model/ModelAPI.hpp>
#include "ModelObject_Impl.hpp"

namespace openstudio {
namespace model {

namespace detail {

  /** AirflowNetworkMultiZoneReferenceCrackConditions_Impl is a ModelObject_Impl that is the implementation class for AirflowNetworkMultiZoneReferenceCrackConditions.*/
  class MODEL_API AirflowNetworkMultiZoneReferenceCrackConditions_Impl : public ModelObject_Impl {
   public:
    /** @name Constructors and Destructors */
    //@{

    AirflowNetworkMultiZoneReferenceCrackConditions_Impl(const IdfObject& idfObject,
                                                         Model_Impl* model,
                                                         bool keepHandle);

    AirflowNetworkMultiZoneReferenceCrackConditions_Impl(const openstudio::detail::WorkspaceObject_Impl& other,
                                                         Model_Impl* model,
                                                         bool keepHandle);

    AirflowNetworkMultiZoneReferenceCrackConditions_Impl(const AirflowNetworkMultiZoneReferenceCrackConditions_Impl& other,
                                                         Model_Impl* model,
                                                         bool keepHandle);

    virtual ~AirflowNetworkMultiZoneReferenceCrackConditions_Impl() {}

    //@}
    /** @name Virtual Methods */
    //@{

    virtual const std::vector<std::string>& outputVariableNames() const;

    virtual IddObjectType iddObjectType() const;

    //@}
    /** @name Getters */
    //@{

    double referenceTemperature() const;

    bool isReferenceTemperatureDefaulted() const;

    double referenceBarometricPressure() const;

    bool isReferenceBarometricPressureDefaulted() const;

    double referenceHumidityRatio() const;

    bool isReferenceHumidityRatioDefaulted() const;

    //@}
    /** @name Setters */
    //@{

    void setReferenceTemperature(double referenceTemperature);

    void resetReferenceTemperature();

    bool setReferenceBarometricPressure(double referenceBarometricPressure);

    void resetReferenceBarometricPressure();

    void setReferenceHumidityRatio(double referenceHumidityRatio);

    void resetReferenceHumidityRatio();

    //@}
    /** @name Other */
    //@{

    //@}
   protected:
   private:
    REGISTER_LOGGER("openstudio.model.AirflowNetworkMultiZoneReferenceCrackConditions");
  };

} // detail

} // model
} // openstudio

#endif // MODEL_AIRFLOWNETWORKMULTIZONEREFERENCECRACKCONDITIONS_IMPL_HPP

