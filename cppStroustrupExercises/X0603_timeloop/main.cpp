/* -*- c++ -*- */

#include <iostream>
#include <chrono>
#include <thread> // Y se requiere -lpthread en el Makefile

// Time loop to compare the duration between default-debug and release compilation

int main()
{
    std::chrono::_V2::system_clock::time_point tIni = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < 30; ++i)
    {
        std::cout << i + 1 << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds{1000});
	}
	std::chrono::_V2::system_clock::time_point tFin = std::chrono::high_resolution_clock::now();
	long int ns = (tFin - tIni).count();
	int ms = ((tFin - tIni).count() / 1000000);
	std::cout<<ns<<" nanosegundos, "<<ms<<" milisegundos"<<std::endl;
	
	return EXIT_SUCCESS;
}
