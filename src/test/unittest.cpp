#include "test/unittest.h"
using namespace bbbTest;


UnitTest::UnitTest() {}

void UnitTest::run()
{
    //********************************************************
    //* Testing the class bbb::_Regex
    //*-------------------------------------------------------
    //* This will test the methods in the _Regex class.  If
    //*  any tests fails, travis.ci will display the failed
    //*  test in the log file and the build will fail.
    //********************************************************
    _RegexTest rxTest;
    QTest::qExec(&rxTest);
    //********************************************************


    //********************************************************
    //* Testing the class bbb::Category
    //*-------------------------------------------------------
    //* This will test the methods in the Category class.  If
    //*  any tests fails, travis.ci will display the failed
    //*  test in the log file and the build will fail.
    //********************************************************
    CategoryTest catTest;
    QTest::qExec(&catTest);
    //********************************************************

    //********************************************************
    //* Testing the class bbb::Item
    //*-------------------------------------------------------
    //* This will test the methods in the Item class.  If
    //*  any tests fails, travis.ci will display the failed
    //*  test in the log file and the build will fail.
    //********************************************************
    ItemTest itemTest;
    QTest::qExec(&itemTest);
    //********************************************************

//    _FileWriterBench bench;
//    QTest::qExec(&bench);


    QrTest qrTest;
    QTest::qExec(&qrTest);

}
