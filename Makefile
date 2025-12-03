all: a.exe

a.exe: game.o library.o
	gcc game.o library.o -o a.exe

game.o: game.c library.h
	gcc -c game.c

library.o: library.c library.h
	gcc -c library.c

clean:
	rm -f *.o a.exe