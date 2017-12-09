#include "../Headers/Option.h"
#include <string>
#include <iostream>
#include <windows.h>
#include "../Headers/Console.h"
#include "../Headers/User.h"
#include <conio.h>

using namespace std;

User::User() {}

void User::SetUsername(string _username)
{
    this->username = _username;
}

void User::SetPassword(string _password)
{
    this->password = _password;
}

istream& operator>>(istream& stream, User& user)
{
    if(stream == cin)
    {
        Console::PrintCenter( "Enter the username: ", 10);
        string username;
        stream >> username;
        user.SetUsername(username);

        Console::PrintCenter("Enter password: ",11);
        char *c;
        c = new char[100];
        int i = 0;
        while((c[i] = _getch()))
        {
            if(c[i] == 13)
            {
                c[i] = '\0';
                system("cls");
                break;
            }
            cout << "*";
            if(VK_BACK == c[i] and i != 0)
            {
                cout << "\b \b\b \b";
                i -= 2;
            }
            i++;
        }
        string password(c);
        user.SetPassword(password);
        delete[] c;
    }
	return stream;
}
string User::GetUsername()
{
    return this->username;
}
string User::GetPassword()
{
    return this->password;
}

User::~User() {}
