#include "object.h"
#include "admin.h"
#include "password.h"
#include <conio.h>
#include <iostream>
#include <fstream>
#include <cstring>
#include "Person.h"

using namespace std;

Adminmenu::Adminmenu()
{
    this->RemoveItem();
    this->RemoveItem();
    this->RemoveItem();
    this->AddItem("Add phone record");
    this->AddItem("Display all records");
    this->AddItem("Remove record");
    this->AddItem("Search by id");
    this->AddItem("Search by number");
    this->AddItem("Search by name");
    this->AddItem("Back to main menu");
}

int Adminmenu::point=0;

void Adminmenu::PrintItems()
{
    int f=1;
    while(f)
    {
        system("cls");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
        cout<<"***********************Phonebook ***********************"<<endl;
        for(int i=0; i < (int)_count; i++)
        {
            if(point == i)
            {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
                cout<<objects[i].GetName()<<'\n';
            }
            else
            {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
                cout<<objects[i].GetName()<<'\n';
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
            else
                if(ch==80)
                {
                    point += 1;
                    if(point == (int)_count)
                        point = 0;
                    break;
                }
            else
                if(ch==13)
                {
                    this->AddButton();
                    t = 0; f=0;
                }
        }
        Sleep(140);
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
            exit(0);
             break;
        }
        case 1:
        {
            system("cls");
            Persoana pers;
            //pers.Display();
            char line[100];
            while(file>>pers.id)
            {
                cout<<pers.id<<" ";
                file.getline(line,100);
                file.getline(line,100);
                cout<<line<<" ";
                file.getline(line,100);
                strcpy(pers.name.ptr,line);
                cout<<pers.name.ptr<<" ";
                file.getline(line,100);
                strcpy(pers.email.ptr,line);
                cout<<pers.email.ptr<<'\n';
            }
            exit(0);
            break;
        }
        case 2:
        {
                system("cls");
                Persoana pers;
            int n;
                cin>>n;
              while(file>>pers.id>>pers.number>>pers.name>>pers.email)
                {

                    if(pers.id.Get()!=n)
                       {
                        ifile<<pers.id<<" "<<pers.number<<" "<<pers.name<<" "<<pers.email<<'\n';
                       }
                }
                file.close();
                ifile.close();
                rename("database.txt","infile.txt");
                rename("ifile.txt","database.txt");
                rename("infile.txt","ifile.txt");
                remove("ifile.txt");
                exit(0);
                break;
            }
        case 3:
            {
                system("cls");
            int n;
            Persoana pers;
            cin>>n;
            while(file>>pers.id>>pers.number>>pers.name>>pers.email)
            {
                if(pers.id.Get()==n)
                    cout<<pers.id<<" "<<pers.number<<" "<<pers.name<<" "<<pers.email<<'\n';
            }
            exit(0);
            break;
            }
        case 4:
            {
                system("cls");
                Persoana pers;
                string n;
                cin>>n;
                while(file>>pers.id>>pers.number>>pers.name>>pers.email)
                {
                    if(pers.number.Get().compare(n)==0)
                        cout<<pers.id<<" "<<pers.number<<" "<<pers.name<<" "<<pers.email<<'\n';
                }
                exit(0);
                break;
            }
        case 5:
            {
                system("cls");
                Persoana pers;
                char n[100];
                cin.getline(n,100);
                while( file>>pers.id>>pers.number>>pers.name>>pers.email)
                {
                    //if(strstr(pers.name.Get(),n))
                        cout<<pers.id<<" "<<pers.number<<" "<<pers.name<<" "<<pers.email<<'\n';
                        //cout<<pers.name.Get();
                }
                exit(0);
                break;
            }
        case 6:
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

