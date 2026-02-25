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
#include <string>
#include <cstdlib>
using namespace std;

//Constants
const int GRID_ROW = 10; // Size of the grid
const int GRID_COL = 10; // Size of the grid
const int WORD_COUNT = 6; // Number of words in the list

//Function Prototypes
void readFile(string inputFile, string gridArray[GRID_ROW][GRID_COL], string wordList[WORD_COUNT]);
void displayGrid(string gridArray[GRID_ROW][GRID_COL]);
void displayWords(string wordList[WORD_COUNT]);
bool isValid(int inputRow, int inputCol);
int determineDirection(int startRow, int startCol, int endRow, int endCol);
string buildWord(string gridArray[GRID_ROW][GRID_COL], int startRow, int startCol, int endRow, int endCol);
bool inWordList(string wordList[WORD_COUNT], string builtWord);

int main(){
    //Declare necessary variables
    string inputFile;
    string gridArray[GRID_ROW][GRID_COL];
    string wordList[WORD_COUNT];
    int wordsFound = 0;
    int startRow;
    int startCol;
    int endRow;
    int endCol;

    //Read file and populate grid and word list
    cout << "What is the file name?" << endl;
    cin >> inputFile;
    readFile(inputFile, gridArray, wordList);

    //Do-While there are still words in the list
    do {

        //Display grid and word list
        displayGrid(gridArray);
        displayWords(wordList);

        //Prompt user for start and end coordinates
        cout << "What are the coordinates of the start of the word? (row space column)" << endl;
        cin >> startRow >> startCol;
        cout << "What are the coordinates of the end of the word? (row space column)" << endl;
        cin >> endRow >> endCol;

        //Check if input is valid
        if (isValid(startRow, startCol) == false || isValid(endRow, endCol) == false){
            cout << "INVALID COORDINATES" << endl;
        }

        //If valid, determine if row, column, or diagonal
        else if (determineDirection(startRow, startCol, endRow, endCol) == -1){
            cout << "INVALID COORDINATES" << endl;
        }
        else {
            //Build the word from the grid
            string forward = buildWord(gridArray, startRow, startCol, endRow, endCol);
            string backward = buildWord(gridArray, endRow, endCol, startRow, startCol);

            //Check if the built word is in the list
            if (inWordList(wordList, forward) == true) {
                cout << "Hooray! You found the word, " << forward << "!" << endl;
                wordsFound++;
            }
            else if (inWordList(wordList, backward) == true) {
                cout << "Hooray! You found the word, " << backward << "!" << endl;
                wordsFound++;
            }

            //Else, notify failure
            else {
                cout << "Sorry, that isn't one of the words. Please try again." << endl;
            }
        }
    } while (wordsFound < WORD_COUNT);

    //Notify user of success and end program
    cout << "Congratulations! You found all of the words!" << endl;
    return 0;
}

//Reads file and returns grid array and words as two separate lists
void readFile(string inputFile, string gridArray[GRID_ROW][GRID_COL], string wordList[WORD_COUNT]){
    
    ifstream fileData(inputFile);

    for (int row = 0; row < GRID_ROW; row++){
        string rowText;
        fileData >> rowText;
        
        for (int col = 0; col < GRID_COL; col++){
            string letter = "";
            letter = letter + rowText[col];
            gridArray[row][col] = letter;
        }
    }

    for (int wordNum = 0; wordNum < WORD_COUNT; wordNum++){
        fileData >> wordList[wordNum];
    }

    fileData.close();   
}

//Displays the 10x10 grid with numbered rows and columns
void displayGrid(string gridArray[GRID_ROW][GRID_COL]){
    
    cout << "   0 1 2 3 4 5 6 7 8 9" << endl;
    
    for (int row = 0; row < GRID_ROW; row++){
        cout << row << " ";
        for (int col = 0; col < GRID_COL; col++){
            cout << gridArray[row][col] << " ";
        }
        cout << endl;
    }
}

/*
Displays all remaining words in the list. Will catch words that are now blank due to
them being found.
*/
void displayWords(string wordList[WORD_COUNT]){

    for (int wordNum = 0; wordNum < WORD_COUNT; wordNum++){
        if (wordList[wordNum] != "")
            cout << wordList[wordNum] << endl;
    }
}

//Checks if user input is a valid coordinate
bool isValid(int inputRow, int inputCol){
    if (inputRow < 0)
        return false;
    if (inputRow > 9)
        return false;
    if (inputCol < 0)
        return false;
    if (inputCol > 9)
        return false;
    return true;
}

//Takes start and end coords to determine if horizontal, vertical, or diagonal
//If none of the conditions are met, a -1 is returned to signal invalid
int determineDirection(int startRow, int startCol, int endRow, int endCol){
    if (startRow == endRow)
        return 1; //Horizontal
    if (startCol == endCol)
        return 2; //Vertical
    if (abs(endRow - startRow) == abs(endCol - startCol))
        return 3; //Diagonal
    return -1;
}

/*
Builds the word from given coords by stepping from start to finish in the right direction
depending on the order the coords were given. I first attempted to build everything in a 
forward direction first, then if failed, I'd reverse the word and check it again. If that 
failed then I'd finally return an invalid word prompt. Unfortunetly, I could never figure out 
how to reverse the word. Definitely not as easy as Python's reverse string [::-1]
*/
string buildWord(string gridArray[GRID_ROW][GRID_COL], int startRow, int startCol, int endRow, int endCol){
    string builtWord = "";
    
    int rowStep = 0;
    int colStep = 0;

    if (endRow > startRow)
        rowStep = 1;
    else if (endRow < startRow)
        rowStep = -1;
    
    if (endCol > startCol)
        colStep = 1;
    else if (endCol < startCol)
        colStep = -1;

    int steps = abs(endRow - startRow);
    if (steps == 0)
        steps = abs(endCol - startCol);
    
    int r = startRow;
    int c = startCol;
    for (int step = 0; step <= steps; step++){
        builtWord += gridArray[r][c];
        r += rowStep;
        c += colStep;
    }
    return builtWord;
}

/*
Checks if the built word is in the list of words. I had a remove word function
but I decided it would be much cleaner to "remove" the word immediately if the
built word matched a word in the list.
*/
bool inWordList(string wordList[WORD_COUNT], string builtWord){
    for (int wordNum = 0; wordNum < WORD_COUNT; wordNum++){
        if (wordList[wordNum] == builtWord) {
            wordList[wordNum] = "";
            return true;
        }
    }
    return false;
}