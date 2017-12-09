#ifndef ILOGINMANAGER_H_INCLUDED
#define ILOGINMANAGER_H_INCLUDED

#include "../Headers/User.h"

class ILoginManager
{
public:
   virtual bool CheckUsername(User&) = 0;
   virtual bool CheckPassword(User&) = 0;
   virtual bool Authentificate(User&)= 0;
};

#endif // ILOGINMANAGER_H_INCLUDED
