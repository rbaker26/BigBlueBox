#ifndef CATEGORY_H
#define CATEGORY_H

//*********************************************************************************
// For string operations
#include <QString>
#include <QStringList>
//*********************************************************************************

namespace bbb {
//*********************************************************************************
//! \class   Category
//! \brief   Holds catagory enum and related methods :Business Object
//! \details Contains the enum for the item catagory as well as static methods
//!          for conveting the enums to strings for the UI.
//! \author  Bob Baker
//*********************************************************************************
class Category
{
public:
    //**********************************************************
    //! \brief   Default no-args constructor
    //! \author  Bob Baker
    Category();
    //**********************************************************

    //**********************************************************
    //! \enum categoryType
    //! \brief Holds all catagories that items belong to.
    //! \author Bob Baker
    enum categoryType {
                NO_OPP  = 0,
                KITCHEN = 1,
                PROPANE = 2,
                CRAFTS  = 3,
                TARPS   = 4,
                OFFICE  = 5
                };
    //**********************************************************


    //**********************************************************
    //! \brief  Turns enum to string
    //! \param  Category::categoryType cat
    //! \author Bob Baker
    static QString categoryToQString(Category::categoryType cat);
    //**********************************************************


    //**********************************************************
    //! \brief  Turns (int)enum to string
    //! \param  int cat
    //! \author Bob Baker
    static QString categoryToQString(int cat);
    //**********************************************************

    static int intFromString(QString catStr);

}; // end class
//*********************************************************************************
} // end namespace
#endif // CATEGORY_H
