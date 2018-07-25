/* -*- c++ -*- */

#include <iostream>
#include <vector>
#include <exception>

struct Nodo
{
    char * val;
    std::vector<Nodo * > hijos;
};

class NoEncontrado: public exception
{
public:
  virtual const char * what() const throw()
  {
    return "Pues no se ha encontrado hello";
  }
};

Nodo * buscaHello(Nodo * actual)
{
    Nodo * encontrado = nullptr;  
    
    if (actual->val == "hello")
    {
        encontrado = actual;
    }
    else
    {
        for (Nodo * hijo : actual->hijos)
        {
            Nodo * res = buscaHello(hijo);
            if (res != nullptr)
            {
                encontrado = res;
            }
        }

    }
}

/**
 * arbol binario
 */
int main()
{
    // Rellenar el arbol
    Nodo raiz;
    Nodo h1;
    Nodo h1h1;
    Nodo h1h2;
    Nodo h2;
    Nodo h2h1;
    Nodo h3;

    h1.val = "h1";
    h2.val = "h2";
    h3.val = "h3";
    h1h1.val = "h1h1";
    h1h2.val = "h1h2";
    h2h1.val = "hello";

    std::vector<Nodo *> hijosRaiz = {& h1, & h2, & h3};
    raiz.hijos.insert(raiz.hijos.end(), hijosRaiz.begin(), hijosRaiz.end());
    
    std::vector<Nodo *> hijosH1 = {& h1h1, & h1h2};
    h1.hijos.insert(h1.hijos.end(), hijosH1.begin(), hijosH1.end());
    
    std::vector<Nodo *> hijosH2 = {& h2h1};
    h2.hijos.insert(h2.hijos.end(), hijosH2.begin(), hijosH2.end());

    try
    {    
        // Buscar "hello"
        Nodo * encontrado = buscaHello(& raiz);

        if (encontrado == nullptr)
        {
            NoEncontrado noEncontrado();
            throw noEncontrado;
        }

    }
    catch (NoEncontrado ex)
    {
        std::cout<<"EXCEPTION!!!!!! "<<ex.what()<<std::endl;
    }


    std::cout<<"Encontrado nodo supongo, ya que estamos aquí "<<std::endl;
    
	return EXIT_SUCCESS;
}
