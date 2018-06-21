#include "_filereader.h"
using namespace bbb;


_FileReader::_FileReader()
{

}


QString _FileReader::readDbFileLoc()
{
    QString dirpath = bbb::DirectoryHandler::getAndCheckRoamingPath();
    QDir dir(dirpath +  "/rec/");
    if(!dir.exists())
    {
        dir.mkpath(dirpath +  "/rec/");
    }

    QFile dbFile(dirpath + "/rec/db_path.data");

    dbFile.open(QIODevice::ReadOnly | QIODevice::Text);

    QTextStream ofs(&dbFile);

    QString path;
    path = ofs.readLine(128);

    dbFile.close();


    return path;

}


QString _FileReader::readReportsDir()
{
    QString dirpath = bbb::DirectoryHandler::getAndCheckRoamingPath();
    QDir dir(dirpath +  "/rec/");
    if(!dir.exists())
    {
        dir.mkpath(dirpath +  "/rec/");
    }


    QFile reportFile(dirpath + "/rec/report_dir.data");
    reportFile.open(QIODevice::ReadOnly | QIODevice::Text);

    QTextStream ofs(&reportFile);

    QString path;
    path = ofs.readLine(128);

    reportFile.close();

    return path;
}
