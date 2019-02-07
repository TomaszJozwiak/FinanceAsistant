#ifndef HELPINGMETHODS_H
#define HELPINGMETHODS_H

#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std;

class HelpingMethods
{
public:
    static string intToStringConversion(int number);
    static int stringToIntConversion(string number);
    static string loadLine();
    static char loadSign();
    static double stringToDoubleConversion (string word);
};
#endif
