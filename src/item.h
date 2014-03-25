#ifndef __ITEM_H__
#define __ITEM_H__
class Item{

	static int idCount;
		
	protected:
		int id;
		
	public:
		Item(int id);
		static int generateId();
<<<<<<< HEAD
=======
		int getId();
>>>>>>> 1aeeadf45f3190acfa69d09b6fc53abe9f699bdb
		virtual ~Item() = 0;
		virtual void use();
};
#endif
