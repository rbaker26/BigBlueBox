#ifndef ITEM_H
#define ITEM_H

#include <QString>


class Item
{
private:
    QString itemName;
    int     quantity;
    int     effectiveOnHand;


public:
    Item();
    ~Item();
    void setItemName();
    int  getItemName() const;

    void setEffectiveOnHands();
    int  getEffectiveOnHands() const;




};

#endif // ITEM_H
