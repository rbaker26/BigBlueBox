#ifndef CATEGORYTEST_H
#define CATEGORYTEST_H

#include <QObject>
#include <QtTest>
#include <QString>

#include "category.h"

namespace bbbTest {
/***********************************************************************************/
class CategoryTest : public QObject
{
    Q_OBJECT
public:
    //************************************************************
    //! \brief Default Constructor
    //! \author Bob Baker
    CategoryTest();
    //************************************************************

// All testing functions must be in private slots.
private slots:
    //************************************************************
    //* Testing Functions
    //************************************************************
    //! \brief Makes sure QTest, .yml an travis.ci are working.
    //! \author Bob Baker
    void testTest();
    //&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
    //! \brief Tests the int values of the enums
    //! \author Bob Baker
    void testCatEnumVals();
    //&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
    //! \brief Test Data for testEnumToString()
    //! \author Bob Baker
    void testEnumToString_data();
    //&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
    //! \brief Tests category enum to QString conversions
    //! \author Bob Baker
    void testEnumToString();
    //&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
    //************************************************************

}; // end class
/***********************************************************************************/

} // end namespace
#endif // CATEGORYTEST_H
