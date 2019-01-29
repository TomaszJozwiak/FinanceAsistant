#ifndef YOURFINANCES_H
#define YOURFINANCES_H

#include <iostream>

#include "UserManager.h"
//#include "FinanceManager.h"

using namespace std;

class YourFinances
{
    UserManager userManager;

public:

    void registration();
    void login();
    void changePassword();
    void logout();
};

#endif
