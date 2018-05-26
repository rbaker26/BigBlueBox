#include "dbconnect.h"
using namespace bbb;
//*********************************************************************************
DbConnect* DbConnect::instance = nullptr;
//*********************************************************************************

//*********************************************************************************
DbConnect::DbConnect()
{
    bbb_db = QSqlDatabase::addDatabase("QSQLITE");

    QString dbPath = bbb::_FileReader::readDbFileLoc();
    bbb_db.setDatabaseName(dbPath);

    if(!bbb_db.open())
    {
        qDebug() << "DB not open:\n" << bbb_db.lastError().text();
    }
    else
    {
        qDebug() << "Db Open\n";
    }
}
//*********************************************************************************


//*********************************************************************************
DbConnect::~DbConnect()
{
    bbb_db.close();

    delete instance;
    qDebug() << "Db Closed";
}
//*********************************************************************************


//*********************************************************************************
DbConnect* DbConnect::getInstance()
{
    if(instance == nullptr)
    {
        instance = new DbConnect();
    }
    return instance;
}
//*********************************************************************************

//*********************************************************************************
 QVector<Item> DbConnect::getFullInvAsVector()
 {
    QVector<Item> returnVector;
    Item tempItem;

    QSqlQuery query;
    query.prepare("Select * FROM inventory  ORDER BY cat ASC, item_name ASC");

    if(!query.exec())
    {
        qDebug() << query.lastError().text();
    }

    int itemNameFieldNum  = query.record().indexOf("item_name");
    int quantityFieldNum  = query.record().indexOf("quantity");
    int efOnHandFieldNum  = query.record().indexOf("target_quantity");
    int categoryFieldNum  = query.record().indexOf("cat");
    int boxNumFieldNum    = query.record().indexOf("box_num");
    int canExpFieldNum    = query.record().indexOf("can_expire");


    query.first();
    do
    {
        tempItem.itemName        = query.value(itemNameFieldNum).toString();
        tempItem.quantity        = query.value(quantityFieldNum).toInt();
        tempItem.effectiveOnHand = query.value(efOnHandFieldNum).toInt();
        tempItem.category        = static_cast<Category::categoryType>(query.value(categoryFieldNum).toInt());
        tempItem.boxStr          = query.value(boxNumFieldNum).toString();
        tempItem.canExpire       = query.value(canExpFieldNum).toBool();
//**************************************************************
//*                       * Test Code *                        *
//**************************************************************
//        qDebug() << "Name:\t" << tempItem.itemName;
//        qDebug() << "Quantity:\t" << tempItem.quantity;
//        qDebug() << "EOH:\t" << tempItem.effectiveOnHand;
//        qDebug() << "Cat:\t"<< tempItem.category;
//        qDebug() << "Box#:\t" << tempItem.boxNum << "\n\n";
//**************************************************************

        returnVector.push_back(tempItem);
    }while(query.next());

    // for reg vector
    //returnVector.shrink_to_fit();
    returnVector.squeeze();
    return returnVector;

 }
//*********************************************************************************
void DbConnect::updateItem(QString orgName, Row newRowInfo)
{
    QSqlQuery query;
    query.prepare("UPDATE inventory "
                  "SET item_name       = (:item_name_new), "
                      "quantity        = (:quantity), "
                      "target_quantity = (:target_quantity), "
                      "cat             = (:cat), "
                      "can_expire      = (:can_expire), "
                      "box_num         = (:box_num), "
                      "date_modified   = (:date_modified) "
                  "WHERE item_name = (:item_name_org)");

    query.bindValue(":item_name_org", orgName);

    query.bindValue(":quantity",        newRowInfo.quantity);
    query.bindValue(":target_quantity", newRowInfo.effectiveOnHand);
    query.bindValue(":cat",             static_cast<int>(newRowInfo.category));
    query.bindValue(":can_expire",      static_cast<int>(newRowInfo.canExpire));
    qDebug() << newRowInfo.canExpire;
    query.bindValue(":box_num",         newRowInfo.boxStr);  // this should be boxStr, not boxNum.  Boxnum is obsol.
    query.bindValue(":date_modified",   newRowInfo.dateModified.toString(dateFormat));

    query.bindValue(":item_name_new",   newRowInfo.itemName);


    if(!query.exec())
    {
        qDebug() << "Exec err:\t" << query.lastError().text();
    }
}
//*********************************************************************************

//*********************************************************************************
void DbConnect::addNewItem(Item newItem)
{
    QSqlQuery query;
    query.prepare("INSERT INTO inventory (item_name, quantity, target_quantity, "
                                         "cat, can_expire, box_num, date_modified) "
                  "VALUES (:item_name, :quantity, :target_quantity, "
                          ":cat, :can_expire, :box_num, :date_modified)");

    query.bindValue(":item_name", newItem.itemName);
    query.bindValue(":quantity", newItem.quantity);
    query.bindValue(":target_quantity", newItem.effectiveOnHand);
    query.bindValue(":cat", static_cast<int>(newItem.category) );
    query.bindValue(":can_expire", newItem.canExpire);
    query.bindValue(":box_num", newItem.boxStr);
    query.bindValue(":date_modified", newItem.dateModified.toString(dateFormat));

    if(!query.exec())
    {
        qDebug() << query.lastError().text();
    }

}
//*********************************************************************************

