# User-Management-Console-Application

## Introduction:
This User Management Console Application is a C++ program that allows users to create, modify, and manage user accounts. The application uses Dynamic Link Libraries (DLLs) for modularity, ensuring a clean separation of functionalities and ease of maintenance.

## Features:
1. **Create User**: Allows creating a new user by providing a username, password, and description. All fields are mandatory.
2. **List All Users**: Lists all created users with their username, description, and login status.
3. **Modify User Details**: Allows modifying the password or description of an existing user.
4. **Login**: Logs in a user by validating the username and password.
5. **Logout**: Logs out a user.
6. **Display Logged-In User**: Displays the currently logged-in user.
7. **Delete User**: Allows deleting registered users.

## Hidden Features:
1. To log in with new user credentials, the currently logged-in user must first log out.
2. Password length must be a minimum of 8 characters.
3. While modifying the password, it must also be a minimum of 8 characters.
4. The user must be logged in first to modify details.

## Modularity with DLLs:
The application leverages DLLs to separate various functionalities into distinct modules. This enhances code organization and allows for independent development and testing of each module. The following functionalities are encapsulated within DLLs:

1. **User Management**: A DLL responsible for creating, listing, and deleting users.
2. **Authentication**: A DLL dedicated to handling login and logout operations.
3. **User Details Modification**: A DLL for modifying user details such as password and description.

