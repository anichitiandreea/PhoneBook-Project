#include <iostream>
#include <conio.h>
#include "../Headers/Password.h"
#include "../Headers/Console.h"


Password::Password()
{
    c = new char[100];
    Console::gotoxy(33,11);
    cout << "Enter password: ";
}

void Password::AddPassword()
{

    int i = 0;
    while((c[i] = _getch()))
    {
        if(c[i]==13)
        {
            c[i] = '\0';
            system("cls");
            break;
        }
        cout << "*";
        if(VK_BACK==c[i] and i!=0)
        {
            cout << "\b \b\b \b";
            i -= 2;
        }
        i++;
    }
}

int Password::ReturnPass()
{
    char *a;
    a=new char[100];
    strcpy(a,c);
    if(strstr(a,"andreea") and strlen(a)==7)
        return 1;
    else
        return 0;
}

Password::~Password()
{
    delete[] c;
}
