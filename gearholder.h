#ifndef GEARHOLDER_H
#define GEARHOLDER_H

#include <QString>
#include <QVector>
#include "gear.h"
#include "troopletter.h"
#include "patrolname.h"



class GearHolder
{
protected:
    QString firstName;
    QString lastName;
    TroopLetter troopLetter;

    QVector<Gear> gearHeld;
    PatrolName patrolName;
public:
    GearHolder();
    ~GearHolder();

    void setName(const QString& firstName, const QString& lastName);
    void setTroopLetter(const TroopLetter& troopLetter);
    void setPatrolName(const PatrolName& patrolName);

    void addGearToHolder(const Gear& gear);


};

#endif // GEARHOLDER_H
