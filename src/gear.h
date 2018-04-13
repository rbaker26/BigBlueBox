#ifndef GEAR_H
#define GEAR_H

#include <QString>
#include <QDateTime>

class Gear
{


public:

    enum HealthStatus
    {
        HEALTHY,
        MISSING_PARTS,
        NEEDS_MAINTENANCE,
        NEEDS_REPAIR,
        NEEDS_REPLACE
    };

    Gear();

private:
    HealthStatus gearHealth;
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
