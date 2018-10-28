#ifndef PHONE_H
#define PHONE_H

#include <iostream>

using namespace std;

class Phone
{
public:
    string name = "";
    string number = "";
    Phone();
    Phone(string name);
    Phone(string name, string number);
    ~Phone();
    friend bool operator < (const Phone &l, const Phone &r);
    friend bool operator > (const Phone &l, const Phone &r);
    friend bool operator == (const Phone &l, const Phone &r);
    friend bool operator <= (const Phone &l, const Phone &r);
    friend bool operator >= (const Phone &l, const Phone &r);
    friend ostream &operator << (ostream &os, const Phone &phone);
};

Phone::Phone()
{
    this->name = "";
    this->number = "";
}

Phone::Phone(string name)
{
    this->name = name;
    this->number = "";
}

Phone::Phone(string name, string number)
{
    this->name = name;
    this->number = number;
}

Phone::~Phone()
{
    ;
}

bool operator < (const Phone &l, const Phone &r)
{
    return l.name < r.name;
}

bool operator > (const Phone &l, const Phone &r)
{
    return l.name > r.name;
}

bool operator == (const Phone &l, const Phone &r)
{
    return l.name == r.name;
}

bool operator <= (const Phone &l, const Phone &r)
{
    return l.name <= r.name;
}

bool operator >= (const Phone &l, const Phone &r)
{
    return l.name >= r.name;
}

ostream &operator << (ostream &os, const Phone &phone)
{
    os << phone.name << "," << phone.number << endl;
    return os;
}

#endif // PHONE_H
