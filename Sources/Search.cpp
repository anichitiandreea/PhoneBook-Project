#include "../Headers/Search.h"
#include "../Headers/Console.h"
#include <string>
#include "../Headers/Person.h"
#include <iostream>
#include <fstream>

namespace Search
{

    void ByNumber()
    {
        fstream file;
        file.open("database.txt", ios_base::app | ios::in | ios::out);
        int ok=0,i=15;
        string number;
        Persoana pers;
        Console::PrintCenter("Enter the number of the person you want to search for: ",10);
       std::cin>>number;
        while(file>>pers)
            if((pers.number.Get()).find(number) != std::string::npos)
                {
                   if(!ok)
                {
                    cout<<"\n\n";
                    cout<<"ID:";
                    for(unsigned int j=1; j <= 6-3+1; j++)
                        cout << " ";
                    cout<<"TELEPHONE NUMBER:";
                    for(unsigned int j=1; j <= 20-17+1; j++)
                        cout << " ";
                    cout<<"NAME:";
                    for(unsigned int j=1; j <= 30-5+1; j++)
                        cout << " ";
                    cout<<"EMAIL:";
                    for(unsigned int j=1; j <= 30-6+1; j++)
                        cout << " ";
                    cout<<'\n';
                }
                   cout<<pers;
                   i++;
                   ok=1;
                }
        if(ok==0)
            Console::PrintCenter("Person not found",13);
        file.close();
    }
    void ById()
    {
        fstream file;
        file.open("database.txt", ios_base::app | ios::in | ios::out);
        string id;
        Persoana pers;
        int ok=0,i=15;
        Console::PrintCenter("Enter the id of the person you want to search for: ",10);
        cin>>id;
        while(file>>pers)
            if((pers.id.Get()).find(id) != std::string::npos)
                {
                    if(!ok)
                {
                    cout<<"\n\n";
                    cout<<"ID:";
                    for(unsigned int j=1; j <= 6-3+1; j++)
                        cout << " ";
                    cout<<"TELEPHONE NUMBER:";
                    for(unsigned int j=1; j <= 20-17+1; j++)
                        cout << " ";
                    cout<<"NAME:";
                    for(unsigned int j=1; j <= 30-5+1; j++)
                        cout << " ";
                    cout<<"EMAIL:";
                    for(unsigned int j=1; j <= 30-6+1; j++)
                        cout << " ";
                    cout<<'\n';
                }
                    cout<<pers;
                    i++;
                    ok=1;
                }
        if(ok==0)
            Console::PrintCenter("Person not found" ,13);
        file.close();
    }
    void ByName()
    {
        fstream file;
        file.open("database.txt", ios_base::app | ios::in | ios::out);
        Persoana pers;
        int ok=0,i=15;
        string name;
        Console::PrintCenter("Enter the name of the person you want to search for: ",10);
        cin>>name;
        while(file>>pers)
            if((pers.name.Get()).find(name) != std::string::npos)
                {
                    if(!ok)
                {
                    cout<<"\n\n";
                    cout<<"ID:";
                    for(unsigned int j=1; j <= 6-3+1; j++)
                        cout << " ";
                    cout<<"TELEPHONE NUMBER:";
                    for(unsigned int j=1; j <= 20-17+1; j++)
                        cout << " ";
                    cout<<"NAME:";
                    for(unsigned int j=1; j <= 30-5+1; j++)
                        cout << " ";
                    cout<<"EMAIL:";
                    for(unsigned int j=1; j <= 30-6+1; j++)
                        cout << " ";
                    cout<<'\n';
                }
                    cout<<pers;
                    i++;
                    ok=1;
                }
        if(ok==0)
            Console::PrintCenter("Person not found" ,13);
        file.close();
    }
    void ByEmail()
    {
        fstream file;
        file.open("database.txt", ios_base::app | ios::in | ios::out);
        Persoana pers;
        string email;
        int ok=0,i=15;
        Console::PrintCenter("Enter the email of the person you want to search for: ",10);
        getline(cin,email);
        while(file >> pers)
            if(pers.email.Get().find(email) != std::string::npos)
            {
                if(!ok)
                {
                    cout<<"\n\n";
                    cout<<"ID:";
                    for(unsigned int j=1; j <= 6-3+1; j++)
                        cout << " ";
                    cout<<"TELEPHONE NUMBER:";
                    for(unsigned int j=1; j <= 20-17+1; j++)
                        cout << " ";
                    cout<<"NAME:";
                    for(unsigned int j=1; j <= 30-5+1; j++)
                        cout << " ";
                    cout<<"EMAIL:";
                    for(unsigned int j=1; j <= 30-6+1; j++)
                        cout << " ";
                    cout<<'\n';
                }
                cout<<pers;
                i++;
                ok=1;
            }
        if(ok==0)
            Console::PrintCenter("Person not found",13);
        file.close();
    }
}
