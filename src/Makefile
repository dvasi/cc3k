CXX = g++
CXXFLAGS = -Wall -MMD
EXEC = cc3k
OBJECTS = cc3k.o game.o character.o player.o enemy.o vampire.o human.o floor.o chamber.o passage.o cell.o item.o gold.o itemfactory.o enemyfactory.o fileparser.o textdisplay.o commandinterpreter.o command.o movecommand.o playerinterpreter.o
DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -lncurses -o ${EXEC}

-include ${DEPENDS}

.PHONY: clean

clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}
