#include "dbconnect.h"
using namespace bbb;
//*********************************************************************************
DbConnect* DbConnect::instance = nullptr;
//*********************************************************************************

//*********************************************************************************
DbConnect::DbConnect()
{
    bbb_db = QSqlDatabase::addDatabase("QSQLITE");

    bbb_db.setDatabaseName("C:/Users/007ds/Documents/GitHub/BigBlueBox/rec/BigBlueBox.db");

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
    // do not delete instance
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
    query.prepare("Select * FROM inventory");

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
