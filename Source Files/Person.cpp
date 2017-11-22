#include <iostream>
#include <fstream>
#include "Admin.h"
#include "object.h"
#include <cstring>
#include <string>
#include "Person.h"
#include "Console.h"

using namespace std;

fstream file;
fstream ifile;

Persoana::Persoana(){}

Persoana::~Persoana(){}

void Persoana::AddPersoana()
{
    file.open("database.txt", ios_base::app | ios::in | ios::out);
    Console::gotoxy(37,10);
    cout<<"Enter the person's id: "; id.AddId();
    Console::gotoxy(37,11);
    cout<<"Enter the telephone number: "; number.AddNumber();
    Console::gotoxy(37,12);
    cout<<"Enter the full name: "; name.AddName();
    Console::gotoxy(37,13);
    cout<<"Enter the email: "; email.AddEmail();
    string s(this->email.Get());
    if(Console::is_email_valid(s))
    {
        file<<this->id<<'\n'<<this->number<<'\n'<<this->name<<'\n'<<this->email<<'\n';
        file<<'\n';
        Console::gotoxy(37,15);
        cout<<"Person added succesfully.";
    }
    else
    {
        Console::gotoxy(37,15);
        cout<<"Person can't be added.";
    }
}

void Persoana::Remove()
{
    file.open("database.txt", ios_base::app | ios::in | ios::out);
    ifile.open("ifile.txt", ios_base::app | ios::in | ios::out);
    Persoana pers;
    char n[10];
    Console::gotoxy(30,10);
    cout<<"Enter the id of the person you want to remove: ";
    cin>>n;
    while(file>>pers)
    {
        if(strstr(pers.id.Get(),n)==NULL || strlen(n)!=strlen(pers.id.Get()))
        {
            ifile<<pers.id.Get()<<'\n'<<pers.number.Get()<<'\n'<<pers.name.Get()<<'\n'<<pers.email.Get()<<'\n';
            ifile<<'\n';
        }
        else
        {
            Console::gotoxy(36,13);
            cout<<pers.id.Get()<<'\n';
            Console::gotoxy(36,14);
            cout<<pers.number.Get()<<'\n';
            Console::gotoxy(36,15);
            cout<<pers.name.Get()<<'\n';
            Console::gotoxy(36,16);
            cout<<pers.email.Get()<<'\n';
            Console::gotoxy(30,18);
            cout<<"Are you sure you want to remove this person?(y/n) ";
            char c;
            cin>>c;
            if(c=='n' || c=='N')
            {
                ifile<<pers.id.Get()<<'\n'<<pers.number.Get()<<'\n'<<pers.name.Get()<<'\n'<<pers.email.Get()<<'\n';
                ifile<<'\n';
            }
            else
            {
                Console::gotoxy(32,20);
                cout<<"Person succesfully removed.";
            }
        }
    }
    file.close();
    ifile.close();

}

istream& operator>>(istream& file, Persoana& pers)
{
    char line[10];
    file.getline(pers.id.Get(),100);
    file.getline(pers.number.Get(),100);
    file.getline(pers.name.Get(),100);
    file.getline(pers.email.Get(),100);
    file.getline(line,100);
    return file;
}

ostream& operator<<(ostream& file, Persoana& pers)
{

    cout<<pers.id.Get();
    for(int i=1;i<=6-strlen(pers.id.Get())+1;i++)
        cout<<" ";
    cout<<pers.number.Get();
    for(int i=1;i<=12-strlen(pers.number.Get())+1;i++)
        cout<<" ";
    cout<<pers.name.Get();
    for(int i=1;i<=30-strlen(pers.name.Get())+1;i++)
        cout<<" ";
    cout<<pers.email.Get();
    for(int i=1;i<=30-strlen(pers.email.Get())+1;i++)
        cout<<" ";
    cout<<'\n';
    return file;
}


