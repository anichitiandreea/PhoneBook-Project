#ifndef USERMENU_H_INCLUDED
#define USERMENU_H_INCLUDED

#include "../Headers/Menu.h"

class UserMenu : public Menu
{
public:
    UserMenu();
    ~UserMenu();
    void addButton();
    void printItems();
    static int point;
};

#endif // USERMENU_H_INCLUDED
