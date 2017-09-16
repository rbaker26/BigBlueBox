#include "mainwindow.h"
#include <QApplication>

//delete these after testing
#include "gear.h"
#include "gearholder.h"
#include "dbmanager.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    Date date(2017,10,22);
    DbManager dbtest("C:/Users/007ds/Documents/qT/BigBlueBox/BigBlueBox.db");
    dbtest.addGearItem("item", 5, 6, true, OK, date);


    return a.exec();
}
