#include "test/_regextest.h"
using namespace bbbTest;

//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
_RegexTest::_RegexTest() { qDebug() << "\n"; }

//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&


//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
void _RegexTest::testTest()
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

void _RegexTest::testIsItemName_data()
{
    // Setting up Columns for testing.
    QTest::addColumn<QString>("itemName");
    QTest::addColumn<bool>("result");

    // Casing
    QTest::newRow("all lower ") << "mypot"  << true;
    QTest::newRow("mixed case") << "MyPot"  << true;
    QTest::newRow("upper case") << "MYPOT"  << true;

    // Illegal Length
    QTest::newRow("too short ") << ""       << false;
    QTest::newRow("too long  ") << "abcdefghijklmnop"
                                   "qrstuvwxyz012345"
                                   "678910"
                                            << false;
    // Legal Symbols
    QTest::newRow("beg w. num") << "5myPot" << true;
    QTest::newRow("beg w. (  ") << "(myPot" << true;
    QTest::newRow("beg w. )  ") << ")myPot" << true;
    QTest::newRow("beg w. .  ") << ".myPot" << true;
    QTest::newRow("beg w. -  ") << "-myPot" << true;
    QTest::newRow("beg w. _  ") << "_myPot" << true;

    QTest::newRow("end w. num") << "5myPot" << true;
    QTest::newRow("end w. (  ") << "myPot(" << true;
    QTest::newRow("end w. )  ") << "myPot)" << true;
    QTest::newRow("end w. .  ") << "myPot." << true;
    QTest::newRow("end w. -  ") << "myPot-" << true;
    QTest::newRow("end w. _  ") << "myPot_" << true;

    QTest::newRow("has ()    ") << "myP()t" << true;
    QTest::newRow("has )(    ") << "myP)(t" << true;
    QTest::newRow("has ..    ") << "my..ot" << true;
    QTest::newRow("has _num  ") << "my_6ot" << true;
    QTest::newRow("has (num) ") << "myP(4)" << true;

    // Illegal Symbols
    QTest::newRow("beg w. !  ") << "!myPot" << false;
    QTest::newRow("has    !  ") << "my!Pot" << false;
    QTest::newRow("end w. !  ") << "myPot!" << false;
    QTest::newRow("beg w. @  ") << "@myPot" << false;
    QTest::newRow("has    @  ") << "my@Pot" << false;
    QTest::newRow("end w. @  ") << "myPot@" << false;
    QTest::newRow("beg w. #  ") << "#myPot" << false;
    QTest::newRow("has    #  ") << "my#Pot" << false;
    QTest::newRow("end w. #  ") << "myPot#" << false;
    QTest::newRow("beg w. $  ") << "$myPot" << false;
    QTest::newRow("has    $  ") << "my$Pot" << false;
    QTest::newRow("end w. $  ") << "myPot$" << false;
    QTest::newRow("beg w. %  ") << "%myPot" << false;
    QTest::newRow("has    %  ") << "my%Pot" << false;
    QTest::newRow("end w. %  ") << "myPot%" << false;
    QTest::newRow("beg w. ^  ") << "^myPot" << false;
    QTest::newRow("has    ^  ") << "my^Pot" << false;
    QTest::newRow("end w. ^  ") << "myPot^" << false;
    QTest::newRow("beg w. &  ") << "&myPot" << false;
    QTest::newRow("has    &  ") << "my&Pot" << false;
    QTest::newRow("end w. &  ") << "myPot&" << false;
    QTest::newRow("beg w. *  ") << "*myPot" << false;
    QTest::newRow("has    *  ") << "my*Pot" << false;
    QTest::newRow("end w. *  ") << "myPot*" << false;
    QTest::newRow("beg w. +  ") << "+myPot" << false;
    QTest::newRow("has    +  ") << "my+Pot" << false;
    QTest::newRow("end w. +  ") << "myPot+" << false;
    QTest::newRow("beg w. =  ") << "=myPot" << false;
    QTest::newRow("has    =  ") << "my=Pot" << false;
    QTest::newRow("end w. =  ") << "myPot=" << false;
    QTest::newRow("beg w. ~  ") << "~myPot" << false;
    QTest::newRow("has    ~  ") << "my~Pot" << false;
    QTest::newRow("end w. ~  ") << "myPot~" << false;
}

//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&

void _RegexTest::testIsItemName()
{
    //************************************************************
    //* Testing begins here
    //************************************************************
    //* Bugs caught so far...
    //*  * In Regex, the "-" needs to come first.
    //*     e.x. "^[-A-Za-z0-9()._]{1}[-A-Za-z0-9() ._]{0,35}$"
    //*     if the hyphen does not come first, it will cause
    //*     errors will all symbols.
    //*  * Special chars do NOT have to be escaped before passing
    //*     them into the regex engine.
    //************************************************************
    QFETCH(QString, itemName);
    QFETCH(bool, result);

    typedef bbb::_Regex rx;

    //QCOMPARE( actual, expected)
    QCOMPARE(rx::isItemName(itemName), result);
    //************************************************************
}
//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
