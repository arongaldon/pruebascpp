#include "frontmainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    FrontMainWindow w;
    w.show();

    return a.exec();
}
