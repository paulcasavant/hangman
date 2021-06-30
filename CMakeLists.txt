cmake_minimum_required(VERSION 3.17)
project(hangman)

set(CMAKE_CXX_STANDARD 11)

add_executable(hangman main.cpp Game.cpp Body.cpp)