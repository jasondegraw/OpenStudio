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

#include <gtest/gtest.h>

#include <model/test/ModelFixture.hpp>

#include "../AirflowNetworkSimulationControl.hpp"
#include "../AirflowNetworkSimulationControl_Impl.hpp"
#include "../ThermalZone.hpp"
#include "../Space.hpp"
#include "../Surface.hpp"
#include "../SubSurface.hpp"

// Includes for demo model builder
#include "../Building.hpp"
#include "../Building_Impl.hpp"
#include "../BuildingStory.hpp"
#include "../SpaceType.hpp"
#include "../DesignSpecificationOutdoorAir.hpp"
#include "../../utilities/geometry/Point3d.hpp"
#include "../ThermostatSetpointDualSetpoint.hpp"
#include "../ThermostatSetpointDualSetpoint_Impl.hpp"
#include "../SizingZone.hpp"
#include "../AirLoopHVAC.hpp"
#include "../AirLoopHVAC_Impl.hpp"
#include "../HVACTemplates.hpp"
#include "../SetpointManagerSingleZoneReheat.hpp"
#include "../SetpointManagerSingleZoneReheat_Impl.hpp"

/*
// Includes for template builder
#include "../Version.hpp"
#include "../SimulationControl.hpp"
#include "../Timestep.hpp"
#include "../RunPeriod.hpp"
#include "../InsideSurfaceConvectionAlgorithm.hpp"
#include "../OutsideSurfaceConvectionAlgorithm.hpp"
#include "../HeatBalanceAlgorithm.hpp"
#include "../ZoneAirHeatBalanceAlgorithm.hpp"
#include "../ConvergenceLimits.hpp"
#include "../ShadowCalculation.hpp"
#include "../Site.hpp"
#include "../SiteGroundTemperatureBuildingSurface.hpp"
#include "../SiteWaterMainsTemperature.hpp"
#include "../DesignDay.hpp"
*/

using namespace openstudio;
using namespace openstudio::model;

