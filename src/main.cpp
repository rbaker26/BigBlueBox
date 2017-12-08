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
    a.setWindowIcon(QIcon(":/img/nyltIcon.png"));
    a.setApplicationName("BigBlueBox v1.1");
    MainWindow w;
    w.setWindowTitle("BigBlueBox v1.1");
    w.show();




   return a.exec();
}
