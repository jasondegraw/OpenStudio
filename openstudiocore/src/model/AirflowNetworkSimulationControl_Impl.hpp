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

#ifndef MODEL_AIRFLOWNETWORKSIMULATIONCONTROL_IMPL_HPP
#define MODEL_AIRFLOWNETWORKSIMULATIONCONTROL_IMPL_HPP

#include "ParentObject_Impl.hpp"
#include "ModelObject_Impl.hpp"
#include "../utilities/core/Logger.hpp"
#include "../utilities/core/StringStreamLogSink.hpp"

//#include <utilities/units/Quantity.hpp>
//#include <utilities/units/OSOptionalQuantity.hpp>

namespace openstudio {

class ProgressBar;

namespace model {

class Model;
class ModelObject;
class Space;
class ThermalZone;
class SubSurface;
class Surface;

namespace detail {

/** NetworkBuilder objects translates an OpenStudio model into a CONTAM model.
 *
 *  ForwardTranslator translates an OpenStudio energy model into a CONTAM
 *  airflow model using a streamlined approach. Each wall is assigned an
 *  overall leakage rate and individual components are not directly represented.
 *
 */
class MODEL_API SurfaceNetworkBuilder
{
public:
  /** @name Constructors and Destructors */
  //@{
  /** Construct a new object. */
  explicit SurfaceNetworkBuilder(ProgressBar *progressBar=0);
  /** Destroy the translator.*/
  ~SurfaceNetworkBuilder(){}

  //@}
  /** @name Network Construction Functions */
  //@{

  bool build(model::Model & model);

  //@}
  /** @name Surface-Finding Functions */
  //@{

  static std::vector<Surface> getInteriorZoneSurfaces(Model & model);
  static std::vector<Surface> getExteriorZoneSurfaces(Model & model);

  //@}
  /** @name Getters and Setters */
  //@{

  /** Returns the progress bar currently associated with the object. */
  ProgressBar * progressBar() const;

  /** Sets the progress bar to be updated by the object. */
  void setProgressBar(ProgressBar *progressBar);

  //@}
  /** @name Miscellaneous Functions */
  //@{

  /** Clear any internally stored information in the builder object. */
  virtual void clear()
  {
  }

  /** Returns true if interior subsurfaces will be linked. */
  virtual bool interiorSubSurfacesLinked() const
  {
    return true;
  }

  /** Returns true if exterior subsurfaces will be linked. */
  virtual bool exteriorSubSurfacesLinked() const
  {
    return true;
  }

  /** Returns warning messages generated by the last translation. */
  std::vector<LogMessage> warnings() const;

  /** Returns error messages generated by the last translation. */
  std::vector<LogMessage> errors() const;

  /** Returns error messages generated by the last translation. */
  std::vector<LogMessage> logMessages() const;

  //@}

protected:
  void progress();
  void initProgress(int max, std::string label);

  virtual bool linkExteriorSurface(ThermalZone zone, Space space, Surface surface);
  virtual bool linkExteriorSubSurface(ThermalZone zone, Space space, Surface surface, SubSurface subSurface);
  virtual bool linkInteriorSurface(ThermalZone zone, Space space, Surface surface, 
    Surface adjacentSurface, Space adjacentSpace, ThermalZone adjacentZone);
  virtual bool linkInteriorSubSurface(ThermalZone zone, Space space, Surface surface, SubSurface subSurface,
    SubSurface adjacentSubSurface, Surface adjacentSurface, Space adjacentSpace, ThermalZone adjacentZone);

private:
  ProgressBar* m_progressBar;
  StringStreamLogSink m_logSink;

  REGISTER_LOGGER("openstudio.airflow.NetworkBuilder");
};

class MODEL_API AirflowNetworkSimulationControl_Impl : public ParentObject_Impl, public SurfaceNetworkBuilder
{
  Q_OBJECT;
  Q_PROPERTY(boost::optional<std::string> airflowNetworkControl READ airflowNetworkControl WRITE setAirflowNetworkControl);
  Q_PROPERTY(boost::optional<std::string> windPressureCoefficientType READ windPressureCoefficientType WRITE setWindPressureCoefficientType);
  // TODO: Add relationships for objects related to this one, but not pointed to by the underlying data.
  //       Such relationships can be generated by the GenerateRelationships.rb script.
public:

  /** @name Constructors and Destructors */
  //@{

  // constructor
  AirflowNetworkSimulationControl_Impl(const IdfObject& idfObject,
    Model_Impl* model,
    bool keepHandle);

  // construct from workspace
  AirflowNetworkSimulationControl_Impl(const openstudio::detail::WorkspaceObject_Impl& other,
    Model_Impl* model,
    bool keepHandle);

  // copy constructor
  AirflowNetworkSimulationControl_Impl(const AirflowNetworkSimulationControl_Impl& other,
    Model_Impl* model,
    bool keepHandle);

  // virtual destructor
  virtual ~AirflowNetworkSimulationControl_Impl();

  //@}
  /** @name Getters */
  //@{

  // return the parent object in the hierarchy
  virtual boost::optional<ParentObject> parent() const;

  // return any children objects in the hierarchy
  virtual std::vector<ModelObject> children() const;

  /// get a vector of allowable children types
  virtual std::vector<IddObjectType> allowableChildTypes() const;

  // Get all output variable names that could be associated with this object.
  virtual const std::vector<std::string>& outputVariableNames() const;

  virtual IddObjectType iddObjectType() const;

  boost::optional<std::string> airflowNetworkControl() const;
  boost::optional<std::string> windPressureCoefficientType() const;
  // Skipping AirflowNetworkWindPressureCoefficientArrayName
  boost::optional<std::string> heightSelectionforLocalWindPressureCalculation() const;
  boost::optional<std::string> buildingType() const;
  boost::optional<int> maximumNumberofIterations() const;
  boost::optional<std::string> initializationType() const;
  boost::optional<double> relativeAirflowConvergenceTolerance() const;
  boost::optional<double> absoluteAirflowConvergenceTolerance() const;
  boost::optional<double> convergenceAccelerationLimit() const;
  boost::optional<double> azimuthAngleofLongAxisofBuilding() const;
  boost::optional<double> ratioofBuildingWidthAlongShortAxistoWidthAlongLongAxis() const;
  boost::optional<std::string> networkBuildType() const;

  //@}
  /** @name Setters */
  //@{

  bool setAirflowNetworkControl(boost::optional<std::string> airflowNetworkControl);
  bool setAirflowNetworkControl(std::string airflowNetworkControl);
  bool setWindPressureCoefficientType(boost::optional<std::string> type);
  bool setWindPressureCoefficientType(std::string type);
	// Skipping AirflowNetworkWindPressureCoefficientArrayName
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
  bool setNetworkBuildType(boost::optional<std::string> type);
  bool setNetworkBuildType(std::string type);

  //@}

private:
  REGISTER_LOGGER("openstudio.model.AirflowNetworkSimulationControl");

  //openstudio::Quantity loadsConvergenceToleranceValue_SI() const;
  //openstudio::Quantity loadsConvergenceToleranceValue_IP() const;
  //openstudio::Quantity temperatureConvergenceToleranceValue_SI() const;
  //openstudio::Quantity temperatureConvergenceToleranceValue_IP() const;
  //std::vector<std::string> solarDistributionValues() const;
};

} // detail

} // model
} // openstudio

#endif // MODEL_AIRFLOWNETWORKSIMULATIONCONTROL_IMPL_HPP
