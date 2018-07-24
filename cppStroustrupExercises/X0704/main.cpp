/* -*- c++ -*- */

#include <iostream>
#include <functional>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <math.h>

/**
 * histograma
 */
int main()
{
    const int VALORES = 5;
    std::srand(std::time(nullptr));  
	std::vector<int> histograma(VALORES);

	// Rellenar con frecuencias de valores [0:VALORES]
	for (int i = 0; i < VALORES; ++i)
	{
	    const int x = std::rand()/(RAND_MAX/VALORES);
		
		if (x < histograma.size())
		{
			std::cout<<x<<std::endl;
			++histograma[x];
		}
		else
		{
		    std::cout<<"Incorrecto: "<<x<<std::endl;
		}
	}

	std::cout<<"Dibujando histograma..."<<std::endl;

	for (unsigned int i = 0; i < VALORES; ++i)
	{
		std::cout << i << "\t";
		for (int j = 0; j < histograma[i]; ++j)
		{
		    std::cout << '*';
	    }
		std::cout << std::endl;
	}

	return EXIT_SUCCESS;
}
