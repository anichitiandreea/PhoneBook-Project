#include "../Headers/Option.h"
#include <string.h>
#include <iostream>
#include <windows.h>
#include <conio.h>
#include "../Headers/Password.h"
#include "../Headers/Admin.h"
#include "../Headers/Console.h"
#include "../Headers/UserMenu.h"

using namespace std;

Option::Option() : name("") {}

Option::Option(const string& _name) : name(_name) {}

string& Option::GetName()
{
    return name;
}

void Option::SetName(const string& _name)
{
    name = _name;
}
