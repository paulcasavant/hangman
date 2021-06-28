CC=g++
CFLAGS=-I

hangman: Game.cpp Body.cpp main.cpp
	$(CC) -o hangman Game.cpp Body.cpp main.cpp $(CFLAGS).
