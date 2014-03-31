#ifndef __BDPOT_H__
#define __BDPOT_H__
#include "potion.h"
#include "item.h"

class BDPot: public Potion
{
	static bool revealed;
public:
    BDPot(int id);
    bool isRevealed();
};

#endif
