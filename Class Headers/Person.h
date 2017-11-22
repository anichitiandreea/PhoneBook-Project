#ifndef PERSON_H_INCLUDED
#define PERSON_H_INCLUDED

#include "object.h"
#include "Name.h"
#include "Email.h"
#include "Id.h"
#include "Number.h"
#include "IPerson.h"

class Persoana: public IPerson
{

 public:
    Id id;
    Name name;
    Number number;
    Email email;
    Persoana();
    ~Persoana();
    void AddPersoana();
    void Remove();
    friend istream& operator>>(istream& file,Persoana& pers);
    friend ostream& operator<<(ostream& file, Persoana& pers);
};

#endif // PERSON_H_INCLUDED
