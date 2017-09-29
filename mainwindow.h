#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "manageInventory.h"


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


    void on_pushButton_mInv_clicked();

private:
    Ui::MainWindow *ui;
    ManageInventory *manageInvetory;
};

#endif // MAINWINDOW_H
