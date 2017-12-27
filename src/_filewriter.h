#ifndef _FILEWRITER_H
#define _FILEWRITER_H
//*************************************************************************************
#include <QFile>
#include <QTextStream>
#include <QXmlStreamWriter>

#include <QVector>
#include <QStringList>

#include "item.h"
//*************************************************************************************


namespace bbb {
//*********************************************************************************
//! \class   _FileWriter
//! \brief   Output File Stream Handler : Singleton
//! \details Handles all writing to files.  This is mainly for creating reports.
//!          It can output in .txt format or in .csv format.
//! \author  Bob Baker
//*********************************************************************************
class _FileWriter
{
private:
    //**********************************************************
    //! \brief   Default no-args constructor
    //! \details Private: No objects can be instantiated.
    _FileWriter();
    //**********************************************************

    //**********************************************************
    //! \brief Singleton Pointer
    static _FileWriter* instance;
    //**********************************************************

public:
    //**********************************************************
    //! \brief   Default non-args de-constructor
    //! \details Resets instance to nullptr.
    //! \author  Bob Baker
    ~_FileWriter();
    //**********************************************************

    //**********************************************************
    //! \brief   Singleton pointer return function.
    //! \details Returns pointer to singleton object.
    //! \return  _FileWriter*
    static _FileWriter* getInstance();
    //**********************************************************

    //**********************************************************
    //! \brief   Writes a Inventory Report to txt file.
    //! \details Takes in Vector<Item> then formats and writes
    //!          it to a .txt file.
    //! \author  Bob Baker
    // every option should also have a output to .csv option as well
    // can be controled via combo box dropdown in reports veiw.
     void makeTxtInvReport(QVector<Item> inventory);
     //**********************************************************

     //**********************************************************
     //! \brief Writes Inventory Report to xml file
     //! \details Takes in Vector<Item> then formats and writes
     //!          it to a .xml file.
     //! \author Bob Baker
     void makeXmlInvReport(QVector<Item> inventory);
     //**********************************************************


}; // end class
//*********************************************************************************
} // end namespace


#endif // _FILEWRITER_H
