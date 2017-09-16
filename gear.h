#ifndef GEAR_H
#define GEAR_H


#include <string>
#include <QString>
#include <QVector>
#include "date.h"

enum HealthStatus
{
    OK, DAMAGED_NEEDS_REPAIR, DAMAGED_NEEDS_REPLACE
};

class Gear
{

private:
    QString gearDescription;
    int     gearCatID;  // The catigory ID
    int     gearIdvID;  // The indiviual ID

    bool hasParts;
    QVector <int> partsFromInventory; // will change <int> to a clas of items
                                      // Upto 5 parts

    HealthStatus healthStatus; // note: send to db as string "yyyy/mm/dd"
    QString HealthStatusString[3] = {
                                    "OK",
                                    "DAMAGED_NEEDS_REPAIR",
                                    "DAMAGED_NEEDS_REPLACE"
                                    };

    Date obsolescenceDate;

public:
    Gear();
    ~Gear();

    void setGearDescription(const QString& gearDescription);
    void setGearCatID(const int gearCatID);
    void setGearIdvID(const int gearIdvID);
    void setHasParts (const bool hasParts);
    //void addPartsFromInventory(const int supplyItemNumber);
    QString getHealthStatusString();
    void setDate(const int year, const int month, const int day);
};

#endif // GEAR_H
