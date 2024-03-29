#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QScreen>
#include <QWindow>
#include <QImageWriter>
#include <QFileDialog>
#include <QDate>
#include <QMessageBox>
#include <QStandardPaths>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->action_Clear->setEnabled(false);
    ui->action_Save->setEnabled(false);
}

MainWindow::~MainWindow()
{
    if (foto) {
        delete foto;
        foto = NULL;
    }
    delete ui;
}

void MainWindow::capturar()
{
    QScreen *screen = QGuiApplication::primaryScreen();
    if (const QWindow *window = windowHandle())
        screen = window->screen();
    if (!screen)
        return;

    foto = new QPixmap(screen->grabWindow(0));
    ui->scrollArea->findChild<QLabel *>("label")->setPixmap(*foto);
    ui->action_Clear->setEnabled(true);
    ui->action_Save->setEnabled(true);
}

void MainWindow::limpiar()
{
    ui->scrollArea->findChild<QLabel *>("label")->clear();
    delete foto;
    foto = NULL;
    ui->action_Clear->setEnabled(false);
    ui->action_Save->setEnabled(false);
}

void MainWindow::guardar()
{
    if (!foto)
        return;

    const QString ext = "JPG";
    QString initialPath = QStandardPaths::writableLocation(QStandardPaths::PicturesLocation);
    if (initialPath.isEmpty())
        initialPath = QDir::currentPath();
    initialPath += tr("/%1.").arg(QDate::currentDate().toString("yyyyMM")) + ext;

    QFileDialog fileDialog(this, tr("Guardar como"), initialPath);
    fileDialog.setAcceptMode(QFileDialog::AcceptSave);
    fileDialog.setFileMode(QFileDialog::AnyFile);
    fileDialog.setDirectory(initialPath);
    QStringList mimeTypes;
    foreach (const QByteArray &bf, QImageWriter::supportedMimeTypes())
        mimeTypes.append(QLatin1String(bf));
    fileDialog.setMimeTypeFilters(mimeTypes);

    const QString format = "jpeg";
    fileDialog.selectMimeTypeFilter("image/" + format);
    fileDialog.setDefaultSuffix(format);
    if (fileDialog.exec() != QDialog::Accepted)
        return;
    const QString fileName = fileDialog.selectedFiles().first();
    if (!foto->save(fileName)) {
        QMessageBox::warning(this, tr("No puedo guardar"), tr("No se pudo guardar en \"%1\".")
                             .arg(QDir::toNativeSeparators(fileName)));
    }
}
