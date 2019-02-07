#ifndef EXPENSEXMLFILE_H
#define EXPENSEXMLFILE_H

#include <iostream>
#include <vector>
#include <string>

#include "Markup.h"
#include "Expense.h"
#include "HelpingMethods.h"

using namespace std;

class ExpenseXMLFile
{
    string fileWithExpensesName;
    int lastExpenseId;

public:
    ExpenseXMLFile()
    {
        lastExpenseId = 0;
        fileWithExpensesName = "expenses.xml";
    };
    void addSingleExpenseToFile(Expense expense);
    vector <Expense> loadLoggedUserExpensesFromXMLFile(int userId);
    int getLastExpenseId();

};

#endif
