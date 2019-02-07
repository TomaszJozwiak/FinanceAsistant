#include "FinanceManager.h"

void FinanceManager::addIncome()
{
    Income income;

    system("cls");
    cout << " >>> DODAWANIE PRZYCHODU <<<" << endl << endl;
    income = setNewIncomeData();

    incomes.push_back(income);
    incomeXMLFile.addSingleIncomeToFile(income);
}

Income FinanceManager::setNewIncomeData()
{
    string date;
    char choice;
    Income income;

    income.setIncomeId((incomeXMLFile.getLastIncomeId() + 1) );
    income.setUserId(loggedUserId);

    system("cls");
    cin.sync();
    cout << "Czy chcesz dodac przychod z dzisiaj? <t/n>" << endl;
    while (choice = HelpingMethods::loadSign())
    {
        if (choice == 't')
        {
            income.setDate (dateOperations.getActualDate() );
            break;
        }
        else if (choice == 'n')
        {
            cout << "Wprowadz date przychodu w formacie RRRR-MM-DD" << endl;
            cin >> date;
            if (date.length() == 10)
            {
                if (dateOperations.dateCorrect(stringDateToIntDateConversion(date)))
                {
                    income.setDate(stringDateToIntDateConversion(date));
                    break;
                }
                else
                {
                    cout << "Wprowadzono niepoprawna date - czy chcesz dodac przychod z dzisiaj? <t/n>: " << endl;
                    cin.sync();
                }
            }
            else
            {
                cout << "Wprowadzono niepoprawny format daty - czy chcesz dodac przychod z dzisiaj? <t/n>: ";
            }
        }
        else
        {
            cout << "Wprowadzono niepoprawny znak" << endl;
        }
    }

    cin.sync();
    cout << "Podaj zrodlo przychodu: ";
    income.setItem(HelpingMethods::loadLine());

    cout << "Podaj wysokosc przychodu: ";
    income.setAmount(changeCommaToDot(HelpingMethods::loadLine()));

    return income;
}

void FinanceManager::addExpense()
{
    Expense expense;

    system("cls");
    cout << " >>> DODAWANIE WYDATKU <<<" << endl << endl;
    expense = setNewExpenseData();

    expenses.push_back(expense);
    expenseXMLFile.addSingleExpenseToFile(expense);
}

Expense FinanceManager::setNewExpenseData()
{
    string date;
    char choice;
    Expense expense;

    expense.setExpenseId((expenseXMLFile.getLastExpenseId() + 1) );
    expense.setUserId(loggedUserId);

    system("cls");
    cin.sync();
    cout << "Czy chcesz dodac wydatek z dzisiaj? <t/n>" << endl;
    while (choice = HelpingMethods::loadSign())
    {
        if (choice == 't')
        {
            expense.setDate (dateOperations.getActualDate() );
            break;
        }
        else if (choice == 'n')
        {
            cout << "Wprowadz date wydatku w formacie RRRR-MM-DD" << endl;
            cin >> date;

            if (date.length() == 10)
            {
                if (dateOperations.dateCorrect(stringDateToIntDateConversion(date)))
                {
                    expense.setDate(stringDateToIntDateConversion(date));
                    break;
                }
                else
                {
                    cout << "Wprowadzono niepoprawna date - czy chcesz dodac wydatek z dzisiaj? <t/n>: " << endl;
                    cin.sync();
                }
            }
            else
            {
                cout << "Wprowadzono niepoprawny format daty - czy chcesz dodac wydatek z dzisiaj? <t/n>: ";
            }
        }
        else
        {
            cout << "Wprowadzono niepoprawny znak" << endl;
        }
    }

    cin.sync();
    cout << "Podaj zrodlo wydatku: ";
    expense.setItem(HelpingMethods::loadLine());

    cout << "Podaj wysokosc wydatku: ";
    expense.setAmount(changeCommaToDot(HelpingMethods::loadLine()));

    return expense;
}

string FinanceManager::numberDateToStringDateConversion(int date)
{
    string newFormatDate;
    newFormatDate = HelpingMethods::intToStringConversion(date);
    newFormatDate.insert(4, "-");
    newFormatDate.insert(7, "-");
    return newFormatDate;
}

