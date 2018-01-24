#include "_filereader.h"
using namespace bbb;


_FileReader::_FileReader()
{

}


QString _FileReader::readDbFileLoc()
{
    QFile dbFile("C:/Users/007ds/Documents/GitHub/BigBlueBox/rec/db_path.data");  // todo correct to proper final path

    dbFile.open(QIODevice::ReadOnly | QIODevice::Text);

    QTextStream ofs(&dbFile);

    QString path;
    path = ofs.readLine(128);

    dbFile.close();

    return path;

}


QString _FileReader::readReportsDir()
{
    QFile reportFile("C:/Users/007ds/Documents/GitHub/BigBlueBox/rec/report_dir.data");  // todo correct to proper final path
    reportFile.open(QIODevice::ReadOnly | QIODevice::Text);

    QTextStream ofs(&reportFile);

    QString path;
    path = ofs.readLine(128);

    reportFile.close();

    return path;
}
