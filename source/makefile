CC=g++
CFLAGS=-c -Wall -static
LDFLAGS=
SOURCES=main.C Game.C Board.C Piece.C SpellCaster.C Empty.C FootSoldier.C King.C Knight.C Phantom.C Custom.C Healer.C Dragon.C Necromancer.C GraveYard.C AI.C
OBJECTS=$(SOURCES:.C=.o)
EXECUTABLE=game

all: $(SOURCES) $(EXECUTABLE)
	
$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.C.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	-rm -f *.o *~
