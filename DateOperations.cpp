#include "DateOperations.h"

int DateOperations::getActualDate()
{
    time_t rawTime;
    struct tm * timeInfo;
    char buffer[9];

    time (&rawTime);
    timeInfo = localtime(&rawTime);

    strftime(buffer,sizeof(buffer),"%Y%m%d",timeInfo);
    string date(buffer);

    return HelpingMethods::stringToIntConversion(date);
}


int DateOperations::getDay(int date)
{
    return date % 100;
}

int DateOperations::getMonth(int date)
{
    return ((date % 10000) - getDay(date)) / 100;
}

int DateOperations::getYear(int date)
{
    return (date % 100000000 - getMonth(date) - getDay(date)) / 10000;
}

bool DateOperations::leepYear(int year)
{
    if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
        return true;
    else
        return false;
}

int DateOperations::calculatingMonthDays(int date)
{
    int days = 0;
    int month = getMonth(date);

    if (month == 1 || month == 3  || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
    {
        days = 31;
        return days;
    }
    else if (month == 4 || month == 6  || month == 9 || month == 11)
    {
        days = 30;
        return days;
    }
    else if (month == 2)
    {
        if (leepYear(getYear(date)) == true)
        {
            days = 29;
            return days;
        }
        else
        {
            days = 28;
            return days;
        }
    }
}


bool DateOperations::dateCorrect(int date)
{
    int startingDate = 20000101;
    int todaysDate = getActualDate();

    if (getYear(startingDate) <= getYear(date) && getYear(date) < getYear(todaysDate))
    {
        if (getMonth(date) >= 1 && getMonth(date) <= 12)
        {
            if (getDay(date) >=1 && getDay(date) <= calculatingMonthDays(date))
                return true;
            else
                return false;
        }
        else
            return false;
    }
    else if (getYear(date) == getYear(todaysDate))
    {
        if (getMonth(date) >= 1 && getMonth(date) <= getMonth(todaysDate))
        {
            if (getDay(date) >=1 && getDay(date) <= calculatingMonthDays(todaysDate))
                return true;
            else
                return false;
        }
        else
            return false;
    }
    else
        return false;
}

bool DateOperations::isDateFromCurrentMonth(int date)
{
    int todaysDate = getActualDate();

    if(getYear(date) == getYear(todaysDate))
    {
        if (getMonth(date) == getMonth(todaysDate))
            return true;
        else
            return false;
    }
    else
        return false;
}

bool DateOperations::isDateFromPreviousMonth(int date)
{
    int todaysDate = getActualDate();

    if (getMonth(todaysDate) == 1)
    {
        if(getYear(date) == (getYear(todaysDate) - 1))
        {
            if (getMonth(date) == 12)
                return true;
            else
                return false;
        }
        else
            return false;
    }
    else if (getYear(date) == getYear(todaysDate))
    {
        if (getMonth(date) == (getMonth(todaysDate) - 1))
            return true;
        else
            return false;
    }
    else
        return false;
}
