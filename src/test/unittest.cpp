#include "UnitTest.h"
using namespace bbbTest;


UnitTest::UnitTest() {}

void UnitTest::run()
{
    //********************************************************
    //* Testing the class _RegexTest
    //*-------------------------------------------------------
    //* This will test the methods in the _Regex class.  If
    //*  any tests fails, travis.ci will display the failed
    //*  test in the log file and the build will fail.
    //********************************************************
    _RegexTest rxt;
    QTest::qExec(&rxt);
    //********************************************************


    //********************************************************
    //* Testing the class dataAcessMgr
    //*-------------------------------------------------------
    //* This will test the methods in the dataAcessMgr class.  If
    //*  any tests fails, travis.ci will display the failed
    //*  test in the log file and the build will fail.
    //********************************************************
//    sqlTest sqltest;
//    QTest::qExec(&sqltest);
    //********************************************************

}
