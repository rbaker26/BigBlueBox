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

void CategoryTest::testEnumToString_data()
{
    typedef bbb::Category::categoryType cat;
    QTest::addColumn<cat>("catEmum");
    QTest::addColumn<QString>("result");

    QTest::newRow("KITCHEN") << cat::KITCHEN << "Kitchen";
    QTest::newRow("PROPANE") << cat::PROPANE << "Propane / Stoves";
    QTest::newRow("CRAFTS") << cat::CRAFTS << "Arts and Crafts";
    QTest::newRow("TARPS") << cat::TARPS << "Tarps";
    QTest::newRow("OFFICE") << cat::OFFICE << "Office";

}

//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&

void CategoryTest::testEnumToString()
{
    bbb::Category cat;

    //************************************************************
    //* Testing begins here
    //************************************************************
    QFETCH(cat, catEnum);
    QFETCH(QString, result);
    QCOMPARE(cat.categoryToQString(catEnum), result);
    //************************************************************
}

//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
