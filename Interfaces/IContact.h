#ifndef ICONTACT_H_INCLUDED
#define ICONTACT_H_INCLUDED

class IContact
{
public:
   // void AddId() = 0;
    virtual void Print() = 0;
    virtual char* Get()  = 0;
};

#endif // ICONTACT_H_INCLUDED
