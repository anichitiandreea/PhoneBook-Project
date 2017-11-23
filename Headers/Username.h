#ifndef USERNAME_H_INCLUDED
#define USERNAME_H_INCLUDED

#include "../Interfaces/IUsername.h"

class Username: public IUsername
{
    char* username;
public:
    Username();
    void EnterUser();
    int ReturnUser();
    ~Username();
};

#endif // USERNAME_H_INCLUDED
