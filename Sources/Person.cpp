#include <iostream>
#include <fstream>
#include "../Headers/Admin.h"
#include "../Headers/Option.h"
#include <cstring>
#include <string>
#include "../Headers/Person.h"
#include "../Headers/Console.h"

using namespace std;

fstream file;
fstream ifile;

Persoana::Persoana() {}

Persoana::~Persoana() {}

void Persoana::AddPersoana()
{
    cin.get();
    string tempid, tempname, tempnumber, tempemail;
    file.open("database.txt", ios_base::app | ios::in | ios::out);

    Console::PrintCenter("Enter the person's id: ",10);
    getline(cin, tempid);
    id.Set(tempid);

    Console::PrintCenter("Enter the telephone number: ",11);
    getline(cin,tempnumber);
    number.Set(tempnumber);

    Console::PrintCenter("Enter the full name: ",12);
    getline(cin,tempname);
    name.Set(tempname);

    Console::PrintCenter("Enter the email: ",13);
    getline(cin,tempemail);
    email.Set(tempemail);

    if(email.IsValid())
    {
        file << this->id << '\n' << this->number << '\n' << this->name << '\n' << this->email << '\n';
        file << '\n';
        Console::PrintCenter("Person added succesfully.", 15);
    }
    else
    {
        Console::PrintCenter("Person can't be added.", 15);
    }
    file.close();
}

void Persoana::Remove()
{
    file.open("database.txt", ios_base::app | ios::in | ios::out);
    ifile.open("ifile.txt", ios_base::app | ios::in | ios::out);
    Persoana pers;
    string n;
    Console::PrintCenter( "Enter the id of the person you want to remove: ", 10);
    cin>>n;
    while(file >> pers)
    {
        if((pers.id.Get()).find(n) == std::string::npos || pers.id.Get().size() != n.size())
        {
            ifile << pers.id.Get() << '\n' << pers.number.Get() << '\n' ;
            ifile << pers.name.Get() << '\n' << pers.email.Get() << '\n';
            ifile << '\n';
        }
        else
        {
            string s("ID: " + pers.id.Get());
            Console::PrintCenter(s,13);
            s="TELEPHONE NUMBER: " + pers.number.Get();
            Console::PrintCenter(s,14);
            s="NAME: " + pers.name.Get();
            Console::PrintCenter(s,15);
            s="EMAIL: " + pers.email.Get();
            Console::PrintCenter(s,16);
            Console::PrintCenter( "Are you sure you want to remove this person?(y/n) ", 18);
            char c;
            cin>>c;
            if(c == 'n' || c == 'N')
            {
                ifile << pers.id.Get() << '\n' << pers.number.Get() << '\n';
                ifile << pers.name.Get() << '\n'<<pers.email.Get() << '\n';
                ifile << '\n';
            }
            else
            {
                Console::PrintCenter( "Person succesfully removed.", 20);
            }
        }
    }
    file.close();
    ifile.close();

}

istream& operator >> (istream& fille, Persoana& pers)
{
    string line,id,name,email,number;

    getline(fille, id);
    pers.id.Set(id);

    getline(fille, number);
    pers.number.Set(number);

    getline(fille, name);
    pers.name.Set(name);

    getline(fille, email);
    pers.email.Set(email);

    getline(fille,line);
    return fille;
}

ostream& operator << (ostream& fille, Persoana& pers)
{
    cout << pers.id.Get();
    for(unsigned int i=1; i <= 6-(pers.id.Get().size())+1; i++)
        cout << " ";
    cout<<pers.number.Get();
    for(unsigned int i=1; i <= 20-(pers.number.Get().size())+1; i++)
        cout << " ";
    cout<<pers.name.Get();
    for(unsigned int i=1; i <= 30-(pers.name.Get().size())+1; i++)
        cout << " ";
    cout<<pers.email.Get();
    for(unsigned int i=1; i <= 30-(pers.email.Get().size())+1; i++)
        cout << " ";
    cout << '\n';
    return fille;
}
