#include "manageInventory.h"
#include "ui_manageInventory.h"

#include "mainwindow.h"


ManageInventory::ManageInventory(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ManageInventory)
{
    ui->setupUi(this);
    this->parent = parent;
}

ManageInventory::~ManageInventory()
{
    delete ui;
}



void ManageInventory::on_pushButton_home_clicked()
{
    this->parent->show();
    hide();

}

