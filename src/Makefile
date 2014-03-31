CXX = g++
CXXFLAGS = -Wall -MMD -g
EXEC = cc3k
OBJECTS = cc3k.o game.o character.o commandinterpreter.o command.o movecommand.o attackcommand.o itemusecommand.o playerinterpreter.o enemyinterpreter.o player.o enemy.o dragon.o goblin.o merchant.o phoenix.o troll.o werewolf.o vampire.o human.o floor.o chamber.o cell.o item.o potion.o gold.o wapot.o wdpot.o rhpot.o bapot.o bdpot.o phpot.o itemfactory.o enemyfactory.o visitor.o attackvisitor.o itemusevisitor.o fileparser.o textdisplay.o  
DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -lncurses -o ${EXEC}

-include ${DEPENDS}

.PHONY: clean

clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}
