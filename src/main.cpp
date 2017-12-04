#include "mainwindow.h"
#include <QApplication>


// test header
// remove after test
#include "item.h"
#include "dbconnect.h"
#include "QDebug"
#include <QVector>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();





   return a.exec();
}
