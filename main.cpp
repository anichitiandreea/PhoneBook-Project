#include <iostream>
#include "object.h"
#include "Admin.h"
#include <fstream>

using namespace std;


int main()
{
   ILevel *level=new Level();
   level->PrintItems();

    return 0;
}
