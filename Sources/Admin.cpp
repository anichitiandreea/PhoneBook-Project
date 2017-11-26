#include "../Headers/Object.h"
#include "../Headers/Admin.h"
#include "../Headers/Password.h"
#include <conio.h>
#include <iostream>
#include <fstream>
#include <cstring>
#include "../Headers/Person.h"
#include "../Headers/Console.h"
#include "../Headers/Search.h"

using namespace std;

Adminmenu::Adminmenu()
{
    this->RemoveItem();
    this->RemoveItem();
    this->RemoveItem();
    this->AddItem("ADD PHONE RECORD");
    this->AddItem("DISPLAY ALL RECORDS");
    this->AddItem("REMOVE RECORD");
    this->AddItem("SEARCH BY ID");
    this->AddItem("SEARCH BY NUMBER");
    this->AddItem("SEARCH BY NAME");
    this->AddItem("SEARCH BY EMAIL");
    this->AddItem("BACK TO MAIN MENU");
}

int Adminmenu::point=0;

void Adminmenu::PrintItems()
{
    int f=1;
    while(f)
    {
        system("cls");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
        Console::PrintCenter("#####**************************PHONEBOOK**************************#####", 0);
        for(int i=0; i < static_cast<int>(_count); i++)
        {
            if(point == i)
            {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5);
                Console::PrintCenter( objects[i].GetName() , i+10);
            }
            else
            {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
                Console::PrintCenter( objects[i].GetName() , i+10);
            }
        }
        int t = 1;
        char ch;
        while(t)
        {
            ch=_getch();
            if(ch==72)
            {
                point -= 1;
                if(point == -1)
                    point = _count - 1;
                break;
            }
            else if(ch==80)
            {
                point += 1;
                if(point == static_cast<int>(_count))
                    point = 0;
                break;
            }
            else if(ch==13)
            {
                this->AddButton();
                t = 0;
                f=0;
            }
        }
        Sleep(110);
    }
    cout << '\n';
}
void Adminmenu::AddButton()
{
    fstream file;
    fstream ifile;
    file.open("database.txt", ios_base::app | ios::in | ios::out);
    ifile.open("ifile.txt", ios_base::app | ios::in | ios::out);
    switch(point)
    {
    case 0:
    {
        system("cls");
        Persoana pers;
        pers.AddPersoana();
        Console::PrintCenter("Do you want to return to Admin menu? (y/n)", 17);
        char c;
        cin >> c;
        if(c == 'y' || c == 'Y')
        {
            system("cls");
            Level *admin = new Adminmenu();
            admin->PrintItems();
        }
        else
            exit(0);
        break;
    }
    case 1:
    {
        system("cls");
        Persoana pers;
        int i=0;
        while(file>>pers)
        {
            cout<<pers;
            i++;
        }
        Console::PrintCenter("Do you want to return to Admin menu? (y/n)",i+3);
        char c;
        cin>>c;
        if(c=='y' || c=='Y')
        {
            system("cls");
            Level *admin = new Adminmenu();
            admin->PrintItems();
        }
        else
            exit(0);
        break;
    }
    case 2:
    {
        system("cls");
        Persoana pers;
        pers.Remove();
        file.close();
        ifile.close();
        remove("database.txt");
        rename("ifile.txt","database.txt");
        exit(0);
        break;
    }
    case 3:
    {
        system("cls");
        Search::ById();
        Console::PrintCenter("Do you want to return to Admin menu? (y/n)" ,20);
        char c;
        cin>>c;
        if(c=='y' || c=='Y')
        {
            system("cls");
            Adminmenu *admin = new Adminmenu();
            admin->PrintItems();
        }
        else
            exit(0);
        break;
    }
    case 4:
      {
        system("cls");
        Search::ByNumber();
        Console::PrintCenter("Do you want to return to User menu? (y/n)",20);
        char c;
        cin>>c;
        if(c=='y' || c=='Y')
        {
            system("cls");
            Adminmenu *admin = new Adminmenu();
            admin->PrintItems();
        }
        else
            exit(0);
        break;
        }
    case 5:
        {
        system("cls");
        Search::ByName();
        Console::PrintCenter("Do you want to return to User menu? (y/n)",20);
        char c;
        cin>>c;
        if(c=='y' || c=='Y')
        {
            system("cls");
            Adminmenu *admin = new Adminmenu();
            admin->PrintItems();
        }
        else
            exit(0);
        break;
        }
    case 6:
    {
        system("cls");
        Search::ByEmail();
        Console::PrintCenter("Do you want to return to Admin menu? (y/n)" ,20);
        char c;
        cin>>c;
        if(c=='y' || c=='Y')
        {
            system("cls");
            Adminmenu *admin = new Adminmenu();
            admin->PrintItems();
        }
        else
            exit(0);
        break;
    }
    case 7:
    {
        system("cls");
        Level level;
        level.PrintItems();
        break;
    }
    }
}
Adminmenu::~Adminmenu()
{

    if(objects!=NULL)
    {
        delete []objects;
    }
}
