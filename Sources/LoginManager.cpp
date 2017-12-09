#include "../Headers/User.h"
#include "../Headers/LoginManager.h"
#include <string>
using namespace std;

bool LoginManager::CheckUsername(User& user)
{
    if((user.GetUsername().find("Andreea") != std::string::npos) and user.GetUsername().size() == 7)
            return true;
    return false;
}
bool LoginManager::CheckPassword(User& user)
{
    if((user.GetPassword().find("andreea") != std::string::npos) and user.GetPassword().size() == 7)
            return true;
    return false;
}

LoginManager::LoginManager() {}

LoginManager::~LoginManager() {}

bool LoginManager::Authentificate(User& user)
{
    if(CheckPassword(user) and CheckUsername(user))
        return true;
    return false;
}
