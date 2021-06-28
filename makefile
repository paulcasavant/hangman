CC=g++
CFLAGS=-I

hangman: Game.cpp Body.cpp main.cpp
	$(CC) hangman Game.cpp Body.cpp main.cpp $(CFLAGS).