int FinanceManager::stringDateToIntDateConversion(string date)
{
    int newFormatDate;
    date.erase(7, 1);
    date.erase(4, 1);
    newFormatDate = HelpingMethods::stringToIntConversion(date);
    return newFormatDate;
}

string FinanceManager::changeCommaToDot(string word)
{
    for (int i=0; i < word.length(); i++)
    {
        if (word[i] == ',')
            word[i] = '.';
    }
    return word;
}

void FinanceManager::currentMonthBalance()
{
    sort (incomes.begin(), incomes.end());
    sort (expenses.begin(), expenses.end());

    system("cls");
    cout << "---BILANS Z BIEZACEGO MIESIACA---" << endl;
    showCurrentMonthIncome(incomes);
    cout << "--------------------" << endl;
    showCurrentMonthExpense(expenses);
    cout << "--------------------" << endl;
    cout << "Suma przychodow w biezacym miesiacu wysiosla: " << incomeAmount << endl;
    cout << "Suma wydatkow w biezacym miesiacu wysiosla: " << expenseAmount << endl;
    cout << "Bilans w biezacym miesiacu wynosi: " << incomeAmount - expenseAmount << endl;
    incomeAmount = 0;
    expenseAmount = 0;
    system("pause");
}

void FinanceManager::prevoiusMonthBalance()
{
    sort (incomes.begin(), incomes.end());
    sort (expenses.begin(), expenses.end());

    system("cls");
    cout << "---BILANS Z POPRZEDNIEGO MIESIACA---" << endl;
    showPreviousMonthIncome(incomes);
    cout << "--------------------" << endl;
    showPrevoiusMonthExpense(expenses);
    cout << "--------------------" << endl;
    cout << "Suma przychodow w poprzednim miesiacu wysiosla: " << incomeAmount << endl;
    cout << "Suma wydatkow w poprzednim miesiacu wysiosla: " << expenseAmount << endl;
    cout << "Bilans z poprzedniego miesiaca wynosi: " << incomeAmount - expenseAmount << endl;
    incomeAmount = 0;
    expenseAmount = 0;
    system("pause");
}

void FinanceManager::selectedPeriodBalance()
{
    sort (incomes.begin(), incomes.end());
    sort (expenses.begin(), expenses.end());
    string dateFrom = "";
    string dateTo = "";

    system("cls");
    cout << "Wprowadz date w formacie RRRR-MM-DD, od ktorej chcesz wyswietlic bilans" << endl;
    {
        while (cin >> dateFrom)
            if (dateFrom.length() == 10)
            {
                if (dateOperations.dateCorrect(stringDateToIntDateConversion(dateFrom)))
                {
                    break;
                }
                else
                {
                    cout << "Wprowadzono niepoprawna date - Wprowadz date w formacie RRRR-MM-DD, od ktorej chcesz wyswietlic bilans" << endl;
                    cin.sync();
                }
            }
            else
            {
                cout << "Wprowadzono niepoprawny format daty - Wprowadz date w formacie RRRR-MM-DD, od ktorej chcesz wyswietlic bilans" << endl;
            }
    }
    cout << "Wprowadz date w formacie RRRR-MM-DD, do ktorej chcesz wyswietlic bilans" << endl;
    {
        while (cin >> dateTo)
            if (dateTo.length() == 10)
            {
                if (dateOperations.dateCorrect(stringDateToIntDateConversion(dateTo)))
                {
                    break;
                }
                else
                {
                    cout << "Wprowadzono niepoprawna date - Wprowadz date w formacie RRRR-MM-DD, do ktorej chcesz wyswietlic bilans" << endl;
                    cin.sync();
                }
            }
            else
            {
                cout << "Wprowadzono niepoprawny format daty - Wprowadz date w formacie RRRR-MM-DD, do ktorej chcesz wyswietlic bilans" << endl;
            }
    }

    cout << "---BILANS Z OKRESU " << dateFrom << "  -  " << dateTo << "---" << endl;
    showSelectedPeriodIncome(incomes, dateFrom, dateTo);
    cout << "--------------------" << endl;
    showSelectedPeriodExpense(expenses, dateFrom, dateTo);
    cout << "--------------------" << endl;
    cout << "Suma przychodow w wybranym okresie wysiosla: " << incomeAmount << endl;
    cout << "Suma wydatkow w wybranym okresie wysiosla: " << expenseAmount << endl;
    cout << "Bilans z wybranego okresu wynosi: " << incomeAmount - expenseAmount << endl;
    incomeAmount = 0;
    expenseAmount = 0;
    system("pause");
}

