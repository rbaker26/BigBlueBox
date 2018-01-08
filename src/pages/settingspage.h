#ifndef SETTINGSPAGE_H
#define SETTINGSPAGE_H

#include <QWidget>
#include <QFileDialog>

namespace Ui {
class SettingsPage;
}

class SettingsPage : public QWidget
{
    Q_OBJECT

public:
    explicit SettingsPage(QWidget *parent = 0);
    ~SettingsPage();

private slots:
    void on_toolButton_fileBrowse_clicked();

    void on_toolButton_reportsLoc_clicked();

private:
    Ui::SettingsPage *ui;
};

#endif // SETTINGSPAGE_H
