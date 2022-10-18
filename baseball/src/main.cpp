/* -*- c++ -*- */

// Manual build:
// mkdir -p build && cd build && g++ -c -std=c++17 ../main.cpp ../BaseballPlayer.cpp ../Person.cpp && g++ -o baseball main.o BaseballPlayer.o Person.o

// CMake build:
// mkdir -p build && cd build && cmake .. && cmake --build .

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

    // Asignar a un puntero BaseballPlayer la dirección de memoria del objeto estático
    BaseballPlayer *pBaseballPlayer = &baseballPlayer;
    std::cout << "El pBaseballPlayer es " << pBaseballPlayer->queSoy() << " y con virtual " << pBaseballPlayer->queSoyVirtual() << std::endl;

    // Asignar a un puntero Person la dirección de memoria del objeto estático
    Person *pPerson = &baseballPlayer;
    std::cout << "La pPerson es " << pPerson->queSoy() << " y con virtual " << pPerson->queSoyVirtual() << std::endl;
 
#if defined(_WIN32) || defined(_WIN64)
	system("pause");
#endif

    return EXIT_SUCCESS;
}
