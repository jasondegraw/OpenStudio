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

#ifndef MODEL_AIRFLOWNETWORKMULTIZONESURFACECRACK_IMPL_HPP
#define MODEL_AIRFLOWNETWORKMULTIZONESURFACECRACK_IMPL_HPP

#include <model/ModelAPI.hpp>
#include <model/ModelObject_Impl.hpp>

namespace openstudio {
namespace model {

// TODO: Check the following class names against object getters and setters.
class AirflowNetworkMultiZoneReferenceCrackConditions;

namespace detail {

  /** AirflowNetworkMultiZoneSurfaceCrack_Impl is a ModelObject_Impl that is the implementation class for AirflowNetworkMultiZoneSurfaceCrack.*/
  class MODEL_API AirflowNetworkMultiZoneSurfaceCrack_Impl : public ModelObject_Impl {
    Q_OBJECT;
   public:
    /** @name Constructors and Destructors */
    //@{

    AirflowNetworkMultiZoneSurfaceCrack_Impl(const IdfObject& idfObject,
                                             Model_Impl* model,
                                             bool keepHandle);

    AirflowNetworkMultiZoneSurfaceCrack_Impl(const openstudio::detail::WorkspaceObject_Impl& other,
                                             Model_Impl* model,
                                             bool keepHandle);

    AirflowNetworkMultiZoneSurfaceCrack_Impl(const AirflowNetworkMultiZoneSurfaceCrack_Impl& other,
                                             Model_Impl* model,
                                             bool keepHandle);

    virtual ~AirflowNetworkMultiZoneSurfaceCrack_Impl() {}

    //@}
    /** @name Virtual Methods */
    //@{

    virtual const std::vector<std::string>& outputVariableNames() const;

    virtual IddObjectType iddObjectType() const;

    //@}
    /** @name Getters */
    //@{

    double airMassFlowCoefficientatReferenceConditions() const;

    double airMassFlowExponent() const;

    bool isAirMassFlowExponentDefaulted() const;

    // TODO: Check return type. From object lists, some candidates are: ReferenceCrackConditions.
    boost::optional<AirflowNetworkMultiZoneReferenceCrackConditions> referenceCrackConditions() const;

    //@}
    /** @name Setters */
    //@{

    bool setAirMassFlowCoefficientatReferenceConditions(double airMassFlowCoefficientatReferenceConditions);

    bool setAirMassFlowExponent(double airMassFlowExponent);

    void resetAirMassFlowExponent();

    // TODO: Check argument type. From object lists, some candidates are: ReferenceCrackConditions.
    bool setReferenceCrackConditions(const boost::optional<AirflowNetworkMultiZoneReferenceCrackConditions>& referenceCrackConditions);

    void resetReferenceCrackConditions();

    //@}
    /** @name Other */
    //@{

    //@}
   protected:
   private:
    REGISTER_LOGGER("openstudio.model.AirflowNetworkMultiZoneSurfaceCrack");
  };

} // detail

} // model
} // openstudio

#endif // MODEL_AIRFLOWNETWORKMULTIZONESURFACECRACK_IMPL_HPP

