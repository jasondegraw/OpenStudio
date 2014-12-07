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

#include <model/AirflowNetworkMultiZoneSurfaceEffectiveLeakageArea.hpp>
#include <model/AirflowNetworkMultiZoneSurfaceEffectiveLeakageArea_Impl.hpp>

TEST_F(ModelFixture, EffectiveLeakageArea)
{
  openstudio::model::Model model;

  // Create an object
  openstudio::model::AirflowNetworkMultiZoneSurfaceEffectiveLeakageArea ela(model, 1.0e-3);

  // Check that everything is as it should be
  EXPECT_EQ(1.0e-3, ela.effectiveLeakageArea());
  EXPECT_TRUE(ela.isDischargeCoefficientDefaulted());
  EXPECT_TRUE(ela.isReferencePressureDifferenceDefaulted());
  EXPECT_TRUE(ela.isAirMassFlowExponentDefaulted());

  // Set values and make sure it worked
  EXPECT_TRUE(ela.setDischargeCoefficient(0.9));
  EXPECT_FALSE(ela.setDischargeCoefficient(-1.9));
  EXPECT_EQ(0.9, ela.dischargeCoefficient());
  EXPECT_FALSE(ela.isDischargeCoefficientDefaulted());

  EXPECT_TRUE(ela.setReferencePressureDifference(75.0));
  EXPECT_FALSE(ela.setReferencePressureDifference(-75.0));
  EXPECT_EQ(75.0, ela.referencePressureDifference());
  EXPECT_FALSE(ela.isReferencePressureDifferenceDefaulted());

  EXPECT_TRUE(ela.setAirMassFlowExponent(0.5));
  EXPECT_FALSE(ela.setAirMassFlowExponent(0.499999));
  EXPECT_FALSE(ela.setAirMassFlowExponent(1.000001));
  EXPECT_EQ(0.5, ela.airMassFlowExponent());
  EXPECT_FALSE(ela.isAirMassFlowExponentDefaulted());

  // Reset and make sure that also worked
  ela.resetDischargeCoefficient();
  ela.resetReferencePressureDifference();
  ela.resetAirMassFlowExponent();

  EXPECT_TRUE(ela.isDischargeCoefficientDefaulted());
  EXPECT_TRUE(ela.isReferencePressureDifferenceDefaulted());
  EXPECT_TRUE(ela.isAirMassFlowExponentDefaulted());

  // Use the other constructor
  ela = openstudio::model::AirflowNetworkMultiZoneSurfaceEffectiveLeakageArea(model, 1.0e-3, 0.9, 75.0, 0.5);

  // Check that nothing is defaulted
  EXPECT_FALSE(ela.isDischargeCoefficientDefaulted());
  EXPECT_FALSE(ela.isReferencePressureDifferenceDefaulted());
  EXPECT_FALSE(ela.isAirMassFlowExponentDefaulted());

  // Check the values
  EXPECT_EQ(0.9, ela.dischargeCoefficient());
  EXPECT_EQ(75.0, ela.referencePressureDifference());
  EXPECT_EQ(0.5, ela.airMassFlowExponent());

  // Reset and make sure that also worked
  ela.resetDischargeCoefficient();
  ela.resetReferencePressureDifference();
  ela.resetAirMassFlowExponent();

  EXPECT_TRUE(ela.isDischargeCoefficientDefaulted());
  EXPECT_TRUE(ela.isReferencePressureDifferenceDefaulted());
  EXPECT_TRUE(ela.isAirMassFlowExponentDefaulted());

}
