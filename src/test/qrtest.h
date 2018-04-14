#ifndef QRTEST_H
#define QRTEST_H

#include <QObject>
#include <QtTest>
#include <QString>

#include "qr/QrInterface.h"

class qrtest
{
    Q_OBJECT
public:
    qrtest();

private slots:
    //************************************************************
    //* Testing Functions
    //************************************************************
    //! \brief Makes sure QTest, .yml an travis.ci are working.
    //! \test
    //! \author Bob Baker
    void testTest();
    //&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
    void svgRenderTest();
    void svgRenderTest_data();
//QString svgString = QrInterface::strToSvg(scanCodeString);

};

#endif // QRTEST_H
