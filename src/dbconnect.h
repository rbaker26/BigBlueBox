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
//#include "Gear.h"
#include "item.h"
//*********************************************************************************


//*********************************************************************************
//! \class   DbConnect
//! \brief   DataBase Comm. Layer : Singleton
//! \details Contains all push/pull/update functions for communication between
//!          DataBase Layer and Business Object Layers.
//! \author  Bob Baker
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
    QVector<Item> getFullInvAsVector();
    //**********************************************************


    void updateItem(QString orgName, Row newRowInfo);
};
//*********************************************************************************
#endif // DBCONNECT_H
