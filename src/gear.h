#ifndef GEAR_H
#define GEAR_H

#include <QString>
#include <QDateTime>

class Gear
{


public:
    Gear();

    QString gearName;
    enum HealthStatus
    {
        HEALTHY,
        MISSING_PARTS,
        NEEDS_MAINTENANCE,
        NEEDS_REPAIR,
        NEEDS_REPLACE
    };
    QDate obsolDate;



    HealthStatus gearHealth;
};

//############################################################################
//############################################################################
//############################################################################

namespace bbb {

class GearNote
{
public:
    GearNote();

    QString   noteText;
    QString   author;
    QDateTime dtMade;
};
}

#endif // GEAR_H
