#ifndef USERNAME_H_INCLUDED
#define USERNAME_H_INCLUDED

#include "../Interfaces/IUser.h"
#include <string>

class User: public IUser
{
    string userName;
public:
    User();
    void SetUserName(string);
    bool CheckUserName();
    ~User();
    friend istream& operator>>(istream& stream, User& user);
};



#endif // USERNAME_H_INCLUDED
