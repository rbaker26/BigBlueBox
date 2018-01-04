#include "mainmenu.h"
#include "ui_mainmenu.h"

MainMenu::MainMenu(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainMenu)
{
    ui->setupUi(this);
}

MainMenu::~MainMenu()
{
    delete ui;
}

void MainMenu::on_pushButton_gotoInv_clicked()
{
    QWidget * inventoryPage = new ReportsView(this);
    ui->horizontalStackedWidget->addWidget(inventoryPage);
    ui->horizontalStackedWidget->setCurrentWidget(inventoryPage);
}
