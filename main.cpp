#include <iostream>
#include "YourFinances.h"

using namespace std;

int main()
{
    YourFinances yourFinances;
    char choice;

    while (true)
    {
        if (yourFinances.userIsLoggedId())
        {
            choice = yourFinances.chooseOptionFromMainMenu();

            switch (choice)
            {
            case '1':
                yourFinances.registration();
                break;
            case '2':
                yourFinances.login();
                break;
            case '9':
                exit(0);
                break;
            default:
                cout << endl << "Nie ma takiej opcji w menu." << endl << endl;
                system("pause");
                break;
            }
        }
        else
        {
            choice = yourFinances.chooseOptionFromFinanceMenu();

            switch (choice)
            {
            case '1':
                yourFinances.addIncome();
                break;
            case '2':
                yourFinances.addExpense();
                break;
            case '3':
                yourFinances.currentMonthBalance();
                break;
            case '4':
                yourFinances.previousMonthBalance();
                break;
            case '5':
                yourFinances.selectedPeriodBalance();
                break;
            case '6':
                yourFinances.changePassword();
                break;
            case '7':
                yourFinances.logout();
                break;
            }
        }
    }

    return 0;
}
