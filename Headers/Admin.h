#ifndef ADMIN_H_INCLUDED
#define ADMIN_H_INCLUDED

#include "Option.h"
#include "../Headers/Menu.h"

using namespace std;

class Adminmenu : public Menu
{
public:
    Adminmenu();
    ~Adminmenu();
    void addButton();
    void printItems();
    static int point;
};

#endif // ADMIN_H_INCLUDED