/*
openstudio::model::Model buildExampleTemplate()
{
  openstudio::model::Model model;

  // add Version
  Version version = model.getUniqueModelObject<Version>();

  // add SimulationControl
  SimulationControl simulationControl = model.getUniqueModelObject<SimulationControl>();
  simulationControl.setDoZoneSizingCalculation(true);
  simulationControl.setDoSystemSizingCalculation(true);
  simulationControl.setRunSimulationforSizingPeriods(false);
  simulationControl.setRunSimulationforWeatherFileRunPeriods(true);

  // add Timestep
  Timestep timestep = model.getUniqueModelObject<Timestep>();

  // add RunPeriod
  RunPeriod runPeriod = model.getUniqueModelObject<RunPeriod>();
  runPeriod.setBeginMonth(1);
  runPeriod.setBeginDayOfMonth(1);
  runPeriod.setEndMonth(12);
  runPeriod.setEndDayOfMonth(31);
  runPeriod.setUseWeatherFileHolidays(false);
  runPeriod.setUseWeatherFileDaylightSavings(false);
  runPeriod.setApplyWeekendHolidayRule(false);
  runPeriod.setUseWeatherFileRainInd(true);
  runPeriod.setUseWeatherFileSnowInd(true);
  runPeriod.setNumTimePeriodRepeats(1);

  // add SurfaceConvectionAlgorithmInside
  InsideSurfaceConvectionAlgorithm insideSurfaceConvectionAlgorithm = model.getUniqueModelObject<InsideSurfaceConvectionAlgorithm>();

  // add SurfaceConvectionAlgorithmOutside
  OutsideSurfaceConvectionAlgorithm outsideSurfaceConvectionAlgorithm = model.getUniqueModelObject<OutsideSurfaceConvectionAlgorithm>();

  // add HeatBalanceAlgorithm
  HeatBalanceAlgorithm heatBalanceAlgorithm = model.getUniqueModelObject<HeatBalanceAlgorithm>();

  // add ZoneAirHeatBalanceAlgorithm
  ZoneAirHeatBalanceAlgorithm zoneAirHeatBalanceAlgorithm = model.getUniqueModelObject<ZoneAirHeatBalanceAlgorithm>();

  // add ConvergenceLimits
  ConvergenceLimits convergenceLimits = model.getUniqueModelObject<ConvergenceLimits>();

  // add ShadowCalculation
  ShadowCalculation shadowCalculation = model.getUniqueModelObject<ShadowCalculation>();

  // add Site
  Site site = model.getUniqueModelObject<Site>();
  site.setLatitude(41.77);
  site.setLongitude(-87.75);
  site.setTimeZone(-6.0);
  site.setElevation(190.0);

  // add SiteGroundTemperatureBuildingSurface
  SiteGroundTemperatureBuildingSurface groundTemp = model.getUniqueModelObject<SiteGroundTemperatureBuildingSurface>();
  groundTemp.setJanuaryGroundTemperature(19.527);
  groundTemp.setFebruaryGroundTemperature(19.502);
  groundTemp.setMarchGroundTemperature(19.536);
  groundTemp.setAprilGroundTemperature(19.598);
  groundTemp.setMayGroundTemperature(20.002);
  groundTemp.setJuneGroundTemperature(21.640);
  groundTemp.setJulyGroundTemperature(22.225);
  groundTemp.setAugustGroundTemperature(22.375);
  groundTemp.setSeptemberGroundTemperature(21.449);
  groundTemp.setOctoberGroundTemperature(20.121);
  groundTemp.setNovemberGroundTemperature(19.802);
  groundTemp.setDecemberGroundTemperature(19.633);

  // add SiteWaterMainsTemperature
  SiteWaterMainsTemperature waterTemp = model.getUniqueModelObject<SiteWaterMainsTemperature>();
  waterTemp.setAnnualAverageOutdoorAirTemperature(9.69);
  waterTemp.setMaximumDifferenceInMonthlyAverageOutdoorAirTemperatures(28.10);

  // add DesignDay
  DesignDay designDay1(model);
  designDay1.setMaximumDryBulbTemperature(-20.6);
  designDay1.setDailyDryBulbTemperatureRange(0.0);
  designDay1.setHumidityIndicatingConditionsAtMaximumDryBulb(-20.6);
  designDay1.setBarometricPressure(99063.0);
  designDay1.setWindSpeed(4.9);
  designDay1.setWindDirection(270);
  designDay1.setSkyClearness(0.0);
  designDay1.setRainIndicator(false);
  designDay1.setSnowIndicator(false);
  designDay1.setDayOfMonth(21);
  designDay1.setMonth(1);
  designDay1.setDayType("WinterDesignDay");
  designDay1.setDaylightSavingTimeIndicator(false);
  designDay1.setHumidityIndicatingType("WetBulb");

  DesignDay designDay2(model);
  designDay2.setMaximumDryBulbTemperature(33.2);
  designDay2.setDailyDryBulbTemperatureRange(10.7);
  designDay2.setHumidityIndicatingConditionsAtMaximumDryBulb(23.8);
  designDay2.setBarometricPressure(99063.0);
  designDay2.setWindSpeed(5.3);
  designDay2.setWindDirection(230);
  designDay2.setSkyClearness(1.0);
  designDay2.setRainIndicator(false);
  designDay2.setSnowIndicator(false);
  designDay2.setDayOfMonth(21);
  designDay2.setMonth(7);
  designDay2.setDayType("SummerDesignDay");
  designDay2.setDaylightSavingTimeIndicator(false);
  designDay2.setHumidityIndicatingType("WetBulb");

  // add schedules
  openstudio::model::addExampleSchedules(model);
  OS_ASSERT(model.getConcreteModelObjects<DefaultScheduleSet>().size() >= 1);
  DefaultScheduleSet defaultScheduleSet = model.getConcreteModelObjects<DefaultScheduleSet>()[0];

  // add constructions
  addExampleConstructions(model);
  OS_ASSERT(model.getConcreteModelObjects<DefaultConstructionSet>().size() >= 1);
  DefaultConstructionSet defaultConstructionSet = model.getConcreteModelObjects<DefaultConstructionSet>()[0];

  // add a space type
  SpaceType spaceType(model);

  // add some lights to the space type
  LightsDefinition lightsDefinition(model);
  lightsDefinition.setWattsperSpaceFloorArea(10.0);
  Lights lights(lightsDefinition);
  lights.setSpaceType(spaceType);

  // add some electric equipment to the space type
  ElectricEquipmentDefinition electricEquipmentDefinition(model);
  electricEquipmentDefinition.setWattsperSpaceFloorArea(5.0);
  ElectricEquipment electricEquipment(electricEquipmentDefinition);
  electricEquipment.setSpaceType(spaceType);

  // add some people to the space type
  PeopleDefinition peopleDefinition(model);
  peopleDefinition.setPeopleperSpaceFloorArea(0.05);
  People people(peopleDefinition);
  people.setSpaceType(spaceType);

  // create the facility
  Facility facility = model.getUniqueModelObject<Facility>();

  // create the building
  Building building = model.getUniqueModelObject<Building>();
  building.setSpaceType(spaceType);
  building.setDefaultConstructionSet(defaultConstructionSet);
  building.setDefaultScheduleSet(defaultScheduleSet);

  return model;
}
*/

