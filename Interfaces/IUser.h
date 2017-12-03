#ifndef IUSER_H_INCLUDED
#define IUSER_H_INCLUDED

class IUser
{
public:
    virtual void SetUserName(string) = 0;
    virtual bool CheckUserName() = 0;
};

#endif // IUSER_H_INCLUDED
