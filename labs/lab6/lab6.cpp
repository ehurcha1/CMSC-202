/*
* File: lab6.cpp
* Assignment: CMSC202 Lab 6, Spring 2026
* Author:
* Date:                    
* Email:
* Makes a sandwich order using user input, then displays it.
*/

#include "Sandwich.h"
#include <vector>
#include <iostream>
using namespace std;

// sets CLUB = 0, HOAGIE = 1, BURGER = 2
enum SANDWICH_TYPE { CLUB, HOAGIE, BURGER };

// To Do:
// 1. Write Sandwich.cpp and make sure it compiles (make Sandwich.o).
// 2. Write FillSandwichOrder below.
// 3. Write DisplayWithoutIterator below.
// 4. Write void DisplayWithIterator below

// Write FillSandwichOrder here:
void FillSandwichOrder(vector<Sandwich> &sandwichOrder) {
  // Declare variables to hold number of customers, flavors, and name

  
  // Ask the user for number of customers
  

  // Clear input buffer
  
  
  // Iterate through number of customers
  // Get customer name and type for each customer


  // Clear input buffer

  
  // Create a Sandwich object with the info and push it to the vector.

  
  // You may have to use:
  //   if(cin.peek() == '\n')
  //      cin.ignore(256, '\n');
  // to clear the buffer.
  
} // End of FillSandwichOrder


// You may use this code for the DisplayWithoutIterator
// and DisplayWithIterator use this code
/*
  switch (FILL THIS IN) {
  case CLUB:
    cout << "- Club for ";
    break;
  case HOAGIE:
    cout << "- Hoagie for ";
    break;
  case BURGER:
    cout << "- Burger for ";
    break;
  default:
    cout << "- unknown flavor for ";
    break;
  }
*/

// Please write DisplayWithoutIterator.
// Display the number of sandwiches in the order.
// For each sandwich, display the type and name.
// Use a switch statement to display the type (provided).
// Don't forget to display the name as well.
void DisplayWithoutIterator(vector<Sandwich> &sandwichOrder) {

}

// Please write DisplayWithIterator.
// This function is the same as the one above, but uses an
// iterator to display the sandwich order.
void DisplayWithIterator(vector<Sandwich> &sandwichOrder) {

}



// Main
// Provided.

int main() {
  vector<Sandwich> sandwichOrder; //Creates an empty vector
  FillSandwichOrder(sandwichOrder); //Populates sandwichOrder
  
  cout << "Displaying Sandwich Order without iterator:" << endl;
  DisplayWithoutIterator(sandwichOrder); //Displays information using loop
  cout << endl << "Displaying Sandwich Order with iterator:" << endl;
  DisplayWithIterator(sandwichOrder); //Displays information using iterators

  cout << endl << "Enjoy the food!" << endl;
  return 0;
}
