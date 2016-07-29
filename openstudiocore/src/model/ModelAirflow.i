#ifndef MODEL_AIRFLOW_I
#define MODEL_AIRFLOW_I

#ifdef SWIGPYTHON
  %module openstudiomodelairflow
#endif


%include <model/Model_Common_Include.i>
%import <model/ModelCore.i>
%import <model/ModelSimulation.i>
%import <model/ModelResources.i>
%import <model/ModelHVAC.i>

%{
  #include <utilities/geometry/Transformation.hpp>
  #include <utilities/geometry/BoundingBox.hpp>
  #include <utilities/data/TimeSeries.hpp>
  #include <utilities/sql/SqlFile.hpp>

%}

#if defined SWIGCSHARP

  #undef _csharp_module_name
  #define _csharp_module_name OpenStudioModelAirFlow
  
#endif

namespace openstudio {
namespace model {

// forward declarations

}
}

MODELOBJECT_TEMPLATES(AirflowNetworkMultiZoneComponentDetailedOpening);
MODELOBJECT_TEMPLATES(AirflowNetworkMultiZoneComponentHorizontalOpening);
MODELOBJECT_TEMPLATES(AirflowNetworkMultiZoneComponentSimpleOpening);
MODELOBJECT_TEMPLATES(AirflowNetworkMultiZoneComponentZoneExhaustFan);
MODELOBJECT_TEMPLATES(AirflowNetworkMultiZoneReferenceCrackConditions);
MODELOBJECT_TEMPLATES(AirflowNetworkMultiZoneSurface);
MODELOBJECT_TEMPLATES(AirflowNetworkMultiZoneSurfaceCrack);
MODELOBJECT_TEMPLATES(AirflowNetworkMultiZoneSurfaceEffectiveLeakageArea);

SWIG_MODELOBJECT(AirflowNetworkMultiZoneComponentDetailedOpening, 1);
SWIG_MODELOBJECT(AirflowNetworkMultiZoneComponentHorizontalOpening, 1);
SWIG_MODELOBJECT(AirflowNetworkMultiZoneComponentSimpleOpening, 1);
SWIG_MODELOBJECT(AirflowNetworkMultiZoneComponentZoneExhaustFan, 1);
SWIG_MODELOBJECT(AirflowNetworkMultiZoneReferenceCrackConditions, 1);
SWIG_MODELOBJECT(AirflowNetworkMultiZoneSurface, 1);
SWIG_MODELOBJECT(AirflowNetworkMultiZoneSurfaceCrack, 1);
SWIG_MODELOBJECT(AirflowNetworkMultiZoneSurfaceEffectiveLeakageArea, 1);

#if defined SWIGCSHARP || defined(SWIGJAVA)

#endif

#if defined(SWIGCSHARP)

#endif

#endif 


