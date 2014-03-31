#ifndef __WAPOT_H__
#define __WAPOT_H__
#include "potion.h"
#include "item.h"
#include <string>

class WAPot: public Potion
{
	static bool revealed;
public:
    WAPot(int id);
    bool isRevealed();
    std::string getName();
};

#endif
