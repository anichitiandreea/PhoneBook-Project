#include <iostream>
#include <fstream>
#include "Admin.h"
#include "object.h"
#include <cstring>
#include <string>
#include "Person.h"

Id::Id()
{
    id=new char[100];
}

void Id::AddId()
{
    cin>>id;
}

void Id::Print()
{
    cout<<*id;
}

Id::~Id()
{
    delete[] id;
}

ostream& operator <<(ostream& file, const Id& idd)
{
       file<<idd.id;
       return file;
}

istream& operator>>(istream& file, Id& idd)
{
    file>>idd.id;
    return file;
}

char* Id::Get()
{
    return id;
}
