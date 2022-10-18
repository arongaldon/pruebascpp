/* -*- c++ -*- */

#pragma once

#include <iostream>
#include "Person.h"

/**
* Si no se indicara nada, la herencia sería private (lo predeterminado),
* la cual bloquea el acceso a cualquier miembro de la clase base.
* Sin embargo, la herencia más comunmente usada es la public,
* que sólo da acceso a los métodos public y protected de la clase base.
*/
class BaseballPlayer: public Person
{
private:
    double battingAverage_; ///< Atributo deportivo
    int homeRuns_; ///< Otro atributo deportivo
    static constexpr int EDAD_MINIMA = 18; ///< constexpr define una constante en tiempo de compilación

public:
    BaseballPlayer( const double battingAverage = 0.0,
                    const int homeRuns = 0 );
    virtual ~BaseballPlayer();

    // override consigue que en todo caso se use este método y no el de la clase base
    // final evita que hijos de BaseballPlayer pudieran redefinir este método
    virtual const std::string queSoyVirtual() override final;

    const std::string queSoy();
};
