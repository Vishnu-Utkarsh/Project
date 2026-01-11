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
    User() {}
    User(int id, const std::string &name, const std::string &pass) : userId(id), username(name), password(pass), rating(0) {}

    // getters
    int getUserId() { return userId; }
    std::string getusername() { return username; }
    int getrating() { return rating; }

    // authentication
    bool checkPassword(const std::string &password) { return password == this -> password; }

    // trust logic(+ve/-ve)
    void updateRating(int rating) { this -> rating = rating; }
};


void _print(User &user)
    {   cerr << user.getUserId() << " : " << user.getusername() << " - " << user.getrating() << endl;}
void print(User &user)
    {   cout << user.getUserId() << " : " << user.getusername() << " - " << user.getrating() << endl;}

#endif