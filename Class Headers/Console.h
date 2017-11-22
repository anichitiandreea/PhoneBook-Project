#ifndef CONSOLE_H_INCLUDED
#define CONSOLE_H_INCLUDED

#include <windows.h>
#include "Person.h"

namespace Console
{
	void gotoxy(int x,int y);
    bool is_email_valid(const std::string& email);
}

#endif // CONSOLE_H_INCLUDED