boost::optional<openstudio::model::Model> buildDemoModel(bool doors=false, bool windows=false)
{
  openstudio::model::Model model;
  openstudio::model::addExampleModelObjects(model);
  // set outdoor air specifications
  openstudio::model::Building building = model.getUniqueModelObject<openstudio::model::Building>();
  boost::optional<openstudio::model::SpaceType> spaceType = building.spaceType();
  if(!spaceType) {
    std::cout << "Failed to find space type" << std::endl;
    return boost::none;
  }
  boost::optional<openstudio::model::DesignSpecificationOutdoorAir> oa = spaceType->designSpecificationOutdoorAir();
  if(!oa) {
    std::cout << "Failed to fine OA spec" << std::endl;
    openstudio::model::DesignSpecificationOutdoorAir oaObj(model);
    oa = boost::optional<openstudio::model::DesignSpecificationOutdoorAir>(oaObj);
  }
  if(!oa->setOutdoorAirMethod("Sum")) {
    return boost::none;
  }
  if(!oa->setOutdoorAirFlowperPerson(0.0)) {
    return boost::none;
  }
  if(!oa->setOutdoorAirFlowperFloorArea(0.00508)) { // 1 cfm/ft^2 = 0.00508 m/s
    return boost::none;
  }
  if(!oa->setOutdoorAirFlowRate(0.0)) {
    return boost::none;
  }
  if(!oa->setOutdoorAirFlowAirChangesperHour(0.0)) {
    return boost::none;
  }

  double floorHeight = 3.0;

  openstudio::model::BuildingStory story1(model);
  story1.setName("Story 1");
  story1.setNominalZCoordinate(0.0);
  story1.setNominalFloortoFloorHeight(floorHeight);

  std::vector<openstudio::Point3d> points;
  points.push_back(openstudio::Point3d(0,0,0));
  points.push_back(openstudio::Point3d(0,17,0));
  points.push_back(openstudio::Point3d(8,17,0));
  points.push_back(openstudio::Point3d(8,10,0));
  points.push_back(openstudio::Point3d(8,0,0));

  boost::optional<openstudio::model::Space> library = openstudio::model::Space::fromFloorPrint(points, floorHeight, model);
  if(!library) {
    return boost::none;
  }
  library->setName("Library");

  points.clear();
  points.push_back(openstudio::Point3d(8,10,0));
  points.push_back(openstudio::Point3d(8,17,0));
  points.push_back(openstudio::Point3d(18,17,0));
  points.push_back(openstudio::Point3d(18,10,0));
  points.push_back(openstudio::Point3d(11,10,0));

  boost::optional<openstudio::model::Space> office2 = openstudio::model::Space::fromFloorPrint(points, floorHeight, model);
  if(!office2) {
    return boost::none;
  }
  office2->setName("Office 2");

  points.clear();
  points.push_back(openstudio::Point3d(8,0,0));
  points.push_back(openstudio::Point3d(8,10,0));
  points.push_back(openstudio::Point3d(11,10,0));
  points.push_back(openstudio::Point3d(11,0,0));

  boost::optional<openstudio::model::Space> hallway = openstudio::model::Space::fromFloorPrint(points, floorHeight, model);
  if(!hallway) {
    return boost::none;
  }
  hallway->setName("Hallway");

  points.clear();
  points.push_back(openstudio::Point3d(11,0,0));
  points.push_back(openstudio::Point3d(11,10,0));
  points.push_back(openstudio::Point3d(18,10,0));
  points.push_back(openstudio::Point3d(18,0,0));

  boost::optional<openstudio::model::Space> office1 = openstudio::model::Space::fromFloorPrint(points, floorHeight, model);
  if(!office1) {
    return boost::none;
  }
  office1->setName("Office 1");

  library->matchSurfaces(*office2);
  library->matchSurfaces(*hallway);
  hallway->matchSurfaces(*office1);
  hallway->matchSurfaces(*office2);
  office1->matchSurfaces(*office2);

  // find thermostat
  boost::optional<openstudio::model::ThermostatSetpointDualSetpoint> thermostat;
  for(openstudio::model::ThermostatSetpointDualSetpoint t : model.getModelObjects<openstudio::model::ThermostatSetpointDualSetpoint>()) {
    thermostat = t;
    break;
  }
  if(!thermostat) {
    std::cout << "Failed to find thermostat" << std::endl;
    ThermostatSetpointDualSetpoint tstat(model);
    thermostat = boost::optional<openstudio::model::ThermostatSetpointDualSetpoint>(tstat);
  }
  
  // create  thermal zones
  openstudio::model::ThermalZone libraryZone(model);
  openstudio::model::SizingZone librarySizing(model, libraryZone);
  libraryZone.setName("Library Zone");
  libraryZone.setThermostatSetpointDualSetpoint(*thermostat);
  library->setThermalZone(libraryZone);
  library->setBuildingStory(story1);

  openstudio::model::ThermalZone hallwayZone(model);
  //model::SizingZone hallwaySizing(model, hallwayZone);
  hallwayZone.setName("Hallway Zone");
  //hallwayZone.setThermostatSetpointDualSetpoint(*thermostat);
  hallway->setThermalZone(hallwayZone);
  hallway->setBuildingStory(story1);

  openstudio::model::ThermalZone office1Zone(model);
  openstudio::model::SizingZone office1Sizing(model, office1Zone);
  office1Zone.setName("Office 1 Zone");
  office1Zone.setThermostatSetpointDualSetpoint(*thermostat);
  office1->setThermalZone(office1Zone);
  office1->setBuildingStory(story1);

  openstudio::model::ThermalZone office2Zone(model);
  openstudio::model::SizingZone office2Sizing(model, office2Zone);
  office2Zone.setName("Office 2 Zone");
  office2Zone.setThermostatSetpointDualSetpoint(*thermostat);
  office2->setThermalZone(office2Zone);
  office2->setBuildingStory(story1);

  // add the air system
  openstudio::model::Loop loop = openstudio::model::addSystemType3(model);
  openstudio::model::AirLoopHVAC airLoop = loop.cast<openstudio::model::AirLoopHVAC>();
  airLoop.addBranchForZone(libraryZone);
  airLoop.addBranchForZone(office1Zone);
  airLoop.addBranchForZone(office2Zone);

  boost::optional<openstudio::model::SetpointManagerSingleZoneReheat> setpointManager;
  for(openstudio::model::SetpointManagerSingleZoneReheat t : model.getModelObjects<openstudio::model::SetpointManagerSingleZoneReheat>()) {
    setpointManager = t;
    break;
  }
  if(!setpointManager) {
    return boost::optional<openstudio::model::Model>();
  }
  setpointManager->setControlZone(libraryZone);

  return boost::optional<openstudio::model::Model>(model);
}

