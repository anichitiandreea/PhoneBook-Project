#include <iostream>
#include "../Headers/Option.h"
#include "../Headers/Admin.h"

using namespace std;

int main()
{
    IMenu *menu = new Menu();
    menu->printItems();
    return 0;
}
