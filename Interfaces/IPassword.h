#ifndef IPASSWORD_H_INCLUDED
#define IPASSWORD_H_INCLUDED

class IPassword
{
public:
    virtual void AddPassword() = 0;
    virtual int ReturnPass()   = 0;
};


#endif // IPASSWORD_H_INCLUDED
