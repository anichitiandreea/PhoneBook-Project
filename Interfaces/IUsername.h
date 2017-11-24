#ifndef IUSERNAME_H_INCLUDED
#define IUSERNAME_H_INCLUDED

class IUsername
{
public:
    virtual void EnterUser() = 0;
    virtual int ReturnUser() = 0;
};

#endif // IUSERNAME_H_INCLUDED
