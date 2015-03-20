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

#include <model/AirflowNetworkMultiZoneSurfaceCrack.hpp>
#include <model/AirflowNetworkMultiZoneSurfaceCrack_Impl.hpp>

TEST_F(ModelFixture, Crack)
{
  openstudio::model::Model model;

  // Create the crack
  openstudio::model::AirflowNetworkMultiZoneSurfaceCrack crack(model,0.0006);

  // Check that everything is as it should be
  EXPECT_EQ(0.0006, crack.airMassFlowCoefficientatReferenceConditions());
  EXPECT_TRUE(crack.isAirMassFlowExponentDefaulted());
  EXPECT_TRUE(crack.isReferenceTemperatureDefaulted());
  EXPECT_TRUE(crack.isReferenceBarometricPressureDefaulted());
  EXPECT_TRUE(crack.isReferenceHumidityRatioDefaulted());

  // Set the reference conditions
  crack.setReferenceTemperature(25.75);
  EXPECT_FALSE(crack.isReferenceTemperatureDefaulted());
  EXPECT_EQ(25.75, crack.referenceTemperature());
  crack.resetReferenceTemperature();
  EXPECT_TRUE(crack.isReferenceTemperatureDefaulted());

  crack.setReferenceHumidityRatio(0.007);
  EXPECT_FALSE(crack.isReferenceHumidityRatioDefaulted());
  EXPECT_EQ(0.007, crack.referenceHumidityRatio());
  crack.resetReferenceHumidityRatio();
  EXPECT_TRUE(crack.isReferenceHumidityRatioDefaulted());

  crack.setReferenceBarometricPressure(101425.7);
  EXPECT_FALSE(crack.isReferenceBarometricPressureDefaulted());
  EXPECT_EQ(101425.7, crack.referenceBarometricPressure());
  crack.resetReferenceBarometricPressure();
  EXPECT_TRUE(crack.isReferenceBarometricPressureDefaulted());

  // Set the exponent
  EXPECT_TRUE(crack.setAirMassFlowExponent(0.66));
  EXPECT_FALSE(crack.setAirMassFlowExponent(0.499999));
  EXPECT_FALSE(crack.setAirMassFlowExponent(1.000001));

  // Check that it worked
  EXPECT_FALSE(crack.isAirMassFlowExponentDefaulted());
  EXPECT_EQ(0.66, crack.airMassFlowExponent());

  // Reset and check that the reset worked
  crack.resetAirMassFlowExponent();
  EXPECT_TRUE(crack.isAirMassFlowExponentDefaulted());

  crack = openstudio::model::AirflowNetworkMultiZoneSurfaceCrack(model, 0.0006, 0.675, 25.75, 101425.7, 0.007);
  EXPECT_EQ(0.0006, crack.airMassFlowCoefficientatReferenceConditions());
  EXPECT_FALSE(crack.isAirMassFlowExponentDefaulted());
  EXPECT_FALSE(crack.isReferenceTemperatureDefaulted());
  EXPECT_FALSE(crack.isReferenceBarometricPressureDefaulted());
  EXPECT_FALSE(crack.isReferenceHumidityRatioDefaulted());
  EXPECT_EQ(0.675, crack.airMassFlowExponent());
  EXPECT_EQ(25.75, crack.referenceTemperature());
  EXPECT_EQ(101425.7, crack.referenceBarometricPressure());
  EXPECT_EQ(0.007, crack.referenceHumidityRatio());


}

