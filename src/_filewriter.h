#ifndef _FILEWRITER_H
#define _FILEWRITER_H
//*************************************************************************************
#include <QFile>
#include <QTextStream>
#include <QXmlStreamWriter>
#include <QStandardPaths>
#include <QDir>

#include <QVector>
#include <QStringList>

#include <QDebug>
#include "item.h"
#include "_filereader.h"
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

    // todo - change this to getFileWriterPathFromDirHandler() &&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
    //**********************************************************
    //! \brief Gets the path to desktop
    QString getReportsPath();
    //**********************************************************



public:
    //**********************************************************
    //! \brief This enum discribes the various reports to be
    //!        printed.
    //! \details <table>
    //!           <tr><th>Constant</th><th>Value</th><th>Discription</th></tr>
    //!           <tr><td>ReportType::Full</td><td>0</td><td>The full report.</td></tr>
    //!           <tr><td>ReportType::Low</td><td>1</td><td>Only prints items if their quantity is within 35% of the target.</td></tr>
    //!           <tr><td>ReportType::Critical</td><td>2</td><td>Only prints items if their quantity is within 10% of target.</td></tr>
    //!           <tr><td>ReportType::Expirable</td><td>3</td><td>Only prints items if they are expirable.</td></tr>
    //!           <tr><td>ReportType::DbDump</td><td>4</td><td>Prints all data in database. (only for xml)</td></tr>
    //!          </table>
    //! \author Bob Baker
    enum ReportType
    {
        Full,
        Low,
        Critical,
        Expirable,
        DbDump
    };
    //**********************************************************
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
     void makeTxtInvReport(QVector<Item> inventory, ReportType type = Full);
     //**********************************************************

     //**********************************************************
     //! \brief Writes Inventory Report to xml file
     //! \details Takes in Vector<Item> then formats and writes
     //!          it to a .xml file.
     //! \author Bob Baker
     void makeXmlInvReport(QVector<Item> inventory, ReportType type = Full);
     //**********************************************************



     static void writeDbFileLoc(QString path);
     static void writeReportsDir(QString path);
     static QString getAndCheckRoamingPath()
     {
         QString filePath = QStandardPaths::writableLocation(QStandardPaths::AppDataLocation);

         QDir dir(filePath);
         if(!dir.exists())
         {
             dir.mkpath(filePath);
         }

         return filePath;
     }

}; // end class
//*********************************************************************************
} // end namespace


#endif // _FILEWRITER_H
