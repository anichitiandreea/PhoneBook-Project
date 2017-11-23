#include <iostream>
#include "../Headers/Object.h"
#include "../Headers/Admin.h"
#include <fstream>

using namespace std;

int main()
{
	ILevel *level = new Level();
	level->PrintItems();
	cout<<"salut";
	return 0;
}
