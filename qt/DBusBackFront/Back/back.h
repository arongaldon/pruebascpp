#ifndef BACK_H
#define BACK_H

#include <QtCore/QObject>

namespace arongaldongines {

class Back: public QObject
{
    Q_OBJECT

public slots:
    Q_SCRIPTABLE QString numberChanged(const int &arg);
};

} // namespace arongaldongines

#endif // BACK_H
