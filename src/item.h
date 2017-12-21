#ifndef ITEM_H
#define ITEM_H

//*********************************************************************************
#include <QString>
#include "category.h"
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
    int      boxNum;
    //! \brief If it can expire
    bool     canExpire;
    //! \brief Category::categoryType
    bbb::Category::categoryType category;
    //**********************************************************

    //**********************************************************
    //! \brief Uses the toString method in catagory class
    //! \param Category::categoryType category
    //! \author Bob Baker
    QString categoryToQString(bbb::Category::categoryType category);
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
