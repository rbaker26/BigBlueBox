#ifndef MAINMENU_H
#define MAINMENU_H

#include <QWidget>
#include "reportsView.h"
#include "pages/settingspage.h"
#include "pages/gearCenter.h"
#include "pages/gearCenter.h"

namespace Ui {
class MainMenu;
}

class MainMenu : public QWidget
{
    Q_OBJECT

public:
    explicit MainMenu(QWidget *parent = 0);
    ~MainMenu();

private slots:
    void on_pushButton_gotoInv_clicked();

    void on_pushButton_gotoSettings_clicked();

    void on_pushButton_gotoGear_clicked();

private:
    Ui::MainMenu *ui;
};

#endif // MAINMENU_H
