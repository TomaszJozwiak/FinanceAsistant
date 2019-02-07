#include "UserManager.h"

void UserManager::registration()
{
    User user = setNewUserData();

    users.push_back(user);
    userXMLFile.addSingleUserToFile(user);
    cout << endl << "Konto zalozono pomyslnie" << endl << endl;
    system("pause");
}

void UserManager::login()
{
    User user;
    string login = "", password = "";

    system("cls");
    cout << endl << "Podaj login: ";
    cin >> login;

    for (int i = 0; i < users.size(); i++)
    {
        if (users[i].getLogin() == login)
        {
            for (int attempts = 3; attempts > 0; attempts--)
            {
                cout << "Podaj haslo. Pozostalo prob: " << attempts << ": ";
                cin >> password;

                if (users[i].getPassword() == password)
                {
                    cout << endl << "Zalogowales sie." << endl << endl;
                    system("pause");
                    loggedUserId = users[i].getId();
                    return;
                }
            }
            cout << "Wprowadzono 3 razy bledne haslo." << endl;
            system("pause");
            loggedUserId = 0;
            return;
        }
    }
    cout << "Nie ma uzytkownika z takim loginem" << endl << endl;
    system("pause");
    loggedUserId = 0;
    return;
}

User UserManager::setNewUserData()
{
    User user;

    user.setId(getNewUserId());

    string login;
    system("cls");
    do
    {
        cout <<  "Podaj login: ";
        cin >> login;
        user.setLogin(login);
    }
    while (loginExists(user.getLogin()) == true);

    string password;
    cout << "Podaj haslo: ";
    cin >> password;
    user.setPassword(password);

    cin.sync();
    cout << "Podaj imie: ";
    user.setName(HelpingMethods::loadLine());

    cout << "Podaj nazwisko: ";
    user.setSurname(HelpingMethods::loadLine());


    return user;
}

int UserManager::getNewUserId()
{
    if (users.empty() == true)
        return 1;
    else
        return users.back().getId() + 1;
}

bool UserManager::loginExists(string login)
{
    for (int i = 0; i < users.size(); i++)
    {
        if (users[i].getLogin() == login)
        {
            cout << endl << "Istnieje uzytkownik o takim loginie." << endl;
            return true;
        }
    }
    return false;
}


void UserManager::changePassword()
{
    string newPassword = "";
    cout << "Podaj nowe haslo: ";
    cin >> newPassword;

    for (int i = 0; i < users.size(); i++)
    {
        if (users[i].getId() == loggedUserId)
        {
            users[i].setPassword(newPassword);
            cout << "Haslo zostalo zmienione." << endl << endl;
            system("pause");
        }
    }
    userXMLFile.changeUserPassword(loggedUserId, newPassword);
}

void UserManager::logout()
{
    loggedUserId = 0;
    cout << "Wylogowano pomyslnie";
}

bool UserManager::userLoggedIn()
{
    if (loggedUserId > 0)
        return true;
    else
        return false;
}

int UserManager::getLoggedUserId()
{
    return loggedUserId;
}
