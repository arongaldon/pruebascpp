#ifndef FRONTMAINWINDOW_H
#define FRONTMAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class FrontMainWindow;
}

class FrontMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit FrontMainWindow(QWidget *parent = nullptr);
    ~FrontMainWindow();

private slots:
    void on_number_spinBox_valueChanged(int arg1);

private:
    Ui::FrontMainWindow *ui;
    const QString SERVICE_NAME = "arongaldongines.DBusBackFront";
};

#endif // FRONTMAINWINDOW_H
