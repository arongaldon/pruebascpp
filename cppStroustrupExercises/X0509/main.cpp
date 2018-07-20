/* -*- c++ -*- */

#include <iostream>
#include <fstream>

using namespace std;

/**
 * Escribir un centenar de enteros en un fichero
 */
int main()
{
	ofstream is{ "integers" }; // Output stream for file "integers"

	for (int x = 1; x < 100; ++x) {
		is << x << endl;
	} // Print vector
	
    return EXIT_SUCCESS;
}
