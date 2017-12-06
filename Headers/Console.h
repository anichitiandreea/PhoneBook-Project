#ifndef CONSOLE_H_INCLUDED
#define CONSOLE_H_INCLUDED

#include <windows.h>
#include "../Headers/Person.h"

namespace Console
{
    void gotoxy(int x,int y);
    bool is_email_valid(const std::string& email);
    void PrintCenter(string message, int line);
    void printMessage();
    void hideCursor();
}

#endif // CONSOLE_H_INCLUDED
