#ifndef LOGINMANAGER_H_INCLUDED
#define LOGINMANAGER_H_INCLUDED

#include "../Headers/User.h"
#include "../Interfaces/ILoginManager.h"

class LoginManager: public ILoginManager
{
   bool CheckUsername(User& user);
   bool CheckPassword(User& user);
public:
   ~LoginManager();
   LoginManager();
   bool Authentificate(User& user); //{bool CheckUsername(User& user); bool CheckPassword(User& user);}
};

#endif // LOGINMANAGER_H_INCLUDED
