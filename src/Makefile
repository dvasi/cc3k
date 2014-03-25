CXX = g++
CXXFLAGS = -Wall -MMD
EXEC = cc3k
OBJECTS = cc3k.o game.o world.o character.o floor.o chamber.o passage.o cell.o item.o gold.o itemfactory.o fileparser.o textdisplay.o commandinterpreter.o playerinterpreter.o
DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -lncurses -o ${EXEC}

-include ${DEPENDS}

.PHONY: clean

clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}
