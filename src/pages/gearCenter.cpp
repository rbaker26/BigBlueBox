#include "gearCenter.h"
#include "ui_gearCenter.h"

GearCenter::GearCenter(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GearCenter)
{
    ui->setupUi(this);
}

GearCenter::~GearCenter()
{
    delete ui;
}

void GearCenter::on_pushButton_checkInOut_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}
