/* -*- c++ -*- */

#include "BaseballPlayer.h"

// Opcionalmente, podemos llamar a un constructor de la clase base.
// Si no, se llamaría al construtor por defecto, el que no tiene argumentos.
BaseballPlayer::BaseballPlayer( const double battingAverage,
                                const int homeRuns )
: Person("Manolo", EDAD_MINIMA), 
  battingAverage_( battingAverage ),
  homeRuns_( homeRuns )
{
    // Veremos que la última clase derivada, la más específica, es la última
    // en llamar a su constructor.
    // Notar que el nombre es private, y por tanto la derivada usa el método
    // público para acceder.
    // Como la edad es protected, la dervidada puede acceder directamente a ella.
    std::cout << " Constructor BaseballPlayer " << getName() << " con edad "
    << age_ << " años" << std::endl;
}

// Hay que declarar los destructores heredados como virtuales, ya que
// si no lo hacemos no se llamará al de la clase derivada si se usa delete con un puntero
// de tipo clase base que apunta a un objeto de la derivada
BaseballPlayer::~BaseballPlayer( )
{
    std::cout << " Destructor BaseballPlayer " << getName() << std::endl;
}

// Versión del método en la clase derivada:
// si especificamos virtual (override method),
// aunque el puntero sea base se usará este.
// Con la palabra clave override method evitamos que una inexactitud
// en el método haga que no se aplique el override de forma silenciosa, es decir,
// forzamos un error de compilación si en realidad no va a funcionar el virtual como es nuestra intención.
// Si añadimos final, ya no permitimos que derivadas nuestras vuelvan a redefinir
const std::string BaseballPlayer::queSoyVirtual( )
{
    return "un jugador";
}

const std::string BaseballPlayer::queSoy( )
{
    return "un jugador";
}
