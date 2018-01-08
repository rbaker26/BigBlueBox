#ifndef DIRECTORYHANDLER_H
#define DIRECTORYHANDLER_H

#include <QDir>
#include <QFile>;
#include <QString>

#include <QStandardPaths>

#include <QXmlStreamReader>
#include <QXmlStreamReader>

namespace bbb {
class DirectoryHandler
{
private:
    DirectoryHandler();
public:
    ~DirectoryHandler();

    enum CommonDirs
    {
        DESKTOP,
        PROGRAM_FILES,
        PROGRAM_FILES_X86
    };

    static QString getDefaultPaths(CommonDirs dir);

    static void setDefaultReportPath(QString path);

    static QString getDefaultReportPath();



}; // end class

} // end namespace bbb
#endif // DIRECTORYHANDLER_H
