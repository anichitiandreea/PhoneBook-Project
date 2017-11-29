#ifndef NAME_H_INCLUDED
#define NAME_H_INCLUDED

#include "../Interfaces/IContact.h"
#include <string>

class Name: public IContact
{
    string value;
public:
    Name(string= "");
    ~Name();
    void Set(string);
    string Get();
    friend ostream& operator <<(ostream& file, Name& idd);
    friend istream& operator >>(istream& file, Name& idd);
};

#endif // NAME_H_INCLUDED
