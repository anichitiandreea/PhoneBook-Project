#ifndef NUMBER_H_INCLUDED
#define NUMBER_H_INCLUDED

#include "../Interfaces/IContact.h"

class Number: public IContact
{
    string value;
public:
    Number(string ="");
    ~Number();
    string  Get();
    void Set(string);
    bool isValid();
    friend ostream& operator <<(ostream& file, Number&);
    friend istream& operator >>(istream& file, Number&);
};

#endif // NUMBER_H_INCLUDED
