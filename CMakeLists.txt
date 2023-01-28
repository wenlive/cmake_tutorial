cmake_minimum_required (VERSION 2.6)
project (Tutorial)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)


set (Tutorial_VERSION_MAJOR 1)
set (Tutorial_VERSION_MINOR 0)


option (USE_MYMATH "Use tutorial provided math implementation" ON)

# 检查函数支持要在configure_file前
include(CheckFunctionExists)
check_function_exists (log HAVE_LOG)
check_function_exists (exp HAVE_EXP)

# 生成 TutorialConfig.h
configure_file (
  "${PROJECT_SOURCE_DIR}/TutorialConfig.h.in"
  "${PROJECT_BINARY_DIR}/TutorialConfig.h"
  )


include_directories("${PROJECT_BINARY_DIR}")







if (USE_MYMATH)
  # include_directories ("${PROJECT_SOURCE_DIR}/MathFunctions")
  add_subdirectory (MathFunctions)
  list(APPEND EXTRA_LIBS MathFunctions)
  # set (EXTRA_LIBS ${EXTRA_LIBS} MathFunctions)
  # set (EXTRA_INCLUDES ${EXTRA_INCLUDES} MathFunctions)
  list(APPEND EXTRA_INCLUDES "${PROJECT_SOURCE_DIR}/MathFunctions")
endif (USE_MYMATH)



add_executable (Tutorial tutorial.cpp)
target_link_libraries (Tutorial  ${EXTRA_LIBS})
target_include_directories(Tutorial PUBLIC
                           "${PROJECT_BINARY_DIR}"
                           ${EXTRA_INCLUDES}
                           )

# add the install targets
install (TARGETS Tutorial DESTINATION bin)
install (FILES "${PROJECT_BINARY_DIR}/TutorialConfig.h"
         DESTINATION include)


include(CTest)
add_test(TutorialRUN Tutorial 25)
set_tests_properties (TutorialRUN PROPERTIES PASS_REGULAR_EXPRESSION "25 is 26")