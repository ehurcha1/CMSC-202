// File: Ski.h
// Desc: This is one of the child classes for lab 10
// Date: 1/27/2026
// Author: Samuel Truong

#ifndef SKI_H
#define SKI_H
#include "Olympic.h"
#include <iostream>
using namespace std;

class Ski : public Olympic {
public:
  // Constructor
  // Preconditions: None
  // Postconditions: None
  Ski();
  
  // Destructor
  // Preconditions: None
  // Postconditions: None
  ~Ski();
  
  // Overloaded Constructor
  // Preconditions: None
  // Postconditions: Member variables initialized
  Ski(string name, string item1, string item2);
  
  // DisplayItems() - shows Ski's items
  // Preconditions: has a name and two items
  // Postconditions: None
  void DisplayItems() final;
  
  // SportActivity() - describes Ski's activity
  // Preconditions: None
  // Postconditions: None
  void SportActivity() final;
private:
  string m_name; // name of olympic activity
  string m_item1; // Ski's first item
  string m_item2; // Ski's second item
};

#endif

