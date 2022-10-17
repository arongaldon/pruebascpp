# mkdir -p build && cd build && cmake .. && make

cmake_minimum_required (VERSION 3.16)
project(baseball)
set (CMAKE_CXX_STANDARD 17)
add_executable(baseball main.cpp BaseballPlayer.cpp Person.cpp)
