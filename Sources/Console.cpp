#include "../Headers/Console.h"
#include "../Headers/Person.h"
#include <windows.h>

namespace Console
{
	void gotoxy(int x, int y)
	{
		COORD coord;
		coord.X = x;
		coord.Y = y;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
	}
	void PrintCenter(string message, int line)
    {
        CONSOLE_SCREEN_BUFFER_INFO csbi;
        int columns,rows;

        GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
        columns = csbi.srWindow.Right - csbi.srWindow.Left + 1;
        rows = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;

       // line = 0;
        gotoxy((columns - message.size()) / 2, line);
        cout<<message;
    }
}
