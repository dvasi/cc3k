CXX = g++
CXXFLAGS = -Wall -MMD
EXEC = cc3k
OBJECTS = cc3k.o game.o world.o floor.o chamber.o passage.o cell.o fileparser.o 
DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC} -g

-include ${DEPENDS}

.PHONY: clean

clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}
