#ifndef IPERSON_H_INCLUDED
#define IPERSON_H_INCLUDED

class IPerson
{
public:
    virtual void IsEmailValid()       = 0;
    virtual void Remove()             = 0;
};

#endif // IPERSON_H_INCLUDED
