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

void GearCenter::on_pushButton_checkinOut_clicked()
{
//    QrInterface qri;

//    QString s = qri.testsss();

//    QFile file("C:/test.svg");
//    file.open(QIODevice::WriteOnly | QIODevice::Text);
//    QTextStream ofs(&file);
//    ofs << s;
//    file.close();


    ui->widget->load(QString("./test.svg"));
}
