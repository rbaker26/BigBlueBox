#include "directoryhandler.h"
using namespace bbb;

DirectoryHandler::DirectoryHandler()
{

}

QString DirectoryHandler::getDefaultPaths(CommonDirs dir)
{
    QString path = "";
    switch (dir)
    {
    case DESKTOP :
        path = QStandardPaths::locate(QStandardPaths::DesktopLocation,
                                      "",
                                      QStandardPaths::LocateDirectory);
        break;
    case PROGRAM_FILES :
        path = "C:/Program Files";
        break;
    case PROGRAM_FILES_X86 :
        path = "C:/Program Files (x86)";
        break;
    default:
        path = "C:";
    }

    return path;
}

void DirectoryHandler::setDefaultReportPath(QString path)
{
    // use xml;
}

QString DirectoryHandler::getAndCheckRoamingPath()
{
    QString filePath = QStandardPaths::writableLocation(QStandardPaths::AppDataLocation);
    //QStandardPaths::writableLocation(QStandardPaths::App)
    QDir dir(filePath);
    if(!dir.exists())
    {
        dir.mkpath(filePath);
    }

    return filePath;
}

