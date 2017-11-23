#ifndef ILEVEL_H_INCLUDED
#define ILEVEL_H_INCLUDED

#include <string>

class ILevel
{
public:
    virtual void PrintItems()                 = 0;
    virtual void RemoveItem()                 = 0;
    virtual void AddItem(const  std::string&) = 0;
    virtual void AddButton()                  = 0;
};


#endif // ILEVEL_H_INCLUDED
