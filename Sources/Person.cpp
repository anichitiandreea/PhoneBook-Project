#include <iostream>
#include <fstream>
#include "../Headers/Admin.h"
#include "../Headers/Option.h"
#include <cstring>
#include <string>
#include "../Headers/Person.h"
#include "../Headers/Console.h"
#include "../Headers/FileManager.h"

using namespace std;

fstream ifile;

Persoana::Persoana() {}

Persoana::~Persoana() {}

void Persoana::IsEmailValid()
{

    if(email.IsValid())
    {
        fstream * file = FileManager::GetSingletone();
        *file << *this;
        Console::PrintCenter("Person added succesfully.", 15);
    }
    else
    {
        Console::PrintCenter("Person can't be added.", 15);
    }
}

void Persoana::Remove()
{
    ifile.open("ifile.txt", ios_base::app | ios::in | ios::out);
    Persoana pers;
    string n;
    Console::PrintCenter( "Enter the id of the person you want to remove: ", 10);
    cin>>n;
    fstream * file = FileManager::GetSingletone();
    while(*file >> pers)
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
    ifile.close();
    //FileManager::Close();

}

istream& operator>>(istream& fille, Persoana& pers)
{
    if(&fille == &cin)//citeste o persoana de la tastatura
    {
        cin.get();
        string tempid, tempname, tempnumber, tempemail;

        Console::PrintCenter("Enter the person's id: ",10);
        getline(cin, tempid);
        pers.id.Set(tempid);

        Console::PrintCenter("Enter the telephone number: ",11);
        getline(cin,tempnumber);
        pers.number.Set(tempnumber);

        Console::PrintCenter("Enter the full name: ",12);
        getline(cin,tempname);
        pers.name.Set(tempname);

        Console::PrintCenter("Enter the email: ",13);
        getline(cin,tempemail);
        pers.email.Set(tempemail);

    }
    else//citeste o persoana din fisier
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
    }
    return fille;
}

ostream& operator<<(ostream& fille, Persoana& pers)
{
    if(&fille == &cout)//afiseaza o persoana pe ecran
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
    }
    else
    {
        fstream * file = FileManager::GetSingletone();
        *file << pers.id.Get() << '\n' << pers.number.Get() << '\n' << pers.name.Get() << '\n' << pers.email.Get() << '\n';
        *file << '\n';
    }
    return fille;
}
