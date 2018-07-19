/* -*- c++ -*- */

/* Read in a bool, a char, an int, a double and a string                   */

#include <iostream>

int main( int argc, char *argv[] )
{
    bool verdadero = true;
    bool falso = false;
    char caracter = 'x';
    int entero = 15;
    double decimal = 6.54321;
    std::string cadena = "Texto";

    std::cout <<
        "verdadero? ...dime 1 ;) : ";
    std::cin >> verdadero;
    std::cout <<
        "    falso? ...dime 0 ;) : ";
    std::cin >> falso;
    std::cout <<
        " caracter?: ";
    std::cin >> caracter;
    std::cout <<
        "   entero?: ";
    std::cin >> entero;
    std::cout <<
        "  decimal?: ";
    std::cin >> decimal;
    std::cout <<
        "   cadena?: ";
    std::cin >> cadena;

    std::cout << std::endl <<
        "Esto es lo que me has dicho:" << std::endl <<
        "verdadero: " << verdadero << std::endl <<
        "    falso: " << falso     << std::endl <<
        " caracter: " << caracter  << std::endl <<
        "   entero: " << entero    << std::endl <<
        "  decimal: " << decimal   << std::endl <<
        "   cadena: " << cadena    << std::endl;

    return EXIT_SUCCESS;
}
