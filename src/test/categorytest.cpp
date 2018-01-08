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

    bbb::Category myCat(); // tests constructor

    QString str = "hello";
    QVERIFY(str.toUpper() == QString("HELLO"));
    QCOMPARE(5,5); //QCOMPARE( actual, expected)
    //************************************************************
}

//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&

void CategoryTest::testCatEnumVals()
{
    qDebug() << endl; // For spacing

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

    qDebug() << endl; // For spacing

    //************************************************************
    //* Testing begins here
    //************************************************************
    QFETCH(int, catNum);
    QFETCH(QString, result);
    QCOMPARE(bbb::Category::categoryToQString(catNum), result);
    //************************************************************
}

//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&

void CategoryTest::testStringToInt_data()
{
    QTest::addColumn<QString>("catString");
    QTest::addColumn<int>("result");

    QTest::newRow("N/A      ") << "N/A"              << 0;
    QTest::newRow("NO_OPP   ") << "NO_OPP"           << 0;
    QTest::newRow("Kitchen  ") << "Kitchen"          << 1;
    QTest::newRow("Propane  ") << "Propane"          << 2;
    QTest::newRow("Propane 2") << "Propane / Stoves" << 2;
    QTest::newRow("Crafts   ") << "Crafts"           << 3;
    QTest::newRow("Crafts 2 ") << "Arts and Crafts"  << 3;
    QTest::newRow("Tarps    ") << "Tarps"            << 4;
    QTest::newRow("Office   ") << "Office"           << 5;
}

//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&

void CategoryTest::testStringToInt()
{
    //************************************************************
    //* Testing begins here
    //************************************************************
    QFETCH(QString, catString);
    QFETCH(int,     result);
    QCOMPARE(bbb::Category::intFromString(catString), result);
    //************************************************************
}

//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&

