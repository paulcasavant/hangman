CC=g++
CFLAGS=-I

hangman: Game.h Game.cpp Body.h Body.cpp main.cpp
	$(CC) -o hangman main.cpp Game.cpp Body.cpp $(CFLAGS).
