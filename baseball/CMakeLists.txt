# mkdir -p build && cd build && cmake .. && make

project(baseball)
cmake_minimum_required(VERSION 3.16)
set(CMAKE_CXX_STANDARD 17)
add_subdirectory(src)
