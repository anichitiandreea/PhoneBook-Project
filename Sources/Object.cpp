#include "../Headers/Object.h"
#include <string.h>
#include <iostream>
#include <windows.h>
#include <conio.h>
#include "../Headers/Password.h"
#include "../Headers/Admin.h"
#include "../Headers/Console.h"
#include "../Headers/User.h"

using namespace std;

OBJECT::OBJECT() : _name(""){}

OBJECT::OBJECT( const string& name) : _name(name)
{
}

string& OBJECT::GetName()
{
    return _name;
}

void OBJECT::SetName(const string& name)
{
    _name = name;
}
