#ifndef DBCONNECT_H
#define DBCONNECT_H

//*********************************************************************************
// For database connection & error checking
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QDebug>
#include <QSqlError>
#include <QSqlRecord>

// For strings
#include <QString>

// For returnings vectors of objects
#include <QVector>
#include <algorithm>

// Business Objects
#include "item.h"
#include "_filereader.h"
#include "gear.h"
//*********************************************************************************

namespace bbb {
//*********************************************************************************
//! \class   DbConnect
//! \brief   DataBase Comm. Layer : Singleton
//! \details Contains all push/pull/update functions for communication between
//!          DataBase Layer and Business Object Layers.
//! \author  Bob Baker
// I know there is a lot of stuff in this class, I'm sorry.  I did not want to
//  mess with inherting singletons and building interfaces.
//*********************************************************************************
class DbConnect
{
private:
    //**********************************************************
    //! \brief Database object
    QSqlDatabase bbb_db;
    //**********************************************************

    //**********************************************************
    //! \brief Singleton Pointer
    static DbConnect* instance;
    //**********************************************************

    //**********************************************************
    //! \brief   Default no-args constructor
    //! \details Private: No objects can be instantiated.
    //!          Sets the path for the database.
    //! \author  Bob Baker
    DbConnect();
    //**********************************************************

public:
    //**********************************************************
    //! \brief Server DateTime format for all Date.toString()'s
    const QString dateFormat = "yyyy/MM/dd hh:mm::ss";
    //**********************************************************

    //**********************************************************
    //! \brief   Default non-args de-constructor
    //! \details Closes database.
    //! \author  Bob Baker
    ~DbConnect();
    //**********************************************************

    //**********************************************************
    //! \brief   Singleton pointer return function.
    //! \details Returns pointer to singleton object.
    //! \return  DbConnect*
    //! \author  Bob Baker
    static DbConnect* getInstance();
    //**********************************************************

    //**********************************************************
    //! \brief   Gets full inventory.
    //! \details Returns a QVector of all items in the inventory
    //!          table in the database.
    //! \return  QVector<Item> fullInventory
    //! \author  Bob Baker
    QVector<Item> getFullInvAsVector();
    //**********************************************************

    //**********************************************************
    //! \brief   Updates the contents of one item
    //! \details Take a QString containing the org name, and a
    //!           Row containing the new info for the item.  A
    //!           Row is a empty inheritance of Item.
    //! \param   QString orgName, Row newRowInfo
    //! \author  Bob Baker
    void updateItem(QString orgName, Row newRowInfo);
    //**********************************************************

    //**********************************************************
    //! \brief Addes a new item to the database.
    //! \details Items must be unique or the sql will fail.
    //! \param Item newItem
    //! \author Bob Baker
    void addNewItem(Item newItem);
    //**********************************************************

    //**********************************************************
    //! \brief Deletes a item from the database.
    //! \details Removes a item from the db based on a matching
    //!           Item name
    //! \param QString itemName
    //! \author Bob Baker
    void deleteItem(QString name);
    //**********************************************************

    //**********************************************************
    //! \brief Checks to see if an item exists.
    //! \details Queries DB with itemName to see if any records
    //!          with the same name exist.  If they exist,
    //!          the function will return true.
    bool itemAlreadyExists(QString name);
    //**********************************************************


    // this is a slow query.  Make sure to thread it.
    QVector<GearNote> getGearNotes(int catId, int idvId);
    // not really <int>, i just havnt made that struct yet
    // Use a join om two cols
    // JOIN ON
    //   gear_list.gear_cat_id = gear_notes.gear_cat_id
    //  AND
    //   gear_list.gear_idv_id = gear_notes.gear_idv_id
    //
    // will prob have to use a GROUP BY to make them come in together


    QStringList getTroopNames();

    QStringList getPatrolNamesByTroop(int troopNum);

    QStringList getGearHealthStatusList();

    bool isCheckedOut(int catId, int idvId);


}; // end class
//*********************************************************************************
} // end namespace
#endif // DBCONNECT_H
