/**********************************************************************
 *  Copyright (c) 2008-2015, Alliance for Sustainable Energy.
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

#ifndef MODEL_CONCRETEMODELOBJECTS_HPP
#define MODEL_CONCRETEMODELOBJECTS_HPP

#include "AirConditionerVariableRefrigerantFlow.hpp"
#include "AirflowNetworkMultiZoneComponentHorizontalOpening.hpp"
#include "AirflowNetworkMultiZoneComponentSimpleOpening.hpp"
#include "AirflowNetworkMultiZoneSurfaceCrack.hpp"
#include "AirflowNetworkMultiZoneSurfaceEffectiveLeakageArea.hpp"
#include "AirflowNetworkSimulationControl.hpp"
#include "AirGap.hpp"
#include "AirLoopHVAC.hpp"
#include "AirLoopHVACOutdoorAirSystem.hpp"
#include "AirLoopHVACUnitaryHeatPumpAirToAir.hpp"
#include "AirLoopHVACUnitaryHeatCoolVAVChangeoverBypass.hpp"
#include "AirLoopHVACUnitaryHeatPumpAirToAirMultiSpeed.hpp"
#include "AirLoopHVACReturnPlenum.hpp"
#include "AirLoopHVACSupplyPlenum.hpp"
#include "AirLoopHVACUnitarySystem.hpp"
#include "AirLoopHVACZoneMixer.hpp"
#include "AirLoopHVACZoneSplitter.hpp"
#include "AirTerminalSingleDuctInletSideMixer.hpp"
#include "AirTerminalSingleDuctConstantVolumeCooledBeam.hpp"
#include "AirTerminalSingleDuctConstantVolumeFourPipeInduction.hpp"
#include "AirTerminalSingleDuctConstantVolumeReheat.hpp"
#include "AirTerminalSingleDuctParallelPIUReheat.hpp"
#include "AirTerminalSingleDuctSeriesPIUReheat.hpp"
#include "AirTerminalSingleDuctUncontrolled.hpp"
#include "AirTerminalSingleDuctVAVReheat.hpp"
#include "AirTerminalSingleDuctVAVNoReheat.hpp"
#include "AirTerminalSingleDuctVAVHeatAndCoolNoReheat.hpp"
#include "AirTerminalSingleDuctVAVHeatAndCoolReheat.hpp"
#include "AirWallMaterial.hpp"
#include "AvailabilityManagerAssignmentList.hpp"
#include "AvailabilityManagerNightCycle.hpp"
#include "AvailabilityManagerScheduled.hpp"
#include "Blind.hpp"
#include "BoilerHotWater.hpp"
#include "BoilerSteam.hpp"
#include "Building.hpp"
#include "BuildingStory.hpp"
#include "CFactorUndergroundWallConstruction.hpp"
#include "ClimateZones.hpp"
#include "ChillerElectricEIR.hpp"
#include "CoilCoolingCooledBeam.hpp"
#include "CoilCoolingDXMultiSpeed.hpp"
#include "CoilCoolingDXMultiSpeedStageData.hpp"
#include "CoilCoolingDXSingleSpeed.hpp"
#include "CoilCoolingDXTwoSpeed.hpp"
#include "CoilCoolingDXVariableRefrigerantFlow.hpp"
#include "CoilCoolingLowTempRadiantConstFlow.hpp"
#include "CoilCoolingLowTempRadiantVarFlow.hpp"
#include "CoilCoolingWater.hpp"
#include "CoilCoolingWaterToAirHeatPumpEquationFit.hpp"
#include "CoilHeatingDesuperheater.hpp"
#include "CoilHeatingDXSingleSpeed.hpp"
#include "CoilHeatingDXVariableRefrigerantFlow.hpp"
#include "CoilHeatingElectric.hpp"
#include "CoilHeatingGas.hpp"
#include "CoilHeatingGasMultiStage.hpp"
#include "CoilHeatingGasMultiStageStageData.hpp"
#include "CoilHeatingLowTempRadiantConstFlow.hpp"
#include "CoilHeatingLowTempRadiantVarFlow.hpp"
#include "CoilHeatingWater.hpp"
#include "CoilHeatingWaterToAirHeatPumpEquationFit.hpp"
#include "CoilHeatingWaterBaseboard.hpp"
#include "CoilWaterHeatingDesuperheater.hpp"
#include "ComponentCostAdjustments.hpp"
#include "ComponentData.hpp"
#include "Connection.hpp"
#include "ConnectorMixer.hpp"
#include "ConnectorSplitter.hpp"
#include "Construction.hpp"
#include "ConstructionWithInternalSource.hpp"
#include "ControllerMechanicalVentilation.hpp"
#include "ControllerOutdoorAir.hpp"
#include "ControllerWaterCoil.hpp"
#include "ConvergenceLimits.hpp"
#include "CoolingTowerPerformanceCoolTools.hpp"
#include "CoolingTowerPerformanceYorkCalc.hpp"
#include "CoolingTowerSingleSpeed.hpp"
#include "CoolingTowerTwoSpeed.hpp"
#include "CoolingTowerVariableSpeed.hpp"
#include "CurrencyType.hpp"
#include "CurveBicubic.hpp"
#include "CurveBiquadratic.hpp"
#include "CurveCubic.hpp"
#include "CurveDoubleExponentialDecay.hpp"
#include "CurveExponent.hpp"
#include "CurveExponentialDecay.hpp"
#include "CurveExponentialSkewNormal.hpp"
#include "CurveFanPressureRise.hpp"
#include "CurveFunctionalPressureDrop.hpp"
#include "CurveLinear.hpp"
#include "CurveQuadratic.hpp"
#include "CurveQuadraticLinear.hpp"
#include "CurveQuartic.hpp"
#include "CurveRectangularHyperbola1.hpp"
#include "CurveRectangularHyperbola2.hpp"
#include "CurveSigmoid.hpp"
#include "CurveTriquadratic.hpp"
#include "DaylightingControl.hpp"
#include "DaylightingDeviceShelf.hpp"
#include "DefaultConstructionSet.hpp"
#include "DefaultScheduleSet.hpp"
#include "DefaultSubSurfaceConstructions.hpp"
#include "DefaultSurfaceConstructions.hpp"
#include "DesignDay.hpp"
#include "DesignSpecificationOutdoorAir.hpp"
#include "DesignSpecificationZoneAirDistribution.hpp"
#include "DistrictCooling.hpp"
#include "DistrictHeating.hpp"
#include "ElectricEquipment.hpp"
#include "ElectricEquipmentDefinition.hpp"
#include "EvaporativeCoolerDirectResearchSpecial.hpp"
#include "EvaporativeCoolerIndirectResearchSpecial.hpp"
#include "EvaporativeFluidCoolerSingleSpeed.hpp"
#include "ExteriorLights.hpp"
#include "ExteriorLightsDefinition.hpp"
#include "Facility.hpp"
#include "FanConstantVolume.hpp"
#include "FanOnOff.hpp"
#include "FanVariableVolume.hpp"
#include "FanZoneExhaust.hpp"
#include "FFactorGroundFloorConstruction.hpp"
#include "Gas.hpp"
#include "GasEquipment.hpp"
#include "GasEquipmentDefinition.hpp"
#include "GasMixture.hpp"
#include "GenericModelObject.hpp"
#include "GlareSensor.hpp"
#include "GroundHeatExchangerVertical.hpp"
#include "HeatBalanceAlgorithm.hpp"
#include "HeatExchangerAirToAirSensibleAndLatent.hpp"
#include "HeatExchangerFluidToFluid.hpp"
#include "HotWaterEquipment.hpp"
#include "HotWaterEquipmentDefinition.hpp"
#include "HumidifierSteamElectric.hpp"
#include "IlluminanceMap.hpp"
#include "InfraredTransparentMaterial.hpp"
#include "InsideSurfaceConvectionAlgorithm.hpp"
#include "InteriorPartitionSurface.hpp"
#include "InteriorPartitionSurfaceGroup.hpp"
#include "InternalMass.hpp"
#include "InternalMassDefinition.hpp"
#include "LifeCycleCost.hpp"
#include "LifeCycleCostParameters.hpp"
#include "LifeCycleCostUsePriceEscalation.hpp"
#include "LightingDesignDay.hpp"
#include "LightingSimulationControl.hpp"
#include "LightingSimulationZone.hpp"
#include "Lights.hpp"
#include "LightsDefinition.hpp"
#include "Luminaire.hpp"
#include "LuminaireDefinition.hpp"
#include "MasslessOpaqueMaterial.hpp"
#include "Meter.hpp"
#include "ModelObjectList.hpp"
#include "Node.hpp"
#include "PortList.hpp"
#include "OtherEquipment.hpp"
#include "OtherEquipmentDefinition.hpp"
#include "OutputControlReportingTolerances.hpp"
#include "OutputVariable.hpp"
#include "OutsideSurfaceConvectionAlgorithm.hpp"
#include "People.hpp"
#include "PeopleDefinition.hpp"
#include "PipeAdiabatic.hpp"
#include "PlantLoop.hpp"
#include "ProgramControl.hpp"
#include "PumpConstantSpeed.hpp"
#include "PumpVariableSpeed.hpp"
#include "RadianceParameters.hpp"
#include "RefractionExtinctionGlazing.hpp"
#include "RefrigerationAirChiller.hpp"
#include "RefrigerationCase.hpp"
#include "RefrigerationCompressor.hpp"
#include "RefrigerationCondenserAirCooled.hpp"
#include "RefrigerationCondenserCascade.hpp"
#include "RefrigerationCondenserEvaporativeCooled.hpp"
#include "RefrigerationCondenserWaterCooled.hpp"
#include "RefrigerationDefrostCycleParameters.hpp"
#include "RefrigerationGasCoolerAirCooled.hpp"
#include "RefrigerationSubcoolerLiquidSuction.hpp"
#include "RefrigerationSubcoolerMechanical.hpp"
#include "RefrigerationSecondarySystem.hpp"
#include "RefrigerationSystem.hpp"
#include "RefrigerationTranscriticalSystem.hpp"
#include "RefrigerationWalkIn.hpp"
#include "RefrigerationWalkInZoneBoundary.hpp"
#include "RenderingColor.hpp"
#include "RoofVegetation.hpp"
#include "RunPeriod.hpp"
#include "RunPeriodControlDaylightSavingTime.hpp"
#include "RunPeriodControlSpecialDays.hpp"
#include "ScheduleCompact.hpp"
#include "ScheduleConstant.hpp"
#include "ScheduleDay.hpp"
#include "ScheduleFixedInterval.hpp"
#include "ScheduleTypeLimits.hpp"
#include "ScheduleRule.hpp"
#include "ScheduleRuleset.hpp"
#include "ScheduleWeek.hpp"
#include "ScheduleYear.hpp"
#include "ScheduleVariableInterval.hpp"
#include "Screen.hpp"
#include "SetpointManagerFollowOutdoorAirTemperature.hpp"
#include "SetpointManagerMixedAir.hpp"
#include "SetpointManagerMultiZoneHumidityMinimum.hpp"
#include "SetpointManagerMultiZoneMinimumHumidityAverage.hpp"
#include "SetpointManagerOutdoorAirReset.hpp"
#include "SetpointManagerOutdoorAirPretreat.hpp"
#include "SetpointManagerScheduled.hpp"
#include "SetpointManagerScheduledDualSetpoint.hpp"
#include "SetpointManagerSingleZoneHumidityMinimum.hpp"
#include "SetpointManagerSingleZoneReheat.hpp"
#include "SetpointManagerWarmest.hpp"
#include "SetpointManagerWarmestTemperatureFlow.hpp"
#include "Shade.hpp"
#include "ShadingControl.hpp"
#include "ShadingSurface.hpp"
#include "ShadingSurfaceGroup.hpp"
#include "ShadowCalculation.hpp"
#include "SimpleGlazing.hpp"
#include "SimulationControl.hpp"
#include "Site.hpp"
#include "SiteGroundReflectance.hpp"
#include "SiteGroundTemperatureBuildingSurface.hpp"
#include "SiteWaterMainsTemperature.hpp"
#include "SizingParameters.hpp"
#include "SizingPlant.hpp"
#include "SizingSystem.hpp"
#include "SizingZone.hpp"
#include "SkyTemperature.hpp"
#include "Space.hpp"
#include "SpaceInfiltrationDesignFlowRate.hpp"
#include "SpaceInfiltrationEffectiveLeakageArea.hpp"
#include "SpaceType.hpp"
#include "StandardGlazing.hpp"
#include "StandardOpaqueMaterial.hpp"
#include "StandardsInformationConstruction.hpp"
#include "StandardsInformationMaterial.hpp"
#include "SteamEquipment.hpp"
#include "SteamEquipmentDefinition.hpp"
#include "SubSurface.hpp"
#include "Surface.hpp"
#include "TableMultiVariableLookup.hpp"
#include "ThermalZone.hpp"
#include "ThermostatSetpointDualSetpoint.hpp"
#include "ThermochromicGlazing.hpp"
#include "Timestep.hpp"
#include "UtilityBill.hpp"
#include "UtilityCost_Charge_Block.hpp"
#include "UtilityCost_Charge_Simple.hpp"
#include "UtilityCost_Computation.hpp"
#include "UtilityCost_Qualify.hpp"
#include "UtilityCost_Ratchet.hpp"
#include "UtilityCost_Tariff.hpp"
#include "UtilityCost_Variable.hpp"
#include "Version.hpp"
#include "WaterHeaterMixed.hpp"
#include "WaterUseConnections.hpp"
#include "WaterUseEquipment.hpp"
#include "WaterUseEquipmentDefinition.hpp"
#include "WeatherFile.hpp"
#include "WeatherFileConditionType.hpp"
#include "WeatherFileDays.hpp"
#include "WindowDataFile.hpp"
#include "WindowPropertyFrameAndDivider.hpp"
#include "YearDescription.hpp"
#include "ZoneAirContaminantBalance.hpp"
#include "ZoneAirHeatBalanceAlgorithm.hpp"
#include "ZoneCapacitanceMultiplierResearchSpecial.hpp"
#include "ZoneControlHumidistat.hpp"
#include "ZoneControlThermostatStagedDualSetpoint.hpp"
#include "ZoneHVACBaseboardConvectiveElectric.hpp"
#include "ZoneHVACBaseboardConvectiveWater.hpp"
#include "ZoneHVACEquipmentList.hpp"
#include "ZoneHVACIdealLoadsAirSystem.hpp"
#include "ZoneHVACFourPipeFanCoil.hpp"
#include "ZoneHVACHighTemperatureRadiant.hpp"
#include "ZoneHVACLowTemperatureRadiantElectric.hpp"
#include "ZoneHVACLowTempRadiantConstFlow.hpp"
#include "ZoneHVACLowTempRadiantVarFlow.hpp"
#include "ZoneHVACPackagedTerminalHeatPump.hpp"
#include "ZoneHVACPackagedTerminalAirConditioner.hpp"
#include "ZoneHVACTerminalUnitVariableRefrigerantFlow.hpp"
#include "ZoneHVACWaterToAirHeatPump.hpp"
#include "ZoneHVACUnitHeater.hpp"

// include all concrete ModelObject Impls too
#include "AirConditionerVariableRefrigerantFlow_Impl.hpp"
#include "AirflowNetworkMultiZoneComponentHorizontalOpening_Impl.hpp"
#include "AirflowNetworkMultiZoneComponentSimpleOpening_Impl.hpp"
#include "AirflowNetworkMultiZoneSurfaceCrack_Impl.hpp"
#include "AirflowNetworkMultiZoneSurfaceEffectiveLeakageArea_Impl.hpp"
#include "AirflowNetworkSimulationControl_Impl.hpp"
#include "AirGap_Impl.hpp"
#include "AirLoopHVAC_Impl.hpp"
#include "AirLoopHVACUnitaryHeatCoolVAVChangeoverBypass_Impl.hpp"
#include "AirLoopHVACUnitaryHeatPumpAirToAir_Impl.hpp"
#include "AirLoopHVACUnitaryHeatPumpAirToAirMultiSpeed_Impl.hpp"
#include "AirLoopHVACOutdoorAirSystem_Impl.hpp"
#include "AirLoopHVACReturnPlenum_Impl.hpp"
#include "AirLoopHVACSupplyPlenum_Impl.hpp"
#include "AirLoopHVACUnitarySystem_Impl.hpp"
#include "AirLoopHVACZoneMixer_Impl.hpp"
#include "AirLoopHVACZoneSplitter_Impl.hpp"
#include "AirTerminalSingleDuctInletSideMixer_Impl.hpp"
#include "AirTerminalSingleDuctConstantVolumeCooledBeam_Impl.hpp"
#include "AirTerminalSingleDuctConstantVolumeFourPipeInduction_Impl.hpp"
#include "AirTerminalSingleDuctConstantVolumeReheat_Impl.hpp"
#include "AirTerminalSingleDuctParallelPIUReheat_Impl.hpp"
#include "AirTerminalSingleDuctSeriesPIUReheat_Impl.hpp"
#include "AirTerminalSingleDuctUncontrolled_Impl.hpp"
#include "AirTerminalSingleDuctVAVReheat_Impl.hpp"
#include "AirTerminalSingleDuctVAVNoReheat_Impl.hpp"
#include "AirTerminalSingleDuctVAVHeatAndCoolNoReheat_Impl.hpp"
#include "AirTerminalSingleDuctVAVHeatAndCoolReheat_Impl.hpp"
#include "AirWallMaterial_Impl.hpp"
#include "AvailabilityManagerAssignmentList_Impl.hpp"
#include "AvailabilityManagerNightCycle_Impl.hpp"
#include "AvailabilityManagerScheduled_Impl.hpp"
#include "Blind_Impl.hpp"
#include "BoilerHotWater_Impl.hpp"
#include "BoilerSteam_Impl.hpp"
#include "Building_Impl.hpp"
#include "BuildingStory_Impl.hpp"
#include "CFactorUndergroundWallConstruction_Impl.hpp"
#include "ChillerElectricEIR_Impl.hpp"
#include "ClimateZones_Impl.hpp"
#include "CoilCoolingCooledBeam_Impl.hpp"
#include "CoilCoolingDXMultiSpeed_Impl.hpp"
#include "CoilCoolingDXMultiSpeedStageData_Impl.hpp"
#include "CoilCoolingDXSingleSpeed_Impl.hpp"
#include "CoilCoolingDXTwoSpeed_Impl.hpp"
#include "CoilCoolingDXVariableRefrigerantFlow_Impl.hpp"
#include "CoilCoolingLowTempRadiantConstFlow_Impl.hpp"
#include "CoilCoolingLowTempRadiantVarFlow_Impl.hpp"
#include "CoilCoolingWater_Impl.hpp"
#include "CoilCoolingWaterToAirHeatPumpEquationFit_Impl.hpp"
#include "CoilHeatingDesuperheater_Impl.hpp"
#include "CoilHeatingDXSingleSpeed_Impl.hpp"
#include "CoilHeatingDXVariableRefrigerantFlow_Impl.hpp"
#include "CoilHeatingElectric_Impl.hpp"
#include "CoilHeatingGas_Impl.hpp"
#include "CoilHeatingGasMultiStage_Impl.hpp"
#include "CoilHeatingGasMultiStageStageData_Impl.hpp"
#include "CoilHeatingLowTempRadiantConstFlow_Impl.hpp"
#include "CoilHeatingLowTempRadiantVarFlow_Impl.hpp"
#include "CoilHeatingWater_Impl.hpp"
#include "CoilHeatingWaterToAirHeatPumpEquationFit_Impl.hpp"
#include "CoilHeatingWaterBaseboard_Impl.hpp"
#include "CoilWaterHeatingDesuperheater_Impl.hpp"
#include "ComponentCostAdjustments_Impl.hpp"
#include "ComponentData_Impl.hpp"
#include "Connection_Impl.hpp"
#include "ConnectorMixer_Impl.hpp"
#include "ConnectorSplitter_Impl.hpp"
#include "Construction_Impl.hpp"
#include "ConstructionWithInternalSource_Impl.hpp"
#include "ControllerMechanicalVentilation_Impl.hpp"
#include "ControllerOutdoorAir_Impl.hpp"
#include "ControllerWaterCoil_Impl.hpp"
#include "ConvergenceLimits_Impl.hpp"
#include "CoolingTowerPerformanceCoolTools_Impl.hpp"
#include "CoolingTowerPerformanceYorkCalc_Impl.hpp"
#include "CoolingTowerSingleSpeed_Impl.hpp"
#include "CoolingTowerTwoSpeed_Impl.hpp"
#include "CoolingTowerVariableSpeed_Impl.hpp"
#include "CurrencyType_Impl.hpp"
#include "CurveBicubic_Impl.hpp"
#include "CurveBiquadratic_Impl.hpp"
#include "CurveCubic_Impl.hpp"
#include "CurveDoubleExponentialDecay_Impl.hpp"
#include "CurveExponent_Impl.hpp"
#include "CurveExponentialDecay_Impl.hpp"
#include "CurveExponentialSkewNormal_Impl.hpp"
#include "CurveFanPressureRise_Impl.hpp"
#include "CurveFunctionalPressureDrop_Impl.hpp"
#include "CurveLinear_Impl.hpp"
#include "CurveQuadratic_Impl.hpp"
#include "CurveQuadraticLinear_Impl.hpp"
#include "CurveQuartic_Impl.hpp"
#include "CurveRectangularHyperbola1_Impl.hpp"
#include "CurveRectangularHyperbola2_Impl.hpp"
#include "CurveSigmoid_Impl.hpp"
#include "CurveTriquadratic_Impl.hpp"
#include "DaylightingControl_Impl.hpp"
#include "DaylightingDeviceShelf_Impl.hpp"
#include "DefaultConstructionSet_Impl.hpp"
#include "DefaultScheduleSet_Impl.hpp"
#include "DefaultSubSurfaceConstructions_Impl.hpp"
#include "DefaultSurfaceConstructions_Impl.hpp"
#include "DesignDay_Impl.hpp"
#include "DesignSpecificationOutdoorAir_Impl.hpp"
#include "DesignSpecificationZoneAirDistribution_Impl.hpp"
#include "DistrictCooling_Impl.hpp"
#include "DistrictHeating_Impl.hpp"
#include "ElectricEquipment_Impl.hpp"
#include "ElectricEquipmentDefinition_Impl.hpp"
#include "EvaporativeCoolerDirectResearchSpecial_Impl.hpp"
#include "EvaporativeCoolerIndirectResearchSpecial_Impl.hpp"
#include "EvaporativeFluidCoolerSingleSpeed_Impl.hpp"
#include "ExteriorLights_Impl.hpp"
#include "ExteriorLightsDefinition_Impl.hpp"
#include "Facility_Impl.hpp"
#include "FanConstantVolume_Impl.hpp"
#include "FanOnOff_Impl.hpp"
#include "FanVariableVolume_Impl.hpp"
#include "FanZoneExhaust_Impl.hpp"
#include "FFactorGroundFloorConstruction_Impl.hpp"
#include "Gas_Impl.hpp"
#include "GasEquipment_Impl.hpp"
#include "GasEquipmentDefinition_Impl.hpp"
#include "GasMixture_Impl.hpp"
#include "GenericModelObject_Impl.hpp"
#include "GlareSensor_Impl.hpp"
#include "GroundHeatExchangerVertical_Impl.hpp"
#include "HeatBalanceAlgorithm_Impl.hpp"
#include "HeatExchangerAirToAirSensibleAndLatent_Impl.hpp"
#include "HeatExchangerFluidToFluid_Impl.hpp"
#include "HotWaterEquipment_Impl.hpp"
#include "HotWaterEquipmentDefinition_Impl.hpp"
#include "HumidifierSteamElectric_Impl.hpp"
#include "IlluminanceMap_Impl.hpp"
#include "InfraredTransparentMaterial_Impl.hpp"
#include "InsideSurfaceConvectionAlgorithm_Impl.hpp"
#include "InteriorPartitionSurface_Impl.hpp"
#include "InteriorPartitionSurfaceGroup_Impl.hpp"
#include "InternalMass_Impl.hpp"
#include "InternalMassDefinition_Impl.hpp"
#include "LifeCycleCost_Impl.hpp"
#include "LifeCycleCostParameters_Impl.hpp"
#include "LifeCycleCostUsePriceEscalation_Impl.hpp"
#include "LightingDesignDay_Impl.hpp"
#include "LightingSimulationControl_Impl.hpp"
#include "LightingSimulationZone_Impl.hpp"
#include "Lights_Impl.hpp"
#include "LightsDefinition_Impl.hpp"
#include "Luminaire_Impl.hpp"
#include "LuminaireDefinition_Impl.hpp"
#include "MasslessOpaqueMaterial_Impl.hpp"
#include "Meter_Impl.hpp"
#include "ModelObjectList_Impl.hpp"
#include "Node_Impl.hpp"
#include "PortList_Impl.hpp"
#include "OtherEquipment_Impl.hpp"
#include "OtherEquipmentDefinition_Impl.hpp"
#include "OutputControlReportingTolerances_Impl.hpp"
#include "OutputVariable_Impl.hpp"
#include "OutsideSurfaceConvectionAlgorithm_Impl.hpp"
#include "People_Impl.hpp"
#include "PeopleDefinition_Impl.hpp"
#include "PipeAdiabatic_Impl.hpp"
#include "PlantLoop_Impl.hpp"
#include "ProgramControl_Impl.hpp"
#include "PumpConstantSpeed_Impl.hpp"
#include "PumpVariableSpeed_Impl.hpp"
#include "RadianceParameters_Impl.hpp"
#include "RefractionExtinctionGlazing_Impl.hpp"
#include "RefrigerationAirChiller_Impl.hpp"
#include "RefrigerationCase_Impl.hpp"
#include "RefrigerationCompressor_Impl.hpp"
#include "RefrigerationCondenserAirCooled_Impl.hpp"
#include "RefrigerationCondenserCascade_Impl.hpp"
#include "RefrigerationCondenserEvaporativeCooled_Impl.hpp"
#include "RefrigerationCondenserWaterCooled_Impl.hpp"
#include "RefrigerationDefrostCycleParameters_Impl.hpp"
#include "RefrigerationGasCoolerAirCooled_Impl.hpp"
#include "RefrigerationSubcoolerLiquidSuction_Impl.hpp"
#include "RefrigerationSubcoolerMechanical_Impl.hpp"
#include "RefrigerationSecondarySystem_Impl.hpp"
#include "RefrigerationSystem_Impl.hpp"
#include "RefrigerationTranscriticalSystem_Impl.hpp"
#include "RefrigerationWalkIn_Impl.hpp"
#include "RefrigerationWalkInZoneBoundary_Impl.hpp"
#include "RenderingColor_Impl.hpp"
#include "RoofVegetation_Impl.hpp"
#include "RunPeriod_Impl.hpp"
#include "RunPeriodControlDaylightSavingTime_Impl.hpp"
#include "RunPeriodControlSpecialDays_Impl.hpp"
#include "ScheduleCompact_Impl.hpp"
#include "ScheduleConstant_Impl.hpp"
#include "ScheduleDay_Impl.hpp"
#include "ScheduleFixedInterval_Impl.hpp"
#include "ScheduleTypeLimits_Impl.hpp"
#include "ScheduleWeek_Impl.hpp"
#include "ScheduleRule_Impl.hpp"
#include "ScheduleRuleset_Impl.hpp"
#include "ScheduleYear_Impl.hpp"
#include "ScheduleVariableInterval_Impl.hpp"
#include "Screen_Impl.hpp"
#include "SetpointManagerFollowOutdoorAirTemperature_Impl.hpp"
#include "SetpointManagerMixedAir_Impl.hpp"
#include "SetpointManagerMultiZoneHumidityMinimum_Impl.hpp"
#include "SetpointManagerMultiZoneMinimumHumidityAverage_Impl.hpp"
#include "SetpointManagerOutdoorAirPretreat_Impl.hpp"
#include "SetpointManagerOutdoorAirReset_Impl.hpp"
#include "SetpointManagerScheduled_Impl.hpp"
#include "SetpointManagerScheduledDualSetpoint_Impl.hpp"
#include "SetpointManagerSingleZoneHumidityMinimum_Impl.hpp"
#include "SetpointManagerSingleZoneReheat_Impl.hpp"
#include "SetpointManagerWarmest_Impl.hpp"
#include "SetpointManagerWarmestTemperatureFlow_Impl.hpp"
#include "Shade_Impl.hpp"
#include "ShadingControl_Impl.hpp"
#include "ShadingSurface_Impl.hpp"
#include "ShadingSurfaceGroup_Impl.hpp"
#include "ShadowCalculation_Impl.hpp"
#include "SimpleGlazing_Impl.hpp"
#include "SimulationControl_Impl.hpp"
#include "Site_Impl.hpp"
#include "SiteGroundReflectance_Impl.hpp"
#include "SiteGroundTemperatureBuildingSurface_Impl.hpp"
#include "SiteWaterMainsTemperature_Impl.hpp"
#include "SizingParameters_Impl.hpp"
#include "SizingPlant_Impl.hpp"
#include "SizingSystem_Impl.hpp"
#include "SizingZone_Impl.hpp"
#include "SkyTemperature_Impl.hpp"
#include "Space_Impl.hpp"
#include "SpaceInfiltrationDesignFlowRate_Impl.hpp"
#include "SpaceInfiltrationEffectiveLeakageArea_Impl.hpp"
#include "SpaceType_Impl.hpp"
#include "StandardGlazing_Impl.hpp"
#include "StandardOpaqueMaterial_Impl.hpp"
#include "StandardsInformationConstruction_Impl.hpp"
#include "StandardsInformationMaterial_Impl.hpp"
#include "SteamEquipment_Impl.hpp"
#include "SteamEquipmentDefinition_Impl.hpp"
#include "SubSurface_Impl.hpp"
#include "Surface_Impl.hpp"
#include "TableMultiVariableLookup_Impl.hpp"
#include "ThermalZone_Impl.hpp"
#include "ThermochromicGlazing_Impl.hpp"
#include "ThermostatSetpointDualSetpoint_Impl.hpp"
#include "Timestep_Impl.hpp"
#include "UtilityBill_Impl.hpp"
#include "UtilityCost_Charge_Block_Impl.hpp"
#include "UtilityCost_Charge_Simple_Impl.hpp"
#include "UtilityCost_Computation_Impl.hpp"
#include "UtilityCost_Qualify_Impl.hpp"
#include "UtilityCost_Ratchet_Impl.hpp"
#include "UtilityCost_Tariff_Impl.hpp"
#include "UtilityCost_Variable_Impl.hpp"
#include "Version_Impl.hpp"
#include "WaterHeaterMixed_Impl.hpp"
#include "WaterUseConnections_Impl.hpp"
#include "WaterUseEquipment_Impl.hpp"
#include "WaterUseEquipmentDefinition_Impl.hpp"
#include "WeatherFile_Impl.hpp"
#include "WeatherFileConditionType_Impl.hpp"
#include "WeatherFileDays_Impl.hpp"
#include "WindowDataFile_Impl.hpp"
#include "WindowPropertyFrameAndDivider_Impl.hpp"
#include "YearDescription_Impl.hpp"
#include "ZoneAirContaminantBalance_Impl.hpp"
#include "ZoneAirHeatBalanceAlgorithm_Impl.hpp"
#include "ZoneCapacitanceMultiplierResearchSpecial_Impl.hpp"
#include "ZoneControlHumidistat_Impl.hpp"
#include "ZoneControlThermostatStagedDualSetpoint_Impl.hpp"
#include "ZoneHVACBaseboardConvectiveElectric_Impl.hpp"
#include "ZoneHVACBaseboardConvectiveWater_Impl.hpp"
#include "ZoneHVACEquipmentList_Impl.hpp"
#include "ZoneHVACIdealLoadsAirSystem_Impl.hpp"
#include "ZoneHVACFourPipeFanCoil_Impl.hpp"
#include "ZoneHVACHighTemperatureRadiant_Impl.hpp"
#include "ZoneHVACLowTemperatureRadiantElectric_Impl.hpp"
#include "ZoneHVACLowTempRadiantConstFlow_Impl.hpp"
#include "ZoneHVACLowTempRadiantVarFlow_Impl.hpp"
#include "ZoneHVACPackagedTerminalHeatPump_Impl.hpp"
#include "ZoneHVACPackagedTerminalAirConditioner_Impl.hpp"
#include "ZoneHVACTerminalUnitVariableRefrigerantFlow_Impl.hpp"
#include "ZoneHVACWaterToAirHeatPump_Impl.hpp"
#include "ZoneHVACUnitHeater_Impl.hpp"

#endif // MODEL_CONCRETEMODELOBJECTS_HPP
