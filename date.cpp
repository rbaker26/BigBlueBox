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
    QString spacerMonthString = (month < 10 ? "/0" : "/");
    QString spacerDayString = (month < 10 ? "/0" : "/");
    dateString = QString::number(year)  + spacerMonthString +
                 QString::number(month) + spacerDayString +
                 QString::number(day);

    return dateString;
}
