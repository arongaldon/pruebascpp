/* -*- c++ -*- */

// The manual way:
// Compile: g++ -c -std=c++11 main.cpp BaseballPlayer.cpp Person.cpp
// Link:    g++ -o baseball main.o BaseballPlayer.o Person.o

// make with a hand written Makefile: MakefileAMano folder

// cmake: CMakeLists.txt that generates the Makefile

// This project is for learning purposes
// gtests and PlantUML diagrams are available

#include "BaseballPlayer.h"
#include "baseballConfig.h"

#if defined(_WIN32) || defined(_WIN64)
#include <windows.h>
#pragma execution_character_set("utf-8");
#endif

int main( int argc, char *argv[] )
{
#if defined(_WIN32) || defined(_WIN64)
	SetConsoleOutputCP(65001);
#endif

    std::string version = std::to_string(baseball_VERSION_MAJOR) + "." + version += std::to_string(baseball_VERSION_MINOR);
    std::cout << "baseball version " << version << std::endl << std::endl;

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
