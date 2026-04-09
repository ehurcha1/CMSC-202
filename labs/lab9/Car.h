/*
* Car.h - 
* Implement Car.cpp
* Child class of Vehicle
*/

#ifndef CAR_H //Header Guard
#define CAR_H //Header Guard
#include "Vehicle.h" //Parent class
#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

//constants
const int STYLE_SIZE = 3; // Number of possible body styles for a Car
const string STYLES[STYLE_SIZE] = {"Sedan", "Van", "SUV"};

class Car : public Vehicle {
public:
  Car(); // Default constructor and calls RandStyle
  Car(string, int); //color, price and calls RandStyle
  void RandStyle();       // Randomly assigns one STYLE to m_style
  string GetStyle();      // Getter for m_style (extending parent)
  void SetStyle(string);  // Setter for m_style (extending parent)
  void Park();            // The Car is parked (extending parent)
private:
  string m_style;         // Random body style assigned
};

#endif
