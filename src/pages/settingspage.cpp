#include "settingspage.h"
#include "ui_settingspage.h"

SettingsPage::SettingsPage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SettingsPage)
{
    ui->setupUi(this);
}

SettingsPage::~SettingsPage()
{
    delete ui;
}

void SettingsPage::on_toolButton_fileBrowse_clicked()
{
    // todo - get default file loc form class and put it as default path in QFileDialog param

    QString orgFileName = ui->lineEdit_dbFile->text();
    QString fileName = QFileDialog::getOpenFileName(this,  tr("Open Database"), "C:", tr("DB File (*.db)") );

    if(fileName.length() > 0 && orgFileName != fileName)
    {
        ui->lineEdit_dbFile->setText(fileName);
        ui->pushButton_saveDbDir->setEnabled(true);
    }


}

void SettingsPage::on_toolButton_reportsLoc_clicked()
{
    // todo - get defualt loc from class and put it as default path in QFileDialog param

    QString orgFileName = ui->lineEdit_reportsDir->text();
    QString dir = QFileDialog::getExistingDirectory(this, tr("Choose Directory for Writing Reports"), "C:", QFileDialog::ShowDirsOnly);

    if(dir.length() > 0 && orgFileName != dir)
    {
        ui->lineEdit_reportsDir->setText(dir);
        ui->pushButton_saveReportDir->setEnabled(true);
    }

}
