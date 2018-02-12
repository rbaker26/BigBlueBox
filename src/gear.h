#ifndef GEAR_H
#define GEAR_H

#include <QString>
#include <QDateTime>

class Gear
{
public:
    Gear();

};

//############################################################################
//############################################################################
//############################################################################


class GearNote
{
public:
    GearNote();

    QString   noteText;
    QString   author;
    QDateTime dtMade;
};


#endif // GEAR_H
