#ifndef ADMIN_H_INCLUDED
#define ADMIN_H_INCLUDED

#include "object.h"
#include "../Headers/Level.h"

using namespace std;

class Adminmenu : public Level
{
public:
    Adminmenu();
    ~Adminmenu();
  void AddButton();
  static int point;
  void PrintItems();
};

#endif // ADMIN_H_INCLUDED
