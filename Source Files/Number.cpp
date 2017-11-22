#include <iostream>
#include <fstream>
#include "Admin.h"
#include "object.h"
#include <cstring>
#include <string>
#include "Person.h"

Number::Number()
{
    number=new char[100];
}

void Number::AddNumber()
{
    cin.get();
    cin.getline(number,100);
}

void Number::Print()
{
    cout<<number;
}

char* Number::Get()
{
    return number;
}

ostream& operator <<(ostream& file,const Number& numb)
{
       file<<numb.number;
       return file;
}

istream& operator>>(istream& file, Number& numb)
{
    file>>numb.number;
    return file;
}

Number::~Number()
{
    delete[] number;
}
