// File: Olympic.h
// Desc: This is the parent class for lab 10
// Date: 1/27/2025
// Author: Samuel Truong

#ifndef OLYMPIC_H
#define OLYMPIC_H
#include <iostream>
using namespace std;

class Olympic {
public:
  // Constructor
  // Preconditions: None
  // Postconditions: None
  Olympic();
  
  // Destructor
  // Preconditions: None
  // Postconditions: None
  ~Olympic();
  
  // PrintName() - Prints Olympic sport's name
  // Preconditions: Object exists
  // Postconditions: Object's type is printed
  virtual void PrintName();
  
  // GetName() - returns Olympics's name
  // Preconditions: name is initialized
  // Postconditions: None
  string GetName();
  
  // SetName() - sets the Olympic's name
  // Preconditions: None
  // Postconditions: None
  void SetName(string name);
  
  // DisplayItems() - shows Olympic sport's items
  // Preconditions: None
  // Postconditions: None
  virtual void DisplayItems() = 0; // <- Declares as purely virtual function
  
  // SportActivity() - describes SportActivity
  // Preconditions: Object exists
  // Postconditions: None
  virtual void SportActivity() = 0; // <- Declares as purely virtual function
  
private:
  string m_name; // Name of the Olympic sport
};

#endif
