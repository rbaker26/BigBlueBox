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
#include "_settings.h"
#include "DarkStyle.h"
#include "framelesswindow/framelesswindow.h"
//#############################################################################################

int main(int argc, char *argv[])
{
     const QString APP_NAME = "BigBlueBox v0.4.0";

    QApplication a(argc, argv);
    a.setWindowIcon(QIcon(":/img/nyltIcon.png"));
    a.setApplicationName(APP_NAME);


    // Make both windows and hide them
    MainWindow w;
    FramelessWindow framelessWindow;
    w.hide();
    framelessWindow.hide();

    // Get Light/Dark theme settings from JSON file
    bbb::_Settings set;
    QString theme = set.getAppColorTheme();

    //*************************************************************
    // Light Mode                                                 *
    //*************************************************************
    if(theme == "light")
    {
        framelessWindow.close(); // Close other window
        w.setWindowTitle(APP_NAME);
        w.show();
    }
    //*************************************************************
    // Dark Mode                                                  *
    //*************************************************************
    else if(theme == "dark")
    {
        w.close(); // Close other window

        a.setStyle(new DarkStyle);
        framelessWindow.setWindowTitle(APP_NAME);
        framelessWindow.setWindowState(Qt::WindowMaximized);

        MainWindow *mainWindow = new MainWindow;
        framelessWindow.setContent(mainWindow);
        framelessWindow.show();
    }
    //*************************************************************
    return a.exec();
}

//#############################################################################################
//#############################################################################################

