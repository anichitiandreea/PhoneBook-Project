#ifndef OBJECT_H_INCLUDED
#define OBJECT_H_INCLUDED

#include <string.h>
#include <iostream>

using namespace std;

class OBJECT
{
    string _name;
public:
    OBJECT();
    OBJECT(const string& name);
    string& GetName();
    void SetName(const string& name);
};


#endif // OBJECT_H_INCLUDED
