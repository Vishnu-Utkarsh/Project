#ifndef COURT
#define COURT

#include "Template.hpp"

class Court
{
private:
    bool occupied;
    string bookedBy;
    // enum type
    // {   INDOOR, OUTDOOR, GROUND };

protected:
    // constructor
    Court();

    void switchStatus();
    bool checkAvailibility() const;
    bool book(const string &name);
    // void setType(type &type);
    // type courtType();
};

// forward declaration
Court::Court() : occupied(false) {}

void Court::switchStatus() { occupied ^= true; }
bool Court::checkAvailibility() const { return ! occupied; }
// void Court::setType(type &type) { type = type; }

bool Court::book(const string &name)
{
    if(occupied)    return false;

    occupied = true;
    bookedBy = name;
    return true;
}


class Badminton : public Court
{
private:
    int courtNumber;

public:
    // constructor
    Badminton();
    Badminton(const int number);

    // output operator (<<)
    friend std::ostream& operator<<(std::ostream& os, const Badminton &badminton)
    {
        os << "Badminton Court " << badminton.courtNumber << "\t";
        os << "type: " << "Indoor" << "\t";
        os << "status: " << (badminton.checkAvailibility() ? "Available" : "Not Available") << "\t";
        return os;
    }
};

// forward declaration
Badminton::Badminton() : courtNumber(0) {}
Badminton::Badminton(const int number) : courtNumber(number) {}
// Badminton::Court::type Court::courtType() { return INDOOR; }

#endif