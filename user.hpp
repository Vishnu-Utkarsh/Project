#ifndef USER
#define USER

#include "Template.hpp"

struct User
{
private:
    int rating;
    std::string username, password;

public:
    // constructor
    User();
    User(const std::string &name, const std::string &pass);
    User(const std::string &name, const std::string &pass, int rate);

    // getters
    std::string getusername();
    std::string getpassword();
    int getrating();

    // authentication
    bool checkPassword(const std::string &password);

    // change rating
    void updateRating(int rating);
};

// forward declaration
User::User() {}
User::User (const std::string &name, const std::string &pass) : username(name), password(pass), rating(0) {}
User::User (const std::string &name, const std::string &pass, int rating) : username(name), password(pass), rating(rating) {}

std::string User::getusername() { return username; }
std::string User::getpassword() { return password; }
int User::getrating() { return rating; }

bool User::checkPassword(const std::string &password) { return password == this -> password; }

void User::updateRating(int rating) { this -> rating = rating; }


void _print(User user)
    {   cerr << user.getusername() << " : " << user.getpassword() << " - " << user.getrating();}
void print(User user)
    {   cout << user.getrating();}

#endif