/* -*- c++ -*- */

/* Get the ‘‘Hello, world!’’ program (§2.2.1) to run. This is not an         *
 * exercise in programming. It is an exercise to test your use of your       *
 * edit-compile-link-execute tool chain.                                     */

// Compila: g++ -c -std=c++14 holamundo.cpp
// Linka:   g++ -o a.out holamundo.o

#include <iostream>

int main( int argc, char *argv[] )
{
    std::cout << "Hola mundo" << std::endl;

    return EXIT_SUCCESS;
}
