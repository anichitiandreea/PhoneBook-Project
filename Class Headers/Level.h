#ifndef LEVEL_H_INCLUDED
#define LEVEL_H_INCLUDED

#include "ILevel.h"

class Level: public ILevel
{
protected:
    OBJECT* objects;
    unsigned int _count;

public:
    static int point;
    Level();
    ~Level();
    void AddItem(const string& name);
    void RemoveItem();
    void PrintItems();
    void AddButton();

};

#endif // LEVEL_H_INCLUDED
