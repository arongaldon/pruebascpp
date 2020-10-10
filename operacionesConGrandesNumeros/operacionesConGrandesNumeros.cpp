/*
11^1             11 -> 2
11^2            121 -> 2
11^3           1331 -> 2
11^4          14641 -> 2
11^5         161051 -> 3
11^6        1771561 -> 3
11^7       19487171 -> 3
11^8      214358881 -> 2
11^9     2357947691 -> 1
11^10   25937424601 -> 1
11^11  285311670611 -> 4
11^12 3138428376721 -> 2

  11   121   1331   14641
+110 +1210 +13310 +146410
----  ----  -----  ------
 121  1331  14641  161051

*/

#include <iostream>
#include <math.h>
#include <vector>

unsigned int contarDigitos(int numero)
{
    unsigned int digitos = 1;
    do
    {
        numero /= 10;
        digitos++;
    } while (numero >= 10);
    return digitos;
}

unsigned int cifra(int numero, int posicion)
{
    unsigned int cifra = 0;
    int dieces = pow(10, posicion);
    int invertido = int(numero / dieces) * dieces;
    return (numero - invertido) / pow(10, posicion - 1);
}

unsigned int contarAparicionesDigitoEnVector(const std::vector< unsigned int > &vector, unsigned int digito)
{
    unsigned int apariciones = 0;

    for (auto n : vector)
    {
        std::cout<<n;
        if (n == digito) apariciones++;
    }
    std::cout<<std::endl;
    return apariciones;
}

unsigned int unosEnOnceElevadoA(int n)
{
    unsigned int unos = 2;
    std::vector< unsigned int > resultado = {1, 1}; // 11^1

    for (int i = 2; i <= n; ++i)
    {
        unsigned int prev = 1; // El primer previo es la cifra de las unidades, que siempre será 1
        resultado.insert(resultado.begin(), 0); // El número aumentará un cifra por la izquierda

        unsigned int acarreo = 0;

        for (int pos = resultado.size() - 2; pos >= 0; pos--) 
        {
            const unsigned int original = resultado[pos];

            unsigned int nuevo = original + prev + acarreo;
            if (nuevo >= 10)
            {
                acarreo = int(nuevo / 10);
                nuevo -= acarreo * 10;
            }
            else acarreo = 0;

            resultado[pos] = nuevo;

            prev = original;
        }
    }

    return contarAparicionesDigitoEnVector(resultado, 1);
}

int main(int argc, char *argv[])
{
    for (int n = 1; n <= 20; ++n)
    {
        int unos = unosEnOnceElevadoA(n);
        std::cout<<"Unos en 11^"<<n<<" = "<<unos<<std::endl;
    }

    return 0;
}
