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

Persoana::Persoana() {}

Persoana::~Persoana() {}

void Persoana::IsEmailValid()
{

    if(email.IsValid())
    {
        fstream * file = FileManager::GetSingletone();
        FileManager::RegisterSave(*this);
        Console::PrintCenter("Person added succesfully.", 15);
    }
    else
    {
        Console::PrintCenter("Person can't be added.", 15);
    }
}

void Persoana::Remove()
{
    fstream ifile;
    ifile.open("ifile.txt", ios_base::app | ios::in | ios::out);
    Persoana pers;
    string n;
    Console::PrintCenter( "Enter the id of the person you want to remove: ", 10);
    cin>>n;
    int ok = 0;
    fstream * file = FileManager::GetSingletone();
    while(!ok)
    {
        *file >> pers;
        if((pers.id.Get()).find(n) == std::string::npos || pers.id.Get().size() != n.size())
            ifile<<pers;
        else
        {
            ok = 1;
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
               ifile<<pers;
            else
                Console::PrintCenter( "Person succesfully removed.", 20);
        }
    }
    if(ok == 0)
        Console::PrintCenter("This person can't be found in the database!", 16);
    ifile.close();
    FileManager::Close();

}

istream& operator>>(istream& filestream, Persoana& pers)
{
    if(filestream == cin)
    {

        string toRead;
        Console::PrintCenter("Enter the person's id: ", 10);
        filestream.get();
        getline(filestream, toRead);
        pers.id.Set(toRead);

        Console::PrintCenter("Enter the telephone number: ", 11);
        getline(filestream, toRead);
        pers.number.Set(toRead);

        Console::PrintCenter("Enter the full name: ", 12);
        getline(filestream, toRead);
        pers.name.Set(toRead);

        Console::PrintCenter("Enter the email: ", 13);
        getline(filestream, toRead);
        pers.email.Set(toRead);

    }
    else
    {
        string toRead;

        getline(filestream, toRead);
        pers.id.Set(toRead);

        getline(filestream, toRead);
        pers.number.Set(toRead);

        getline(filestream, toRead);
        pers.name.Set(toRead);

        getline(filestream, toRead);
        pers.email.Set(toRead);

        getline(filestream, toRead);
    }
    return filestream;
}

ostream& operator<<(ostream& filestream, Persoana& pers)
{
    if(filestream == cout)
    {
        filestream << pers.id.Get();
        for(unsigned int i=1; i <= 6-(pers.id.Get().size())+1; i++)
            filestream << " ";
        filestream << pers.number.Get();
        for(unsigned int i=1; i <= 20-(pers.number.Get().size())+1; i++)
            filestream << " ";
        filestream << pers.name.Get();
        for(unsigned int i=1; i <= 30-(pers.name.Get().size())+1; i++)
            filestream << " ";
        filestream << pers.email.Get();
        for(unsigned int i=1; i <= 30-(pers.email.Get().size())+1; i++)
            filestream << " ";
        filestream << '\n';
    }
    else
    {
        filestream << pers.id.Get() << '\n' << pers.number.Get() << '\n' << pers.name.Get() << '\n' << pers.email.Get() << '\n';
        filestream << '\n';
    }
    return filestream;
}
