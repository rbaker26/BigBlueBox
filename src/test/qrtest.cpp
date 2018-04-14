#include "qrtest.h"
using namespace bbbTest;

QrTest::QrTest()
{
    qDebug() << "\n";
}


void QrTest::testTest()
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

void QrTest::svgRenderTest_data()
{
    QTest::addColumn<QString>("input");
    QTest::addColumn<QString>("svg");

    QTest::newRow("Phone Number") << "949-555-1234" <<
     "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n<!DOCTYPE svg "
     "PUBLIC \"-//W3C//DTD SVG 1.1//EN\" \"http://www.w3.org/Graphics"
     "/SVG/1.1/DTD/svg11.dtd\">\n<svg xmlns=\"http://www.w3.org/2000"
     "/svg\" version=\"1.1\" viewBox=\"0 0 29 29\" stroke=\""
     "none\">\n\t<rect width=\"100%\" height=\"100%\" fill=\"#FFFFFF"
     "\"/>\n\t<path d=\"M4,4h1v1h-1z M5,4h1v1h-1z M6,4h1v1h-1z M7,"
     "4h1v1h-1z M8,4h1v1h-1z M9,4h1v1h-1z M10,4h1v1h-1z M13,4h1v1h-1z"
     " M14,4h1v1h-1z M15,4h1v1h-1z M16,4h1v1h-1z M18,4h1v1h-1z M19,"
     "4h1v1h-1z M20,4h1v1h-1z M21,4h1v1h-1z M22,4h1v1h-1z M23,"
     "4h1v1h-1z M24,4h1v1h-1z M4,5h1v1h-1z M10,5h1v1h-1z M12,"
     "5h1v1h-1z M14,5h1v1h-1z M18,5h1v1h-1z M24,5h1v1h-1z M4,6h1v1h-1z "
     "M6,6h1v1h-1z M7,6h1v1h-1z M8,6h1v1h-1z M10,6h1v1h-1z M15,6h1v1h-1z "
     "M18,6h1v1h-1z M20,6h1v1h-1z M21,6h1v1h-1z M22,6h1v1h-1z M24,"
     "6h1v1h-1z M4,7h1v1h-1z M6,7h1v1h-1z M7,7h1v1h-1z M8,7h1v1h-1z "
     "M10,7h1v1h-1z M12,7h1v1h-1z M15,7h1v1h-1z M18,7h1v1h-1z M20,7h1v1h-"
     "1z M21,7h1v1h-1z M22,7h1v1h-1z M24,7h1v1h-1z M4,8h1v1h-1z M6,"
     "8h1v1h-1z M7,8h1v1h-1z M8,8h1v1h-1z M10,8h1v1h-1z M12,8h1v1h-1z "
     "M14,8h1v1h-1z M16,8h1v1h-1z M18,8h1v1h-1z M20,8h1v1h-1z M21,8h1v1h-1z "
     "M22,8h1v1h-1z M24,8h1v1h-1z M4,9h1v1h-1z M10,9h1v1h-1z M13,"
     "9h1v1h-1z M15,9h1v1h-1z M18,9h1v1h-1z M24,9h1v1h-1z M4,"
     "10h1v1h-1z M5,10h1v1h-1z M6,10h1v1h-1z M7,10h1v1h-1z M8,"
     "10h1v1h-1z M9,10h1v1h-1z M10,10h1v1h-1z M12,10h1v1h-1z "
     "M14,10h1v1h-1z M16,10h1v1h-1z M18,10h1v1h-1z M19,10h1v1h-1z "
     "M20,10h1v1h-1z M21,10h1v1h-1z M22,10h1v1h-1z M23,10h1v1h-1z "
     "M24,10h1v1h-1z M12,11h1v1h-1z M13,11h1v1h-1z M14,11h1v1h-1z "
     "M15,11h1v1h-1z M5,12h1v1h-1z M7,12h1v1h-1z M8,12h1v1h-1z M9,"
     "12h1v1h-1z M10,12h1v1h-1z M12,12h1v1h-1z M15,12h1v1h-1z M17,"
     "12h1v1h-1z M18,12h1v1h-1z M20,12h1v1h-1z M21,12h1v1h-1z M23,"
     "12h1v1h-1z M6,13h1v1h-1z M8,13h1v1h-1z M11,13h1v1h-1z M16,"
     "13h1v1h-1z M18,13h1v1h-1z M19,13h1v1h-1z M20,13h1v1h-1z M22,"
     "13h1v1h-1z M23,13h1v1h-1z M24,13h1v1h-1z M4,14h1v1h-1z M6,"
     "14h1v1h-1z M7,14h1v1h-1z M8,14h1v1h-1z M10,14h1v1h-1z M11,"
     "14h1v1h-1z M12,14h1v1h-1z M14,14h1v1h-1z M15,14h1v1h-1z M17,"
     "14h1v1h-1z M18,14h1v1h-1z M19,14h1v1h-1z M4,15h1v1h-1z M6,"
     "15h1v1h-1z M7,15h1v1h-1z M12,15h1v1h-1z M14,15h1v1h-1z M15,"
     "15h1v1h-1z M17,15h1v1h-1z M19,15h1v1h-1z M22,15h1v1h-1z M23,"
     "15h1v1h-1z M5,16h1v1h-1z M6,16h1v1h-1z M7,16h1v1h-1z M10,"
     "16h1v1h-1z M11,16h1v1h-1z M15,16h1v1h-1z M17,16h1v1h-1z M23,"
     "16h1v1h-1z M12,17h1v1h-1z M14,17h1v1h-1z M15,17h1v1h-1z M16,"
     "17h1v1h-1z M17,17h1v1h-1z M18,17h1v1h-1z M20,17h1v1h-1z M21,"
     "17h1v1h-1z M24,17h1v1h-1z M4,18h1v1h-1z M5,18h1v1h-1z M6,18h1"
     "v1h-1z M7,18h1v1h-1z M8,18h1v1h-1z M9,18h1v1h-1z M10,18h1v1h-1z"
     " M16,18h1v1h-1z M17,18h1v1h-1z M19,18h1v1h-1z M20,18h1v1h-1z M"
     "22,18h1v1h-1z M23,18h1v1h-1z M4,19h1v1h-1z M10,19h1v1h-1z M12"
     ",19h1v1h-1z M15,19h1v1h-1z M16,19h1v1h-1z M18,19h1v1h-1z M20,1"
     "9h1v1h-1z M22,19h1v1h-1z M4,20h1v1h-1z M6,20h1v1h-1z M7,20h1v1h-"
     "1z M8,20h1v1h-1z M10,20h1v1h-1z M12,20h1v1h-1z M13,20h1v1h-1z M"
     "15,20h1v1h-1z M18,20h1v1h-1z M19,20h1v1h-1z M23,20h1v1h-1z M24,"
     "20h1v1h-1z M4,21h1v1h-1z M6,21h1v1h-1z M7,21h1v1h-1z M8,21h1v1h"
     "-1z M10,21h1v1h-1z M12,21h1v1h-1z M14,21h1v1h-1z M16,21h1v1h-1z"
     " M17,21h1v1h-1z M18,21h1v1h-1z M19,21h1v1h-1z M20,21h1v1h-1z M2"
     "1,21h1v1h-1z M4,22h1v1h-1z M6,22h1v1h-1z M7,22h1v1h-1z M8,22h1v"
     "1h-1z M10,22h1v1h-1z M13,22h1v1h-1z M15,22h1v1h-1z M16,22h1v1h-"
     "1z M17,22h1v1h-1z M20,22h1v1h-1z M22,22h1v1h-1z M23,22h1v1h-1z "
     "M24,22h1v1h-1z M4,23h1v1h-1z M10,23h1v1h-1z M12,23h1v1h-1z M15,"
     "23h1v1h-1z M16,23h1v1h-1z M23,23h1v1h-1z M4,24h1v1h-1z M5,24h1v"
     "1h-1z M6,24h1v1h-1z M7,24h1v1h-1z M8,24h1v1h-1z M9,24h1v1h-1z "
     "M10,24h1v1h-1z M13,24h1v1h-1z M16,24h1v1h-1z M17,24h1v1h-1z "
     "M19,24h1v1h-1z M22,24h1v1h-1z M23,24h1v1h-1z\" fill=\"#000000\"/>\n</svg>\n";
}

void QrTest::svgRenderTest()
{
    QFETCH(QString, input);
    QFETCH(QString, svg);

    QCOMPARE(QrInterface::strToSvg(input), svg);
}
