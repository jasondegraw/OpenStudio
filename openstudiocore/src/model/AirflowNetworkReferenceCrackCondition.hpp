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

#ifndef MODEL_AIRFLOWNETWORKREFERENCECRACKCONDITION_HPP
#define MODEL_AIRFLOWNETWORKREFERENCECRACKCONDITION_HPP

#include <model/ModelAPI.hpp>
#include <model/ModelObject.hpp>

namespace openstudio {

namespace model {

namespace detail {

  class AirflowNetworkReferenceCrackCondition_Impl;

} // detail

/** AirflowNetworkReferenceCrackCondition is a ModelObject that wraps the OpenStudio IDD object 'OS:AirflowNetworkReferenceCrackConditions'. */
class MODEL_API AirflowNetworkReferenceCrackCondition : public ModelObject {
 public:
  /** @name Constructors and Destructors */
  //@{

  explicit AirflowNetworkReferenceCrackCondition(const Model& model);

  virtual ~AirflowNetworkReferenceCrackCondition() {}

  //@}

  static IddObjectType iddObjectType();

  /** @name Getters */
  //@{

  double referenceTemperature() const;

  bool isReferenceTemperatureDefaulted() const;

  double referenceBarometricPressure() const;

  bool isReferenceBarometricPressureDefaulted() const;

  double referenceHumidityRatio() const;

  bool isReferenceHumidityRatioDefaulted() const;

  //@}
  /** @name Setters */
  //@{

  void setReferenceTemperature(double referenceTemperature);

  void resetReferenceTemperature();

  bool setReferenceBarometricPressure(double referenceBarometricPressure);

  void resetReferenceBarometricPressure();

  void setReferenceHumidityRatio(double referenceHumidityRatio);

  void resetReferenceHumidityRatio();

  //@}
  /** @name Other */
  //@{

  //@}
 protected:
  /// @cond
  typedef detail::AirflowNetworkReferenceCrackCondition_Impl ImplType;

  explicit AirflowNetworkReferenceCrackCondition(boost::shared_ptr<detail::AirflowNetworkReferenceCrackCondition_Impl> impl);

  friend class detail::AirflowNetworkReferenceCrackCondition_Impl;
  friend class Model;
  friend class IdfObject;
  friend class openstudio::detail::IdfObject_Impl;
  /// @endcond
 private:
  REGISTER_LOGGER("openstudio.model.AirflowNetworkReferenceCrackCondition");
};

/** \relates AirflowNetworkReferenceCrackCondition*/
typedef boost::optional<AirflowNetworkReferenceCrackCondition> OptionalAirflowNetworkReferenceCrackCondition;

/** \relates AirflowNetworkReferenceCrackCondition*/
typedef std::vector<AirflowNetworkReferenceCrackCondition> AirflowNetworkReferenceCrackConditionVector;

} // model
} // openstudio

#endif // MODEL_AIRFLOWNETWORKREFERENCECRACKCONDITION_HPP

