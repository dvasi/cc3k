#ifndef __VISITOR_H__
#define __VISITOR_H__

class Character;

class Visitor{

	public:
		Visitor();
		virtual ~Visitor() = 0;
		virtual void visit(Character* ch) = 0;
};
#endif
