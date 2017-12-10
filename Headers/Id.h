#ifndef ID_H_INCLUDED
#define ID_H_INCLUDED

#include "../Interfaces/IContact.h"

class Id: public IContact
{
    string value;
public:
    Id(string ="");
    ~Id();
    void Set(string);
    string Get();
    bool isValid();
    friend ostream& operator <<(ostream& file, Id& idd);
    friend istream& operator >>(istream& file, Id& idd);
};

#endif // ID_H_INCLUDED
