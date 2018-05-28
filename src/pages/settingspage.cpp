#include "settingspage.h"
#include "ui_settingspage.h"
//*********************************************************************************
SettingsPage::SettingsPage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SettingsPage)
{
    ui->setupUi(this);

    initPaths();
}
//*********************************************************************************


//*********************************************************************************
SettingsPage::~SettingsPage()
{
    delete ui;
}
//*********************************************************************************




//*********************************************************************************
void SettingsPage::initPaths()
{
    QString dbPath = bbb::_FileReader::readDbFileLoc();
    ui->lineEdit_dbFile->setText(dbPath);

    QString reportPath = bbb::_FileReader::readReportsDir();
    ui->lineEdit_reportsDir->setText(reportPath);

}
//*********************************************************************************




//*********************************************************************************
void SettingsPage::on_toolButton_fileBrowse_clicked()
{
    // todo - get default file loc form class and put it as default path in QFileDialog param

    QString orgFileName = ui->lineEdit_dbFile->text();
    QString fileName = QFileDialog::getOpenFileName(this,  tr("Open Database"), "C:", tr("SQLite database files (*.db *.sqlite *.sqlite3 *.db3)") );

    if(fileName.length() > 0 && orgFileName != fileName)
    {
        ui->lineEdit_dbFile->setText(fileName);
        ui->pushButton_saveDbDir->setEnabled(true);
    }


}
//*********************************************************************************




//*********************************************************************************
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
//*********************************************************************************





//*********************************************************************************
void SettingsPage::on_pushButton_saveDbDir_clicked()
{
    bbb::_FileWriter::writeDbFileLoc(ui->lineEdit_dbFile->text());
    ui->pushButton_saveDbDir->setEnabled(false);

    QMessageBox msgBox;
    msgBox.setText("App Restart Needed\n"
                   "Until the app is restarted, no changes will take place.\n");
    msgBox.setInformativeText("Please Restart App.");
    msgBox.setStandardButtons(QMessageBox::Ok);
    msgBox.setDefaultButton(QMessageBox::Ok);
    msgBox.exec();

    bbb::DbConnect::getInstance()->sysLog("SYSTEM:\tDB_PATH_CHANGED->" +
                                          ui->lineEdit_dbFile->text());

}
//*********************************************************************************




//*********************************************************************************
void SettingsPage::on_pushButton_saveReportDir_clicked()
{
    ui->lineEdit_reportsDir->setFocus();
    bbb::_FileWriter::writeReportsDir(ui->lineEdit_reportsDir->text());
    ui->pushButton_saveReportDir->setEnabled(false);

    bbb::DbConnect::getInstance()->sysLog("SYSTEM:\tREPORT_DIR_CHANGED->" +
                                          ui->lineEdit_reportsDir->text());
}
//*********************************************************************************
