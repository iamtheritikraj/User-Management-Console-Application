//This file is a dll project file.
#include "pch.h"
#include "UserManager.h"
#include <iostream>
#include <algorithm>

using namespace std;

namespace UserManager {
    vector<User> users;

    void CreateUser(const string& username, const string& password, const string& description) {

        if (username.empty() || password.empty() || description.empty()) {
            cout << "All fields are requied !!\n";
            cout << endl;
            return;
        }
        for (const auto& user : users)
        {
            if (user.username == username)
            {
                cout << "User '" << username << "' already exists\n";
                cout << endl;
                return;
            }
        }
        users.push_back({ username, password, description, false });
        cout << "User '" << username << "' created successfully.\n";
        cout << endl;

    }

    vector<User> ListAllUsers() {
        return users;
    }

    void ModifyUserPassword(const string& username, const string& newPassword) {
        for (auto& user : users)
        {
            if (user.username == username)
            {
                user.password = newPassword;
                cout << "Password for user '" << username << "' modified successfully.\n";
                cout << endl;
            }

        }
    }

    void ModifyUserDescription(const string& username, const string& newDescription) {
        for (auto& user : users)
        {
            if (user.username == username)
            {
                user.description = newDescription;
                cout << "Description for user '" << username << "' modified successfully.\n";
                cout << endl;
            }
        }
    }

    void LoginUser(const string& username, const string& password) {
        for (auto& user : users)
        {
            if (user.username == username)
            {
                if (user.password == password)
                {
                    user.loggedIn = true;
                    cout << username << " logged in successfully \n";
                    cout << endl;
                }
                else
                {
                    cout << "Wrong password\n";
                    cout << endl;
                }
            }
            else
            {
                cout << "Inavlid username\n";
                cout << endl;

            }
        }
    }
    void LogoutUser(const string& username) {
        for (auto& user : users)
        {
            if (username == user.username)
            {
                user.loggedIn = false;
                cout << "User successfully logged out\n";
                cout << endl;
                return;
            }
        }
        cout << "Invalid username!!\n" << endl;
    }
    vector<string> DisplayLoggedInUsers() {
        vector<string> loggedInUsers;
        for (const auto& user : users) {
            if (user.loggedIn) {
                loggedInUsers.push_back(user.username);
            }
        }
        return loggedInUsers;
    }
    void DeleteUser(const string& username) {
        for (size_t i = 0; i < users.size(); ++i) {
            if (users[i].username == username) {
                users.erase(users.begin() + i);
                cout << "User '" << username << "' deleted successfully.\n";
                cout << endl;
                return;
            }
        }
        cout << "Error: User '" << username << "' not found.\n";
        cout << endl;
    }
    bool LoggedInStatus(const string& username)
    {
        for (int i = 0;i < users.size();i++)
        {
            if (users[i].username == username && users[i].loggedIn == true)
            {
                return true;
            }
        }
        return false;
    }
    bool LoggedInStatus()
    {
        for (const auto& user : users)
        {
            if (user.loggedIn == true)
            {
                return true;
            }
        }
        return false;
    }
    bool Pass_Length(const string& password)
    {
        if (password.length() >= 8)
        {
            return true;
        }
        else
        {
            return false;
        }

    }
}



