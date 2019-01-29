#include "YourFinances.h"

void YourFinances::registration()
{
    userManager.registration();
}

void YourFinances::login()
{
    userManager.login();
    // tutaj bedzie financemenad¿er
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
}
