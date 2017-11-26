#include <iostream>
#include <fstream>
#include "../Headers/Admin.h"
#include "../Headers/Option.h"
#include <cstring>
#include <string>
#include "../Headers/Person.h"

Name::Name(string name)
{
    value = name;
}

Name::~Name() {}

void Name::Set(string name)
{
    this -> value = name;
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
