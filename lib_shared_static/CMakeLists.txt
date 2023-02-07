cmake_minimum_required(VERSION 3.5 FATAL_ERROR)

project(obj_example LANGUAGES CXX)

add_library(message_obj OBJECT Message.hpp Message.cpp)

set_target_properties(message_obj PROPERTIES POSITION_INDEPENDENT_CODE 1)
add_library(message-shared
  SHARED
    $<TARGET_OBJECTS:message_obj>
  )
set_target_properties(message-shared
  PROPERTIES
    OUTPUT_NAME "message"
  )

add_library(message-static
  STATIC
    $<TARGET_OBJECTS:message_obj>
  )
set_target_properties(message-static
  PROPERTIES
    OUTPUT_NAME "message"
  )


add_executable(helloworld helloworld.cpp)
# 两种库都可以
# target_link_libraries(helloworld message-static)
target_link_libraries(helloworld message-shared)