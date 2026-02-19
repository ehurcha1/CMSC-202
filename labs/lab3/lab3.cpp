/*****************************************
 ** File:    lab3.cpp
 ** Project: CMSC 202 Lab 3, Spring 2026
 **
 ** Lab 3 involves using arrays. In this file you need to
 ** implement the main() and getEvenCount() functions 
 ***********************************************/

#include <iostream>
using namespace std;

//Global Constants
const int NUM_NUMBERS = 4; //Size of array and count of numbers to read

// Function Name: isUnique
// Pre-conditions: Requires a new number, and an array of numbers
// Post-conditions: Returns true if the new number is not in the array, else false
// PROVIDED Below
bool isUnique(int, int[]);

// Function Name: getEvenCount
// Pre-conditions: Requires an array
// Post-conditions: Returns the number of even numbers in the array
int getEvenCount(int[]);

// Implement main HERE*********
int main() {
  // Declare your necessary variable(s)
  int input;
  int i = 0;
  // Declare array (myArray)
  int myArray[NUM_NUMBERS] = {0};
  
  // Populate Array with unique, non-zero numbers from user for size NUM_NUMBERS
  for (int i = 0; i < NUM_NUMBERS; i++){
    cout << "Enter a unique number (not including 0): ";
    cin >> input;

    //if the input is 0, notifies user and re-prompts
    if (input == 0) {
      cout << "is an invalid input, try another number: ";
      cin >> input;
    }

    //if the input is not unique (already in array), notifies user and re-prompts
    if (isUnique(input, myArray) == false){
      cout << "This number already exists in the array, try another number: ";
      cin >> input;
    //Otherwise, adds to the array
    }else{
      myArray[i] = input;
    }
  }
  
  //Iterate through array and display all numbers (not sorted)
  for (int i = 0; i < NUM_NUMBERS; i++){
    cout << myArray[i] << " ";
  }
  cout << endl;
  
  //Display the number of even numbers in array using getEvenCount
  cout << "Number of even numbers in the array is: " << getEvenCount(myArray) << endl;
  
  return 0;
}


// Implementation of function that checks input uniqueness (true if unique else false)
// isUnique is provided
//parses through array and checks if passed value exists in array already
bool isUnique(int input, int array1[]){
  for (int i = 0; i < NUM_NUMBERS; i++){
    if (input == array1[i])
      return false;
  }
  return true;
}

// Implement getEvenCount here
// Function that returns the number of even numbers in an array
int getEvenCount(int myArray[]){
  int evenCount = 0;
  for (int i = 0; i < NUM_NUMBERS; i++){
    if (myArray[i] % 2 == 0)
      evenCount++;
  }
  return evenCount;
}
