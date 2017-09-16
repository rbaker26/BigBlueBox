#ifndef DATE_H
#define DATE_H

#include <QString>

class Date
{
    QString dateString;

public:
    Date();
    Date(const int year, const int month, const int day);
    ~Date();

    int year;
    int month;
    int day;

    QString getDateString();

};

#endif // DATE_H

