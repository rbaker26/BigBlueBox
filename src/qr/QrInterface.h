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
// They should be able to scan a patrol or Itam first.
//
//
//********************************************************************************
//
// QrCode String Format
// To help the program tell the difference between a Patrol Name QR and a Item QR,
// they need to be formated to a standered.
// This is the standed we will be using/
//
// Patrol Name
//  "PAT:<troop_letter>:<patrol_name pad(0)for20>
//
// Troop Letter
//  "TRP:<troop_letter>"
//
// Item
//  "ITM:<catagory_num (5 digit hex)>:<item_id (5 digit hex)>"
//********************************************************************************

#include "qr/QrCode.h"
#include <string>
#include <vector>
#include <QDebug>
class QrInterface
{
public:
    QrInterface();

    QString testsss()
    {
        using namespace qrcodegen;
        QrCode qr0 = QrCode::encodeText("TRP:B", QrCode::Ecc::MEDIUM);
        std::string svg = qr0.toSvgString(4);

        return QString::fromStdString(svg);
    }

};

#endif // QRINTERFACE_H
