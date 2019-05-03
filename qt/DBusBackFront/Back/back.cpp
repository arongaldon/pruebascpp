#include "back.h"
#include <iostream>

namespace arongaldongines {

QString Back::numberChanged(const int &arg)
{
    QString msg = QString("¡He escuchado tu cambio a %1!").arg(arg);
    std::cout<<msg.toStdString()<<std::endl;
    return msg;
}

} // namespace arongaldongines
