#ifndef __BAPOT_H__
#define __BAPOT_H__
#include "potion.h"
#include "item.h"

class BAPot: public Potion
{
	static bool revealed;
public:
    BAPot(int id);
    bool isRevealed();
};

#endif
