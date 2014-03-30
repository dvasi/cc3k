#ifndef __ITEM_H__
#define __ITEM_H__
class Visitor;

class Item{

	static int idCount;
	protected:
		int id;
		bool lootable;
		bool useable;
		
	public:
		Item(int id, bool lootable=false, bool useable=true);
		static int generateId();
		int getId();
		bool canPickUp();
		bool canUse();
		virtual ~Item() = 0;
		virtual void accept(Visitor &v);
};
#endif
