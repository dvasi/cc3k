#include "rhpot.h"
#include "visitor.h"
#include <string>
using namespace std;

RHPot::RHPot(int id) :
    Potion(id, 10, '0'){
}

bool RHPot::isRevealed(){
    return RHPot::revealed;
}

void RHPot::revealPotion(){
    RHPot::revealed = true;
}

void RHPot::concealPotion(){
    RHPot::revealed = false;
}

string RHPot::getName(){
    return "RH potion";
}

void RHPot::accept(Visitor &v){
    v.visit(this);
}

bool RHPot::revealed = false;
