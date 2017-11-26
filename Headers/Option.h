#ifndef OPTION_H_INCLUDED
#define OPTION_H_INCLUDED

#include <string.h>
#include <iostream>

using namespace std;

class Option
{
    string name;
public:
    Option();
    Option(const string&);
    string& GetName();
    void SetName(const string&);
};

#endif // OPTION_H_INCLUDED
