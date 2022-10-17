/* -*- c++ -*- */

// Manual build:
// mkdir -p build && cd build
// g++ -c -std=c++17 ../main.cpp ../BaseballPlayer.cpp ../Person.cpp
// g++ -o baseball main.o BaseballPlayer.o Person.o

// Create a new CMake project
// Add unit tests

// This project is for learning purposes
// gtests and PlantUML diagrams are available

#include "BaseballPlayer.h"

#if defined(_WIN32) || defined(_WIN64)
#include <windows.h>
#pragma execution_character_set("utf-8");
#endif

int main( int argc, char *argv[] )
{
#if defined(_WIN32) || defined(_WIN64)
	SetConsoleOutputCP(65001);
#endif

    // Crear un objeto de tipo BaseballPlayer de forma estática (memoria stack)
    BaseballPlayer baseballPlayer;

    // Mostrar nombre y qué es
    std::cout << std::endl << "- BaseballPlayer " <<
        baseballPlayer.getName() << ", ¿qué eres?" << std::endl << "- Soy " <<
        baseballPlayer.queSoy() << " y con virtual soy " <<
        baseballPlayer.queSoyVirtual() << std::endl;

    // Asignar a un puntero BaseballPlayer la dirección de memoria del objeto estático
    BaseballPlayer *pBaseballPlayer = &baseballPlayer;

    // Mostrar nombre y qué es
    std::cout << std::endl << "- BaseballPlayer* " <<
        pBaseballPlayer->getName() << ", ¿qué eres?" << std::endl << "- Soy " <<
        pBaseballPlayer->queSoy() << " y con virtual soy " << 
        baseballPlayer.queSoyVirtual() << std::endl;

    // Asignar a un puntero Person la dirección de memoria del objeto estático
    Person *pPerson = &baseballPlayer;
 
    // Mostrar nombre y qué es
    std::cout << std::endl << "- Person* " <<
        pPerson->getName() << ", ¿qué eres?" << std::endl << "- Soy " <<
        pPerson->queSoy() << " y con virtual soy " << 
        baseballPlayer.queSoyVirtual() << std::endl;

#if defined(_WIN32) || defined(_WIN64)
	system("pause");
#endif

    return 0;
}
