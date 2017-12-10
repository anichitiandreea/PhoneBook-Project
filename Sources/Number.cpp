#include <iostream>
#include <fstream>
#include "../Headers/Admin.h"
#include "../Headers/Option.h"
#include <cstring>
#include <string>
#include "../Headers/Person.h"

Number::Number(string number)
{
    value = number;
}

void Number::Set(string number)
{
    this -> value = number;
}
string Number::Get()
{
    return this -> value;
}

bool Number::isValid()
{
    for(unsigned int i=0; i<=value.size(); i++)
        if(value[i]<48 || value[i]>57)
        return false;
    if(value.size()>20)
        return false;
    return true;

}

ostream& operator << (ostream& file, Number& numb)
{
    file << numb.Get();
    return file;
}

istream& operator >> (istream& file, Number& numb)
{
    string tempnumber;
    file >> tempnumber;
    numb.Set(tempnumber);
    return file;
}

Number::~Number() {}
