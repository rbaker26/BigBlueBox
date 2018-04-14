//*********************************************************************************************
//   ______  _          ______  _                 ______                                      *
//  (____  \(_)        (____  \| |               (____  \                                     *
//   ____)  )_  ____    ____)  ) | _   _ _____    ____)  ) ___ _   _                          *
//  |  __  (| |/ _  |  |  __  (| || | | | ___ |  |  __  ( / _ ( \ / )                         *
//  | |__)  ) ( (_| |  | |__)  ) || |_| | ____|  | |__)  ) |_| ) X (                          *
//  |______/|_|\___ |  |______/ \_)____/|_____)  |______/ \___(_/ \_)                         *
//            (_____|                                                                         *
//*********************************************************************************************


//#############################################################################################
//########################################## WARNING ##########################################
//                               Do not add extra lines to main.
//                           This file should only be used to create
//                              the QApplication and MainWindow.
//#############################################################################################

//#############################################################################################
#include "mainwindow.h"
#include <QApplication>
//#############################################################################################

// test code
#include <QVector>

//#############################################################################################
int main(int argc, char *argv[])
{
    //qDebug() << "Checked in\t" << isCheckedOut;

   qDebug() <<  QrInterface::strToSvg("pid:abc:de0123");



    QApplication a(argc, argv);
    a.setWindowIcon(QIcon(":/img/nyltIcon.png"));
    a.setApplicationName("BigBlueBox v0.4.0");
    MainWindow w;
    w.setWindowTitle("BigBlueBox v0.4.0");
    w.show();

   return a.exec();
}

//#############################################################################################
//#############################################################################################

