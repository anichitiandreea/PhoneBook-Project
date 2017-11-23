#include "../Headers/Object.h"
#include "../Headers/Admin.h"
#include "../Headers/Password.h"
#include <conio.h>
#include <iostream>
#include <fstream>
#include <cstring>
#include "../Headers/Person.h"
#include "../Headers/Console.h"

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
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
        cout<<"#####******************************PHONEBOOK******************************#####"<<endl;
        for(int i=0; i < (int)_count; i++)
        {
            if(point == i)
            {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),5);
                Console::gotoxy(31,i+10);
                cout<<objects[i].GetName();
            }
            else
            {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
                Console::gotoxy(31,i+10);
                cout<<objects[i].GetName();
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
                if(point == (int)_count)
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
        Console::gotoxy(30,17);
        cout<<"Do you want to return to Admin menu? (y/n)";
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
        Console::gotoxy(30,i+3);
        cout<<"Do you want to return to Admin menu? (y/n)";
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
        char id[10];
        Persoana pers;
        int ok=0;
        Console::gotoxy(10,10);
        cout<<"Enter the id of the person you want to search for: ";
        cin>>id;
        while(file>>pers)
            if(strstr(pers.id.Get(),id)>0)
                if(strlen(id)==strlen(pers.id.Get()))
                {
                    Console::gotoxy(36,13);
                    cout<<pers.id.Get()<<'\n';
                    Console::gotoxy(36,14);
                    cout<<pers.number.Get()<<'\n';
                    Console::gotoxy(36,15);
                    cout<<pers.name.Get()<<'\n';
                    Console::gotoxy(36,16);
                    cout<<pers.email.Get()<<'\n';
                    ok=1;
                }
        if(ok==0)
        {
            Console::gotoxy(30,13);
            cout<<"Person not found";
            Console::gotoxy(25,14);
            cout<<"Do you want to return to Admin menu? (y/n)";
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
        }
        break;
    }
    case 4:
    {
        system("cls");
        Persoana pers;
        char number[20];
        int ok=0;
        Console::gotoxy(10,10);
        cout<<"Enter the number of the person you want to search for: ";
        cin>>number;
        while(file>>pers)
            if(strstr(pers.number.Get(),number)>0)
                if(strlen(number)==strlen(pers.number.Get()))
                {
                    Console::gotoxy(36,13);
                    cout<<pers.id.Get()<<'\n';
                    Console::gotoxy(36,14);
                    cout<<pers.number.Get()<<'\n';
                    Console::gotoxy(36,15);
                    cout<<pers.name.Get()<<'\n';
                    Console::gotoxy(36,16);
                    cout<<pers.email.Get()<<'\n';
                    ok=1;
                }
        if(ok==0)
        {
            Console::gotoxy(30,13);
            cout<<"Person not found";
            Console::gotoxy(25,14);
            cout<<"Do you want to return to Admin menu? (y/n)";
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
        }
        break;
    }
    case 5:
    {
        system("cls");
        Persoana pers;
        char name[100];
        int ok=0;
        Console::gotoxy(10,10);
        cout<<"Enter the name of the person you want to search for: ";
            cin.get(name,100);
        while(file>>pers)
            if(strstr(pers.name.Get(),name)>0)
                if(strlen(name)==strlen(pers.name.Get()))
                {
                    Console::gotoxy(36,13);
                    cout<<pers.id.Get()<<'\n';
                    Console::gotoxy(36,14);
                    cout<<pers.number.Get()<<'\n';
                    Console::gotoxy(36,15);
                    cout<<pers.name.Get()<<'\n';
                    Console::gotoxy(36,16);
                    cout<<pers.email.Get()<<'\n';
                    ok=1;
                }
       if(ok==0)
        {
            Console::gotoxy(30,13);
            cout<<"Person not found";
            Console::gotoxy(25,14);
            cout<<"Do you want to return to Admin menu? (y/n)";
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
        }
        break;
    }
    case 6:
    {
        system("cls");
        Persoana pers;
        string email;
        int ok=0;
        Console::gotoxy(10,10);
        cout<<"Enter the email of the person you want to search for: ";
        getline(cin, email);
        while(file >> pers)
            if((pers.email.Get()).find(email) != std::string::npos)
                {
                    Console::gotoxy(36,13);
                    cout<<pers.id.Get()<<'\n';
                    Console::gotoxy(36,14);
                    cout<<pers.number.Get()<<'\n';
                    Console::gotoxy(36,15);
                    cout<<pers.name.Get()<<'\n';
                    Console::gotoxy(36,16);
                    cout<<pers.email.Get()<<'\n';
                    ok=1;
                }
        if(ok==0)
        {
            Console::gotoxy(30,13);
            cout<<"Person not found";
            Console::gotoxy(25,14);
            cout<<"Do you want to return to Admin menu? (y/n)";
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
        }
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
