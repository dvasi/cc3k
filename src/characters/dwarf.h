#ifndef __DWARF_H__
#define __DWARF_H__
#include "player.h"

class Dwarf: public Player{

public:
    Dwarf(int x, int y, int id);
    ~Dwarf();
};
#endif
