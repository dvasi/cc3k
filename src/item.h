#ifndef __ITEM_H__
#define __ITEM_H__
class Item{

	static int idCount;
		
	protected:
		int id;
		
	public:
		Item(int id);
		static int generateId();
		virtual ~Item() = 0;
		virtual void use();
};
#endif
