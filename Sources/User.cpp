#include "../Headers/Option.h"
#include <string>
#include <iostream>
#include <windows.h>
#include "../Headers/Password.h"
#include "../Headers/Console.h"
#include "../Headers/User.h"

using namespace std;

User::User() {}

void User::SetUserName(string _userName)
{
    this->userName = _userName;
}

bool User::CheckUserName()
{
    if((userName.find("Andreea") != std::string::npos) and userName.size() == 7)
        return true;
    return false;
}

istream& operator>>(istream& stream, User& user)
{
	string username;
	stream >> username;
	user.SetUserName(username);
	return stream;
}

User::~User() {}
