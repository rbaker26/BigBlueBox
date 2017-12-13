#include "mainwindow.h"
#include "ui_mainwindow.h"

//*********************************************************************************
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QWidget* reportsView = new ReportsView(this);

    try
    {
         //function to change the central widget
        setCentralWidget(reportsView);
    }
    catch(int i)
    {
        qDebug() << "catch";
    }
    ui->actionHome->trigger();
}
//*********************************************************************************

//*********************************************************************************
MainWindow::~MainWindow()
{
    delete ui;
}
//*********************************************************************************

void MainWindow::on_actionHome_triggered()
{
// non reachable slotS
}

void MainWindow::on_actionGoto_Home_triggered()
{
    QWidget* gearView = new GearCentral(this);
    setCentralWidget(gearView);
    qDebug() << "Trigger";
}
