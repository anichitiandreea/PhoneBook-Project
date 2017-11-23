#ifndef PASSWORD_H_INCLUDED
#define PASSWORD_H_INCLUDED

#include "../Interfaces/IPassword.h"

class Password: public IPassword
{
    char *c;
public:
    Password();
    ~Password();
    void AddPassword();
    int ReturnPass();
};


#endif // PASSWORD_H_INCLUDED
