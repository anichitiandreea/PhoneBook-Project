#ifndef ICONTACT_H_INCLUDED
#define ICONTACT_H_INCLUDED

class IContact
{
public:

	virtual void Set(string) = 0;
    virtual string Get()     = 0;

};

#endif // ICONTACT_H_INCLUDED
