#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void capturar();
    void limpiar();
    void guardar();
private:
    Ui::MainWindow *ui = NULL;
    QPixmap *foto = NULL;
};

#endif // MAINWINDOW_H
