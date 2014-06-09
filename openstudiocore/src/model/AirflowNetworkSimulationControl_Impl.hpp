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

#include <model/ParentObject_Impl.hpp>
#include <model/ModelObject_Impl.hpp>

#include <utilities/units/Quantity.hpp>
#include <utilities/units/OSOptionalQuantity.hpp>

namespace openstudio {
namespace model {

// class ZoneAirContaminantBalance;

namespace detail {

class MODEL_API AirflowNetworkSimulationControl_Impl : public ParentObject_Impl {
  Q_OBJECT;
  Q_PROPERTY(boost::optional<std::string> airflowNetworkControl READ airflowNetworkControl WRITE setAirflowNetworkControl);

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

  /** @name Getters */
  //@{

  boost::optional<std::string> airflowNetworkControl() const;

  //@}
  /** @name Setters */
  //@{

  bool setAirflowNetworkControl(boost::optional<std::string> control);

  bool setAirflowNetworkControl(std::string control);

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
