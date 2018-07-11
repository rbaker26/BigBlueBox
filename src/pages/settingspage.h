#ifndef SETTINGSPAGE_H
#define SETTINGSPAGE_H

#include <QWidget>
#include <QFileDialog>
#include <QFile>
#include <QMessageBox>

#include "_filereader.h"  // will be replaced by the settings json class
#include "_filewriter.h"  //
#include "dbconnect.h"

#include "_settings.h"

namespace Ui {
class SettingsPage;
}

class SettingsPage : public QWidget
{
    Q_OBJECT
public:
    explicit SettingsPage(QWidget *parent = 0);
    ~SettingsPage();

    void toggleDbSettings(bool toggle);

private:
    void initPaths();

private slots:
    void on_toolButton_fileBrowse_clicked();

    void on_toolButton_reportsLoc_clicked();

    void on_pushButton_saveDbDir_clicked();

    void on_pushButton_saveReportDir_clicked();

    void on_comboBox_databaseLoc_currentIndexChanged(const QString &arg1);


    void on_comboBox_databaseType_currentIndexChanged(int index);

private:
    Ui::SettingsPage *ui;
};

#endif // SETTINGSPAGE_H
