#ifndef DBCONNECT_H
#define DBCONNECT_H

#include <QString>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QDebug>
#include <QSqlError>
#include <QSqlRecord>
//#include "Gear.h"
#include "item.h"

#include <QVector>
#include <algorithm>

class DbConnect
{
private:
    QSqlDatabase bbb_db;
    static DbConnect* instance;

    DbConnect();

public:
    static DbConnect* getInstance();

    QVector<Item> getFullInvAsVector();
};

#endif // DBCONNECT_H
