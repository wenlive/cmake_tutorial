cmake_minimum_required (VERSION 2.6)
project (Tutorial)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)


set (Tutorial_VERSION_MAJOR 1)
set (Tutorial_VERSION_MINOR 0)


option (USE_MYMATH
        "Use tutorial provided math implementation" ON)


# 生成 TutorialConfig.h
configure_file (
  "${PROJECT_SOURCE_DIR}/TutorialConfig.h.in"
  "${PROJECT_BINARY_DIR}/TutorialConfig.h"
  )


include_directories("${PROJECT_BINARY_DIR}")





if (USE_MYMATH)
  include_directories ("${PROJECT_SOURCE_DIR}/MathFunctions")
  add_subdirectory (MathFunctions)
  set (EXTRA_LIBS ${EXTRA_LIBS} MathFunctions)
endif (USE_MYMATH)



add_executable (Tutorial tutorial.cpp)
target_link_libraries (Tutorial  ${EXTRA_LIBS})



