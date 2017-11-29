#ifndef IMENU_H_INCLUDED
#define IMENU_H_INCLUDED

#include <string>

class IMenu
{
public:
    virtual void addButton()                  = 0;
    virtual void addItem(const  std::string&) = 0;
    virtual void printItems()                 = 0;
    virtual void removeItem()                 = 0;
};


#endif // IMENU_H_INCLUDED
