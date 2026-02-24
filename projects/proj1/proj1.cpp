/*****************************************
** File:    proj1.cpp
** Project: CMSC 202 Project 1, Spring 2026
** Author:  Elliot Hurchalla
** Date:    02/22/26
** Section: 14
** E-mail:  ehurcha1@umbc.edu
**
**This program will read an input file that has a 10x10 grid of letters
**and a list of 6 words. It then displays the grid with numbered rows and columns for user input.
**It also displays the list of words in the grid.
**The user will then be prompted to enter the coordinates of the first and last letter of a word in the grid.
**Input will be checked for validity.
**If valid, the word will be removed from the list.
**When all words are removed from the list, the program ends.
*****************************************/

#include <iostream>
#include <fstream>
using namespace std;

//Constants
const int GRID_Y = 10; // Size of the grid
const int GRID_X = 10; // Size of the grid

//Function Prototypes

//Reads file and returns grid array and words as two separate lists

//Displays the 10x10 grid with numbered rows and columns. Top left is 0x0, bottom right is 9x9

//Displays all remaining words in the list

//Checks if user input is a valid coordinate

//Takes start and end coords to determine if row, column, or diagonal

//Builds the word by walking through grid from start to end coords

//Checks if the built word is in the list of words

//Removes the word from the list if it is found

int main(){
    //Declare necessary variables

    //Read file and populate grid and word list

    //Display grid and word list

    //While there are still words in the list
        //Prompt user for start and end coordinates

        //Check if input is valid

        //If valid, determine if row, column, or diagonal

        //Build the word from the grid

        //Check if the built word is in the list

        //If it is, remove it from the list and notify user of success
        //Else, notify user of failure

    //Notify user of success and end program
    return 0;
}

//Function definitions go here