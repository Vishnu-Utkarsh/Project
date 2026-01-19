#ifndef COURT
#define COURT

#include "Template.hpp"

class Court
{
private:
    bool occupied;

protected:
    // constructor
    Court();

    void switchStatus();
    bool checkAvailibility() const;

};

// forward declaration
Court::Court() : occupied(false) {}

void Court::switchStatus() { occupied ^= true; }
bool Court::checkAvailibility() const { return ! occupied; }


class Badminton : public Court
{
private:
    int courtNumber;
    string type = "Indoor";

public:
    // constructor
    Badminton();
    Badminton(const int number);

    // output operator (<<)
    friend std::ostream& operator<<(std::ostream& os, const Badminton &court)
    {
        os << "Badminton Court " << court.courtNumber << "\t";
        os << "type: " << court.type << "\t";
        os << "status: " << (court.checkAvailibility() ? "Available" : "Not Available") << "\t";
        return os;
    }
};

// forward declaration
Badminton::Badminton() : courtNumber(0) {}
Badminton::Badminton(const int number) : courtNumber(number) {}

#endif