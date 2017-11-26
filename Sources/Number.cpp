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
