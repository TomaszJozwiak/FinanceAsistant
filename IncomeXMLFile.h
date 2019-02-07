#ifndef INCOMEXMLFILE_H
#define INCOMEXMLFILE_H

#include <iostream>
#include <vector>
#include <string>

#include "Markup.h"
#include "Income.h"
#include "HelpingMethods.h"

using namespace std;

class IncomeXMLFile
{
    string fileWithIncomesName;
    int lastIncomeId;

public:
    IncomeXMLFile()
    {
        lastIncomeId = 0;
        fileWithIncomesName = "incomes.xml";
    };
    void addSingleIncomeToFile(Income income);
    vector <Income> loadLoggedUserIncomesFromXMLFile(int userId);
    int getLastIncomeId();

};

#endif
