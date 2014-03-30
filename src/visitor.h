#ifndef __VISITOR_H__
#define __VISITOR_H__

class Character;
class Potion;
class Gold;

class Visitor{

	public:
		Visitor();
		virtual ~Visitor() = 0;
		virtual void visit(Character* ch);
		virtual void visit(Potion *potion);
		virtual void visit(Gold *gold);
};
#endif
