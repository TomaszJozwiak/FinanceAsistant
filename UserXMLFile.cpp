#include "UserXMLFile.h"

void UserXMLFile::addSingleUserToFile(User user)
{
    CMarkup xml;
    xml.Load(fileWithUsersName);
    xml.AddElem("User");
    xml.IntoElem();
    xml.AddElem("userId", user.getId());
    xml.AddElem("login", user.getLogin());
    xml.AddElem("password", user.getPassword());
    xml.AddElem("name", user.getName());
    xml.AddElem("surname", user.getSurname());
    xml.Save(fileWithUsersName);
}


vector <User> UserXMLFile::loadUsersFromXMLFile()
{
    User user;
    vector <User> users;

    CMarkup xml;
    xml.Load(fileWithUsersName);
    while (xml.FindElem("User"))
    {
        xml.IntoElem();
        xml.FindElem("userId");
        user.setId(HelpingMethods::stringToIntConversion(xml.GetData()));
        xml.FindElem("login");
        user.setLogin(xml.GetData());
        xml.FindElem("password");
        user.setPassword(xml.GetData());
        xml.FindElem("name");
        user.setName(xml.GetData());
        xml.FindElem("surname");
        user.setSurname(xml.GetData());
        xml.OutOfElem();

        users.push_back(user);
    }

    return users;
}


void UserXMLFile::changeUserPassword(int loggedUserId, string newPassword)
{
    CMarkup xml;
    xml.Load(fileWithUsersName);
    while (xml.FindElem("User"))
    {
        xml.IntoElem();
        xml.FindElem("userId");
        if (HelpingMethods::stringToIntConversion(xml.GetData()) == loggedUserId)
        {
            xml.FindElem("password");
            xml.RemoveElem();
            xml.AddElem("password", newPassword);
        }
        xml.OutOfElem();
    }
    xml.Save(fileWithUsersName);
}
