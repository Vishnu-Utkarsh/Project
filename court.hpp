#ifndef COURT
#define COURT

#include "Template.hpp"
#include <ostream>

enum type
{   INDOOR, OUTDOOR, GROUND };

std::ostream& operator<<(std::ostream& os, type courtType)
{
    switch (courtType)
    {
        case type::INDOOR:  os << "INDOOR";     break;
        case type::OUTDOOR: os << "OUTDOOR";    break;
        case type::GROUND:  os << "GROUND";     break;
        default:            os << "UNKNOWN";    break;
    }
    return os;
}

class Court
{
private:
    bool occupied;
    int courtNumber;
    string bookedBy;
    type courtType;

protected:
    void switchStatus();
    bool checkAvailibility() const;
    bool book(const string &name);

public:
    // constructor
    Court();
    Court(type courtType);
    Court(type courtType, int courtNumber);

    // output operator (<<)
    friend std::ostream& operator<<(std::ostream& os, const Court &court)
    {
        os << "Badminton Court " << court.courtNumber << "\t\t";
        os << "type: " << court.courtType << "\t\t";
        os << "status: " << (court.checkAvailibility() ? "Available" : "Not Available") << "\t\t";
        return os;
    }
};

// forward declaration
Court::Court() : occupied(false) {}
Court::Court(type courtType) : occupied(false), courtType(courtType) {}
Court::Court(type courtType, int courtNumber) : occupied(false), courtType(courtType), courtNumber(courtNumber) {}

void Court::switchStatus() { occupied ^= true; }
bool Court::checkAvailibility() const { return ! occupied; }

bool Court::book(const string &name)
{
    if(occupied)    return false;

    occupied = true;
    bookedBy = name;
    return true;
}


class Badminton : public Court
{
public:
    // constructor
    Badminton();
    Badminton(const int number);

};

// forward declaration
Badminton::Badminton() : Court(INDOOR) {}
Badminton::Badminton(const int number) : Court(INDOOR, number) {}
// Badminton::Court::type Court::courtType() { return INDOOR; }

void _print(type &courtType)
    {   cout << courtType;}
void print(type courtType)
    {   cout << courtType << endl; }


void _print(Court &court)
    {   cerr << court;}
void print(Court &court)
    {   cout << court << endl; }

#endif