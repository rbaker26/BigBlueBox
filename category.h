#ifndef CATEGORY_H
#define CATEGORY_H

#include <QString>



class CatCls
{
public:
    enum Category
    {
        KITCHEN = 1,
        PROPANE = 2,
        CRAFTS  = 3,
        TARPS   = 4,
        OFFICE  = 5
    };
    QString categoryStrAr[5] = {"Kitchen",
                                 "Propane / Stoves",
                                 "Arts and Crafts" ,
                                 "Tarps",
                                 "Office"};
};



#endif // CATEGORY_H
