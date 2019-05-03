#include <QtCore/QCoreApplication>
#include <QtCore/QTimer>
#include <QtDBus/QtDBus>
#include "back.h"

int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);

    const QString SERVICE_NAME = "arongaldongines.DBusBackFront";

    if (!QDBusConnection::sessionBus().isConnected()) {
        fprintf(stderr, "Cannot connect to the D-Bus session bus.\n"
                "To start it, run:\n"
                "\teval `dbus-launch --auto-syntax`\n");
        return 1;
    }

    if (!QDBusConnection::sessionBus().registerService(SERVICE_NAME)) {
        fprintf(stderr, "%s\n",
                qPrintable(QDBusConnection::sessionBus().lastError().message()));
        exit(1);
    }

    arongaldongines::Back back;
    QDBusConnection::sessionBus().registerObject("/", &back, QDBusConnection::ExportAllSlots);

    app.exec();
    return 0;
}
