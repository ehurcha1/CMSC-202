/*Title: pointer1.cpp
Author: CMSC 202
Date: 9/18/2023
Description: This is introducing pointers in c++.
*/
#include <iostream>
using namespace std;

int main() {
  int x = 10; //Declare and initialize normal integer variable
  int *ptrX = &x; //Declare integer pointer and initialize to the address of x
  cout << "x = " << x << endl; //Output the value of x
  cout << "&x = " << &x << endl; //Output the address-of x
  cout << "ptrX = " << ptrX << endl; //Output the value of ptrX (address of x)
  cout << "*ptrX = " << *ptrX << endl; //Output the dereferenced ptrX (value of x)
  cout << "&ptrX = " << &ptrX << endl; //Output the address-of ptrX
  return 0;
}