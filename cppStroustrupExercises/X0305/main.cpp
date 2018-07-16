/* -*- c++ -*- */

/* Write out a bool, a char, an int, a double and a string                   */

#include <iostream>

int main( int argc, char *argv[] )
{
    const bool verdadero = true;
    const bool falso = false;
    const char caracter = 'x';
    const int entero = 15;
    const double decimal = 6.54321;
    const std::string cadena = "Texto";

    std::cout <<
        "verdadero: " << verdadero << std::endl << // debe salir 1
        "    falso: " << falso     << std::endl << // debe salir 0
        " caracter: " << caracter  << std::endl <<
        "   entero: " << entero    << std::endl <<
        "  decimal: " << decimal   << std::endl <<
        "   cadena: " << cadena    << std::endl;

    return EXIT_SUCCESS;
}
