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

#include <model/AirflowNetworkMultiZoneReferenceCrackConditions.hpp>
#include <model/AirflowNetworkMultiZoneReferenceCrackConditions_Impl.hpp>

TEST_F(ModelFixture, ReferenceCrackConditions)
{
  openstudio::model::Model model;

  // Create an object
  openstudio::model::AirflowNetworkMultiZoneReferenceCrackConditions refconds(model);

  // Check that everything is defaulted
  EXPECT_TRUE(refconds.isReferenceTemperatureDefaulted());
  EXPECT_TRUE(refconds.isReferenceBarometricPressureDefaulted());
  EXPECT_TRUE(refconds.isReferenceHumidityRatioDefaulted());

  // Make sure that changing values works
  refconds.setReferenceTemperature(25.75);
  EXPECT_FALSE(refconds.isReferenceTemperatureDefaulted());
  EXPECT_EQ(25.75, refconds.referenceTemperature());
  refconds.setReferenceBarometricPressure(101425.7);
  EXPECT_FALSE(refconds.isReferenceBarometricPressureDefaulted());
  EXPECT_EQ(101425.7, refconds.referenceBarometricPressure());
  refconds.setReferenceHumidityRatio(0.007);
  EXPECT_FALSE(refconds.isReferenceHumidityRatioDefaulted());
  EXPECT_EQ(0.007, refconds.referenceHumidityRatio());

  // Reset it all back and check
  refconds.resetReferenceTemperature();
  EXPECT_TRUE(refconds.isReferenceTemperatureDefaulted());
  refconds.resetReferenceBarometricPressure();
  EXPECT_TRUE(refconds.isReferenceBarometricPressureDefaulted());
  refconds.resetReferenceHumidityRatio();
  EXPECT_TRUE(refconds.isReferenceHumidityRatioDefaulted());

}