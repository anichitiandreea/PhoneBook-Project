#include <iostream>
#include <fstream>
#include "Admin.h"
#include "object.h"
#include <cstring>
#include <string>
#include "Person.h"

Email::Email()
{
    email=new char[100];
}

Email::~Email()
{
    delete[] email;
}

void Email::AddEmail()
{
    cin.getline(email,100);
}

void Email::Print()
{
    cout<<email;
}

ostream& operator <<(ostream& file,const Email& em)
{
    file<<em.email;
    return file;
}

istream& operator>>(istream& file, Email& em)
{
    file>>em.email;
    return file;
}

char* Email::Get()
{
    return email;
}
