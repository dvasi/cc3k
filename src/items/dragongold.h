#ifndef __DRAGONGOLD_H__
#define __DRAGONGOLD_H__
#include "gold.h"

class DragonGold: public Gold{

friend class Dragon;

public:
    DragonGold(int id);
    ~DragonGold();
};
#endif
