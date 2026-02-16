/*
  File: lab2.cpp

  This is the starting file for project 2 for CMSC 202

  Description: This program practices C++ regarding input/output,
  using the functions in C++
*/

//Libraries
#include <iostream> //Used for cin and cout
using namespace std;


// Constants
// Create a constant for LIMIT so that it is equal to 10

// Implement function prototypes for doubleQuotient() and greaterThanTen():

// **main**
// main should have one line of code (other than return 0). It should pass the
// results of doubleQuotient to greaterThanTen in one line
// Implement main here:

// **doubleQuotient**
// Prompts the user for the dividend and stores as a double.
// Prompts the user for the divisor and stores as a double.
// Returns the result of quotient
// Implement doubleQuotient here:

// **greaterThanTen**
//  This function should display a message to indicate whether
//  the double passed is greater than ten or not
//  Use the global constant LIMIT (10)
//  This function does not return anything
// Implement greaterThanTen here:

const int LIMIT = 10;

double doubleQuotient(int dividend, int divider);
int greaterThanTen(double quotient, int LIMIT);
 
int dividend=0;
int divider=0;
double quotient=0.0;


int main(){

  cout << "Enter the dividend: " << endl;
  cin >> dividend;

  cout << "Enter the divisor: " << endl;
  cin >> divider;

  double quotient = doubleQuotient(dividend, divider);
  cout << "The double quotient is: " << quotient << endl;
  greaterThanTen(quotient, LIMIT);
  
  return 0;
}

double doubleQuotient(int dividend, int divider){
    return(dividend/divider);
  }

int greaterThanTen(double quotient, int LIMIT){
    if(quotient > LIMIT){
      cout << "Your quotient is bigger than 10!" << endl;
    }else{
      cout << "Your quotient is less than 10." << endl;
    }
    return 0;
  }