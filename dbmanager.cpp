#include "dbmanager.h"

/*****************************************************************************/
DbManager::DbManager(const QString& path)
{
   bbb_db = QSqlDatabase::addDatabase("QSQLITE");
   bbb_db.setDatabaseName(path);

   if (!bbb_db.open())
   {
      qDebug() << "Error: connection with database fail";
   }
   else
   {
      qDebug() << "Database: connection ok";
   }
}

/*****************************************************************************/
void DbManager::addGearItem(const QString& gearDescription,
                            const int gearCatID,
                            const int gearIdvID,
                            const bool hasParts,
                            //const QVector <int>& partsFromInventory,
                            const HealthStatus& healthStatus,
                            Date& obsolescenceDate)
{
     qDebug() << "Database is open?:\t" << bbb_db.isOpen();
    // check args
    QSqlQuery query;
    query.prepare("INSERT INTO gear (gear_discription, gear_cat_id, gear_idv_id, has_parts, health_status, obsol_date) "
                  "VALUES (:gearDescription, :gear_cat_id, :gear_idv_id, :has_parts, :health_status, :obsolDate)");



    query.bindValue(":gearDescription", gearDescription);
    query.bindValue(":gear_cat_id", gearCatID);
    query.bindValue(":gear_idv_id", gearIdvID);
    query.bindValue(":has_parts", hasParts);
    query.bindValue(":health_status", healthStatus);
    query.bindValue(":obsolDate", obsolescenceDate.getDateString());
    //query.bindValue(":obsol_date", obsolescenceDate);
    qDebug() << "query.bindValue .lastError():\t" << query.lastError();

    query.exec();

    qDebug() << "query.exec() .lastError():\t" << query.lastError();
    //qDebug() << query5.exec();
    //query6.exec();


}

/*****************************************************************************/
void DbManager::addGearPartsToDB(const QString& gearDescription,
                                 const QVector<int>& partsFromInventory)
{

    QSqlQuery query;

    switch (partsFromInventory.length()) {
    case 5:
        query.prepare("INSERT INTO gearParts (gear_discription, part_1, part_2, part_3, part_4, part_5) "
                      "VALUES (:gearDescription, :part1, :part2, :part3, :part4, :part5");
        query.bindValue(":gearDescription", gearDescription);
        query.bindValue(":part_1", partsFromInventory[0]);
        query.bindValue(":part_2", partsFromInventory[1]);
        query.bindValue(":part_3", partsFromInventory[2]);
        query.bindValue(":part_4", partsFromInventory[3]);
        query.bindValue(":part_5", partsFromInventory[4]);
        query.exec();
        break;
    case 4:
        query.prepare("INSERT INTO gearParts (gear_discription, part_1, part_2, part_3, part_4) "
                      "VALUES (:gearDescription, :part1, :part2, :part3, :part4");
        query.bindValue(":gearDescription", gearDescription);
        query.bindValue(":part_1", partsFromInventory[0]);
        query.bindValue(":part_2", partsFromInventory[1]);
        query.bindValue(":part_3", partsFromInventory[2]);
        query.bindValue(":part_4", partsFromInventory[3]);
        query.exec();
        break;
    case 3:
        query.prepare("INSERT INTO gearParts (gear_discription, part_1, part_2, part_3) "
                      "VALUES (:gearDescription, :part1, :part2, :part3");
        query.bindValue(":gearDescription", gearDescription);
        query.bindValue(":part_1", partsFromInventory[0]);
        query.bindValue(":part_2", partsFromInventory[1]);
        query.bindValue(":part_3", partsFromInventory[2]);
        query.exec();
        break;
    case 2:
        query.prepare("INSERT INTO gearParts (gear_discription, part_1, part_2) "
                      "VALUES (:gearDescription, :part1, :part2");
        query.bindValue(":gearDescription", gearDescription);
        query.bindValue(":part_1", partsFromInventory[0]);
        query.bindValue(":part_2", partsFromInventory[1]);
        query.exec();
        break;
    case 1:
        query.prepare("INSERT INTO gearParts (gear_discription, part_1) "
                      "VALUES (:gearDescription, :part1");
        query.bindValue(":gearDescription", gearDescription);
        query.bindValue(":part_1", partsFromInventory[0]);
        query.exec();
        break;
    default:
        return;
        break;
    }
}
/*****************************************************************************/
