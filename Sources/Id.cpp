#include <iostream>
#include <fstream>
#include "../Headers/Admin.h"
#include "../Headers/Option.h"
#include <cstring>
#include <string>
#include "../Headers/Person.h"
#include "../Headers/FileManager.h"

Id::Id(string id)
{
    value = id;
}

void Id::Set(string id)
{
    this->value = id;
}

bool Id::isValid()
{
    fstream * file = FileManager::GetSingletone();
    Persoana pers;
    while(*file >> pers)
    {
       if(pers.id.Get().find(value) != std::string::npos and pers.id.Get().size() == value.size())
            return false;
    }
    return true;
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
