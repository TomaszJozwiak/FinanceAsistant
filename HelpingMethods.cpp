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

char HelpingMethods::loadSign()
{
    string wejscie = "";
    char znak  = {0};

    cin.sync();
    while (true)
    {
        getline(cin, wejscie);

        if (wejscie.length() == 1)
        {
            znak = wejscie[0];
            break;
        }
        cout << "To nie jest pojedynczy znak. Wpisz ponownie." << endl;
    }
    return znak;
}

double HelpingMethods::stringToDoubleConversion (string word)
{
istringstream iss(word);
double number;
iss >> number;
return number;
}
