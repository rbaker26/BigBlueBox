#ifndef SETTINGSPAGE_H
#define SETTINGSPAGE_H

#include <QWidget>
#include <QFileDialog>
#include <QFile>
#include <QMessageBox>

#include "_filereader.h"
#include "_filewriter.h"


namespace Ui {
class SettingsPage;
}

class SettingsPage : public QWidget
{
    Q_OBJECT

public:
    explicit SettingsPage(QWidget *parent = 0);
    ~SettingsPage();

private:
    void initPaths();

private slots:
    void on_toolButton_fileBrowse_clicked();

    void on_toolButton_reportsLoc_clicked();

    void on_pushButton_saveDbDir_clicked();

    void on_pushButton_saveReportDir_clicked();

private:
    Ui::SettingsPage *ui;
};

#endif // SETTINGSPAGE_H
