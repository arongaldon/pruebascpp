/* -*- c++ -*- */

/* Read in a bool, a char, an int, a double and a string                     */
/* Ver .vscode/tasks.json */

#include <cstdlib>
#include <iostream>

int main( int argc, char *argv[] )
{
    bool booleano = false;
    char caracter = '\0';
    int entero = 0;
    double decimal = 0.0;
    std::string cadena = "";

    std::cout << " ¿booleano?: ";
    std::cin >> booleano;
    std::cout << " ¿caracter?: ";
    std::cin >> caracter;
    std::cout << "   ¿entero?: ";
    std::cin >> entero;
    std::cout << "  ¿decimal?: ";
    std::cin >> decimal;
    std::cout << "   ¿cadena?: ";
    std::cin >> cadena;

    std::cout <<
        " booleano: " << booleano << std::endl <<
        " caracter: " << caracter << std::endl <<
        "   entero: " << entero   << std::endl <<
        "  decimal: " << decimal  << std::endl <<
        "   cadena: " << cadena   << std::endl;

    return EXIT_SUCCESS;
}