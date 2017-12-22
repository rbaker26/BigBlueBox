#ifndef CATEGORYTEST_H
#define CATEGORYTEST_H

#include <QObject>
#include <QtTest>
#include <QString>

namespace bbb {
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
    //************************************************************
};
/***********************************************************************************/
}
#endif // CATEGORYTEST_H
