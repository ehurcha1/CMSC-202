// File: Snowboard.h
// Desc: This is one of the child classes for lab 10
// Date: 1/27/2026
// Author: Samuel Truong

#ifndef SNOWBOARD_H
#define SNOWBOARD_H
#include "Olympic.h"
#include <iostream>
using namespace std;

class Snowboard : public Olympic {
public:
  // Constructor
  // Preconditions: None
  // Postconditions: None
  Snowboard();
  
  // Destructor
  // Preconditions: None
  // Postconditions: None
  ~Snowboard();
  
  // Overloaded Constructor
  // Preconditions: None
  // Postconditions: Member variables initialized
  Snowboard(string name, string item1, string item2);
  
  // displayItems() - shows Snowboard's items
  // Preconditions: has a name and two items
  // Postconditions: None
  void DisplayItems() final;
  
  // SportActivity() - describes Snowboard's activity
  // Preconditions: None
  // Postconditions: None
  void SportActivity() final;
  
private:
  string m_name; //Name of Olympic
  string m_item1; // Snowboard's first Item
  string m_item2; // Snowboard's second Item
};

#endif
