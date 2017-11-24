#ifndef USER_H_INCLUDED
#define USER_H_INCLUDED

#include "../Headers/Level.h"

class User : public Level
{
public:
    User();
    ~User();
    void PrintItems();
    void AddButton();
    static int point;
};


#endif // USER_H_INCLUDED
