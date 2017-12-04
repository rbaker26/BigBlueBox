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


};

#endif // ITEM_H
