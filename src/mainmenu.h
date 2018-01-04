#ifndef MAINMENU_H
#define MAINMENU_H

#include <QWidget>
#include "reportsView.h"

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

private:
    Ui::MainMenu *ui;
};

#endif // MAINMENU_H
