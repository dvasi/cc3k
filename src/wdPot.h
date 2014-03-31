#ifndef __WDPOT_H__
#define __WDPOT_H__
#include "potion.h"
#include "item.h"
#include <string>

class WDPot: public Potion
{
	static bool revealed;
public:
    WDPot(int id);
    bool isRevealed();
    std::string getName();
};

#endif

