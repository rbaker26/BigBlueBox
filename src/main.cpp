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

//*********************************************************************************
// test header
// remove after testing
#include "item.h"
#include "dbconnect.h"
#include "QDebug"
#include <QVector>
#include "_filewriter.h"
//*********************************************************************************

//*********************************************************************************
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setWindowIcon(QIcon(":/img/nyltIcon.png"));
    a.setApplicationName("BigBlueBox v0.3.0");
    MainWindow w;
    w.setWindowTitle("BigBlueBox v0.3.0");
    w.show();

   bbb::Item myItem;
   myItem.itemName = "test";
   myItem.quantity = 55;
   myItem.effectiveOnHand = 100;
   myItem.canExpire = false;
   myItem.category = bbb::Category::KITCHEN;
   myItem.boxNum = 16;
   myItem.dateModified = QDateTime::currentDateTime();

   bbb::DbConnect::getInstance()->addNewItem(myItem);
   return a.exec();
}
//*********************************************************************************
