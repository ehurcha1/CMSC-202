/*
 * File: Sandwich.h
 * Project: CMSC202 Lab 6, Spring 2026
 */

#ifndef SANDWICH_H //Header guards
#define SANDWICH_H //Header guards

#include <iostream>
#include <string>
using namespace std;

class Sandwich {
 public:
  Sandwich(); //default constructor

  Sandwich(string name, int type); //overloaded constructor

  // GetName() returns the name of the customer for this sandwich
  string GetName();

  // GetType() returns the type of sandwich
  int GetType();

  // SetName() sets m_name to name
  void SetName(string name);

  // SetType() sets m_type to type
  void SetType(int type);

 private:
  string m_name; // name of the customer
  int m_type; // type of sandwich (club, hoagie, burger)
};

#endif
