/* -*- c++ -*- */

#include "Person.h"

Person::Person( const std::string & name, const int age )
: name_( name ),
  age_( age )
{
    // Veremos que la clase base, la más general, es la primera en llamar al
    // constructor
    std::cout << " Constructor Person " << name_ << std::endl;
}

Person::~Person()
{
    std::cout << " Destructor Person " << name_ << std::endl;
}

// Como name_ es privado, ni siquiera las clases derivadas pueden acceder
// directamente
const std::string Person::getName()
{
    return name_;
}

const std::string Person::queSoyVirtual()
{
    return "una persona";
}

const std::string Person::queSoy()
{
    return "una persona";
}
