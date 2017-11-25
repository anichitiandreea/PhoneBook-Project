#include <iostream>
#include <fstream>
#include "../Headers/Admin.h"
#include "../Headers/Object.h"
#include <cstring>
#include <string>
#include "../Headers/Person.h"
#include "../Headers/Console.h"

using namespace std;

fstream file;
fstream ifile;

Persoana::Persoana(){}

Persoana::~Persoana(){}

void Persoana::AddPersoana()
{
    file.open("database.txt", ios_base::app | ios::in | ios::out);
    Console::gotoxy(37,10);
    string tempid;
    cout<<"Enter the person's id: "; getline(cin, tempid);
    id.Set(tempid);
    Console::gotoxy(37,11);
    string tempnumber;
    cout<<"Enter the telephone number: "; getline(cin,tempnumber);
    number.Set(tempnumber);
    Console::gotoxy(37,12);
    string tempname;
    cout<<"Enter the full name: "; getline(cin,tempname);
    name.Set(tempname);
    Console::gotoxy(37,13);
    string tempEmail;
    cout<<"Enter the email: "; cin >> tempEmail;
    email.Set(tempEmail);
    if(email.IsValid())
    {
        file<<this->id<<'\n'<<this->number<<'\n'<<this->name<<'\n'<<this->email<<'\n';
        file<<'\n';
        Console::PrintCenter("Person added succesfully.",15);
    }
    else
    {
        Console::PrintCenter("Person can't be added." ,15);
    }
}

void Persoana::Remove()
{
    file.open("database.txt", ios_base::app | ios::in | ios::out);
    ifile.open("ifile.txt", ios_base::app | ios::in | ios::out);
    Persoana pers;
    string n;
    Console::PrintCenter("Enter the id of the person you want to remove: ",10);
    cin>>n;
    while(file>>pers)
    {
        if((pers.id.Get()).find(n) == std::string::npos || pers.id.Get().size()!=n.size())
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
            Console::PrintCenter("Are you sure you want to remove this person?(y/n) " ,18);
            char c;
            cin>>c;
            if(c=='n' || c=='N')
            {
                ifile<<pers.id.Get()<<'\n'<<pers.number.Get()<<'\n'<<pers.name.Get()<<'\n'<<pers.email.Get()<<'\n';
                ifile<<'\n';
            }
            else
            {
                Console::PrintCenter("Person succesfully removed." ,20);
            }
        }
    }
    file.close();
    ifile.close();

}

istream& operator>>(istream& file, Persoana& pers)
{
    string line;
    string id;
    getline(file,id);
    pers.id.Set(id);
    string number;
    getline(file,number);
    pers.number.Set(number);
    string name;
    getline(file, name);
    pers.name.Set(name);
    string email;
    getline(file, email);
    pers.email.Set(email);
    getline(file ,line);
    return file;
}

ostream& operator<<(ostream& file, Persoana& pers)
{
    cout << pers.id.Get();
    for(int i=1; i <= 6-(pers.id.Get().size())+1; i++)
        cout << " ";
    cout<<pers.number.Get();
    for(int i=1; i <= 12-(pers.number.Get().size())+1; i++)
        cout << " ";
    cout<<pers.name.Get();
    for(int i=1; i <= 30-(pers.name.Get().size())+1; i++)
        cout << " ";
    cout<<pers.email.Get();
    for(int i=1; i <= 30-(pers.email.Get().size())+1; i++)
        cout << " ";
    cout << '\n';
    return file;
}


