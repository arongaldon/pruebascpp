# mkdir -p build && cd build && cmake .. && make

if(POLICY CMP0048)
    cmake_policy(SET CMP0048 NEW) # VERSION option
endif()

project(
    Baseball
    LANGUAGES C CXX
    VERSION 0.1.3
    DESCRIPTION "My C++17, CMake and GoogleTest training project"
)
cmake_minimum_required(VERSION 3.16)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
add_subdirectory(src)
add_subdirectory(tests)
