# Aron Galdon Gines
# My CMake example project.
# Steps:
#  mkdir build
#  cd build
#  cmake ..
#  make

cmake_minimum_required (VERSION 3.5)

project(baseball)

# version M.m for my project
set (baseball_VERSION_MAJOR 1)
set (baseball_VERSION_MINOR 2)

# c++ version to use
set (CMAKE_CXX_STANDARD 14)

MESSAGE("PROJECT_SOURCE_DIR='${PROJECT_SOURCE_DIR}'")
MESSAGE("PROJECT_BINARY_DIR='${PROJECT_BINARY_DIR}'")
MESSAGE("CMAKE_CXX_STANDARD='${CMAKE_CXX_STANDARD}'")

# configure a header file to pass some of the CMake settings to the source code
configure_file (
    "${PROJECT_SOURCE_DIR}/baseballConfig.h.in"
    "${PROJECT_BINARY_DIR}/baseballConfig.h"
)
 
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

##############################
# Get the Google Test library
# copied from https://crascit.com/2015/07/25/cmake-gtest/

# add the binary tree to the search path for include files
# so that we will find baseballConfig.h
include_directories("${PROJECT_BINARY_DIR}")


# Download and unpack googletest at configure time
configure_file(CMakeLists.txt.in googletest-download/CMakeLists.txt)
execute_process(COMMAND "${CMAKE_COMMAND}" -G "${CMAKE_GENERATOR}" .
    WORKING_DIRECTORY "${CMAKE_BINARY_DIR}/googletest-download" )
execute_process(COMMAND "${CMAKE_COMMAND}" --build .
    WORKING_DIRECTORY "${CMAKE_BINARY_DIR}/googletest-download" )

# Prevent GoogleTest from overriding our compiler/linker options
# when building with Visual Studio
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

# Add googletest directly to our build. This adds
# the following targets: gtest, gtest_main, gmock
# and gmock_main
add_subdirectory("${CMAKE_BINARY_DIR}/googletest/googletest-src"
                 "${CMAKE_BINARY_DIR}/googletest/googletest-build")

# The gtest/gmock targets carry header search path
# dependencies automatically when using CMake 2.8.11 or
# later. Otherwise we have to add them here ourselves.
if(CMAKE_VERSION VERSION_LESS 2.8.11)
    include_directories("${gtest_SOURCE_DIR}/include"
                        "${gmock_SOURCE_DIR}/include")
endif()

add_executable(baseball main.cpp BaseballPlayer.cpp Person.cpp)

############################################################
# GTests
# copied from https://github.com/snikulov/google-test-examples

find_package(Threads REQUIRED)
enable_testing()
include_directories(${PROJECT_SOURCE_DIR})

file(GLOB TEST_SRC_FILES ${PROJECT_SOURCE_DIR}/gtest/*.cpp)

# from list of files we'll create tests test_name.cpp -> test_name
 foreach(_test_file ${TEST_SRC_FILES})
     get_filename_component(_test_name ${_test_file} NAME_WE)
     add_executable(${_test_name} ${_test_file} Person.cpp)
     add_dependencies(${_test_name} gtest)
     target_link_libraries(${_test_name} gtest gtest_main ${CMAKE_THREAD_LIBS_INIT})
     add_test(${_test_name} ${_test_name})
     set_tests_properties(${_test_name} PROPERTIES FOLDER gtest TIMEOUT 5)
 endforeach()
 
