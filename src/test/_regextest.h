#ifndef _REGEXTEST_H
#define _REGEXTEST_H

#include <QObject>
#include <QtTest>
#include <QString>

#include "_regex.h"

namespace bbbTest {
/***********************************************************************************/
//! \class   _RegexTest
//! \brief   Contains the tests for the _Regex class
//! \details This file is only on included in test builds.  It will not be
//!             complied debug or release builds. It will be used by travis.ci to
//!             run unit tests for the _Regex class
//! \test
//! \author Bob Baker
/***********************************************************************************/
class _RegexTest : public QObject
{
    Q_OBJECT // Qt Object macro
public:
    //************************************************************
    //! \brief Default Constructor
    //! \author Bob Baker
    _RegexTest();
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
    //! \brief Data for testIsItemName()
    //! \test
    //! \author  Bob Baker
    void testIsItemName_data();
    //&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
    //! \brief Tests regex on isItemName
    //! \test
    //! \author Bob Baker
    void testIsItemName();
    //&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
    //! \brief Test Data for testIsBoxName
    //! \test
    //! \author Bob Baker
    void testIsBoxName_data();
    //&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
    //! \brief Tests regec on isBoxName
    //! \test
    //! \author Bob Baker
    void testIsBoxName();
    //************************************************************

}; // end class
/***********************************************************************************/

} // end namespace
#endif // _REGEXTEST_H
