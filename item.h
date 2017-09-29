#ifndef ITEM_H
#define ITEM_H

#include <QString>
#include "category.h"


struct Item
{

    QString          itemName;
    int              quantity;
    int              effectiveOnHand;
    CatCls::Category category;
    int              boxNum;


};

#endif // ITEM_H
