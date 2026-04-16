// File: lab10.cpp
// Desc: This is a lab illustrating polymorphism in C++
// Date: 1/27/2026
// Author: Samuel Truong

#include "Olympic.h"
#include "Ski.h"
#include "Snowboard.h"
#include <iostream>
#include <string>
using namespace std;

int main() {

  // Instantiation of child objects
  Ski Ski1("Salomon Skis", "Boots", "Poles");
  Snowboard Snowboard1("Burton Snowboard", "Bindings", "Step Ons");
  
  // Olympic Pointers to child objects (Polymorphism)
  Olympic* Ski1Ptr = &Ski1;
  Olympic* Snowboard1Ptr = &Snowboard1;
  
  // Ski functions calls
  Ski1Ptr->PrintName();
  Ski1Ptr->DisplayItems();
  Ski1Ptr->SportActivity();
  
  cout << endl;
  
  // Snowboard function calls
  Snowboard1Ptr->PrintName();
  Snowboard1Ptr->DisplayItems();
  Snowboard1Ptr->SportActivity();

  return 0;

}

