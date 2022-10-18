include(FetchContent)

FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG release-1.12.1
)
FetchContent_MakeAvailable(googletest)

add_executable(
  Person_test
  Person_test.cpp
)
target_link_libraries(
  Person_test
  Person
  GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(Person_test)
