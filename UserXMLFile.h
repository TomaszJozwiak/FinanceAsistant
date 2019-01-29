#ifndef USERXMLFILE_H
#define USERXMLFILE_H

#include <iostream>
#include <vector>

#include "Markup.h"
#include "User.h"
#include "HelpingMethods.h"

using namespace std;

class UserXMLFile
{
    string fileWithUsersName;

public:
    UserXMLFile()
    {
        fileWithUsersName = "users.xml";
    };
    void addSingleUserToFile(User user);
    vector <User> loadUsersFromXMLFile();
    void changeUserPassword(int loggedUserId, string newPassword);

};

#endif
