/*Title: addTwo.cpp
Author: CMSC 202
Date: 9/18/2023
Description: This practices pointers and returning two values from a function in c++.
*/
#include <iostream>
using namespace std;

void addTwo(int*,int*);

int main () {
  int num1 = 10; //declare and initialize integer
  int num2 = 20; //declare and initialize integer
  int *numPtr1 = &num1; //declare and initialize integer pointer
  int *numPtr2 = &num2; //declare and initialize integer pointer
  addTwo(&num1, &num2); //call addTwo passing it the addresses of two integer variables
  addTwo(numPtr1, numPtr2); //call addTwo passing it two integer pointers
  addTwo(&num1, numPtr2); //call addTwo passing it one address of integer and one integer pointer
  cout << "num1 = " << num1 << endl; //output num1
  cout << "num2 = " << num2 << endl; //output num2
  cout << "*numPtr1 = " << *numPtr1 << endl; //output dereferenced numPtr1
  cout << "*numPtr2 = " << *numPtr2 << endl; //output dereferenced numPtr2
  return 0;
}

void addTwo(int *ptr1, int *ptr2) { //addTwo takes in two integer pointers (void function)
  /* add two to the value of the 
     integer ptr1 points to */
  *ptr1 = *ptr1 + 2; //dereferences the ptr1 and adds two
  /* add two to the value of the 
     integer ptr2 points to */
  *ptr2 = *ptr2 + 2; //dereferences the ptr2 and adds two
  /* return nothing */
  /* NOTE - SCOPE! */
}
