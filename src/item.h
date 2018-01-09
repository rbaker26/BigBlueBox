#ifndef ITEM_H
#define ITEM_H

//*********************************************************************************
#include <QString>
#include "category.h"
#include <QDate>
//*********************************************************************************

namespace bbb {
//*********************************************************************************
//! \class   Item
//! \brief   Business Object Layer : Inventory Item
//! \details Contains all of the data members for one item in the inventory table
//!          in the database.
//! \author  Bob Baker
//*********************************************************************************
class Item
{
public:
    //**********************************************************
    //! \brief   Default no-args constructor
    //! \author  Bob Baker
    Item();
    //**********************************************************

    //**********************************************************
    //! \brief Item Name
    QString  itemName;

    //! \brief Item Quantity
    int      quantity;

    //! \brief  Item Effective OnHand
    int      effectiveOnHand;

    //! \brief Box item is in
    //! \obsolete Replaced by box string
    int      boxNum;

    //! \brief Box item is in
    QString boxStr;

    //! \brief If it can expire
    bool     canExpire;

    //! \brief Category::categoryType
    bbb::Category::categoryType category;

    //! \brief Date it was modified
    QDateTime dateModified;

     //! \brief User who last modified the item
    QString modifiedBy;
    //**********************************************************

    //**********************************************************
    //! \brief Uses the toString method in catagory class
    //! \param Category::categoryType category
    //! \author Bob Baker
    QString categoryIntToQString(int cat);
    //**********************************************************
}; // end class
//*********************************************************************************
} // end namespace

//*********************************************************************************


namespace bbb {
//*********************************************************************************
//! \class   Row
//! \brief   Ui Object Layer : Inventory Table Row
//! \details One row in the Inventory table.
//! \inherits Item
//! \author  Bob Baker
//*********************************************************************************
struct Row : public Item {};
} // end namespace
#endif // ITEM_H
