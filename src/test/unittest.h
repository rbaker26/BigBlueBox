#ifndef UNITTEST_H
#define UNITTEST_H

#include <QObject>
#include <QtTest>
#include <QString>

/***********************************************************************************/
// Put test classes here.
// The test classes will include the classes to be tested.
// ex. CustomerTest.h includes customer.h
/***********************************************************************************/
//#include "CustomerTest.h"
//#include "sqltest.h"

#include "test/_regextest.h"

namespace bbbTest {
/***********************************************************************************/
//! \class   UnitTest
//! \brief   Starts the regression an unit testing
//! \details This file is only on included in test builds.  It will not be
//!             complied debug or release builds. It will be used by travis.ci to
//!             run unit tests.
//! \author Bob Baker
/***********************************************************************************/
class UnitTest : public QObject
{   Q_OBJECT
public:
    /***********************************************************************************/
    //! \brief  Constructor
    //! \author Bob Baker
    UnitTest();
    //***********************************************************************************/


    /***********************************************************************************/
    //! \brief Static fx, calls all unit test objects and executes them.
    //! \return void
    //! \author Bob Baker
    static void run();
    /***********************************************************************************/

}; // end class
/***********************************************************************************/

} // end namespace
#endif // UNITTEST_H
