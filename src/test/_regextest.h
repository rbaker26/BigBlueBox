#ifndef _REGEXTEST_H
#define _REGEXTEST_H

#include <QObject>
#include <QtTest>
#include <QString>
#include <QStringList>

#include "_regex.h"

namespace bbbTest {
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
    //! \author Bob Baker
    void testTest();
    //&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
    void testIsItemName_data();
    //! \brief Tests regex on isItemName
    //! \author Bob Baker
    void testIsItemName();
    //&&&&&&&&&&&&&&&&&&&&&&&&&&&&&


}; // end class
/***********************************************************************************/

} // end namespace
#endif // _REGEXTEST_H
