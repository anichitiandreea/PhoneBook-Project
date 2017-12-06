#ifndef USERNAME_H_INCLUDED
#define USERNAME_H_INCLUDED

#include "../Interfaces/IUser.h"
#include <string>

class User: public IUser
{
    string username;
    string password;
public:
    User();
    void SetUsername(string);
    void SetPassword(string);
    bool CheckUserName();
    ~User();
    friend istream& operator>>(istream& stream, User& user);
};

#endif // USERNAME_H_INCLUDED
