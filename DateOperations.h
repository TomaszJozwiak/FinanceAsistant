#ifndef DATAOPERATIONS_H
#define DATAOPERATIONS_H

#include <iostream>
#include <ctime>

#include "HelpingMethods.h"

using namespace std;

class DateOperations
{
    int getDay(int date);
    int getMonth(int date);
    int getYear(int date);
    bool leepYear(int year);
    int calculatingMonthDays(int date);

public:

    int getActualDate();
    bool dateCorrect(int date);
    bool isDateFromCurrentMonth(int date);
    bool isDateFromPreviousMonth(int date);
};
#endif
