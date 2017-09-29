#include "date.h"

Date::Date() {}

Date::~Date() {}

Date::Date(const int year, const int month, const int day)
{
    this->year = year;
    this->month = month;
    this->day  = day;
}

QString Date::getDateString()
{
    // Formatting for dates less that 10.
    QString spacerMonthString = (month < 10 ? "/0" : "/");
    QString spacerDayString =   (month < 10 ? "/0" : "/");

    // QString::number(int) will turn an int into a QString literal.
    dateString = QString::number(year)  + spacerMonthString +
                 QString::number(month) + spacerDayString +
                 QString::number(day);

    return dateString;
}
