#include "../Headers/Object.h"
#include <string.h>
#include <iostream>
#include <windows.h>
#include "../Headers/Password.h"
#include "../Headers/Console.h"
#include "../Headers/Username.h"

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
