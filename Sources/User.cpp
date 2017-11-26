#include "../Headers/Object.h"
#include <conio.h>
#include <fstream>
#include "../Headers/Person.h"
#include "../Headers/Console.h"
#include "../Headers/User.h"
#include "../Headers/Search.h"

using namespace std;

User::User()
{
    this->RemoveItem();
    this->RemoveItem();
    this->RemoveItem();
    this->AddItem("SEARCH BY ID");
    this->AddItem("SEARCH BY NUMBER");
    this->AddItem("SEARCH BY NAME");
    this->AddItem("SEARCH BY EMAIL");
    this->AddItem("DISPLAY ALL RECORDS");
    this->AddItem("BACK TO MAIN MENU");
}

void User::PrintItems()
{
    int f = 1;
     while(f)
    {
        system("cls");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
        Console::PrintCenter("#####**************************PHONEBOOK**************************#####",0);
        for(int i=0; i < static_cast<int>(_count); i++)
        {
            if(point == i)
            {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),14);
                Console::PrintCenter(objects[i].GetName(),i+10);
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
            }
            else
            {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
                Console::PrintCenter(objects[i].GetName() ,i+10);
            }
        }
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
            else
                if(ch == 80)
                {
                    point += 1;
                    if(point == static_cast<int>(_count))
                        point = 0;
                    break;
                }
            else
                if(ch==13)
                {
                    this->AddButton();
                    t = 0;
                    f = 0;
                }
        }
        Sleep(110);
    }
    cout << '\n';
}

int User::point=0;

void User::AddButton()
{
    fstream file;
    file.open("database.txt", ios_base::app | ios::in | ios::out);
    switch(point)
    {
    case 0:
        {
        system("cls");
        Search::ById();
        Console::PrintCenter("Do you want to return to User menu? (y/n)",20);
        char c;
        cin>>c;
        if(c=='y' || c=='Y')
        {
            system("cls");
            User *user = new User();
            user->PrintItems();
        }
        else
            exit(0);
        break;
        }

    case 1:
        {
        system("cls");
        Search::ByNumber();
        Console::PrintCenter("Do you want to return to User menu? (y/n)",20);
        char c;
        cin>>c;
        if(c=='y' || c=='Y')
        {
            system("cls");
            User *user = new User();
            user->PrintItems();
        }
        else
            exit(0);
        break;
        }
    case 2:
        {
        system("cls");
        Search::ByName();
        Console::PrintCenter("Do you want to return to User menu? (y/n)" , 20);
        char c;
        cin>>c;
        if(c=='y' || c=='Y')
        {
            system("cls");
            User *user = new User();
            user->PrintItems();
        }
        else
            exit(0);
        break;
        }
    case 3:
        {
        system("cls");
        Search::ByEmail();
        Console::PrintCenter("Do you want to return to User menu? (y/n)",20);
        char c;
        cin>>c;
        if(c=='y' || c=='Y')
        {
            system("cls");
            User *user = new User();
            user->PrintItems();
        }
        else
            exit(0);
        break;
        }
    case 4:
        {

        system("cls");
        Persoana pers;
        int i=0;
        while(file>>pers)
        {
            cout<<pers;
            i++;
        }
        Console::PrintCenter("Do you want to return to User menu? (y/n)" ,i+5);
        char c;
        cin>>c;
        if(c=='y' || c=='Y')
        {
            system("cls");
            User *user = new User();
            user->PrintItems();
        }
        else
            exit(0);
        break;
        }
    case 5:
        {
            Level level;
            level.PrintItems();
            break;
        }
    }
}

User::~User()
{
    if(objects!=NULL)
    {
        delete []objects;
    }
}
