#include <iostream>
#include <fstream>
#include "../Headers/Admin.h"
#include "../Headers/Option.h"
#include <cstring>
#include <string>
#include "../Headers/Person.h"

Name::Name(string _name)
{
    value = _name;
}

Name::~Name() {}

void Name::Set(string _name)
{
    this -> value = _name;
}

ostream& operator << (ostream& file, Name& name)
{
    file << name.Get();
    return file;
}

string Name::Get()
{
    return this -> value;
}

istream& operator >> (istream& file, Name& name)
{
    string tempname;
    file >> tempname;
    name.Set(tempname);
    return file;
}