class CountSurfaces : public openstudio::model::detail::SurfaceNetworkBuilder
{
public:
  CountSurfaces() : SurfaceNetworkBuilder(),interiorSurfaces(0),interiorSubSurfaces(0),
    exteriorSurfaces(0),exteriorSubSurfaces(0)
  {}

  virtual bool linkExteriorSurface(ThermalZone zone, Space space, Surface surface)
  {
    exteriorSurfaces++;
    return true;
  }
  virtual bool linkExteriorSubSurface(ThermalZone zone, Space space, Surface surface, SubSurface subSurface)
  {
    exteriorSubSurfaces++;
    return true;
  }
  virtual bool linkInteriorSurface(ThermalZone zone, Space space, Surface surface, 
    Surface adjacentSurface, Space adjacentSpace, ThermalZone adjacentZone)
  {
    interiorSurfaces++;
    return true;
  }
  virtual bool linkInteriorSubSurface(ThermalZone zone, Space space, Surface surface, SubSurface subSurface,
    SubSurface adjacentSubSurface, Surface adjacentSurface, Space adjacentSpace, ThermalZone adjacentZone)
  {
    interiorSubSurfaces++;
    return true;
  }

  unsigned interiorSurfaces;
  unsigned interiorSubSurfaces;
  unsigned exteriorSurfaces;
  unsigned exteriorSubSurfaces;
};

TEST_F(ModelFixture,AirflowNetworkSimulationControl_NetworkBuilder) {
  boost::optional<Model> optmodel = buildDemoModel();
  ASSERT_TRUE(optmodel);
  Model model = optmodel.get();
  CountSurfaces counter;
  EXPECT_TRUE(counter.build(model));
  EXPECT_EQ(5,counter.interiorSurfaces);
  EXPECT_EQ(0,counter.interiorSubSurfaces);
  EXPECT_EQ(12,counter.exteriorSurfaces);
  EXPECT_EQ(0,counter.exteriorSubSurfaces);
}

