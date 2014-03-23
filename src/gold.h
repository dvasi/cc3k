#ifndef __GOLD_H__
#define __GOLD_H__
#include "item.h"
class Gold : public Item{

	int value;
	public:
		Gold(int id, int value=2);
		~Gold();
		void use();
		int getValue();
		void setValue(int value);
};
#endif
