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
#include <QStringList>

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
    //! \return  DbConnect* instanceSingletonClass
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
    //! \return boolItemAlreadyExists
    //! \author Bob Baker
    bool itemAlreadyExists(QString name);
    //**********************************************************

    //**********************************************************
    //! \brief Gets notes for a gear item.
    //! \details Queries DB with catId and idvId to find all
    //!          related node for a certain gear item in chrono
    //!          order.
    //! \return QVector<GearNote>
    //! \author Bob Baker
    QVector<GearNote> getGearNotes(int catId, int idvId);
    //**********************************************************

    //**********************************************************
    //! \brief Gets all info for a gear item.
    //! \details Queries DB with catId and idvId to find all
    //!          related info for a certain gear item.
    //! Gear gearItem
    //! \author Bob Baker
    Gear getGearInfo(int catId, int idvId);
    //**********************************************************

    //**********************************************************
    //! \brief Gets all Heath Statuses
    //! \details Returns a QStringList containing all of the
    //!          Health Status Text Code in the DB.
    //! \return QStringList healthStatusList
    //! \author Bob Baker
    QStringList getGearHealthStatusList();
    //**********************************************************

    //**********************************************************
    //! \brief Checks if Gear is checked out
    //! \details Returns a bool if the Gear Item, based on catId
    //!          and idvId, is checked out.
    //! \return bool isCheckedOut
    //! \author Bob Baker
    bool isCheckedOut(int catId, int idvId);
    //**********************************************************

    //**********************************************************
    //! \brief Gets Troop names
    //! \details Will return all troop names in the DB in a
    //!          QStringList
    //! \return QStringList troopNamesList
    //! \author Bob Baker
    QStringList getTroopNames();
    //**********************************************************

    //**********************************************************
    //! \brief Gets Patrol names
    //! \details Will return all patrol names for the given
    //!          troop id in a QStringList
    //! \return QStringList patrolNamesList
    //! \author Bob Baker
    QStringList getPatrolNamesByTroop(int troopNum);
    //**********************************************************

    //**********************************************************
    //! \brief Gets Default Notes
    //! \details Will return all default notes in the DB.
    //! \return QStringList defaultNotesList
    //! \author Bob Baker
    QStringList getDefaultNotes();
    //**********************************************************

    //**********************************************************
    //! \brief Adds new Gear Note to DB
    //! \details Addes a new note for an Gear Item based on
    //!          catId and idvId.  It will handle the time stamp
    //!          local to the function.
    //! \author Bob Baker
    void addNote(int catId, int idvId, QString note, QString author);
    //**********************************************************

    //**********************************************************
    bool gearItemExists(int catId, int idvId);
    //**********************************************************


    //**********************************************************
    void checkOutGear(int catId, int idvId, QString pid);
    //**********************************************************

    //**********************************************************
    void checkInGear(int catId, int idvId);
    //**********************************************************

    //**********************************************************
    //! \brief System Log
    //! \details Pushes a log with a timestamp to the DB.
    //! \author Bob Baker
    void sysLog(QString log);
    //**********************************************************


    //**********************************************************
    //! \brief Updates Health Status
    //! \details Updates Health Status for an item. Health must
    //!          be passed as an int, not a enum
    //! \author Bob Baker
    void updateGearItemHealth(int catId, int idvId, int health);
    //**********************************************************

    QString isCheckedOutBy(int catId, int idvId);

}; // end class
//*********************************************************************************
} // end namespace
#endif // DBCONNECT_H
