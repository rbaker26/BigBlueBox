#ifndef ITEM_H
#define ITEM_H

#include <QString>
#include "category.h"


class Item
{
public:
    Item();

    QString          itemName;
    int              quantity;
    int              effectiveOnHand;
    Category::categoryType category;
    int              boxNum;


    QString categoryToQString(); // needs implamentation/  use this->cat, or call the fx in Catagory class
};

#endif // ITEM_H
