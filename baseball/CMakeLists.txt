# ARON my cmake! The first thing, is to create a build folder, and the execute cmake .. from there
cmake_minimum_required (VERSION 3.5)

project(baseball)

# version of the baseball project
set (baseball_VERSION_MAJOR 1)
set (baseball_VERSION_MINOR 0)

# c++ version to use
set (CMAKE_CXX_STANDARD 14)

# I show some info
MESSAGE("PROJECT_SOURCE_DIR='${PROJECT_SOURCE_DIR}', PROJECT_BINARY_DIR='${PROJECT_BINARY_DIR}', CMAKE_CXX_STANDARD='${CMAKE_CXX_STANDARD}'")

# configure a header file to pass some of the CMake settings
# to the source code
configure_file (
    "${PROJECT_SOURCE_DIR}/baseballConfig.h.in"
    "${PROJECT_BINARY_DIR}/baseballConfig.h"
)
 
# add the binary tree to the search path for include files
# so that we will find baseballConfig.h
include_directories("${PROJECT_BINARY_DIR}")
 
# add the executable
add_executable(baseball main.cpp BaseballPlayer.cpp Person.cpp)
