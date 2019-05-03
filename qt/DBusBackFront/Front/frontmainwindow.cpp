#include <QtDBus/QtDBus>
#include <iostream>
#include "frontmainwindow.h"
#include "ui_frontmainwindow.h"

FrontMainWindow::FrontMainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::FrontMainWindow)
{
    ui->setupUi(this);
}

FrontMainWindow::~FrontMainWindow()
{
    delete ui;
}

void FrontMainWindow::on_number_spinBox_valueChanged(int arg1)
{
    if (!QDBusConnection::sessionBus().isConnected()) {
        return;
    }

    QDBusInterface iface(SERVICE_NAME, "/", "", QDBusConnection::sessionBus());
    if (iface.isValid()) {
        QDBusReply<QString> reply = iface.call("numberChanged", arg1);
        if (reply.isValid()) {
            std::cout<<QString("Hemos cambiado a %1 en el frontend. El backend nos responde: %2\n").arg(arg1).arg(qPrintable(reply.value())).toStdString();
            return;
        }

        std::cout<<QString("Call failed: %1\n").arg(reply.error().message()).toStdString();
        return;
    }

    std::cout<<QDBusConnection::sessionBus().lastError().message().toStdString();
    return;
}
