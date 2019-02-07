#include "YourFinances.h"

void YourFinances::registration()
{
    userManager.registration();
}

void YourFinances::login()
{
    userManager.login();
    if (userManager.userLoggedIn())
    {
        financeManager = new FinanceManager(userManager.getLoggedUserId());
    }
}

void YourFinances::changePassword()
{
    if (userManager.userLoggedIn())
    {
        userManager.changePassword();
    }
    else
    {
        cout << "Aby zmienic haslo nalezy sie zalogowac" << endl;
        system("pause");
    }
}

void YourFinances::logout()
{
    userManager.logout();
    delete financeManager;
    financeManager = NULL;

}

void YourFinances::addIncome()
{
    if (userManager.userLoggedIn())
    {
        financeManager->addIncome();
    }
    else
    {
        cout << "Aby dodac przychod nalezy sie zalogowac" << endl;
        system("pause");
    }
}

void YourFinances::addExpense()
{
    if (userManager.userLoggedIn())
    {
        financeManager->addExpense();
    }
    else
    {
        cout << "Aby dodac przychod nalezy sie zalogowac" << endl;
        system("pause");
    }
}

void YourFinances::currentMonthBalance()
{
    if (userManager.userLoggedIn())
    {
        financeManager->currentMonthBalance();
    }
    else
    {
        cout << "Aby wyswietlic bilans nalezy sie zalogowac" << endl;
        system("pause");
    }
}

void YourFinances::previousMonthBalance()
{
    if (userManager.userLoggedIn())
    {
        financeManager->prevoiusMonthBalance();
    }
    else
    {
        cout << "Aby wyswietlic bilans nalezy sie zalogowac" << endl;
        system("pause");
    }
}

void YourFinances::selectedPeriodBalance()
{
    if (userManager.userLoggedIn())
    {
        financeManager->selectedPeriodBalance();
    }
    else
    {
        cout << "Aby wyswietlic bilans nalezy sie zalogowac" << endl;
        system("pause");
    }
}

char YourFinances::chooseOptionFromMainMenu()
{
    char choice;

    system("cls");
    cout << "    >>> MENU  GLOWNE <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Rejestracja" << endl;
    cout << "2. Logowanie" << endl;
    cout << "9. Koniec programu" << endl;
    cout << "---------------------------" << endl;
    cout << "Twoj wybor: ";
    choice = HelpingMethods::loadSign();

    return choice;
}

char YourFinances::chooseOptionFromFinanceMenu()
{
    char choice;

    system("cls");
    cout << " >>> MENU UZYTKOWNIKA <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Dodaj przychod" << endl;
    cout << "2. Dodaj wydatek" << endl;
    cout << "3. Bilans z biezacego miesiaca" << endl;
    cout << "4. Bilans z poprzedniego miesiaca" << endl;
    cout << "5. Bilans z wybranego okresu" << endl;
    cout << "6. Zmien haslo" << endl;
    cout << "7. Wyloguj sie" << endl;
    cout << "---------------------------" << endl;
    cout << "Twoj wybor: ";
    choice = HelpingMethods::loadSign();

    return choice;
}

bool YourFinances::userIsLoggedId()
{
    if (userManager.getLoggedUserId() == 0)
        return true;
    else
        return false;
}

