#include "ExpenseXMLFile.h"

void ExpenseXMLFile::addSingleExpenseToFile(Expense expense)
{
    CMarkup xml;
    xml.Load(fileWithExpensesName);
    xml.AddElem("Expense");
    xml.IntoElem();
    xml.AddElem("expenseId", expense.getExpenseId());
    xml.AddElem("userId", expense.getUserId());
    xml.AddElem("date", expense.getDate());
    xml.AddElem("item", expense.getItem());
    xml.AddElem("amount", expense.getAmount());
    xml.Save(fileWithExpensesName);
    lastExpenseId++;
}


vector <Expense> ExpenseXMLFile::loadLoggedUserExpensesFromXMLFile(int userId)
{
    Expense expense;
    vector <Expense> expenses;

    CMarkup xml;
    xml.Load(fileWithExpensesName);
        while (xml.FindElem("Expense"))
        {
            xml.IntoElem();
            xml.FindElem("expenseId");
            lastExpenseId = HelpingMethods::stringToIntConversion(xml.GetData());
            xml.FindElem("userId");
            if (userId == HelpingMethods::stringToIntConversion(xml.GetData()))
            {
                xml.FindElem("userId");
                expense.setUserId(HelpingMethods::stringToIntConversion(xml.GetData()));
                xml.FindElem("expenseId");
                expense.setExpenseId(HelpingMethods::stringToIntConversion(xml.GetData()));
                xml.FindElem("date");
                expense.setDate(HelpingMethods::stringToIntConversion(xml.GetData()));
                xml.FindElem("item");
                expense.setItem(xml.GetData());
                xml.FindElem("amount");
                expense.setAmount(xml.GetData());

                expenses.push_back(expense);
                xml.OutOfElem();
            }
            else
                xml.OutOfElem();
        }

    return expenses;
}

int ExpenseXMLFile::getLastExpenseId()
{
    return lastExpenseId;
}
