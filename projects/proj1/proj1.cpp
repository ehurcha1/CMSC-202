/*****************************************
** File:    proj1.cpp
** Project: CMSC 202 Project 1, Spring 2026
** Author:  Elliot Hurchalla
** Date:    02/22/26
** Section: 14
** E-mail:  ehurcha1@umbc.edu
**
**This program will read an input file that has a 10x10 grid of letters
**and a list of 6 letter words. It then displays the grid with numbered rows and columns for user input.
**It also displays the list of words in the grid.
**The user will then be prompted to enter the coordinates of the first and last letter of a word in the grid.
**Input will be checked for validity.
**If valid, the word will be removed from the list.
**When all words are removed from the list, the program ends.
*****************************************/

#include <iostream>
using namespace std;

//Global Constants
const int GRID_SIZE = 10; // Size of the grid
