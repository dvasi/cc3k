#ifndef __ITEM_H__
#define __ITEM_H__
#include <string>

class Visitor;

class Item{

	static int idCount;
	protected:
		int id;
		bool lootable;
		bool useable;
		
	public:
		Item();
		Item(int id, bool lootable=false, bool useable=true);
		static int generateId();
		int getId();
		bool canPickUp();
		bool canUse();
		virtual std::string getName();
		virtual bool isRevealed();
		virtual ~Item() = 0;
		virtual void accept(Visitor &v);
};
#endif
