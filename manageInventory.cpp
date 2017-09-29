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


void ManageInventory::on_pushButton_viewInv_clicked()
{
    // test code for db
    Date date(2017,10,22);
    DbManager dbtest("C:/Users/007ds/Documents/qT/BigBlueBox/BigBlueBox.db"); // put db object in name space and make a pointer to it.  pass that pointer to all functions that need to access db

}
