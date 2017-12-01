#include "../Headers/Option.h"
#include <string>
#include <iostream>
#include <windows.h>
#include "../Headers/Password.h"
#include "../Headers/Console.h"
#include "../Headers/Username.h"

using namespace std;

Username::Username()
{
    Console::PrintCenter( "Enter the username: ", 10);
}
void Username::EnterUser()
{
    cin >> username;
}
int Username::ReturnUser()
{
    if((username.find("Andreea") != std::string::npos) and username.size() == 7)
        return 1;
    return 0;
}
Username::~Username() {}
