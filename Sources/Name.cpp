#include <iostream>
#include <fstream>
#include "../Headers/Admin.h"
#include "../Headers/Object.h"
#include <cstring>
#include <string>
#include "../Headers/Person.h"

Name::Name()
{
    name=new char[100];
}

Name::~Name()
{
    delete[] name;
}

void Name::AddName()
{
    cin.getline(name,100);
}

void Name::Print()
{
    cout<<name;
}

ostream& operator <<(ostream& file,const Name& nume)
{
       file<<nume.name;
       return file;
}

char* Name::Get()
{
    return name;
}

istream& operator>>(istream& file, Name& nume)
{
    file>>nume.name;
    return file;
}
