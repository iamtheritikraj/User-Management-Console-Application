#include <iostream>
#include <string>
#include<vector>
#include<algorithm>
using namespace std;
class User
{
public:
    string username;
    string password;
    string description;
    bool isloggedIn;
    User(string uname, string pwd, string desc)
    {
        username = uname;
        password = pwd;
        description = desc;
        isloggedIn = false;
    }
};

class UserManager
{
private:
    vector<User> users;
public:
    void createUser()
    {
        string username;
        string password;
        string description;
        cout <<"All fields are mandatory:"<<endl;
        cout << "Enter Username: ";
        getline(cin, username);
        cout << endl;
        bool pass = false;
        while (!pass)
        {
            cout << "Enter Password: ";
            getline(cin, password);
            if (!(password.length() >= 8))
            {
                cout << "Password length should be of minimum 8 characters. \n";
            }
            else
            {
                pass = true;
            }

        }
        cout << endl;
        cout << "Enter Decription: ";
        getline(cin, description);
        cout << endl;
        if (username.empty() || password.empty() || description.empty())
        {
            cout << "!! All Fields are required !! \n";
        }
        else
        {
            users.push_back(User(username, password, description));
            cout << username + ": User registered successfully!!\n";
        }

    }
    void listUsers()
    {
        for (const auto& user : users) {
            cout << "Total created users\n";
            cout << "Username: " << user.username << ", Description: " << user.description << ", Logged In: " << (user.isloggedIn ? "Yes" : "No") << "\n";
        }
    }
    void modifyDetails()
    {
        string username;
        cout << "Enter username to modify password/decription \n";
        getline(cin, username);
        for (auto& user : users) {
            if (user.username == username&&user.isloggedIn==true) 
            {
                int option;
                cout << "1. Modify password\n";
                cout << "2. Modify description\n";
                cout << "3. Exit\n";
                cout << "Choose Option: ";
                cin >> option;
                cin.ignore();
                cout << endl;
                switch (option) {
                case 1 : {
                    bool pass = false;
                    while (!pass)
                    {
                        cout << "Enter Password: ";
                        getline(cin, user.password);
                        if (!(user.password.length() >= 8))
                        {
                            cout << "Password length should be of minimum 8 characters. \n";
                        }
                        else
                        {
                            pass = true;
                        }
                    }
                    cout << "Password modified successfully!\n";
                    user.isloggedIn = false;
                    break;
                }
                case 2 : {
                    cout << "Enter new description: ";
                    getline(cin, user.description);
                    cout << "Description modified successfully!\n";
                    user.isloggedIn = false;
                    break;
                }
                case 3:
                    return;
                default:
                    cout << "Invalid option!\n";
                    break;
                }
                return;
            }
        }
        cout << "User not logged in \n";
        
    }
    void loginUser()
    {
        bool logged_user = check_loggedStatus();
        if (!logged_user)
        {
            string username;
            string password;
            cout << "Enter Username: ";
            getline(cin, username);
            for (auto& user : users)
            {
                if (username == user.username)
                {
                    cout << "Enter Password: ";
                    getline(cin, password);
                    if (user.password == password)
                    {
                        user.isloggedIn = true;
                        cout << username + " successfully logged in \n";
                        
                    }
                    else
                    {
                        cout << "Wrong password\n";
                    }
                    return;
                }
            }
            cout << "Invalid username!!\n";
        }
        else
        {
            cout << "Another user already logged in\n";
        }
        
    }
    void logoutUser()
    {
        bool logged_user = check_loggedStatus();
        if (logged_user)
        {
            string username;
            cout << "Enter username: ";
            getline(cin, username);
            for (auto& user : users)
            {
                if (username == user.username)
                {
                    user.isloggedIn = false;
                    cout << "User successfully logged out\n";
                    return;
                }
            }
            cout << "Invalid username!!\n";
        }
    }
    bool check_loggedStatus()
    {
        for (const auto& user : users) {
            if (user.isloggedIn) {
                return true;
            }
            
        }
        return false;
    }
    void loggedInUser()
    {
        for (const auto& user : users) {
            if (user.isloggedIn) {
                cout << "Logged in user: " << user.username << "\n";
                return;
            }
        }
        cout << "Currently no users is logged in\n";
    }
};

int main()
{
    UserManager userManager;
    cout << "Welcome to the User Management Application" << endl;
    cout << "Choose Option" << endl;
    int option;
    while (true) {
        cout << "\nOptions:\n";
        cout << "1. Create User\n";
        cout << "2. List all created Users\n";
        cout << "3. Modify User\n";
        cout << "4. Login\n";
        cout << "5. Logout\n";
        cout << "6. Display logged in users\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> option;
        cin.ignore();
        cout << endl;

        switch (option) {
        case 1:
            userManager.createUser();
            break;
        case 2:
            userManager.listUsers();
            break;
        case 3:
            userManager.modifyDetails();
            break;
        case 4:
            userManager.loginUser();
            break;
        case 5:
            userManager.logoutUser();
            break;
        case 6:
            userManager.loggedInUser();
            break;
        case 7:
            return 0;
        default:
            cout << "Invalid choice! Please try again.\n";
        }
    }
}