#ifndef _SETTINGS_H
#define _SETTINGS_H

#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonValuePtr>

#include <QCoreApplication>

#include <directoryhandler.h>

namespace bbb {
class _Settings
{
private:
     QString jsonPath;
     QString tempAppName;

     QJsonDocument readFile(QString path);


public:
    _Settings();
    ~_Settings();

    void appNamePassThough(QString name);

    //**********************************************
    // Application Settings
    //**********************************************
     void restoreDefaults();

     QString getAppColorTheme();
    static void setAppColorTheme(QString theme);

    //**********************************************


    //**********************************************
    // Database Settings
    //**********************************************
    static QString getDbType();
    static void setDbType(QString type);

    static QString getDbLoc();
    static void setDbLoc(QString location);

    static QString getDbPath();
    static void setDbPath(QString path);

    static QString getDbIPAddress();
    static void setDbIPAddress(QString addr);

    static QString getDbPort();
    static void setDbPort(QString port);

    static QString getDbUserName();
    static void setDbUserName(QString username);

    static QString getDbPW();
    static void setDbPW(QString pw);
    //**********************************************


};
}

#endif // _SETTINGS_H
