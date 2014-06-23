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
#include "AirflowFixture.hpp"
#include "../airflow/NetworkBuilder.hpp"
#include ".../../model/Model.hpp"
#include "../../osversion/VersionTranslator.hpp"

#include <resources.hxx>

#include <sstream>

TEST_F(AirflowFixture, BasicNetworkBuilder)
{

  // Open the model
  openstudio::path inputPath = openstudio::toPath("CONTAM_Demo_2012_134_windows_doors.osm");
  openstudio::osversion::VersionTranslator vt;
  boost::optional<openstudio::model::Model> optmodel = vt.loadModel(inputPath);
  ASSERT_TRUE(optmodel);
  openstudio::model::Model model = optmodel.get();
  openstudio::airflow::NetworkBuilder builder;
  ASSERT_TRUE(builder.build(model));

  //std::vector<openstudio::LogMessage> messages = builder.logMessages();
  //BOOST_FOREACH(openstudio::LogMessage mesg, messages) {
  //  std::cout << mesg.logMessage() << std::endl;
  //}

  /*
  Model model = exampleModel();

  path p = openstudio::toPath("exampleModel.prj");

  bool test = ForwardTranslator::modelToContam(model, p);

  EXPECT_TRUE(test);
  */
}
