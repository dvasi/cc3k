#ifndef __WDPOT_H__
#define __WDPOT_H__
#include "potion.h"
#include "item.h"

class WDPot: public Potion
{
	static bool revealed;
public:
    WDPot(int id);
    bool isRevealed();
};

#endif

