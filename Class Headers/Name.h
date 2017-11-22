#ifndef NAME_H_INCLUDED
#define NAME_H_INCLUDED

#include "IContact.h"

class Name: public IContact
{
    char *name;
public:
    char *ptr;
    Name();
    ~Name();
   void AddName();
   void Print();
   char* Get();
   friend ostream& operator <<(ostream& file,const Name& idd);
   friend istream& operator >>(istream& file, Name& idd);
};

#endif // NAME_H_INCLUDED
