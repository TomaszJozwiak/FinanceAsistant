#include "HelpingMethods.h"

string HelpingMethods::intToStringConversion(int number)
{
    ostringstream ss;
    ss << number;
    string str = ss.str();
    return str;
}

int HelpingMethods::stringToIntConversion(string number)
{
    int intNumber;
    istringstream iss(number);
    iss >> intNumber;

    return intNumber;
}

string HelpingMethods::loadLine()
{
    string word = "";
    getline(cin, word);
    return word;
}
