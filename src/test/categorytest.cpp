#include "test/categorytest.h"
using namespace bbbTest;

//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
CategoryTest::CategoryTest()
{
    qDebug() << endl;
}

//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&

void CategoryTest::testTest()
{
    //************************************************************
    //* Testing begins here
    //************************************************************
    // this is test code for the test code. lol
    //QCOMPARE( actual, expected)
    QString str = "hello";
    QVERIFY(str.toUpper() == QString("HELLO"));
    QCOMPARE(5,5); //QCOMPARE( actual, expected)
    //************************************************************
}

//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&

void CategoryTest::testCatEnumVals()
{
    typedef bbb::Category::categoryType cat;
    //************************************************************
    //* Testing begins here
    //************************************************************
    QVERIFY(static_cast<int>(cat::KITCHEN) == 1);
    QVERIFY(static_cast<int>(cat::PROPANE) == 2);
    QVERIFY(static_cast<int>(cat::CRAFTS)  == 3);
    QVERIFY(static_cast<int>(cat::TARPS)   == 4);
    QVERIFY(static_cast<int>(cat::OFFICE)  == 5);
    //************************************************************
}

//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&

void CategoryTest::testIntToString_data()
{
    QTest::addColumn<int>("catNum");
    QTest::addColumn<QString>("result");

    QTest::newRow("Int 1 ")  << 1 << "Kitchen";
    QTest::newRow("Int 2 ")  << 2 << "Propane / Stoves";
    QTest::newRow("Int 3 ")  << 3 << "Arts and Crafts";
    QTest::newRow("Int 4 ")  << 4 << "Tarps";
    QTest::newRow("Int 5 ")  << 5 << "Office";
}

//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&

void CategoryTest::testIntToString()
{

    //************************************************************
    //* Testing begins here
    //************************************************************
    QFETCH(int, catNum);
    QFETCH(QString, result);
    QCOMPARE(bbb::Category::categoryToQString(catNum), result);
    //************************************************************
}

//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
