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
#ifndef MODEL_AIRFLOWNETWORKSIMULATIONCONTROL_HPP
#define MODEL_AIRFLOWNETWORKSIMULATIONCONTROL_HPP

#include <model/ModelAPI.hpp>
#include <model/ParentObject.hpp>

namespace openstudio {

class Quantity;
class OSOptionalQuantity;

namespace model {

class ConvergenceLimits;
class HeatBalanceAlgorithm;
class InsideSurfaceConvectionAlgorithm;
class OutsideSurfaceConvectionAlgorithm;
class RunPeriod;
class ShadowCalculation;
class SizingParameters;
class Timestep;
class ZoneAirContaminantBalance;
class ZoneAirHeatBalanceAlgorithm;
class ZoneCapacitanceMultiplierResearchSpecial;

namespace detail {
  class AirflowNetworkSimulationControl_Impl;
}

/** AirflowNetworkSimulationControl derives from ParentObject and is an interface to the OpenStudio IDD object named "SimulationControl".
 *
 *  SimulationControl defines what types of sizing simulations are performed for an EnergyPlus simulation,
 *  it also controls whether or not to report results from sizing and weather file simulations.
 *  SimulationControl parents several other ModelObject types that configure simulation parameters for EnergyPlus.
 *  SimulationControl does not have a public constructor because it is a unique ModelObject.  
 *  To get the SimulationControl object for a Model or create one if it does not yet exist use model.getUniqueObject<SimulationControl>().  
 *  To get the SimulationControl object for a Model but not create one if it does not yet exist use model.getOptionalUniqueObject<SimulationControl>().
 */
class MODEL_API AirflowNetworkSimulationControl : public ParentObject {
 public:
  virtual ~AirflowNetworkSimulationControl() {}


  //@}
  /** @name Static Methods */
  //@{
  static IddObjectType iddObjectType();

  //@}
  /** @name Getters */
  //@{

  boost::optional<std::string> airflowNetworkControl() const;

  //@}
  /** @name Setters */
  //@{

  bool setAirflowNetworkControl(boost::optional<std::string> control);

  bool setAirflowNetworkControl(std::string control);

  //@}

  /// Returns child ZoneAirContaminantBalance if it exists.
  // boost::optional<ZoneAirContaminantBalance> zoneAirContaminantBalance() const;

 protected:

  /** @name Constructors and Destructors */
  //@{

  /// Constructs a new SimulationControl object in the model.
  explicit AirflowNetworkSimulationControl(const Model& model);

  //@}

  /// @cond

  friend class detail::AirflowNetworkSimulationControl_Impl;
  friend class Model;
  friend class IdfObject;
  friend class openstudio::detail::IdfObject_Impl;

  typedef detail::AirflowNetworkSimulationControl_Impl ImplType;

  explicit AirflowNetworkSimulationControl(boost::shared_ptr<ImplType> impl);

 private:

  REGISTER_LOGGER("openstudio.model.AirflowNetworkSimulationControl");

  /// @endcond
};

/** \relates AirflowNetworkSimulationControl */
typedef boost::optional<AirflowNetworkSimulationControl> OptionalAirflowNetworkSimulationControl;

}
}

#endif
