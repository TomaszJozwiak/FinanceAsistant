#ifndef YOURFINANCES_H
#define YOURFINANCES_H

#include <iostream>

#include "UserManager.h"
#include "FinanceManager.h"

using namespace std;

class YourFinances
{
    UserManager userManager;
    FinanceManager *financeManager;

public:

     YourFinances(){financeManager = NULL;};
    ~YourFinances()
    {
        delete financeManager;
        financeManager = NULL;
    }

    void registration();
    void login();
    void changePassword();
    void logout();
    void addIncome();
    void addExpense();
    void currentMonthBalance();
    void previousMonthBalance();
    void selectedPeriodBalance();
    char chooseOptionFromMainMenu();
    char chooseOptionFromFinanceMenu();
    bool userIsLoggedId();
};

#endif
