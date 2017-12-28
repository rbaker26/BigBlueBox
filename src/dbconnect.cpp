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

    query.first();
    do
    {
        tempItem.itemName        = query.value(itemNameFieldNum).toString();
        tempItem.quantity        = query.value(quantityFieldNum).toInt();
        tempItem.effectiveOnHand = query.value(efOnHandFieldNum).toInt();
        tempItem.category        = static_cast<Category::categoryType>(query.value(categoryFieldNum).toInt());
        tempItem.boxNum          = query.value(boxNumFieldNum).toInt();
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
                      "box_num         = (:box_num), "
                      "date_modified   = (:date_modified) "
                  "WHERE item_name = (:item_name_org)");

    query.bindValue(":item_name_org", orgName);

    query.bindValue(":quantity",        newRowInfo.quantity);
    query.bindValue(":target_quantity", newRowInfo.effectiveOnHand);
    query.bindValue(":cat",             static_cast<int>(newRowInfo.category));
    query.bindValue(":box_num",         newRowInfo.boxNum);
    query.bindValue(":date_modified", newRowInfo.dateModified.toString("yyyy/MM/dd hh:mm:ss"));

    query.bindValue(":item_name_new",   newRowInfo.itemName);


    if(!query.exec())
    {
        qDebug() << "Exec err:\t" << query.lastError().text();
    }
}
