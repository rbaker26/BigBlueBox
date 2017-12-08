#include "category.h"

QStringList Category::categoryStrLs = QStringList() << "Kitchen" <<
                 "Propane / Stoves" <<
                 "Arts and Crafts" <<
                 "Tarps" <<
                 "Office";
Category::Category()
{

}


QString Category::categoryToQString(Category::categoryType cat)
{
    return categoryStrLs[static_cast<int> (cat)];
}

QString Category::categoryToQString(int cat)
{
    return categoryStrLs[static_cast<int> (cat)];
}
