#include "object.h"
#include <string.h>
#include <iostream>
#include <windows.h>
#include <conio.h>
#include "Password.h"
#include "Admin.h"
#include "Console.h"
#include "User.h"

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
