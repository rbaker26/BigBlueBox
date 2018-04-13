#ifndef QRINTERFACE_H
#define QRINTERFACE_H

//********************************************************************************
//* QR Code Plan
//********************************************************************************
// This class will act as an interface for the QrCode Lib.
// There will be differnt QrCode categories
//  * Gear Items - Each Qr will point to a unique item.
//  * Troop / Patrol Names - Each Qr will check out the gear to the patrol.
//
//
// The process for checking out an item will be as follows...
//  1. Scan the Item QrCode
//  2. Update Item info in needed
//  3. Scan Troop or Patrol QR code on the back of the participants name tag.
//  4. Repeat
//
// The process for checking in an item will be as follows...
//  1. Scan the Item QrCode.
//  2. Update the Item Info
//  3. Click "Check-In"
//
// ORDER OF SCANNING SHOULD NOT MATTER
// They should be able to scan a patrol or Item first.
//
//
//********************************************************************************
//
// QrCode String Format
// To help the program tell the difference between a Troop/Patrol QR and a Item QR,
// they need to be formated to a standered.
// This is the standard we will be using
//
// Troop/Patrol/Person
//  "PID:<troop_ID> (2 digit hex):<patrol_ID> (2 digit hex):<personal_ID>(6 digit hex)
//
// Item
//  "ITM:<catagory_num (4 digit hex)>:<item_id (6 digit hex)>"
//********************************************************************************

#include "qr/QrCode.h"
#include <string>
#include <vector>
#include <QDebug>
class QrInterface
{
public:
    QrInterface();

    static QString strToSvg(QString s)
    {
        using namespace qrcodegen;
        QrCode qr0 = QrCode::encodeText(s.toStdString().c_str(), QrCode::Ecc::MEDIUM);
        std::string svg = qr0.toSvgString(4);

        return QString::fromStdString(svg);
    }

};

#endif // QRINTERFACE_H
