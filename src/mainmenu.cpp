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

void MainMenu::on_pushButton_gotoSettings_clicked()
{
    QWidget* settingsPage = new SettingsPage(this);
    ui->horizontalStackedWidget->addWidget(settingsPage);
    ui->horizontalStackedWidget->setCurrentWidget(settingsPage);
}

void MainMenu::on_pushButton_gotoGear_clicked()
{
    QWidget* gearPage = new GearCenter(this);
    ui->horizontalStackedWidget->addWidget(gearPage);
    ui->horizontalStackedWidget->setCurrentWidget(gearPage);
}
