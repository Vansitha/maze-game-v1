CC = gcc
CFLAGS = -Wall -pedantic -ansi
OBJ = main.o map.o generateMap.o game.o terminal.o visibilityF.o
EXEC = maze

ifdef DARK
CFLAGS += -D DARK
DARK : clean $(EXEC)
endif

ifdef DEBUG
CFLAGS += -D DEBUG
DEBUG : clean $(EXEC)
endif

$(EXEC): $(OBJ)
	$(CC) $(OBJ) -o $(EXEC)

main.o: main.c map.h generateMap.h game.h terminal.h visibilityF.h
	$(CC) $(CFLAGS) main.c -g -c

map.o: map.c map.h
	$(CC) $(CFLAGS) map.c -c 

generateMap.o: generateMap.c generateMap.h
	$(CC) $(CFLAGS) generateMap.c -c

game.o: game.c game.h
	$(CC) $(CFLAGS)  game.c -c

terminal.o: terminal.c terminal.h
	$(CC) $(CFLAGS) terminal.c -c

visibilityFeature.o: visibilityF.c visibilityF.h
	$(CC) $(CFLAGS) visibilityF.c -c

clean:
	rm -f $(EXEC) $(OBJ)