void FinanceManager::showCurrentMonthIncome(vector <Income> incomes)
{
    int counter = 1;

    for (vector<Income>::iterator itr = incomes.begin(); itr != incomes.end(); itr ++)
    {
        if (dateOperations.isDateFromCurrentMonth(itr->getDate()))
        {
            cout << counter++ << ". " << numberDateToStringDateConversion(itr->getDate()) << " " <<
                 setw(35) << left << itr->getItem() << " " << itr->getAmount() << endl;
            incomeAmount = incomeAmount + HelpingMethods::stringToDoubleConversion(itr->getAmount());
        }
    }
}

void FinanceManager::showCurrentMonthExpense(vector <Expense> expenses)
{
    int counter = 1;

    for (vector<Expense>::iterator itr = expenses.begin(); itr != expenses.end(); itr ++)
    {
        if (dateOperations.isDateFromCurrentMonth(itr->getDate()))
        {
            cout << counter++ << ". " << numberDateToStringDateConversion(itr->getDate()) << " " <<
                 setw(35) << left << itr->getItem() << " " << itr->getAmount() << endl;
            expenseAmount = expenseAmount + HelpingMethods::stringToDoubleConversion(itr->getAmount());
        }
    }
}

void FinanceManager::showPreviousMonthIncome(vector <Income> incomes)
{
    int counter = 1;

    for (vector<Income>::iterator itr = incomes.begin(); itr != incomes.end(); itr ++)
    {
        if (dateOperations.isDateFromPreviousMonth(itr->getDate()))
        {
            cout << counter++ << ". " << numberDateToStringDateConversion(itr->getDate()) << " " <<
                 setw(35) << left << itr->getItem() << " " << itr->getAmount() << endl;
            incomeAmount = incomeAmount + HelpingMethods::stringToDoubleConversion(itr->getAmount());
        }
    }
}

void FinanceManager::showPrevoiusMonthExpense(vector <Expense> expenses)
{
    int counter = 1;

    for (vector<Expense>::iterator itr = expenses.begin(); itr != expenses.end(); itr ++)
    {
        if (dateOperations.isDateFromPreviousMonth(itr->getDate()))
        {
            cout << counter++ << ". " << numberDateToStringDateConversion(itr->getDate()) << " " <<
                 setw(35) << left << itr->getItem() << " " << itr->getAmount() << endl;
            expenseAmount = expenseAmount + HelpingMethods::stringToDoubleConversion(itr->getAmount());
        }
    }
}

void FinanceManager::showSelectedPeriodIncome(vector <Income> incomes, string DateFrom, string DateTo)
{
    int counter = 1;

    for (vector<Income>::iterator itr = incomes.begin(); itr != incomes.end(); itr ++)
    {
        if (itr->getDate() >= stringDateToIntDateConversion(DateFrom) && itr->getDate() <= stringDateToIntDateConversion(DateTo))
        {
            cout << counter++ << ". " << numberDateToStringDateConversion(itr->getDate()) << " " <<
                 setw(35) << left << itr->getItem() << " " << itr->getAmount() << endl;
            incomeAmount = incomeAmount + HelpingMethods::stringToDoubleConversion(itr->getAmount());
        }
    }
}

void FinanceManager::showSelectedPeriodExpense(vector <Expense> expenses, string DateFrom, string DateTo)
{
    int counter = 1;

    for (vector<Expense>::iterator itr = expenses.begin(); itr != expenses.end(); itr ++)
    {
        if (itr->getDate() >= stringDateToIntDateConversion(DateFrom) && itr->getDate() <= stringDateToIntDateConversion(DateTo))
        {
            cout << counter++ << ". " << numberDateToStringDateConversion(itr->getDate()) << " " <<
                 setw(35) << left << itr->getItem() << " " << itr->getAmount() << endl;
            expenseAmount = expenseAmount + HelpingMethods::stringToDoubleConversion(itr->getAmount());
        }
    }
}
