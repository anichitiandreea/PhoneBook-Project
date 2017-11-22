#ifndef NUMBER_H_INCLUDED
#define NUMBER_H_INCLUDED

#include "IContact.h"

class Number: public IContact
{
char *number;
public:
  Number();
  ~Number();
  char* Get();
  void AddNumber();
  void Print();
  friend ostream& operator <<(ostream& file,const Number& numb);
  friend istream& operator >>(istream& file, Number& numb);

};

#endif // NUMBER_H_INCLUDED
