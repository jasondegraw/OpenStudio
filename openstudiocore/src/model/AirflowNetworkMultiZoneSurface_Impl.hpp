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

#ifndef MODEL_AIRFLOWNETWORKMULTIZONESURFACE_IMPL_HPP
#define MODEL_AIRFLOWNETWORKMULTIZONESURFACE_IMPL_HPP

#include <model/ModelAPI.hpp>
#include "ModelObject_Impl.hpp"

namespace openstudio {
namespace model {

// TODO: Check the following class names against object getters and setters.
class PlanarSurface;
//class SurfaceAirflowLeakage;
//class ExternalNode;
//class Schedule;
class Schedule;
//class AirflowNetworkOccupantVentilationControl;

namespace detail {

  /** AirflowNetworkMultiZoneSurface_Impl is a ModelObject_Impl that is the implementation class for AirflowNetworkMultiZoneSurface.*/
  class MODEL_API AirflowNetworkMultiZoneSurface_Impl : public ModelObject_Impl {
   public:
    /** @name Constructors and Destructors */
    //@{

    AirflowNetworkMultiZoneSurface_Impl(const IdfObject& idfObject,
                                        Model_Impl* model,
                                        bool keepHandle);

    AirflowNetworkMultiZoneSurface_Impl(const openstudio::detail::WorkspaceObject_Impl& other,
                                        Model_Impl* model,
                                        bool keepHandle);

    AirflowNetworkMultiZoneSurface_Impl(const AirflowNetworkMultiZoneSurface_Impl& other,
                                        Model_Impl* model,
                                        bool keepHandle);

    virtual ~AirflowNetworkMultiZoneSurface_Impl() {}

    //@}
    /** @name Virtual Methods */
    //@{

    virtual const std::vector<std::string>& outputVariableNames() const;

    virtual IddObjectType iddObjectType() const;

    virtual std::vector<ScheduleTypeKey> getScheduleTypeKeys(const Schedule& schedule) const;

    //@}
    /** @name Getters */
    //@{

    // TODO: Check return type. From object lists, some candidates are: SurfAndSubSurf.
    PlanarSurface surface() const;

    // TODO: Check return type. From object lists, some candidates are: SurfaceAirflowLeakage.
    //SurfaceAirflowLeakage leakageComponent() const;

    // TODO: Check return type. From object lists, some candidates are: ExternalNode.
    //boost::optional<ExternalNode> externalNode() const;

    double windowDoorOpeningFactorOrCrackFactor() const;

    bool isWindowDoorOpeningFactorOrCrackFactorDefaulted() const;

    std::string ventilationControlMode() const;

    bool isVentilationControlModeDefaulted() const;

    // TODO: Check return type. From object lists, some candidates are: Schedule.
    boost::optional<Schedule> ventilationControlZoneTemperatureSetpointSchedule() const;

    double minimumVentingOpenFactor() const;

    bool isMinimumVentingOpenFactorDefaulted() const;

    double indoorandOutdoorTemperatureDifferenceLowerLimitForMaximumVentingOpenFactor() const;

    bool isIndoorandOutdoorTemperatureDifferenceLowerLimitForMaximumVentingOpenFactorDefaulted() const;

    double indoorandOutdoorTemperatureDifferenceUpperLimitforMinimumVentingOpenFactor() const;

    bool isIndoorandOutdoorTemperatureDifferenceUpperLimitforMinimumVentingOpenFactorDefaulted() const;

    double indoorandOutdoorEnthalpyDifferenceLowerLimitForMaximumVentingOpenFactor() const;

    bool isIndoorandOutdoorEnthalpyDifferenceLowerLimitForMaximumVentingOpenFactorDefaulted() const;

    double indoorandOutdoorEnthalpyDifferenceUpperLimitforMinimumVentingOpenFactor() const;

    bool isIndoorandOutdoorEnthalpyDifferenceUpperLimitforMinimumVentingOpenFactorDefaulted() const;

    // TODO: Check return type. From object lists, some candidates are: Schedule.
    boost::optional<Schedule> ventingAvailabilitySchedule() const;

