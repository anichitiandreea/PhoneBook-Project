#ifndef EMAIL_H_INCLUDED
#define EMAIL_H_INCLUDED

#include "IContact.h"

class Email: public IContact
{

    char *email;
 public:
    Email();
     ~Email();
    void AddEmail();
    void Print();
    char* Get();
    friend ostream& operator <<(ostream& file,const Email& em);
    friend istream& operator >>(istream& file, Email& em);

};

#endif // EMAIL_H_INCLUDED
