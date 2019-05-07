// Prueba para provocar un stack-buffer-overflow que nos detecte AddressSanitizer.
// Sin usarlo, este fallo parece no ser detectado y el programa sigue a la suya dejando basurilla en el byte que toma la variable a.
// Compilar en modo sanitizer:
//     g++ buffer_1.cpp -o test -fsanitize=address -lasan

#include <iostream>
#include <cstdio>
#include <cstring>
#include <memory>

int main()
{
    const int bufferSize = 3; // [0..2]

    char buffer[bufferSize]; // Here uninitialized yet: garbage data
    std::cout<<"sizeof(buffer)="<<sizeof(buffer)<<std::endl;

    // Initialize every byte of the array to 0
    memset
    (
        buffer,        // pointer to the begining of the block of memory
        'K',           // new value for each byte
        sizeof(buffer) // number of bytes to fill
    );

    for (int i = 0; i < bufferSize; ++i)
    {
        std::cout<<std::endl<<"for i="<<i<<std::endl;

        char a = buffer[i+1];

        if (a == 'K')
        {
            std::cout<<"OK, no problem yet accessing its next byte in the array."<<std::endl;
        }
        else
        {
            std::cout<<"FAILURE, we got a='"<<a<<"' when 'K' was expected! If you compile with AddressSanitizer the program will crash giving you more details instead of this dummy message."<<std::endl;
        }
    }
}
