#ifndef MANAGEINVENTORY_H
#define MANAGEINVENTORY_H

#include <QWidget>

#include "dbmanager.h"

namespace Ui {
class ManageInventory;
}


class ManageInventory : public QWidget
{
    Q_OBJECT
public:
    explicit ManageInventory(QWidget *parent = 0);
    ~ManageInventory();

private slots:

    void on_pushButton_home_clicked();

    void on_pushButton_viewInv_clicked();

private:
    Ui::ManageInventory *ui;





};

#endif // MANAGEINVENTORY_H
