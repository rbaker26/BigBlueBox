#ifndef ITEMTEST_H
#define ITEMTEST_H

#include <QObject>
#include <QtTest>

#include <item.h>

namespace bbbTest {
/***********************************************************************************/
//! \class   ItemTest
//! \brief   Contains the tests for the Item class
//! \details This file is only on included in test builds.  It will not be
//!             complied debug or release builds. It will be used by travis.ci to
//!             run unit tests for the Item class
//! \test
//! \author Bob Baker
/***********************************************************************************/
class ItemTest : public QObject
{
    Q_OBJECT
public:
    //************************************************************
    //! \brief Default Constructor
    //! \author Bob Baker
    ItemTest();
    //************************************************************

// All testing functions must be in private slots.
private slots:
    //************************************************************
    //* Testing Functions
    //************************************************************
    //! \brief Makes sure QTest, .yml an travis.ci are working.
    //! \test
    //! \author Bob Baker
    void testTest();
    //&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
    //! \brief Tests that the constructor sets the correct vals
    //! \test
    //! \author Bob Baker
    void constructorTest();
    //&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
    //! \brief Test data for Category to string fx
    //! \test
    //! \author Bob Baker
    void categoryToQStringTest_data();
    //&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
    //! \brief Tests the Category to string fx
    //! \test
    //! \author Bob Baker
    void categoryToQStringTest(int cat);
    //************************************************************

}; // end class
/***********************************************************************************/
} // end namespace

/***********************************************************************************/
#endif // ITEMTEST_H
