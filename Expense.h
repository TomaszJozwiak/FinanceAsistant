#ifndef EXPENSE_H
#define EXPENSE_H

#include <iostream>

using namespace std;

class Expense
{
    int expenseId;
    int userId;
    int date;
    string item;
    string amount;

public:
    int getExpenseId();
    int getUserId();
    int getDate();
    string getItem();
    string getAmount();


    void setExpenseId(int newExpenseId);
    void setUserId(int newUserId);
    void setDate(int newDate);
    void setItem(string newItem);
    void setAmount(string newAmount);

    bool operator <(const Expense& rhs)
    {
        return date < rhs.date;
    };
};
#endif
