#ifndef DBMANAGER_H
#define DBMANAGER_H
#include <QString>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QDebug>
#include <QSqlError>
#include "Gear.h"


class DbManager
{
private:
    QSqlDatabase bbb_db;

    void addGearPartsToDB(const QString& gearDescription,
                          const QVector<int>& partsFromInventory);
public:
    DbManager(const QString& path);

    void addGearItem(const QString& gearDescription,
                     const int gearCatID,
                     const int gearIdvID,
                     const bool hasParts,
                     //const QVector<int>& partsFromInventory,
                     const HealthStatus& healthStatus,
                     Date& obsolescenceDate);


};

#endif // DBMANAGER_H
