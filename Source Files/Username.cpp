#include "object.h"
#include <string.h>
#include <iostream>
#include <windows.h>
#include "Password.h"
#include "Console.h"
#include "Username.h"

using namespace std;

Username::Username()
{
    username=new char[100];
    Console::gotoxy(33,10);
    cout<<"Enter the user: ";
}
void Username::EnterUser()
{
    cin>>username;
}
int Username::ReturnUser()
{
    if(strstr(this->username, "Andreea") and strlen(this->username)==7)
        return 1;
    return 0;
}
Username::~Username()
{
    delete[] username;
}
