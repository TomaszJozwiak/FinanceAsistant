#include "IncomeXMLFile.h"

void IncomeXMLFile::addSingleIncomeToFile(Income income)
{
    CMarkup xml;
    xml.Load(fileWithIncomesName);
    xml.AddElem("Income");
    xml.IntoElem();
    xml.AddElem("incomeId", income.getIncomeId());
    xml.AddElem("userId", income.getUserId());
    xml.AddElem("date", income.getDate());
    xml.AddElem("item", income.getItem());
    xml.AddElem("amount", income.getAmount());
    xml.Save(fileWithIncomesName);
    lastIncomeId++;
}


vector <Income> IncomeXMLFile::loadLoggedUserIncomesFromXMLFile(int userId)
{
    Income income;
    vector <Income> incomes;

    CMarkup xml;
    xml.Load(fileWithIncomesName);
        while (xml.FindElem("Income"))
        {
            xml.IntoElem();
            xml.FindElem("incomeId");
            lastIncomeId = HelpingMethods::stringToIntConversion(xml.GetData());
            xml.FindElem("userId");
            if (userId == HelpingMethods::stringToIntConversion(xml.GetData()))
            {
                xml.FindElem("userId");
                income.setUserId(HelpingMethods::stringToIntConversion(xml.GetData()));
                xml.FindElem("incomeId");
                income.setIncomeId(HelpingMethods::stringToIntConversion(xml.GetData()));
                xml.FindElem("date");
                income.setDate(HelpingMethods::stringToIntConversion(xml.GetData()));
                xml.FindElem("item");
                income.setItem(xml.GetData());
                xml.FindElem("amount");
                income.setAmount(xml.GetData());

                incomes.push_back(income);
                xml.OutOfElem();
            }
            else
                xml.OutOfElem();
        }

    return incomes;
}

int IncomeXMLFile::getLastIncomeId()
{
    return lastIncomeId;
}
