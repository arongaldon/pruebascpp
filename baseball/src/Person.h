/* -*- c++ -*- */

#pragma once
 
#include <iostream>

/**
* Generic person
*/
class Person
{
private:
    std::string name_; ///< Parents given name
protected:
    int age_; ///< How many years old
public:
    Person( const std::string & name = "Josep", const int age = 0 );
    virtual ~Person();
    const int getAge();
    const std::string getName();
    virtual const std::string queSoyVirtual();
    const std::string queSoy();
};
