#include "gear.h"

Gear::Gear()  {}

Gear::~Gear() {}

void Gear::setGearDescription(const QString& gearDescription)
{
    this->gearDescription = gearDescription;
}

void Gear::setGearCatID(const int gearCatID)
{
    this->gearCatID = gearCatID;
}

void Gear::setGearIdvID(const int gearIdvID)
{
    this->gearIdvID = gearIdvID;
}


void Gear::setHasParts (const bool hasParts)
{
    this->hasParts= hasParts;
}

QString Gear::getHealthStatusString()
{
    return HealthStatusString[healthStatus];
}

void Gear::setDate(const int year, const int month, const int day)
{
    this->obsolescenceDate.year  = year;
    this->obsolescenceDate.month = month;
    this->obsolescenceDate.day   = day;
}
