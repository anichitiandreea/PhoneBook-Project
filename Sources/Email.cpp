#include <cstring>
#include <fstream>
#include <iostream>
#include <regex>
#include <string>
#include "../Headers/Admin.h"
#include "../Headers/Object.h"
#include "../Headers/Person.h"

Email::Email(string email)
{
	value = email;
}

Email::~Email() {}

string Email::Get()
{
    return this->value;
}

void Email::Set(string email)
{
	this->value = email;
}

bool Email::IsValid()
{
    // define a regular expression
    const std::regex pattern
    ("(\\w+)(\\.|_)?(\\w*)@(\\w+)(\\.(\\w+)).+");

    // try to match the string with the regular expression
    return std::regex_match(this->Get(), pattern);
}

ostream& operator<<(ostream& file, Email& email)
{
    file << email.Get();
    return file;
}

istream& operator>>(istream& file, Email& email)
{
	string tempEmail;
    file >> tempEmail;
    email.Set(tempEmail);
    return file;
}
