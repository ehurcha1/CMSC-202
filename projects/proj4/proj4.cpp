/***********************************************************
 ** File:    proj4.cpp
 ** Project: CMSC 202 - Project 4 (Kingdom Rush Edition)
 ** This file contains main for the project
 **********************************************************/

#include "Game.h"
#include <iostream>
#include <cstdlib>

using namespace std;

int main() {
  srand(time(NULL)); // Seeds random number generator
  Game g; // Creates a new game
  g.StartGame(); // Starts the game
  return 0;
}
