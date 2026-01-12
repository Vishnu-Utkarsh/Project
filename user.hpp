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


void _print(User user)
    {   cerr << user.getusername() << " : " << user.getpassword() << " - " << user.getrating();}
void print(User user)
    {   cout << user.getrating();}

#endif