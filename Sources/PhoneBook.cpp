#include <iostream>
#include "../Headers/Option.h"
#include "../Headers/Admin.h"
#include "../Headers/FileManager.h"

using namespace std;

int main()
{
    FileManager::Initialize("database.txt");

    IMenu *menu = new Menu();
    menu->printItems();

    FileManager::Close();
    return 0;
}
