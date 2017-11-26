#ifndef EMAIL_H_INCLUDED
#define EMAIL_H_INCLUDED

#include "../Interfaces/IContact.h"

class Email: public IContact
{
    string value;
 public:
    Email(string = "");
    ~Email();
    string Get();
    void Set(string);
    bool IsValid();
    friend ostream& operator<<(ostream&, Email&);
    friend istream& operator>>(istream&, Email&);
};

#endif // EMAIL_H_INCLUDED
