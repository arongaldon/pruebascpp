#include "Person.h"
#include "gtest/gtest.h"

/**
 * @brief Google Test Case that contains all the tests over the class Person
 * 
 */
class PersonGtest : public ::testing::Test
{
    protected:

    PersonGtest()
    {

    }

    virtual ~PersonGtest() {
    // You can do clean-up work that doesn't throw exceptions here.
    }

  // If the constructor and destructor are not enough for setting up
  // and cleaning up each test, you can define the following methods:

  virtual void SetUp() {
    // Code here will be called immediately after the constructor (right
    // before each test).
  }

  virtual void TearDown() {
    // Code here will be called immediately after each test (right
    // before the destructor).
  }

};

TEST(PersonGtest, PersonDefaultNameIsJosep) { 
    Person p;
    EXPECT_EQ("Josep", p.getName());
}
 
TEST(PersonGtest, PersonDefaultNameIsNotEmpty) { 
    Person p;
    EXPECT_NE("", p.getName());
}

TEST(PersonGtest, PersonNameIsVladimir) { 
    Person p("Vladimir", 59);
    EXPECT_EQ("Vladimir", p.getName());
}
 
TEST(PersonGtest, PersonNameIsNotEmpty) { 
    Person p("Vladimir", 59);
    EXPECT_NE("", p.getName());
}
 
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
