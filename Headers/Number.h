#ifndef NUMBER_H_INCLUDED
#define NUMBER_H_INCLUDED

#include "../Interfaces/IContact.h"

class Number
{
  string value;
public:
  Number(string ="");
  ~Number();
  string  Get();
  void Set(string);
  friend ostream& operator <<(ostream& file, Number& numb);
  friend istream& operator >>(istream& file, Number& numb);

};

#endif // NUMBER_H_INCLUDED
