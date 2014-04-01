#ifndef __VISITOR_H__
#define __VISITOR_H__

class Character;
class Enemy;
class Merchant;
class Dragon;
class Potion;
class BAPot;
class BDPot;
class PHPot;
class RHPot;
class WAPot;
class WDPot;
class Gold;

class Visitor{

public:
	Visitor();
	virtual ~Visitor() = 0;
	virtual int visit(Character* ch);
	virtual int visit(Enemy* enemy);
	virtual int visit(Merchant* merchant);
	virtual int visit(Dragon* dragon);
	virtual void visit(BAPot* potion);
	virtual void visit(BDPot* potion);
	virtual void visit(PHPot* potion);
	virtual void visit(RHPot* potion);
	virtual void visit(WAPot* potion);
	virtual void visit(WDPot* potion);
	virtual void visit(Gold *gold);
};
#endif
