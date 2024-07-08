//This file is a dll project file.
#ifndef USER_MANAGER_H
#define USER_MANAGER_H

#include <string>
#include <vector>

#ifdef USERMANAGER_EXPORTS
#define USERMANAGER_API __declspec(dllexport)
#else
#define USERMANAGER_API __declspec(dllimport)
#endif
using namespace std;
namespace UserManager {
    class User {
    public:
        string username;
        string password;
        string description;
        bool loggedIn;
    };

    // Function declarations
    USERMANAGER_API void CreateUser(const string& username, const string& password, const string& description);
    USERMANAGER_API vector<User> ListAllUsers();
    USERMANAGER_API void ModifyUserPassword(const string& username, const string& newPassword);
    USERMANAGER_API void ModifyUserDescription(const string& username, const string& newDescription);
    USERMANAGER_API void LoginUser(const string& username, const string& password);
    USERMANAGER_API void LogoutUser(const string& username);
    USERMANAGER_API vector<string> DisplayLoggedInUsers();
    USERMANAGER_API void DeleteUser(const string& username);
    USERMANAGER_API bool LoggedInStatus(const string& username);
    USERMANAGER_API bool LoggedInStatus();
    USERMANAGER_API bool Pass_Length(const string& password);
}

#endif // USER_MANAGER_H
