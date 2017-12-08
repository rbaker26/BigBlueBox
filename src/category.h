#ifndef CATEGORY_H
#define CATEGORY_H

#include <QString>
#include <QStringList>



class Category
{
public:
    Category();
    enum categoryType {
                KITCHEN = 1,
                PROPANE = 2,
                CRAFTS  = 3,
                TARPS   = 4,
                OFFICE  = 5
                };
    static QStringList categoryStrLs;
    static QString categoryToQString(Category::categoryType cat);
    static QString categoryToQString(int cat);
};


#endif // CATEGORY_H
