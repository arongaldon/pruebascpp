#include "../src/Person.h"
#include <gtest/gtest.h>

TEST(Person_test, test_getEmptyName)
{
    Person person("");
    EXPECT_EQ(person.getName(), "");
}

TEST(Person_test, test_getDefaultName)
{
    Person person;
    EXPECT_EQ(person.getName(), "Josep");
}

TEST(Person_test, test_getName)
{
    Person person("Aron");
    EXPECT_EQ(person.getName(), "Aron");
}

TEST(Person_test, test_getDefaultAge)
{
    Person person("Aron");
    EXPECT_EQ(person.getAge(), 0);
}

TEST(Person_test, test_getAge)
{
    Person person("Aron", 13);
    EXPECT_EQ(person.getAge(), 13);
}
