# Hangman (C++)

A simple ASCII-art-based Hangman game that runs in the terminal.  
This project was written as a fun and relaxing side project to practice C++.

## Features

- Classic Hangman gameplay using keyboard input
- ASCII art visuals that update as you guess
- Replay and quit options
- Enter full-word guesses at any time

## Usage

### Controls

- Type any letter (`a`–`z`) to guess
- Press `1` to restart the game
- Press `2` to quit the game
- You may guess the full word by typing it in completely

## Setup

### Requirements

- C++ compiler (e.g. `g++`)
- `make` (optional, if using the provided Makefile)
- A terminal or shell environment

### Build

To compile using `make`:

```bash
make
```

To build manually:

```bash
g++ main.cpp Game.cpp Body.cpp -o hangman
```

### Run

```bash
./hangman
```

## File Overview

- `main.cpp` – Entry point for the game
- `Game.cpp`, `Game.h` – Core gameplay logic
- `Body.cpp`, `Body.h` – ASCII drawing and body rendering
- `wordlist.txt` – List of words to guess
- `CMakeLists.txt` – For CMake-based builds (optional)
- `makefile` – For standard `make`-based build