//*********************************************************************************
void DbConnect::deleteItem(QString name)
{
    QSqlQuery query;
    query.prepare("DELETE FROM inventory WHERE item_name = (:item_name)");
    query.bindValue(":item_name", name);

    if(!query.exec())
    {
        qDebug() << query.lastError().text();
    }
}
//*********************************************************************************

//*********************************************************************************
bool DbConnect::itemAlreadyExists(QString name)
{
    // This function will query the db for one row that matches item_name.
    // It will then return false if it already exists and true if it does
    //  not exist.
    bool alreadyExists;
    QSqlQuery query;

    query.prepare("SELECT CASE WHEN EXISTS (        "
                  "  SELECT *                       "
                  "  FROM inventory                 "
                  "  WHERE item_name = (:item_name) "
                  "  LIMIT 1                        "
                  ")                                "
                  "THEN CAST(1 AS BIT)              "
                  "ELSE CAST(0 AS BIT) END          " );

    query.bindValue(":item_name", name);
    alreadyExists = query.exec();

    query.first();
    alreadyExists = query.value(0).toBool();


    return alreadyExists;
}
//*********************************************************************************


//*********************************************************************************
QVector<GearNote> DbConnect::getGearNotes(int catId, int idvId)
{
    QVector<GearNote> returnVector;
    GearNote tempNote;

    QSqlQuery query;

    // This query doesn't really need the join, it is just here in case
    //  I want to expand its functionality.
    // It just allows the connection of the gear_name.
    // It also adds the possiblity of adding Heath_status to the notes
    //  reports.
    // I plan on making a xml/txt report genrator like I did with the
    //  inventory page.
    // For this, I will need to print out the name of the item as well
    //  as some stats.  I will try to reuse this query / function.

//    query.prepare("SELECT gear_list.gear_name,                          "
//                  "       gear_notes.note, gear_notes.author,           "
//                  "       gear_notes.time_stamp                         "
//                  "FROM gear_list LEFT JOIN gear_notes                  "
//                  "WHERE gear_list.gear_cat_id = gear_notes.gear_cat_id "
//                  "      AND                                            "
//                  "      gear_list.gear_idv_id = gear_notes.gear_idv_id "
//                  "      AND                                            "
//                  "      gear_list.gear_cat_id = (:catId)               "
//                  "      AND                                            "
//                  "      gear_list.gear_idv_id = (:idvId);              ");


    query.prepare("SELECT                           "
                  "       note, author,             "
                  "       time_stamp                "
                  "FROM  gear_notes                 "
                  "WHERE                            "
                  "                                 "
                  "      gear_cat_id = (:catId)     "
                  "      AND                        "
                  "      gear_idv_id = (:idvId)     ");

    query.bindValue(":catId", catId);
    query.bindValue(":idvId", idvId);

    if(!query.exec())
    {
        qDebug() << query.lastError().text();
    }

    int noteFieldNum      = query.record().indexOf("note");
    int authorFieldNum    = query.record().indexOf("author");
    int timeStampFieldNUm = query.record().indexOf("time_stamp");

    query.first();
    do
    {
        tempNote.noteText        = query.value(noteFieldNum).toString();
        tempNote.author          = query.value(authorFieldNum).toString();
        tempNote.dtMade          = QDateTime::fromString( query.value(timeStampFieldNUm).toString(), dateFormat);

    //***********************************2***************************
    //*                       * Test Code *                        *
    //**************************************************************
    //        qDebug() << "Note:\t" << tempNote.noteText;
    //        qDebug() << "Author:\t" << tempNote.author;
    //        qDebug() << "dtMade:\t" << tempNote.dtMade.toString(dateFormat);
    //**************************************************************

        returnVector.push_back(tempNote);
    }while(query.next());

    returnVector.squeeze();
    return returnVector;

}
//*********************************************************************************



