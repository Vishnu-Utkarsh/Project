#ifndef USER
#define USER

#include "Template.hpp"

struct User
{
private:
    int userId, rating;
    std::string username, password;

public:
    // constructor
    User();
    User(int id, const std::string &name, const std::string &pass);
    User(int id, const std::string &name, const std::string &pass, int rate);

    // getters
    int getUserId();
    std::string getusername();
    std::string getpassword();
    int getrating();

    // authentication
    bool checkPassword(const std::string &password);

    // change rating
    void updateRating(int rating);
};


void _print(User user)
    {   cerr << user.getUserId() << " : " << user.getusername() << " - " << user.getrating();}
void print(User user)
    {   cout << user.getUserId() << " : " << user.getusername() << " - " << user.getrating();}

#endif