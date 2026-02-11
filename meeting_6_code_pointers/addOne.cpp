/*Title: addOne
Author: CMSC 202
Date: 9/18/2023
Description: This practices scope in c++.
*/
#include <iostream>
using namespace std;

int addOne(int);

int main () {
  int num1 = 10; //declare and initialize integer
  int num2 = 20; //declare and initialize integer
  addOne(num1); //call addOne passing an integer variable
  num2 = addOne(num2); //setting num2 equal to the results of addOne
  cout << "num1 = " << num1 << endl; //output num1
  cout << "num2 = " << num2 << endl; //output num2
  return 0;
}

int addOne(int num1) { //addOne takes in one int argument and returns an int
  num1++; //adds one to the integer variable
  return num1; //returns integer variable
}
