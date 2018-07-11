//********************************************************************
// MARK FOR DELETE - OBSOLETE
//********************************************************************
#ifndef JSONREADER_H
#define JSONREADER_H
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>

#include <QFile>
#include <QString>

#include "directoryhandler.h"

class JSONReader
{
private:
    static QFile file;
    static QString path;
public:
    JSONReader();
    ~JSONReader();
    void setFilePath(QString path);
    QString readJSON();

};

#endif // JSONREADER_H
