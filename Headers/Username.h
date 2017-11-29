#ifndef USERNAME_H_INCLUDED
#define USERNAME_H_INCLUDED

#include "../Interfaces/IUsername.h"
#include <string>

class Username: public IUsername
{
    string username;
public:
    Username();
    void EnterUser();
    int ReturnUser();
    ~Username();
};

#endif // USERNAME_H_INCLUDED
