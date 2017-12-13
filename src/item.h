#ifndef ITEM_H
#define ITEM_H

//*********************************************************************************
#include <QString>
#include "category.h"
//*********************************************************************************

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
    Category::categoryType category;
    //**********************************************************

    //**********************************************************
    //! \brief Uses the toString method in catagory class
    //! \param Category::categoryType category
    //! \author Bob Baker
    QString categoryToQString(Category::categoryType category);
    //**********************************************************
};
//*********************************************************************************

struct Row : public Item {};
#endif // ITEM_H
