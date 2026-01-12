#include "Template.hpp"
#include "storage.hpp"

#include <vector>
#include <iostream>
#include <sstream>
#include <fstream>

// show all users
void displayUserData()
{
    cout << "Username Rating" << endl;
    print(users);
}

// read from CSV file
void readUserData(const std::string &filename)
{
    std::ifstream file(filename);
    std::string line;

    if (!file.is_open())
    {
        std::cerr << "Error: Could not open user data." << std::endl;
        return;
    }

    while (std::getline(file, line))
    {
        std::stringstream ss(line);
        std::string field;
        std::vector<std::string> row_fields;

        // Split the line into fields using comma as delimiter
        while (std::getline(ss, field, ','))
            row_fields.push_back(field);

        // Process the data
        if (row_fields.empty())
            continue;

        int rating = stoi(row_fields[2]);
        string username = row_fields[0], password = row_fields[1];

        users[username] = User(username, password, rating);
    }

    file.close();
    std::cerr << "CSV file imported and data readed successfully." << std::endl;
    return;
}

// save to CSV file
void saveUserData(const std::string &filename)
{
    std::ofstream file;
    file.open(filename);

    if (!file.is_open())
    {
        std::cerr << "Error: Could not open file for writing." << std::endl;
        return;
    }

    for (auto &user : users)
    {
        User data = user.second;
        int rating = data.getrating();
        string username = data.getusername(), password = data.getpassword();

        file << username << ',' << password << ',' << rating << std::endl;
    }

    file.close();
    std::cerr << "CSV file created and data written successfully." << std::endl;
    return;
}

// Create Account
void createAccount()
{
    string username, password;

    while(true)
    {
        std::cout << std::endl
            << "Enter new username: ";
        std::cin >> username;

        if(! users.count(username))
            break;

        std::cout << std::endl
                  << "Username Already exist" << std::endl
                  << "Try Again !" << std::endl;
    }

    std::cout << std::endl
         << "Create password: ";
    std::cin >> password;

    User user(username, password);
    debug(user);
    users[username] = User(username, password);
}

// User Login
void userLogin()
{
    
}