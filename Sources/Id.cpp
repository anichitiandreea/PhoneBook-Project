#include <iostream>
#include <fstream>
#include "../Headers/Admin.h"
#include "../Headers/Option.h"
#include <cstring>
#include <string>
#include "../Headers/Person.h"

Id::Id(string id)
{
    value = id;
}

void Id::Set(string id)
{
    this->value = id;
}

Id::~Id() {}

ostream& operator<<(ostream& file, Id& _id)
{
    file << _id.Get();
    return file;
}

istream& operator>>(istream& file, Id& _id)
{
    string tempid;
    file >> tempid;
    _id.Set(tempid);
    return file;
}

string Id::Get()
{
    return this -> value;
}
