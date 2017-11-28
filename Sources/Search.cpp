#include "../Headers/Search.h"
#include "../Headers/Console.h"
#include <string>
#include "../Headers/Person.h"
#include <iostream>
#include <fstream>
#include "../Headers/FileManager.h"

namespace Search
{

void ByNumber(int &i)
{
    int ok = 0;
    string number;
    Persoana pers;
    Console::PrintCenter( "Enter the number of the person you want to search for: ", 10);
    std::cin >> number;
    fstream * file = FileManager::GetSingletone();
    while(*file >> pers)
        if((pers.number.Get()).find(number) != std::string::npos)
        {
            if(!ok) Console::printMessage();
            cout << pers;
            i++;
            ok = 1;
        }

    if(ok == 0)
        Console::PrintCenter( "Person not found", 13);
}

void ById(int &i)
{
    string id;
    Persoana pers;
    int ok = 0;
    Console::PrintCenter( "Enter the id of the person you want to search for: ", 10);
    cin >> id;
    fstream * file = FileManager::GetSingletone();
    while(*file >> pers)
        if((pers.id.Get()).find(id) != std::string::npos)
        {
            if(!ok) Console::printMessage();
            cout << pers;
            i++;
            ok = 1;
        }
    if(ok == 0)
        Console::PrintCenter( "Person not found", 13);
}

void ByName(int &i)
{
    Persoana pers;
    int ok = 0;
    string name;
    Console::PrintCenter( "Enter the name of the person you want to search for: ", 10);
    cin >> name;
    fstream * file = FileManager::GetSingletone();
    while(*file >> pers)
        if((pers.name.Get()).find(name) != std::string::npos)
        {
            if(!ok) Console::printMessage();
                cout << pers;
            i++;
            ok = 1;
        }
    if(ok == 0)
        Console::PrintCenter( "Person not found", 13);
}

void ByEmail(int &i)
    {
    Persoana pers;
    int ok = 0;
    string email;
    Console::PrintCenter( "Enter the email of the person you want to search for: ", 10);
    cin >> email;
    fstream * file = FileManager::GetSingletone();
    while(*file >> pers)
        if((pers.email.Get()).find(email) != std::string::npos)
        {
            if(!ok) Console::printMessage();
            cout << pers;
            i++;
            ok = 1;
        }
    if(ok == 0)
        Console::PrintCenter( "Person not found", 13);
    }

}
