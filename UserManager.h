#ifndef USERMANAGER_H
#define USERMANAGER_H

#include <iostream>
#include <vector>
#include <windows.h>
#include <fstream>
#include <sstream>

#include "User.h"
#include "UserXMLFile.h"

using namespace std;

class UserManager
{
    int loggedUserId;
    vector <User> users;
     UserXMLFile userXMLFile;

    User setNewUserData();
    int getNewUserId();
    bool loginExists(string login);

public:
        UserManager()
        {
        loggedUserId = 0;
        users = userXMLFile.loadUsersFromXMLFile();
        };
    void registration();
    void login();
    void changePassword();
    void logout();
    bool loginExists();
    int getLoggedUserId();
    bool userLoggedIn();
};

#endif
