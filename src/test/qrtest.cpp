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



    QTest::newRow("Item") << "itm:ffff:ffffff" <<
     "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n<!DOCTYPE svg "
     "PUBLIC \"-//W3C//DTD SVG 1.1//EN\" \"http://www.w3.org/Gra"
     "phics/SVG/1.1/DTD/svg11.dtd\">\n<svg xmlns=\"http://www.w3."
     "org/2000/svg\" version=\"1.1\" viewBox=\"0 0 33 33\" stroke"
     "=\"none\">\n\t<rect width=\"100%\" height=\"100%\" fill=\"#FF"
     "FFFF\"/>\n\t<path d=\"M4,4h1v1h-1z M5,4h1v1h-1z M6,4h1v1h-1z "
     "M7,4h1v1h-1z M8,4h1v1h-1z M9,4h1v1h-1z M10,4h1v1h-1z M12,4h"
     "1v1h-1z M13,4h1v1h-1z M14,4h1v1h-1z M15,4h1v1h-1z M17,4h1v1"
     "h-1z M18,4h1v1h-1z M19,4h1v1h-1z M22,4h1v1h-1z M23,4h1v1h-1z"
     " M24,4h1v1h-1z M25,4h1v1h-1z M26,4h1v1h-1z M27,4h1v1h-1z M2"
     "8,4h1v1h-1z M4,5h1v1h-1z M10,5h1v1h-1z M13,5h1v1h-1z M16,5h1"
     "v1h-1z M17,5h1v1h-1z M18,5h1v1h-1z M19,5h1v1h-1z M20,5h1v1h-"
     "1z M22,5h1v1h-1z M28,5h1v1h-1z M4,6h1v1h-1z M6,6h1v1h-1z M7,"
     "6h1v1h-1z M8,6h1v1h-1z M10,6h1v1h-1z M14,6h1v1h-1z M17,6h1v1"
     "h-1z M19,6h1v1h-1z M22,6h1v1h-1z M24,6h1v1h-1z M25,6h1v1h-1z"
     " M26,6h1v1h-1z M28,6h1v1h-1z M4,7h1v1h-1z M6,7h1v1h-1z M7,7h"
     "1v1h-1z M8,7h1v1h-1z M10,7h1v1h-1z M14,7h1v1h-1z M15,7h1v1h-"
     "1z M18,7h1v1h-1z M19,7h1v1h-1z M22,7h1v1h-1z M24,7h1v1h-1z M"
     "25,7h1v1h-1z M26,7h1v1h-1z M28,7h1v1h-1z M4,8h1v1h-1z M6,8h1v"
     "1h-1z M7,8h1v1h-1z M8,8h1v1h-1z M10,8h1v1h-1z M12,8h1v1h-1z "
     "M13,8h1v1h-1z M14,8h1v1h-1z M19,8h1v1h-1z M20,8h1v1h-1z M22,8"
     "h1v1h-1z M24,8h1v1h-1z M25,8h1v1h-1z M26,8h1v1h-1z M28,8h1v1h"
     "-1z M4,9h1v1h-1z M10,9h1v1h-1z M12,9h1v1h-1z M13,9h1v1h-1z M1"
     "5,9h1v1h-1z M22,9h1v1h-1z M28,9h1v1h-1z M4,10h1v1h-1z M5,10h1v"
     "1h-1z M6,10h1v1h-1z M7,10h1v1h-1z M8,10h1v1h-1z M9,10h1v1h-1z "
     "M10,10h1v1h-1z M12,10h1v1h-1z M14,10h1v1h-1z M16,10h1v1h-1z M"
     "18,10h1v1h-1z M20,10h1v1h-1z M22,10h1v1h-1z M23,10h1v1h-1z M2"
     "4,10h1v1h-1z M25,10h1v1h-1z M26,10h1v1h-1z M27,10h1v1h-1z M28"
     ",10h1v1h-1z M14,11h1v1h-1z M15,11h1v1h-1z M16,11h1v1h-1z M18,1"
     "1h1v1h-1z M20,11h1v1h-1z M5,12h1v1h-1z M6,12h1v1h-1z M7,12h1v1"
     "h-1z M8,12h1v1h-1z M9,12h1v1h-1z M10,12h1v1h-1z M11,12h1v1h-1z "
     "M13,12h1v1h-1z M23,12h1v1h-1z M24,12h1v1h-1z M28,12h1v1h-1z M7,"
     "13h1v1h-1z M11,13h1v1h-1z M13,13h1v1h-1z M17,13h1v1h-1z M18,13h"
     "1v1h-1z M19,13h1v1h-1z M23,13h1v1h-1z M26,13h1v1h-1z M4,14h1v1h"
     "-1z M5,14h1v1h-1z M8,14h1v1h-1z M9,14h1v1h-1z M10,14h1v1h-1z M1"
     "1,14h1v1h-1z M15,14h1v1h-1z M16,14h1v1h-1z M17,14h1v1h-1z M18,14"
     "h1v1h-1z M19,14h1v1h-1z M21,14h1v1h-1z M22,14h1v1h-1z M24,14h1v1h"
     "-1z M27,14h1v1h-1z M28,14h1v1h-1z M6,15h1v1h-1z M7,15h1v1h-1z M8,"
     "15h1v1h-1z M11,15h1v1h-1z M14,15h1v1h-1z M17,15h1v1h-1z M20,15h1"
     "v1h-1z M24,15h1v1h-1z M25,15h1v1h-1z M28,15h1v1h-1z M4,16h1v1h-1"
     "z M5,16h1v1h-1z M8,16h1v1h-1z M10,16h1v1h-1z M12,16h1v1h-1z M13,"
     "16h1v1h-1z M16,16h1v1h-1z M18,16h1v1h-1z M19,16h1v1h-1z M21,16h1v1h-"
     "1z M22,16h1v1h-1z M23,16h1v1h-1z M24,16h1v1h-1z M26,16h1v1h-1z M27,"
     "16h1v1h-1z M28,16h1v1h-1z M4,17h1v1h-1z M6,17h1v1h-1z M8,17h1v1h-1z"
     " M14,17h1v1h-1z M15,17h1v1h-1z M16,17h1v1h-1z M20,17h1v1h-1z M25,1"
     "7h1v1h-1z M26,17h1v1h-1z M27,17h1v1h-1z M4,18h1v1h-1z M6,18h1v1h-1z"
     " M7,18h1v1h-1z M8,18h1v1h-1z M10,18h1v1h-1z M11,18h1v1h-1z M12,18h1"
     "v1h-1z M13,18h1v1h-1z M14,18h1v1h-1z M18,18h1v1h-1z M19,18h1v1h-1z "
     "M21,18h1v1h-1z M22,18h1v1h-1z M24,18h1v1h-1z M25,18h1v1h-1z M26,18h1"
     "v1h-1z M27,18h1v1h-1z M28,18h1v1h-1z M4,19h1v1h-1z M7,19h1v1h-1z M8"
     ",19h1v1h-1z M11,19h1v1h-1z M12,19h1v1h-1z M13,19h1v1h-1z M14,19h1v1"
     "h-1z M16,19h1v1h-1z M20,19h1v1h-1z M23,19h1v1h-1z M27,19h1v1h-1z M28"
     ",19h1v1h-1z M4,20h1v1h-1z M6,20h1v1h-1z M9,20h1v1h-1z M10,20h1v1h-1"
     "z M13,20h1v1h-1z M14,20h1v1h-1z M15,20h1v1h-1z M16,20h1v1h-1z M17,2"
     "0h1v1h-1z M18,20h1v1h-1z M19,20h1v1h-1z M20,20h1v1h-1z M21,20h1v1"
     "h-1z M22,20h1v1h-1z M23,20h1v1h-1z M24,20h1v1h-1z M25,20h1v1h-"
     "1z M26,20h1v1h-1z M12,21h1v1h-1z M14,21h1v1h-1z M15,21h1v1h-1z"
     " M16,21h1v1h-1z M19,21h1v1h-1z M20,21h1v1h-1z M24,21h1v1h-1z M"
     "4,22h1v1h-1z M5,22h1v1h-1z M6,22h1v1h-1z M7,22h1v1h-1z M8,22h1"
     "v1h-1z M9,22h1v1h-1z M10,22h1v1h-1z M12,22h1v1h-1z M20,22h1v1"
     "h-1z M22,22h1v1h-1z M24,22h1v1h-1z M25,22h1v1h-1z M26,22h1v1h-1z M"
     "27,22h1v1h-1z M28,22h1v1h-1z M4,23h1v1h-1z M10,23h1v1h-1z M12,23h"
     "1v1h-1z M14,23h1v1h-1z M15,23h1v1h-1z M17,23h1v1h-1z M20,23h1v1h-1"
     "z M24,23h1v1h-1z M27,23h1v1h-1z M4,24h1v1h-1z M6,24h1v1h-1z M7,24"
     "h1v1h-1z M8,24h1v1h-1z M10,24h1v1h-1z M12,24h1v1h-1z M13,24h1v1h-"
     "1z M15,24h1v1h-1z M16,24h1v1h-1z M17,24h1v1h-1z M19,24h1v1h-1z M"
     "20,24h1v1h-1z M21,24h1v1h-1z M22,24h1v1h-1z M23,24h1v1h-1z M24,"
     "24h1v1h-1z M25,24h1v1h-1z M26,24h1v1h-1z M27,24h1v1h-1z M4,25h1"
     "v1h-1z M6,25h1v1h-1z M7,25h1v1h-1z M8,25h1v1h-1z M10,25h1v1h-1z"
     " M12,25h1v1h-1z M13,25h1v1h-1z M15,25h1v1h-1z M18,25h1v1h-1z M19"
     ",25h1v1h-1z M20,25h1v1h-1z M21,25h1v1h-1z M22,25h1v1h-1z M24,2"
     "5h1v1h-1z M28,25h1v1h-1z M4,26h1v1h-1z M6,26h1v1h-1z M7,26h1v1h"
     "-1z M8,26h1v1h-1z M10,26h1v1h-1z M12,26h1v1h-1z M13,26h1v1h-1z M"
     "15,26h1v1h-1z M16,26h1v1h-1z M17,26h1v1h-1z M23,26h1v1h-1z M25,26"
     "h1v1h-1z M26,26h1v1h-1z M28,26h1v1h-1z M4,27h1v1h-1z M10,27h1v1h-"
     "1z M12,27h1v1h-1z M13,27h1v1h-1z M14,27h1v1h-1z M17,27h1v1h-1z M1"
     "9,27h1v1h-1z M20,27h1v1h-1z M21,27h1v1h-1z M22,27h1v1h-1z M24,27h"
     "1v1h-1z M28,27h1v1h-1z M4,28h1v1h-1z M5,28h1v1h-1z M6,28h1v1h-1z "
     "M7,28h1v1h-1z M8,28h1v1h-1z M9,28h1v1h-1z M10,28h1v1h-1z M23,28h1v1h-1z "
     "M25,28h1v1h-1z M26,28h1v1h-1z M27,28h1v1h-1z M28,28h1v1h-1z\" fill=\"#000000\"/>\n</svg>\n";



    QTest::newRow("Person") << "pid:abc:de0123" <<
      "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n<!DOCTYPE "
      "svg PUBLIC \"-//W3C//DTD SVG 1.1//EN\" \"http://www.w3"
      ".org/Graphics/SVG/1.1/DTD/svg11.dtd\">\n<svg xmlns=\"ht"
      "tp://www.w3.org/2000/svg\" version=\"1.1\" viewBox=\"0 "
      "0 29 29\" stroke=\"none\">\n\t<rect width=\"100%\" heig"
      "ht=\"100%\" fill=\"#FFFFFF\"/>\n\t<path d=\"M4,4h1v1h-1z"
      " M5,4h1v1h-1z M6,4h1v1h-1z M7,4h1v1h-1z M8,4h1v1h-1z M9,"
      "4h1v1h-1z M10,4h1v1h-1z M13,4h1v1h-1z M16,4h1v1h-1z M18"
      ",4h1v1h-1z M19,4h1v1h-1z M20,4h1v1h-1z M21,4h1v1h-1z M22"
      ",4h1v1h-1z M23,4h1v1h-1z M24,4h1v1h-1z M4,5h1v1h-1z M10,"
      "5h1v1h-1z M14,5h1v1h-1z M15,5h1v1h-1z M16,5h1v1h-1z M18"
      ",5h1v1h-1z M24,5h1v1h-1z M4,6h1v1h-1z M6,6h1v1h-1z M7,6h"
      "1v1h-1z M8,6h1v1h-1z M10,6h1v1h-1z M12,6h1v1h-1z M14,6h1"
      "v1h-1z M15,6h1v1h-1z M18,6h1v1h-1z M20,6h1v1h-1z M21,6h"
      "1v1h-1z M22,6h1v1h-1z M24,6h1v1h-1z M4,7h1v1h-1z M6,7h1"
      "v1h-1z M7,7h1v1h-1z M8,7h1v1h-1z M10,7h1v1h-1z M12,7h1v"
      "1h-1z M13,7h1v1h-1z M15,7h1v1h-1z M16,7h1v1h-1z M18,7h1v"
      "1h-1z M20,7h1v1h-1z M21,7h1v1h-1z M22,7h1v1h-1z M24,7h1v"
      "1h-1z M4,8h1v1h-1z M6,8h1v1h-1z M7,8h1v1h-1z M8,8h1v1h-1"
      "z M10,8h1v1h-1z M12,8h1v1h-1z M13,8h1v1h-1z M14,8h1v1h-1z"
      " M16,8h1v1h-1z M18,8h1v1h-1z M20,8h1v1h-1z M21,8h1v1h-1z"
      " M22,8h1v1h-1z M24,8h1v1h-1z M4,9h1v1h-1z M10,9h1v1h-1z "
      "M12,9h1v1h-1z M13,9h1v1h-1z M14,9h1v1h-1z M16,9h1v1h-1z "
      "M18,9h1v1h-1z M24,9h1v1h-1z M4,10h1v1h-1z M5,10h1v1h-1z "
      "M6,10h1v1h-1z M7,10h1v1h-1z M8,10h1v1h-1z M9,10h1v1h-1z "
      "M10,10h1v1h-1z M12,10h1v1h-1z M14,10h1v1h-1z M16,10h1v1h"
      "-1z M18,10h1v1h-1z M19,10h1v1h-1z M20,10h1v1h-1z M21,10h"
      "1v1h-1z M22,10h1v1h-1z M23,10h1v1h-1z M24,10h1v1h-1z M12"
      ",11h1v1h-1z M13,11h1v1h-1z M14,11h1v1h-1z M15,11h1v1h-1z"
      " M4,12h1v1h-1z M6,12h1v1h-1z M7,12h1v1h-1z M8,12h1v1h-1z"
      " M9,12h1v1h-1z M10,12h1v1h-1z M16,12h1v1h-1z M18,12h1v1h"
      "-1z M19,12h1v1h-1z M20,12h1v1h-1z M21,12h1v1h-1z M22,12h1"
      "v1h-1z M6,13h1v1h-1z M7,13h1v1h-1z M13,13h1v1h-1z M14,13h"
      "1v1h-1z M15,13h1v1h-1z M18,13h1v1h-1z M20,13h1v1h-1z M24,"
      "13h1v1h-1z M4,14h1v1h-1z M6,14h1v1h-1z M8,14h1v1h-1z M9,1"
      "4h1v1h-1z M10,14h1v1h-1z M12,14h1v1h-1z M13,14h1v1h-1z M16"
      ",14h1v1h-1z M18,14h1v1h-1z M19,14h1v1h-1z M21,14h1v1h-1z"
      " M22,14h1v1h-1z M23,14h1v1h-1z M6,15h1v1h-1z M11,15h1v1h-"
      "1z M12,15h1v1h-1z M13,15h1v1h-1z M14,15h1v1h-1z M17,15h1v"
      "1h-1z M20,15h1v1h-1z M21,15h1v1h-1z M22,15h1v1h-1z M5,16h"
      "1v1h-1z M6,16h1v1h-1z M7,16h1v1h-1z M8,16h1v1h-1z M10,16h"
      "1v1h-1z M11,16h1v1h-1z M16,16h1v1h-1z M18,16h1v1h-1z M19,1"
      "6h1v1h-1z M12,17h1v1h-1z M13,17h1v1h-1z M14,17h1v1h-1z M15"
      ",17h1v1h-1z M17,17h1v1h-1z M19,17h1v1h-1z M20,17h1v1h-1z M2"
      "1,17h1v1h-1z M22,17h1v1h-1z M23,17h1v1h-1z M24,17h1v1h-1z M"
      "4,18h1v1h-1z M5,18h1v1h-1z M6,18h1v1h-1z M7,18h1v1h-1z M8,1"
      "8h1v1h-1z M9,18h1v1h-1z M10,18h1v1h-1z M14,18h1v1h-1z M16,1"
      "8h1v1h-1z M22,18h1v1h-1z M23,18h1v1h-1z M4,19h1v1h-1z M10,1"
      "9h1v1h-1z M12,19h1v1h-1z M15,19h1v1h-1z M16,19h1v1h-1z M17,"
      "19h1v1h-1z M19,19h1v1h-1z M20,19h1v1h-1z M22,19h1v1h-1z M24"
      ",19h1v1h-1z M4,20h1v1h-1z M6,20h1v1h-1z M7,20h1v1h-1z M8,20"
      "h1v1h-1z M10,20h1v1h-1z M12,20h1v1h-1z M14,20h1v1h-1z M16,2"
      "0h1v1h-1z M18,20h1v1h-1z M19,20h1v1h-1z M21,20h1v1h-1z M23,"
      "20h1v1h-1z M24,20h1v1h-1z M4,21h1v1h-1z M6,21h1v1h-1z M7,21"
      "h1v1h-1z M8,21h1v1h-1z M10,21h1v1h-1z M12,21h1v1h-1z M14,21"
      "h1v1h-1z M15,21h1v1h-1z M17,21h1v1h-1z M19,21h1v1h-1z M20,21"
      "h1v1h-1z M4,22h1v1h-1z M6,22h1v1h-1z M7,22h1v1h-1z M8,22h1v1"
      "h-1z M10,22h1v1h-1z M12,22h1v1h-1z M13,22h1v1h-1z M16,22h1v1"
      "h-1z M17,22h1v1h-1z M4,23h1v1h-1z M10,23h1v1h-1z M14,23h1v1h"
      "-1z M16,23h1v1h-1z M21,23h1v1h-1z M22,23h1v1h-1z M4,24h1v1h-"
      "1z M5,24h1v1h-1z M6,24h1v1h-1z M7,24h1v1h-1z M8,24h1v1h-1z M"
      "9,24h1v1h-1z M10,24h1v1h-1z M12,24h1v1h-1z M16,24h1v1h-1z M1"
      "7,24h1v1h-1z M18,24h1v1h-1z M19,24h1v1h-1z M23,24h1v1h-1z\" fill=\"#000000\"/>\n</svg>\n";

}

void QrTest::svgRenderTest()
{
    QFETCH(QString, input);
    QFETCH(QString, svg);

    QCOMPARE(QrInterface::strToSvg(input), svg);
}
