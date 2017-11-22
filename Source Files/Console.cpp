#include "Console.h"
#include "Person.h"
#include <regex>

namespace Console
{
	void gotoxy(int x, int y)
	{
		COORD coord;
		coord.X = x;
		coord.Y = y;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
	}

    bool is_email_valid(const std::string& email)
    {
        // define a regular expression
        const std::regex pattern
        ("(\\w+)(\\.|_)?(\\w*)@(\\w+)(\\.(\\w+)).+");

        // try to match the string with the regular expression
        return std::regex_match(email, pattern);
    }


}
