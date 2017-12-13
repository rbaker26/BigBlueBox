#include "gearcentral.h"
#include "ui_gearcentral.h"

GearCentral::GearCentral(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GearCentral)
{
    ui->setupUi(this);
}

GearCentral::~GearCentral()
{
    delete ui;
}
