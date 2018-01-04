#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "gearcentral.h"


// test code, del when finshed
#include "reportsView.h"
#include "mainmenu.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_actionHome_triggered();

    void on_actionGoto_Home_triggered();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
