#include "mainwindow.h"
#include "ui_mainwindow.h"

//*********************************************************************************
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QWidget* reportsView = new ReportsView(this);

    setCentralWidget(reportsView);
}
//*********************************************************************************

//*********************************************************************************
MainWindow::~MainWindow()
{
    delete ui;
}
//*********************************************************************************
