#include "Template.hpp"
#include "user.hpp"

// forward declaration
User::User() {}
User::User (const std::string &name, const std::string &pass) : username(name), password(pass), rating(0) {}
User::User (const std::string &name, const std::string &pass, int rating) : username(name), password(pass), rating(rating) {}

std::string User::getusername() { return username; }
std::string User::getpassword() { return password; }
int User::getrating() { return rating; }

bool User::checkPassword(const std::string &password) { return password == this -> password; }

void User::updateRating(int rating) { this -> rating = rating; }