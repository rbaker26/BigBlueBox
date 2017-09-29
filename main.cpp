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




    return a.exec();
}
