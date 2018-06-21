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
#include "DarkStyle.h"
#include "framelesswindow/framelesswindow.h"
//#############################################################################################

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setWindowIcon(QIcon(":/img/nyltIcon.png"));
    a.setApplicationName("BigBlueBox v0.4.0");
    a.setStyle(new DarkStyle);

    FramelessWindow framelessWindow;
    framelessWindow.setWindowTitle("BigBlueBox v0.4.0");
    framelessWindow.setWindowState(Qt::WindowMaximized);

    MainWindow *mainWindow = new MainWindow;
   // w.setWindowTitle("BigBlueBox v0.4.0");
   // w.show();

    framelessWindow.setContent(mainWindow);
    framelessWindow.show();

   return a.exec();
}

//#############################################################################################
//#############################################################################################

