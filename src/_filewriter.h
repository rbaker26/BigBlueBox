#ifndef _FILEWRITER_H
#define _FILEWRITER_H

#include <QFile>
#include <QTextStream>

#include <QVector>
#include <QStringList>

#include "item.h"

class _FileWriter
{
private:
    _FileWriter();
    static _FileWriter* instance;
public:
    //_FileWriter();
    ~_FileWriter();
    static _FileWriter* getInstance();

     void makeReport(QVector<Item> inventory);
};

#endif // _FILEWRITER_H
