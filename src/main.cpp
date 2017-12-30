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
// remove after test
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
    a.setApplicationName("BigBlueBox v1.1");
    MainWindow w;
    w.setWindowTitle("BigBlueBox v1.1");
    w.show();


//    _FileWriter* fw = _FileWriter::getInstance();
//    fw->makeReport(DbConnect::getInstance()->getFullInvAsVector());

//    bbb::_FileWriter::getInstance()->makeTxtInvReport(bbb::DbConnect::getInstance()->getFullInvAsVector());
//    bbb::_FileWriter::getInstance()->makeTxtInvReport(bbb::DbConnect::getInstance()->getFullInvAsVector(), bbb::_FileWriter::ReportType::Low);
//    bbb::_FileWriter::getInstance()->makeTxtInvReport(bbb::DbConnect::getInstance()->getFullInvAsVector(), bbb::_FileWriter::ReportType::Critical);
//    bbb::_FileWriter::getInstance()->makeTxtInvReport(bbb::DbConnect::getInstance()->getFullInvAsVector(), bbb::_FileWriter::ReportType::Full);


//    bbb::_FileWriter::getInstance()->makeXmlInvReport(bbb::DbConnect::getInstance()->getFullInvAsVector());
//    bbb::_FileWriter::getInstance()->makeXmlInvReport(bbb::DbConnect::getInstance()->getFullInvAsVector(), bbb::_FileWriter::ReportType::Low);
//    bbb::_FileWriter::getInstance()->makeXmlInvReport(bbb::DbConnect::getInstance()->getFullInvAsVector(), bbb::_FileWriter::ReportType::Critical);
//    bbb::_FileWriter::getInstance()->makeXmlInvReport(bbb::DbConnect::getInstance()->getFullInvAsVector(), bbb::_FileWriter::ReportType::DbDump);

   return a.exec();
}
//*********************************************************************************
