#include "Template.hpp"
#include "storage.hpp"

#include <vector>
#include <iostream>
#include <sstream>
#include <fstream>

void displayUserData()
{
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

    // vacantID.reserve(1e5 + 1);
    for (int i = 1; i <= 1e5; i++)
        vacantID.insert(i);

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

        int userID = stoi(row_fields[0]), rating = stoi(row_fields[3]);
        string username = row_fields[1], password = row_fields[2];

        vacantID.erase(userID);
        users[userID] = User(userID, username, password, rating);
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
        int userID = user.first, rating = user.second.getrating();
        string username = user.second.getusername(), password = user.second.getpassword();

        file << userID << ',' << username << ',' << password << ',' << rating << std::endl;
    }

    file.close();
    std::cerr << "CSV file created and data written successfully." << std::endl;
    return;
}

void createAccount()
{
    int userID = *vacantID.begin();
    vacantID.erase(vacantID.begin());
    string username, password;

    cout << std::endl
         << "Enter new username: ";
    std::cin >> username;

    cout << std::endl
         << "Create password: ";
    std::cin >> password;

    cout << std::endl
         << "Your userID is: " << userID;

    User user(userID, username, password);
    debug(user);
    users[userID] = User(userID, username, password);
}