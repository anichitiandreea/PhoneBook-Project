#ifndef IUSER_H_INCLUDED
#define IUSER_H_INCLUDED

#include <string>
using namespace std;

class IUser
{
public:
    virtual void SetUsername(string) = 0;
    virtual void SetPassword(string) = 0;
    virtual string GetPassword()     = 0;
    virtual string GetUsername()     = 0;
};

#endif // IUSER_H_INCLUDED
