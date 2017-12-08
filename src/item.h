#ifndef ITEM_H
#define ITEM_H

#include <QString>
#include "category.h"


class Item
{
public:
    Item();

    QString  itemName;
    int      quantity;
    int      effectiveOnHand;
    int      boxNum;
    bool     canExpire;

    Category::categoryType category;

    QString categoryToQString(); // needs implamentation/  use this->cat, or call the fx in Catagory class
};

#endif // ITEM_H
