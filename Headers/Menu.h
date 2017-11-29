#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

#include "../Interfaces/IMenu.h"

class Menu: public IMenu
{
protected:
    Option* options;
    unsigned int _count;
public:
    static int point;
    Menu();
    ~Menu();
    void addItem(const string& name);
    void removeItem();
    void printItems();
    void addButton();
};

#endif // MENU_H_INCLUDED
