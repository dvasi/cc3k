SRCDIR = src
INCLUDE = -I${SRCDIR} -I${SRCDIR}/world -I${SRCDIR}/items -I${SRCDIR}/characters -I${SRCDIR}/input
CXX = g++
CXXFLAGS = -Wall -MMD -g
EXEC = cc3k
OBJDIR = obj
OBJ = cc3k.o game.o character.o commandinterpreter.o command.o movecommand.o attackcommand.o itemusecommand.o playerinterpreter.o enemyinterpreter.o dragoninterpreter.o player.o enemy.o dragon.o goblin.o merchant.o phoenix.o troll.o werewolf.o vampire.o human.o dwarf.o elf.o orc.o floor.o chamber.o cell.o item.o potion.o gold.o smallgold.o normalgold.o dragongold.o wapot.o wdpot.o rhpot.o bapot.o bdpot.o phpot.o itemfactory.o enemyfactory.o visitor.o attackvisitor.o itemusevisitor.o fileparser.o textdisplay.o  
OBJECTS = $(addprefix ${OBJDIR}/,${OBJ})
DEPENDS = ${OBJECTS:.o=.d}

all: ${OBJDIR} ${EXEC}

${OBJDIR}:
	mkdir -p ${OBJDIR}

${OBJDIR}/%.o: src/%.cc
	${CXX} ${CXXFLAGS} ${INCLUDE} -c $< -o $@

${OBJDIR}/%.o: src/world/%.cc
	${CXX} ${CXXFLAGS} ${INCLUDE} -c $< -o $@
	
${OBJDIR}/%.o: src/items/%.cc
	${CXX} ${CXXFLAGS} ${INCLUDE} -c $< -o $@
	
${OBJDIR}/%.o: src/characters/%.cc
	${CXX} ${CXXFLAGS} ${INCLUDE} -c $< -o $@
	
${OBJDIR}/%.o: src/input/%.cc
	${CXX} ${CXXFLAGS} ${INCLUDE} -c $< -o $@
	
${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${INCLUDE} ${OBJECTS} -lncurses -o ${EXEC}

-include ${DEPENDS}

.PHONY: clean

clean:
	@rm ${OBJECTS} ${EXEC} ${DEPENDS}
	@rm -rf ${OBJDIR}
