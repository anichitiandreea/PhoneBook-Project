#include "../Headers/Option.h"
#include <conio.h>
#include <fstream>
#include "../Headers/Person.h"
#include "../Headers/Console.h"
#include "../Headers/UserMenu.h"
#include "../Headers/Search.h"
#include "../Headers/FileManager.h"

using namespace std;

UserMenu::UserMenu()
{
    this->removeItem();
    this->removeItem();
    this->removeItem();
    this->addItem("SEARCH BY ID");
    this->addItem("SEARCH BY NUMBER");
    this->addItem("SEARCH BY NAME");
    this->addItem("SEARCH BY EMAIL");
    this->addItem("DISPLAY ALL RECORDS");
    this->addItem("BACK TO MAIN MENU");
}

void UserMenu::printItems()
{
    int f = 1;
    while(f)
    {
        system("cls");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
        Console::PrintCenter("#####**************************PHONEBOOK**************************#####", 0);
        for(int i=0; i < static_cast<int>(_count); i++)
        {
            if(point == i)
            {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
                Console::PrintCenter(options[i].GetName(), i+10);
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
            }
            else
            {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
                Console::PrintCenter(options[i].GetName(), i+10);
            }
        }
        int t = 1;
        char ch;
        while(t)
        {
            ch = _getch();
            if(ch == 72)
            {
                point -= 1;
                if(point == -1)
                    point = _count - 1;
                break;
            }
            else if(ch == 80)
            {
                point += 1;
                if(point == static_cast<int>(_count))
                    point = 0;
                break;
            }
            else if(ch == 13)
            {
                this->addButton();
                t = 0;
                f = 0;
            }
        }
        Sleep(110);
    }
    cout << '\n';
}

int UserMenu::point = 0;

void UserMenu::addButton()
{

    switch(point)
    {
    case 0:
    {
        system("cls");
        int i = 15;
        Search::ById(i);
        //FileManager::Close();
        Console::PrintCenter( "Do you want to return to user menu? (y/n)", i+2);
        char c;
        cin >> c;
        if(c == 'y' || c == 'Y')
        {
            system("cls");
            UserMenu *userMenu = new UserMenu();
            userMenu -> printItems();
        }
        else
            exit(0);
        break;
    }

    case 1:
    {
        system("cls");
        int i = 15;
        //FileManager::Initialize("database.txt");
        Search::ByNumber(i);
        //FileManager::Close();
        Console::PrintCenter( "Do you want to return to user menu? (y/n)", i+2);
        char c;
        cin >> c;
        if(c == 'y' || c == 'Y')
        {
            system("cls");
            UserMenu*userMenu = new UserMenu();
            userMenu -> printItems();
        }
        else
            exit(0);
        break;
    }
    case 2:
    {
        system("cls");
        int i = 15;
        //FileManager::Initialize("database.txt");
        Search::ByName(i);
        //FileManager::Close();
        Console::PrintCenter( "Do you want to return to User menu? (y/n)", i+2);
        char c;
        cin >> c;
        if(c == 'y' || c == 'Y')
        {
            system("cls");
            UserMenu *userMenu = new UserMenu();
            userMenu -> printItems();
        }
        else
            exit(0);
        break;
    }
    case 3:
    {
        system("cls");
        int i = 15;
        //FileManager::Initialize("database.txt");
        Search::ByEmail(i);
        Console::PrintCenter( "Do you want to return to User menu? (y/n)", i+2);
        //FileManager::Close();
        char c;
        cin >> c;
        if(c == 'y' || c == 'Y')
        {
            system("cls");
            UserMenu *userMenu = new UserMenu();
            userMenu -> printItems();
        }
        else
            exit(0);
        break;
    }
    case 4:
    {

        system("cls");
        Persoana pers;
        //FileManager::Initialize("database.txt");
        int i = 4, ok = 0;
        fstream * file = FileManager::GetSingletone();
        FileManager::ResetFile();
        while(*file >> pers)
        {
            if(!ok) Console::printMessage();
            cout<<pers;
            ok = 1;
            i++;
        }
       // FileManager::Close();
        Console::PrintCenter( "Do you want to return to User menu? (y/n)", i+2);
        char c;
        cin >> c;
        if(c == 'y' || c == 'Y')
        {
            system("cls");
            UserMenu *userMenu = new UserMenu();
            userMenu -> printItems();
        }
        else
            exit(0);
        break;
    }
    case 5:
    {
        Menu menu;
        menu.printItems();
        break;
    }
    }
}

UserMenu::~UserMenu()
{
    if(options != NULL)
    {
        delete []options;
    }
}
