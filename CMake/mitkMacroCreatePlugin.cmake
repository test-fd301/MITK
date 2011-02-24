MACRO(MACRO_CREATE_MITK_PLUGIN)
  MITK_CHECK_MODULE(_MODULE_CHECK_RESULT Mitk ${ARGN})
  IF(NOT _MODULE_CHECK_RESULT)
  MITK_USE_MODULE(Mitk ${ARGN})
 
  LINK_DIRECTORIES(${ALL_LIBRARY_DIRS})
  INCLUDE_DIRECTORIES(${ALL_INCLUDE_DIRECTORIES})
  MACRO_CREATE_PLUGIN()

  TARGET_LINK_LIBRARIES(${PLUGIN_TARGET} ${ALL_LIBRARIES})
  ELSE(NOT _MODULE_CHECK_RESULT)
    IF(NOT MITK_BUILD_ALL_PLUGINS)
      MESSAGE(SEND_ERROR "${BUNDLE-SYMBOLICNAME} is missing requirements and won't be built. Missing: ${_MODULE_CHECK_RESULT}")
    ELSE()
      MESSAGE(STATUS "${BUNDLE-SYMBOLICNAME} is missing requirements and won't be built. Missing: ${_MODULE_CHECK_RESULT}")
    ENDIF()
  ENDIF(NOT _MODULE_CHECK_RESULT)
ENDMACRO()
