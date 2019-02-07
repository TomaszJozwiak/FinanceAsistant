#ifndef FINANCEMANAGER_H
#define FINANCEMANAGER_H

#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

#include "Income.h"
#include "Expense.h"
#include "IncomeXMLFile.h"
#include "ExpenseXMLFile.h"
#include "DateOperations.h"
#include "HelpingMethods.h"

using namespace std;

class FinanceManager
{
    int loggedUserId;
    double incomeAmount;
    double expenseAmount;
    vector <Income> incomes;
    vector <Expense> expenses;
    IncomeXMLFile incomeXMLFile;
    ExpenseXMLFile expenseXMLFile;
    DateOperations dateOperations;

Income setNewIncomeData();
Expense setNewExpenseData();
string numberDateToStringDateConversion(int date);
int stringDateToIntDateConversion(string date);
string changeCommaToDot(string word);
void showCurrentMonthIncome(vector <Income> incomes);
void showCurrentMonthExpense(vector <Expense> expenses);
void showPreviousMonthIncome(vector <Income> incomes);
void showPrevoiusMonthExpense(vector <Expense> expenses);
void showSelectedPeriodIncome(vector <Income> incomes, string DateFrom, string DateTo);
void showSelectedPeriodExpense(vector <Expense> expenses, string DateFrom, string DateTo);

public:
FinanceManager(int LOGGED_USER_ID)
    : loggedUserId(LOGGED_USER_ID)
    {
        incomeAmount = 0;
        expenseAmount = 0;
        incomes = incomeXMLFile.loadLoggedUserIncomesFromXMLFile(loggedUserId);
        expenses = expenseXMLFile.loadLoggedUserExpensesFromXMLFile(loggedUserId);
    };
void addIncome();
void addExpense();
void currentMonthBalance();
void prevoiusMonthBalance();
void selectedPeriodBalance();


};

#endif
