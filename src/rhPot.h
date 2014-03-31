#ifndef __RHPOT_H__
#define __RHPOT_H__
#include "potion.h"
#include "item.h"
#include <string>

class RHPot: public Potion
{
	static bool revealed;
public:
    RHPot(int id);
    bool isRevealed();
    std::string getName();
};

#endif
