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
//#include <model/AirflowNetworkMultiZoneReferenceCrackConditions.hpp>

TEST_F(ModelFixture, Crack)
{
  openstudio::model::Model model;

  // Create the crack
  openstudio::model::AirflowNetworkMultiZoneSurfaceCrack crack(model,0.0006);

  // Check that everything is as it should be
  EXPECT_EQ(0.0006, crack.airMassFlowCoefficientatReferenceConditions());
  EXPECT_TRUE(crack.isAirMassFlowExponentDefaulted());
  //EXPECT_TRUE(crack.isReferenceCrackConditionsObjectDefaulted()); // No reference conditions available
  //EXPECT_FALSE(crack.referenceCrackConditions());

  // Create a reference conditions object
  //openstudio::model::AirflowNetworkMultiZoneReferenceCrackConditions refconds0(model, 25.75, 101425.7, 0.007);

  // Check that the reference conditions are no longer defaulted
  //EXPECT_FALSE(crack.isReferenceCrackConditionsObjectDefaulted()); // Using refconds0 implicitly
  //EXPECT_FALSE(crack.referenceCrackConditions());

  // Add in a second reference conditions object
  //openstudio::model::AirflowNetworkMultiZoneReferenceCrackConditions refconds1(model, 25.75, 101225.7, 0.007);

  // Check that the reference conditions are no longer defaulted
  //EXPECT_TRUE(crack.isReferenceCrackConditionsObjectDefaulted());
  //EXPECT_FALSE(crack.referenceCrackConditions());

  // Explicitly set the reference conditions object
  //EXPECT_TRUE(crack.setReferenceCrackConditions(refconds1));

  // Check that the reference conditions are no longer defaulted
  //EXPECT_FALSE(crack.isReferenceCrackConditionsObjectDefaulted()); // Using refconds1 explicitly
  //EXPECT_TRUE(crack.referenceCrackConditions());
  //EXPECT_EQ(refconds1, crack.referenceCrackConditions());

  // Set the exponent
  EXPECT_TRUE(crack.setAirMassFlowExponent(0.66));
  EXPECT_FALSE(crack.setAirMassFlowExponent(0.499999));
  EXPECT_FALSE(crack.setAirMassFlowExponent(1.000001));

  // Check that it worked
  EXPECT_FALSE(crack.isAirMassFlowExponentDefaulted());
  EXPECT_EQ(0.66, crack.airMassFlowExponent());

  // Reset
  //crack.resetReferenceCrackConditions();
  crack.resetAirMassFlowExponent();

  // Check that the reset worked
  //EXPECT_TRUE(crack.isReferenceCrackConditionsObjectDefaulted());
  //EXPECT_FALSE(crack.referenceCrackConditions());
  EXPECT_TRUE(crack.isAirMassFlowExponentDefaulted());

  // Go backwards
  //refconds1.remove();
  //EXPECT_FALSE(crack.isReferenceCrackConditionsObjectDefaulted());
  //refconds0.remove();
  //EXPECT_TRUE(crack.isReferenceCrackConditionsObjectDefaulted());

}

