#ifndef MANAGEINVENTORY_H
#define MANAGEINVENTORY_H

#include <QMainWindow>
#include "dbmanager.h"





namespace Ui {
class ManageInventory;
}


class ManageInventory : public QMainWindow
{
    Q_OBJECT

public:
    explicit ManageInventory(QWidget *parent = 0);
    ~ManageInventory();
    QWidget *parent;

private slots:


    void on_pushButton_home_clicked();

    void on_pushButton_viewInv_clicked();

private:
    Ui::ManageInventory *ui;





};

#endif // MANAGEINVENTORY_H
