#include "itemtest.h"
using namespace bbbTest;

//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
ItemTest::ItemTest()
{
    qDebug() << endl;
}

//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&

void ItemTest::testTest()
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

void ItemTest::constructorTest()
{
    bbb::Item testItem;
    QVERIFY(testItem.itemName   == "");
    QVERIFY(testItem.boxStr     == "");
    QVERIFY(testItem.modifiedBy == "");
}

//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&

void ItemTest::categoryToQStringTest_data()
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

void ItemTest::categoryToQStringTest(int cat)
{
    //************************************************************
    //* Testing begins here
    //************************************************************
    QFETCH(int, catNum);
    QFETCH(QString, result);
    QCOMPARE(bbb::Item::categoryIntToQString(catNum), result);
    //************************************************************
}

//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
