#include "../Headers/Option.h"
#include <string.h>
#include <iostream>
#include <windows.h>
#include <conio.h>
#include "../Headers/Admin.h"
#include "../Headers/Console.h"
#include "../Headers/UserMenu.h"
#include "../Headers/User.h"
#include "../Headers/LoginManager.h"

//Add menu items
int Menu::point = 0;

Menu::Menu() : options(NULL), _count(0)
{
    this->addItem("ADMIN");
    this->addItem("USER");
    this->addItem("EXIT");
}
Menu::~Menu()
{
    if(options != NULL)
    {
        delete []options;
    }
}

void Menu::addItem(const string& name)
{
    Option obj(name);
    if(options == NULL)
    {
        options = new Option[1];
        options[0] = obj;
        _count++;
    }
    else
    {
        Option* temp = options;
        options = new Option[_count + 1];
        for(int i=0; i < static_cast<int>(_count); i++)
            options[i] = temp[i];
        options[_count] = obj;
        _count++;
        delete []temp;
    }
}

void Menu::removeItem()
{
    Option* temp=options;
    options = new Option[_count - 1];
    for(int i = 0; i < static_cast<int>(_count-1); i++)
        options[i] = temp[i];
    _count--;
    delete []temp;
}

void Menu::printItems()
{
    int f=1;
    while(f)
    {
        system("cls");
        SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), 13 );
        Console::PrintCenter("Phonebook", 0);
        SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), 15 );
        for(int i=0; i <static_cast<int> (_count); i++)
        {
            if(point == i)
            {
                SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), 13 );
                Console::PrintCenter( options[i].GetName(), i+10);
                SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), 15 );
            }
            else
            {
                Console::PrintCenter( options[i].GetName(), i+10 );
                SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), 15 );
            }
        }
        Console::hideCursor();
        int t = 1;
        char ch;
        while(t)
        {
            ch=_getch();
            if(ch == 72)
            {
                point -= 1;
                if(point == -1)
                    point = _count - 1;
                break;
            }
            else if(ch == 80)
            {
                point += 1;
                if(point ==static_cast<int>(_count))
                    point = 0;
                break;
            }
            else if(ch == 13)
            {
                this->addButton();
                t = 0;
                f = 0;
            }
        }
        Sleep(20);
    }
    cout << '\n';
}

void Menu::addButton()
{
    switch(point)
    {
    case 0:
    {
        system("cls");
        User user;
        LoginManager l;
        cin >> user;
        if(l.Authentificate(user))
        {
            system("cls");
            Console::PrintCenter( "Successful authentication.", 10);
            Console::PrintCenter( "Do you want to continue? Press any key: ", 14);
            _getch();
            system("cls");
            Adminmenu admin;
            admin.printItems();
        }
        else
        {
            Console::PrintCenter( "Incorect password or username. Return to main menu.(y / n) ", 10);
            char c;
            cin >> c;
            if(c == 'y' || c == 'Y')
            {
                system("cls");
                Menu menu;
                menu.printItems();
            }
            else
                exit(0);
        }
        break;
    }
    case 1:
    {
        point = 0;
        system("cls");
        UserMenu userMenu;
        userMenu.printItems();
        break;
    }
    case 2:
    {
        exit(0);
        break;
    }

    }
}
