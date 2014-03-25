CXX = g++
CXXFLAGS = -Wall -MMD
EXEC = cc3k
<<<<<<< HEAD
OBJECTS = cc3k.o game.o world.o character.o floor.o chamber.o passage.o cell.o item.o gold.o fileparser.o 
DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC} -g
=======
OBJECTS = cc3k.o game.o world.o floor.o chamber.o passage.o cell.o item.o gold.o itemfactory.o fileparser.o textdisplay.o
DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}
>>>>>>> 1aeeadf45f3190acfa69d09b6fc53abe9f699bdb

-include ${DEPENDS}

.PHONY: clean

clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}
