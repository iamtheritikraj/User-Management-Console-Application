#include <iostream>
#include "UserManager.h"

using namespace std;


int main() {
    int option;
    string username, password, description, newPassword, newDescription;

    while (true)
    {
        cout << "\nWelcome to the User Management Application\n";
        cout << endl;
        cout << "Choose Option\n";
        cout << endl;
        cout << "1) Create User\n";
        cout << "2) List all created Users\n";
        cout << "3) Modify User Password\n";
        cout << "4) Modify User Description\n";
        cout << "5) Login\n";
        cout << "6) Logout\n";
        cout << "7) Display logged in users\n";
        cout << "8) Delete User\n";
        cout << "0) Exit\n";
        cout << endl;
        cout << "Enter your choice: ";
        cin >> option;

        switch (option) {
        case 1:
            cout << "\nEnter username: ";
            cin >> username;
            cout << "\nEnter password: ";
            cin >> password;
            if (UserManager::Pass_Length(password))
            {
                cout << "\nEnter description: ";
                cin.ignore();
                getline(cin, description);
                UserManager::CreateUser(username, password, description);
            }
            else
            {
                cout << "Password length should be of miniumum 8 characters\n ";
                cout << endl;
            }
            break;

        case 2: {
            auto users = UserManager::ListAllUsers();
            cout << "\nList of all users:";
            cout << endl;
            for (const auto& user : users) {
                cout << "Username: " << user.username << ", Description: " << user.description << "";
            }
            break;
        }

        case 3:
        {
            cout << "\nEnter username to modify password: ";
            cin >> username;
            bool status = UserManager::LoggedInStatus(username);
            if (status == true)
            {
                cout << "\nEnter new password: ";
                cin >> newPassword;
                {
                    if (UserManager::Pass_Length(password))
                    {
                        UserManager::ModifyUserPassword(username, newPassword);
                        UserManager::LogoutUser(username);
                    }
                    else
                    {
                        cout << "Password length should be of miniumum 8 characters\n ";
                        cout << endl;
                    }

                }
            }
            else
            {
                cout << "\nUser not logged in or Invalid user";
                cout << endl;
            }
            break;
        }
        case 4:
        {
            cout << "\nEnter username to modify description: ";
            cin >> username;
            bool status = UserManager::LoggedInStatus(username);
            if (status == true)
            {
                cout << "\nEnter new description: ";
                cin.ignore();
                getline(cin, newDescription);
                UserManager::ModifyUserDescription(username, newDescription);
                UserManager::LogoutUser(username);
            }
            else
            {
                cout << "\nUser not logged in or Invalid user";
                cout << endl;
            }
            break;
        }
        case 5:
        {
            if (!UserManager::LoggedInStatus())
            {
                cout << "\nEnter username: ";
                cin >> username;
                cout << "\nEnter password: ";
                cin >> password;
                UserManager::LoginUser(username, password);
            }
            else
            {
                cout << "\nAnother user logged in";
                cout << endl;
            }
            break;
        }
        case 6:
        {
            if (UserManager::LoggedInStatus())
            {
                cout << "\nEnter username to logout: ";
                cin >> username;
                UserManager::LogoutUser(username);
            }
            else
            {
                cout << "\nNo user logged in";
                cout << endl;
            }
            break;
        }

        case 7: {
            auto loggedInUsers = UserManager::DisplayLoggedInUsers();
            {
                if (loggedInUsers.empty())
                {
                    cout << "User is not logged in\n";
                    cout << endl;
                }
                else
                {
                    cout << "\nLogged in users: ";
                    cout << endl;
                    for (const auto& user : loggedInUsers) {
                        cout << user << "";
                    }

                }
            }
            break;
        }
        case 8:
        {
            cout << "\nEnter Username: ";
            cin >> username;
            UserManager::DeleteUser(username);
            break;

        }
        case 0:
            cout << "\nExiting...";
            return 0;

        default:
            cout << "\nInvalid choice......";
            break;
        }
    }

}
