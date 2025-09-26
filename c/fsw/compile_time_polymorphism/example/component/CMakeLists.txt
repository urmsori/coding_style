target_sources(${CMAKE_CURRENT_LIST_DIR}/component.c)

if (EXISTS ${CMAKE_CURRENT_LIST_DIR}/variant_specific/${VARIANT_COMPONENT}/CMakeLists.txt)
  include(${CMAKE_CURRENT_LIST_DIR}/variant_specific/${VARIANT_COMPONENT}/CMakeLists.txt)
endif ()
