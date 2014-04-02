#ifndef __ELF_H__
#define __ELF_H__
#include "player.h"
class Elf: public Player{
public:
    Elf(int x, int y, int id);
    ~Elf();
};
#endif
