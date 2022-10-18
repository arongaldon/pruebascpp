add_executable(baseball main.cpp BaseballPlayer.cpp Person.cpp)
target_include_directories(baseball PUBLIC include)
set(SOURCES Person.cpp)
add_library(Person STATIC ${SOURCES})
