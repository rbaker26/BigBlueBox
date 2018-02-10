//*********************************************************************************
//   ______  _          ______  _                 ______                          *
//  (____  \(_)        (____  \| |               (____  \                         *
//   ____)  )_  ____    ____)  ) | _   _ _____    ____)  ) ___ _   _              *
//  |  __  (| |/ _  |  |  __  (| || | | | ___ |  |  __  ( / _ ( \ / )             *
//  | |__)  ) ( (_| |  | |__)  ) || |_| | ____|  | |__)  ) |_| ) X (              *
//  |______/|_|\___ |  |______/ \_)____/|_____)  |______/ \___(_/ \_)             *
//            (_____|                                                             *
//*********************************************************************************

//*********************************************************************************
#include "mainwindow.h"
#include <QApplication>


// for testing
#include <QString>
#include <QFile>
#include "qr/QrInterface.h"
//*********************************************************************************
int main(int argc, char *argv[])
{
    QrInterface qri;

    QString s = qri.testsss();

    QFile file("test.svg");
    file.open(QIODevice::WriteOnly | QIODevice::Text);
    QTextStream ofs(&file);
    ofs << s;
    file.close();

    QApplication a(argc, argv);
    a.setWindowIcon(QIcon(":/img/nyltIcon.png"));
    a.setApplicationName("BigBlueBox v0.4.0");
    MainWindow w;
    w.setWindowTitle("BigBlueBox v0.4.0");
    w.show();

   return a.exec();
}
//*********************************************************************************