    // TODO: Check return type. From object lists, some candidates are: AirflowNetworkOccupantVentilationControl.
    //boost::optional<AirflowNetworkOccupantVentilationControl> occupantVentilationControl() const;

    //@}
    /** @name Setters */
    //@{

    // TODO: Check argument type. From object lists, some candidates are: SurfAndSubSurf.
    bool setSurface(const PlanarSurface& surfAndSubSurf);

    // TODO: Check argument type. From object lists, some candidates are: SurfaceAirflowLeakage.
    //bool setLeakageComponent(const SurfaceAirflowLeakage& surfaceAirflowLeakage);

    // TODO: Check argument type. From object lists, some candidates are: ExternalNode.
    //bool setExternalNode(const boost::optional<ExternalNode>& externalNode);

    //void resetExternalNode();

    bool setWindowDoorOpeningFactorOrCrackFactor(double windowDoorOpeningFactorOrCrackFactor);

    void resetWindowDoorOpeningFactorOrCrackFactor();

    bool setVentilationControlMode(std::string ventilationControlMode);

    void resetVentilationControlMode();

    // TODO: Check argument type. From object lists, some candidates are: Schedule.
    bool setVentilationControlZoneTemperatureSetpointSchedule(Schedule& schedule);

    void resetVentilationControlZoneTemperatureSetpointSchedule();

    bool setMinimumVentingOpenFactor(double minimumVentingOpenFactor);

    void resetMinimumVentingOpenFactor();

    bool setIndoorandOutdoorTemperatureDifferenceLowerLimitForMaximumVentingOpenFactor(double indoorandOutdoorTemperatureDifferenceLowerLimitForMaximumVentingOpenFactor);

    void resetIndoorandOutdoorTemperatureDifferenceLowerLimitForMaximumVentingOpenFactor();

    bool setIndoorandOutdoorTemperatureDifferenceUpperLimitforMinimumVentingOpenFactor(double indoorandOutdoorTemperatureDifferenceUpperLimitforMinimumVentingOpenFactor);

    void resetIndoorandOutdoorTemperatureDifferenceUpperLimitforMinimumVentingOpenFactor();

    bool setIndoorandOutdoorEnthalpyDifferenceLowerLimitForMaximumVentingOpenFactor(double indoorandOutdoorEnthalpyDifferenceLowerLimitForMaximumVentingOpenFactor);

    void resetIndoorandOutdoorEnthalpyDifferenceLowerLimitForMaximumVentingOpenFactor();

    bool setIndoorandOutdoorEnthalpyDifferenceUpperLimitforMinimumVentingOpenFactor(double indoorandOutdoorEnthalpyDifferenceUpperLimitforMinimumVentingOpenFactor);

    void resetIndoorandOutdoorEnthalpyDifferenceUpperLimitforMinimumVentingOpenFactor();

    // TODO: Check argument type. From object lists, some candidates are: Schedule.
    bool setVentingAvailabilitySchedule(Schedule& schedule);

    void resetVentingAvailabilitySchedule();

    // TODO: Check argument type. From object lists, some candidates are: AirflowNetworkOccupantVentilationControl.
    //bool setOccupantVentilationControl(const boost::optional<AirflowNetworkOccupantVentilationControl>& airflowNetworkOccupantVentilationControl);

    //void resetOccupantVentilationControl();

    //@}
    /** @name Other */
    //@{

    //@}
   protected:
   private:
    REGISTER_LOGGER("openstudio.model.AirflowNetworkMultiZoneSurface");

    // TODO: Check the return types of these methods.
    // Optional getters for use by methods like children() so can remove() if the constructor fails.
    // There are other ways for the public versions of these getters to fail--perhaps all required
    // objects should be returned as boost::optionals
    boost::optional<PlanarSurface> optionalSurface() const;
    //boost::optional<SurfaceAirflowLeakage> optionalLeakageComponent() const;
  };

} // detail

} // model
} // openstudio

#endif // MODEL_AIRFLOWNETWORKMULTIZONESURFACE_IMPL_HPP

