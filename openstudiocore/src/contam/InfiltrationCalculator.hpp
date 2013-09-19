/**********************************************************************
*  Copyright (c) 2008-2010, Alliance for Sustainable Energy.
*  Copyright (c) 2013, The Pennsylvania State University.
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

#ifndef CONTAM_INFILTRATIONCALCULATOR_HPP
#define CONTAM_INFILTRATIONCALCULATOR_HPP

#include "ContamAPI.hpp"

#include <vector>

//#include <contam/PrjData.hpp>
#include <contam/ForwardTranslator.hpp>

//#include <utilities/idf/Handle.hpp>
//#include <utilities/core/Path.hpp>
//#include <utilities/core/Optional.hpp>

#include <model/Model.hpp>
#include <utilities/core/Logger.hpp>
#include <utilities/core/StringStreamLogSink.hpp>

namespace openstudio{
class ProgressBar;
namespace model{
//class Model;
  class Surface;
}

namespace contam{

class DesignFlowRateCoeffs
{
public:
  DesignFlowRateCoeffs() : m_Idesign(0), m_A(0), m_B(0), m_C(0), m_D(0)
  {}
  DesignFlowRateCoeffs(double Idesign, double A, double B, double C, double D)
    : m_Idesign(Idesign), m_A(A), m_B(B), m_C(C), m_D(D)
  {}

  double Idesign() const
  {
    return m_Idesign;
  }
  double A() const
  {
    return m_A;
  }
  double B() const
  {
    return m_B;
  }
  double C() const
  {
    return m_C;
  }
  double D() const
  {
    return m_D;
  }

private:
  double m_Idesign;
  double m_A;
  double m_B;
  double m_C;
  double m_D;
};

class CONTAM_API InfiltrationCalculator
{
public:
  InfiltrationCalculator(openstudio::model::Model model, int ndirs=4,
    std::string leakageDescriptor="Average", ProgressBar *progressBar=0);

  int directions() const;
  void setDirections(int ndirs);

  bool run();
  void apply();

  // Get warning messages generated by the last translation.
  std::vector<LogMessage> warnings() const;
  // Get error messages generated by the last translation.
  std::vector<LogMessage> errors() const;

private:
  boost::optional<std::map<Handle,DesignFlowRateCoeffs> > windSpeed2Pt(std::string leakageDescriptor="Average");
  boost::optional<QVector<double> > simulate(std::map <openstudio::Handle,int> spaceMap,
                                             openstudio::contam::ForwardTranslator &translator,
                                             std::vector<openstudio::model::Surface> extSurfaces,
                                             double windSpeed, double windDirection);

  openstudio::model::Model m_model;
  int m_ndirs;
  std::string m_leakageDescriptor;

  std::map<Handle,DesignFlowRateCoeffs> m_coeffMap;

  // These probably don't belong here, but I'll put them here temporarily
  openstudio::path contamExe;
  openstudio::path simreadExe; 

  ProgressBar* m_progressBar;
  StringStreamLogSink m_logSink;

  REGISTER_LOGGER("openstudio.contam.InfiltrationCalculator");
};

} // contam
} // openstudio

#endif // CONTAM_INFILTRATIONCALCULATOR_HPP