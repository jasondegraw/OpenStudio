# create a library out of the airflow namespace

SET( target_name openstudio_airflow )

SET( airflow_src
  WindPressure.hpp
  WindPressure.cpp
  SpaceLinker.hpp
  SpaceLinker.cpp
)

SET( afn_src
  afn/ForwardTranslator.hpp
  afn/ForwardTranslator.cpp
)

SET( ${target_name}_depends
  ${Boost_LIBRARIES}
  ${CMAKE_THREAD_LIBS}
  ${QT_LIBS}
  openstudio_utilities
  openstudio_model
  openstudio_energyplus
  boost_log
)

IF(WIN32)
  LIST(APPEND ${target_name}_depends qtwinmigrate)
ENDIF(WIN32)

## Qt MOC generation
#qt4_wrap_cpp( bcl_moc_src ${bcl_moc} )
#qt4_wrap_cpp( cloud_moc_src ${cloud_moc} )

# qrc files
#SET( bcl_qrc
#  bcl/bcl.qrc
#)

# generate rules for building source files from the resources
#qt4_add_resources(bcl_qrc_src ${bcl_qrc})
# set up groups of source files for Visual Studio
SOURCE_GROUP( afn FILES ${afn_src} )

# Is this really needed?
ADD_CUSTOM_COMMAND(
  OUTPUT "${CMAKE_CURRENT_BINARY_DIR}/SWIGRubyRuntime.hxx"
  COMMAND "${SWIG_EXECUTABLE}"
          "-ruby" 
          -external-runtime "${CMAKE_CURRENT_BINARY_DIR}/SWIGRubyRuntime.hxx"
)


SET( ${target_name}_src
  AirflowAPI.hpp
  "${CMAKE_CURRENT_BINARY_DIR}/SWIGRubyRuntime.hxx" # referenced here to make sure it is generated when and where we expect
  ${airflow_src}
  ${afn_src}
)

SET( ${target_name}_test_src
  afn/test/AfnFixture.hpp
  afn/test/AfnFixture.cpp
  afn/test/ForwardTranslator_GTest.cpp
)
 

SET( ${target_name}_swig_src
)

# make sure zconf.h can be found
include_directories(${CMAKE_BINARY_DIR}/src/zlib)

#include subdir for pch
#add_subdirectory(pch)

ADD_LIBRARY( ${target_name} SHARED
  ${${target_name}_src}
)

AddPCH(${target_name})

IF( NOT APPLE )
INSTALL(TARGETS ${target_name}
  RUNTIME DESTINATION bin 
  LIBRARY DESTINATION lib )
ENDIF()

TARGET_LINK_LIBRARIES(${target_name} ${${target_name}_depends})
CREATE_SRC_GROUPS( "${${target_name}_test_src}" )
CREATE_TEST_TARGETS( ${target_name} "${${target_name}_test_src}" "${${target_name}_depends}"  )

IF( BUILD_TESTING )
#  ADD_DEPENDENCIES("${target_name}_tests" openstudio_energyplus_resources openstudio_standardsinterface_resources)
ENDIF()

CREATE_SRC_GROUPS( "${${target_name}_swig_src}" )

#MAKE_SWIG_TARGET( OpenStudioAirflowAfn airflowafn
#  "${CMAKE_CURRENT_SOURCE_DIR}/AirflowAfn.i"
#  "${${target_name}_swig_src}" ${target_name} OpenStudioEnergyPlus )
