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

#ifndef MODEL_AIRFLOWNETWORKMULTIZONESURFACE_HPP
#define MODEL_AIRFLOWNETWORKMULTIZONESURFACE_HPP

#include <model/ModelAPI.hpp>
#include "ModelObject.hpp"

namespace openstudio {

namespace model {

// TODO: Check the following class names against object getters and setters.
//class SurfAndSubSurf;
class Surface;
class SurfaceAirflowLeakage;
class ExternalNode;
class Schedule;
//class Schedule;
class AirflowNetworkOccupantVentilationControl;

namespace detail {

  class AirflowNetworkMultiZoneSurface_Impl;

} // detail

/** AirflowNetworkMultiZoneSurface is a ModelObject that wraps the OpenStudio IDD object 'OS:AirflowNetwork:MultiZoneSurface'. */
class MODEL_API AirflowNetworkMultiZoneSurface : public ModelObject {
public:
  /** @name Constructors and Destructors */
  //@{

  AirflowNetworkMultiZoneSurface(const Model& model, const Surface &surface);

  virtual ~AirflowNetworkMultiZoneSurface() {}

  //@}

  static IddObjectType iddObjectType();

  static std::vector<std::string> ventilationControlModeValues();

  /** @name Getters */
  //@{

  // TODO: Check return type. From object lists, some candidates are: SurfAndSubSurf.
  Surface surface() const;

  // TODO: Check return type. From object lists, some candidates are: SurfaceAirflowLeakage.
  SurfaceAirflowLeakage leakageComponent() const;

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
  boost::optional<AirflowNetworkOccupantVentilationControl> occupantVentilationControl() const;

  //@}
  /** @name Setters */
  //@{

  // TODO: Check argument type. From object lists, some candidates are: SurfAndSubSurf.
  bool setSurface(const Surface& surface);

  // TODO: Check argument type. From object lists, some candidates are: SurfaceAirflowLeakage.
  bool setLeakageComponent(const SurfaceAirflowLeakage& surfaceAirflowLeakage);

  // TODO: Check argument type. From object lists, some candidates are: ExternalNode.
  //bool setExternalNode(const ExternalNode& externalNode);

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
  bool setOccupantVentilationControl(const AirflowNetworkOccupantVentilationControl& airflowNetworkOccupantVentilationControl);

  void resetOccupantVentilationControl();

  //@}
  /** @name Other */
  //@{

  //@}
protected:
  /// @cond
  typedef detail::AirflowNetworkMultiZoneSurface_Impl ImplType;

  explicit AirflowNetworkMultiZoneSurface(std::shared_ptr<detail::AirflowNetworkMultiZoneSurface_Impl> impl);

  friend class detail::AirflowNetworkMultiZoneSurface_Impl;
  friend class Model;
  friend class IdfObject;
  friend class openstudio::detail::IdfObject_Impl;
  /// @endcond
private:
  REGISTER_LOGGER("openstudio.model.AirflowNetworkMultiZoneSurface");
};

/** \relates AirflowNetworkMultiZoneSurface*/
typedef boost::optional<AirflowNetworkMultiZoneSurface> OptionalAirflowNetworkMultiZoneSurface;

/** \relates AirflowNetworkMultiZoneSurface*/
typedef std::vector<AirflowNetworkMultiZoneSurface> AirflowNetworkMultiZoneSurfaceVector;

} // model
} // openstudio

#endif // MODEL_AIRFLOWNETWORKMULTIZONESURFACE_HPP

