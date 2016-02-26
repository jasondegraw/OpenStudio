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

/** AirflowNetworkSimulationControl derives from ParentObject and is an interface to the OpenStudio IDD object named "AirflowNetwork:SimulationControl".
 *
 *  AirflowNetworkSimulationControl defines what types of multizone airflow calculations are part of an EnergyPlus simulation.
 *  AirflowNetworkSimulationControl parents several other ModelObject types that configure simulation parameters for EnergyPlus.
 *  AirflowNetworkSimulationControl does not have a public constructor because it is a unique ModelObject.  
 *  To get the AirflowNetworkSimulationControl object for a Model or create one if it does not yet exist use model.getUniqueObject<AirflowNetworkSimulationControl>().  
 *  To get the AirflowNetworkSimulationControl object for a Model but not create one if it does not yet exist use model.getOptionalUniqueObject<AirflowNetworkSimulationControl>().
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

  /** Determines the type of AirflowNetwork simulation that will be run.
   *
   *  NoMultizoneOrDistribution: Only perform Simple calculations (objects ZoneInfiltration:*,
   *  ZoneVentilation:*, ZoneMixing, ZoneCrossMixing, ZoneRefrigerationDoorMixing, 
   *  ZoneAirBalance:OutdoorAir, ZoneEarthtube, ZoneThermalChimney, and ZoneCoolTower:Shower);
   *
   *  MultizoneWithoutDistribution: Use AirflowNetwork objects to simulate multizone
   *  Airflows driven by wind during simulation time, and objects of ZoneInfiltration:*,
   *  ZoneVentilation:*, ZoneMixing, ZoneCrossMixing, ZoneRefrigerationDoorMixing, ZoneAirBalance:OutdoorAir, 
   *  ZoneEarthtube, ZoneThermalChimney, and ZoneCoolTower:Shower are ignored;
   *
   *  MultizoneWithDistributionOnlyDuringFanOperation: Perform distribution system
   *  calculations during system fan on time and Simple calculations during system Fan off time;
   *
   *  MultizoneWithDistribution: Perform distribution system calculations during system
   *  fan on time and multizone Airflow driven by wind during system fan off time.
   */
  boost::optional<std::string> airflowNetworkControl() const;

  /** Determines the wind pressure treatment used by AirflowNetork.
   *
   *  Input: User must enter AirflowNetwork:MultiZone:WindPressureCoefficientArray,
   *  AirflowNetwork:MultiZone:ExternalNode, and AirflowNetwork:MultiZone:WindPressureCoefficientValues objects.
   *
   *  SurfaceAverageCalculation: used only for rectangular buildings. AirflowNetwork:MultiZone:WindPressureCoefficientArray, 
   *  AirflowNetwork:MultiZone:ExternalNode, and AirflowNetwork:MultiZone:WindPressureCoefficientValues objects are not used.
   */
  boost::optional<std::string> windPressureCoefficientType() const;

  /** Determines how height is selected for wind pressure.
   *  If ExternalNode is selected, the height given in the AirflowNetwork:MultiZone:ExternalNode object will be used.
   *
   *  If OpeningHeight is selected, the surface opening height (centroid) will be used to calculate local wind pressure
   *
   *  This field is ignored when the choice of the Wind Pressure Coefficient Type field is SurfaceAverageCalculation.
   */
  boost::optional<std::string> heightSelectionforLocalWindPressureCalculation() const;

  /** General build type, used only if Wind Pressure Coefficient Type = SurfaceAverageCalculation.
   */
  boost::optional<std::string> buildingType() const;

  /** Determines the maximum number of iterations used to converge on a solution. If this limit
   *  is exceeded, the program terminates.
   */
  boost::optional<int> maximumNumberofIterations() const;

  /** Determines how the network equations are initialized.
   */
  boost::optional<std::string> initializationType() const;

  /** This tolerance is defined as the absolute value of the sum of the mass flow rates divided by the sum of the absolute value 
   *  of the mass Flow Rates. The mass flow rates described here refer to the mass Flow Rates at all Nodes in the AirflowNetwork 
   *  model. The solution converges when both this tolerance and the tolerance in the Absolute Airflow Convergence Tolerance
   *  field are satisfied.
   */
  boost::optional<double> relativeAirflowConvergenceTolerance() const;

  /** This tolerance is defined as the absolute value of the sum of the mass flow rates. The mass flow rates described here refer
   *  to the mass flow rates at all nodes in the AirflowNetwork model. The solution converges when both this tolerance and the 
   *  tolerance in the previous field (Relative Airflow Convergence Tolerance) are satisfied.
   */
  boost::optional<double> absoluteAirflowConvergenceTolerance() const;

  /** Used only for AirflowNetwork:SimulationControl
   */
  boost::optional<double> convergenceAccelerationLimit() const;
  
  /** Azimuth angle of long axis of building in degrees clockwise from true North.
   *  Used only if Wind Pressure Coefficient Type = SurfaceAverageCalculation.
   */
  boost::optional<double> azimuthAngleofLongAxisofBuilding() const;
  
  /** Ratio of building width along short axis to width along long axis.
   *  Used only if Wind Pressure Coefficient Type = SurfaceAverageCalculation.
   */
  boost::optional<double> ratioofBuildingWidthAlongShortAxistoWidthAlongLongAxis() const;

  //@}
  /** @name Setters */
  //@{

  bool setAirflowNetworkControl(boost::optional<std::string> airflowNetworkControl);
  bool setAirflowNetworkControl(std::string airflowNetworkControl);
  bool setWindPressureCoefficientType(boost::optional<std::string> type);
  bool setWindPressureCoefficientType(std::string type);
  bool setHeightSelectionforLocalWindPressureCalculation(boost::optional<std::string> height);
  bool setHeightSelectionforLocalWindPressureCalculation(std::string height);
  bool setBuildingType(boost::optional<std::string> type);
  bool setBuildingType(std::string type);
  bool setMaximumNumberofIterations(boost::optional<int> number);
  bool setMaximumNumberofIterations(int number);
  bool setInitializationType(boost::optional<std::string> type);
  bool setInitializationType(std::string type);
  bool setRelativeAirflowConvergenceTolerance(boost::optional<double> tolerance);
  bool setRelativeAirflowConvergenceTolerance(double tolerance);
  bool setAbsoluteAirflowConvergenceTolerance(boost::optional<double> tolerance);
  bool setAbsoluteAirflowConvergenceTolerance(double tolerance);
  bool setConvergenceAccelerationLimit(boost::optional<double> limit);
  bool setConvergenceAccelerationLimit(double limit);
  bool setAzimuthAngleofLongAxisofBuilding(boost::optional<double> angle);
  bool setAzimuthAngleofLongAxisofBuilding(double angle);
  bool setRatioofBuildingWidthAlongShortAxistoWidthAlongLongAxis(boost::optional<double> ratio);
  bool setRatioofBuildingWidthAlongShortAxistoWidthAlongLongAxis(double ratio);

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

  explicit AirflowNetworkSimulationControl(std::shared_ptr<ImplType> impl);

 private:

  REGISTER_LOGGER("openstudio.model.AirflowNetworkSimulationControl");

  /// @endcond
};

/** \relates AirflowNetworkSimulationControl */
typedef boost::optional<AirflowNetworkSimulationControl> OptionalAirflowNetworkSimulationControl;

}
}

#endif