//*********************************************************************************
Gear DbConnect::getGearInfo(int catId, int idvId)
{
    Gear temp;

    QSqlQuery query;
    query.prepare("SELECT *                      "
                  "FROM gear_list                "
                  "WHERE                         "
                  "   gear_cat_id = (:catId)     "
                  "   AND                        "
                  "   gear_idv_id = (:idvId)     "
                  "LIMIT 1;                      ");

    query.bindValue(":catId", catId);
    query.bindValue(":idvId", idvId);

    if(!query.exec())
    {
        qDebug() << query.lastError().text();
    }

    int nameFieldNum   = query.record().indexOf("gear_name");
    int dateFieldNum   = query.record().indexOf("obsol_date");
    int healthFieldNum = query.record().indexOf("health_status");

    query.first();
    temp.gearName   = query.value(nameFieldNum).toString();
    temp.obsolDate  = QDate::fromString( query.value(dateFieldNum).toString(), "yyyy/MM/dd");
    temp.gearHealth = static_cast<Gear::HealthStatus>(query.value(healthFieldNum).toInt());

    qDebug() << "Gear Name: " << temp.gearName;
    qDebug() << query.value(dateFieldNum).toString();
    qDebug() << "Gear Date: " << temp.obsolDate.toString("MM/dd/yyyy");
    qDebug() << "Gear Heth: " << temp.gearHealth;
    return temp;
}
//*********************************************************************************




//*********************************************************************************
QStringList DbConnect::getTroopNames()
{
    QStringList list;

    QSqlQuery query;
    query.prepare("SELECT * FROM troop_names "
                  "ORDER BY troop_id ASC");

    if(!query.exec())
    {
        qDebug() << query.lastError().text();
    }

    int troopLetterNum = query.record().indexOf("troop_letter");

    query.first();
    do
    {

        //qDebug() << query.value(troopLetterNum).toString();
        list << query.value(troopLetterNum).toString();
    }while(query.next());

    //**************************************************************
    //*                       * Test Code *                        *
    //**************************************************************
    //qDebug() << list;
    //**************************************************************

    return list;

}
//*********************************************************************************



//*********************************************************************************
QStringList DbConnect::getPatrolNamesByTroop(int troopNum)
{
    QStringList list;

    QSqlQuery query;

    query.prepare("SELECT name                  "
                  "FROM patrol_names            "
                  "WHERE troop_id = (:troopNum);");
    query.bindValue(":troopNum", troopNum);

    if(!query.exec())
    {
        qDebug() << query.lastError().text();
    }

    int nameFieldNum = query.record().indexOf("name");

    query.first();
    do
    {
        //qDebug() << query.value(nameFieldNum).toString();
        list << query.value(nameFieldNum).toString();
    }while(query.next());

    return list;

}
//*********************************************************************************




//*********************************************************************************
QStringList DbConnect::getGearHealthStatusList()
{
    QStringList list;

    QSqlQuery query;

    query.prepare("SELECT health_string     "
                  "FROM gear_status        ;");

    if(!query.exec())
    {
        qDebug() << query.lastError().text();
    }

    int statusFieldNum = query.record().indexOf("health_string");

    query.first();
    do
    {
        //qDebug() << query.value(statusFieldNum).toString();
        list << query.value(statusFieldNum).toString();
    }while(query.next());

    return list;

}
//*********************************************************************************




//*********************************************************************************
bool DbConnect::isCheckedOut(int catId, int idvId)
{
    QSqlQuery query;

    bool bIsCheckedOut = false;

    query.prepare(" SELECT is_checked_out           "
                  " FROM gear_list                  "
                  " WHERE                           "
                  "  gear_cat_id = (:gear_cat_id)   "
                  "  AND                            "
                  "  gear_idv_id = (:gear_idv_id)   "
                  " LIMIT 1;                        ");

    query.bindValue(":gear_cat_id", catId);
    query.bindValue(":gear_idv_id", idvId);

    if(!query.exec())
    {
        qDebug() << query.lastError().text();
    }

    query.first();
    bIsCheckedOut = query.value(0).toBool();

    qDebug() << "Is checked out:\t" << (bIsCheckedOut ? "yes\n" : "no\n");
    return bIsCheckedOut;

}
//*********************************************************************************


//*********************************************************************************
QStringList DbConnect::getDefaultNotes()
{
    QSqlQuery query;
    query.prepare("SELECT note             "
                  "FROM gear_default_notes ");
    QStringList temp;

    if(!query.exec())
    {
        qDebug() << query.lastError().text();
    }

    int noteFieldNum = query.record().indexOf("note");

    query.first();
    do
    {
        temp << query.value(noteFieldNum).toString();
    }while(query.next());

    return temp;
}
//*********************************************************************************


//*********************************************************************************
void  DbConnect::addNote(int catId, int idvId, QString note, QString author)
{
    QDateTime dt = QDateTime::currentDateTime();

    QSqlQuery query;
    query.prepare("INSERT INTO gear_notes (gear_cat_id, gear_idv_id, note, author, time_stamp) "
                  "VALUES ( (:catId), (:idvId), (:note), (:author), (:dt) )");
    query.bindValue(":catId", catId);
    query.bindValue(":idvId", idvId);
     query.bindValue(":note", note);
    query.bindValue(":author", author);
    query.bindValue(":dt", dt.toString(dateFormat));

    if(!query.exec())
    {
        qDebug() << query.lastError().text();
    }

}
//*********************************************************************************





