#ifndef ID_H_INCLUDED
#define ID_H_INCLUDED

#include "../Interfaces/IContact.h"

class Id: public IContact
{

   char* id;
public:
   Id();
   ~Id();
   void AddId();
   void Print();
   char* Get();
   friend ostream& operator <<(ostream& file,const Id& idd);
   friend istream& operator >>(istream& file, Id& idd);
};

#endif // ID_H_INCLUDED
