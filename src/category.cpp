#include "category.h"
using namespace bbb;
//*********************************************************************************
Category::Category()
{

}
//*********************************************************************************

//*********************************************************************************
QString Category::categoryToQString(Category::categoryType cat)
{
    QStringList categoryStrLs = QStringList() << "N/A" << "Kitchen" <<
                     "Propane / Stoves" <<
                     "Arts and Crafts" <<
                     "Tarps" <<
                     "Office";
    return categoryStrLs[static_cast<int> (cat)];
}
//*********************************************************************************

//*********************************************************************************
QString Category::categoryToQString(int cat)
{
    QStringList categoryStrLs = QStringList() << "N/A" << "Kitchen" <<
                     "Propane / Stoves" <<
                     "Arts and Crafts" <<
                     "Tarps" <<
                     "Office";
    return categoryStrLs[static_cast<int> (cat)];
}
//*********************************************************************************

//*********************************************************************************
int Category::intFromString(QString catStr)
{
    if(catStr == "N/A" || catStr == "NO_OPP") {return 0;}
    else if(catStr == "Kitchen") {return 1;}
    else if(catStr == "Propane" || catStr == "Propane / Stoves") {return 2;}
    else if(catStr == "Crafts" || catStr == "Arts and Crafts" ) {return 3;}
    else if(catStr == "Tarps") {return 4;}
    else if(catStr == "Office") {return 5;}
    else
    {
       return 0;
    }


}
//*********************************************************************************
