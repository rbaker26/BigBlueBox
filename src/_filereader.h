#ifndef _FILEREADER_H
#define _FILEREADER_H

#include <QString>
#include <QFile>
#include <QTextStream>
#include <QDir>

#include "directoryhandler.h"

namespace bbb {
class _FileReader
{
public:
    _FileReader();

    static QString readDbFileLoc();
    static QString readReportsDir();


};
}
#endif // _FILEREADER_H
