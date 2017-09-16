#include "gearholder.h"

GearHolder::GearHolder() {}
GearHolder::~GearHolder() {}


void GearHolder::setName(const QString& firstName, const QString& lastName)
{
    this->firstName = firstName;
    this->lastName  = lastName;
}

void GearHolder::setTroopLetter(const TroopLetter& troopLetter)
{
    this->troopLetter = troopLetter;
}

void GearHolder::setPatrolName(const PatrolName &patrolName)
{
    this->patrolName = patrolName;
}


void GearHolder::addGearToHolder(const Gear& gear)
{
    gearHeld.push_back(gear);
}


