#include "mainwindow.h"
#include "ui_mainwindow.h"


//*********************************************************************************
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    bbb::DbConnect::getInstance()->sysLog("SYSTEM:\tSTART");
    ui->setupUi(this);
    this->showMaximized();
    //function to change the central widget
//    QWidget* reportsView = new ReportsView(this);
//    setCentralWidget(reportsView);

    QWidget* mainMenu = new MainMenu(this);
    setCentralWidget(mainMenu);
}
//*********************************************************************************

//*********************************************************************************
MainWindow::~MainWindow()
{
    bbb::DbConnect::getInstance()->sysLog("SYSTEM:\tSHUTDOWN");
    delete ui;
}
//*********************************************************************************

//*********************************************************************************
void MainWindow::on_actionHome_triggered()
{
// non reachable slotS
    // Idk what this does, do not delete until final.
}
//*********************************************************************************

//*********************************************************************************
void MainWindow::on_actionGoto_Home_triggered()
{
    //This is the home botton.
    QWidget* mainMenu = new MainMenu(this);
    setCentralWidget(mainMenu);
}
//*********************************************************************************
