#include "gearManager.h"
#include "ui_gearManager.h"

GearManager::GearManager(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GearManager)
{
    ui->setupUi(this);
}

GearManager::~GearManager()
{
    delete ui;
}
