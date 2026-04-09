/*
* Vehicle.h - 
* Implement Vehicle.cpp
*/

#ifndef VEHICLE_H //Header guard
#define VEHICLE_H //Header guard
#include <iostream>
#include <string>
using namespace std;

class Vehicle {
public:
  Vehicle(); // Default constructor
  Vehicle(string, int); // color and price
  void Description(); // Using the member variables, write a description
  string GetColor();        // Getter for m_color
  int GetPrice();   // Getter for m_price
  void SetColor(string);    // Setter for m_color
  void SetPrice(int); //Setter for m_price
  // Friend function allows user to cout << **vehicle_object** << endl;
  // Overloaded operator <<
  // Hint: When implementing this function, it should NOT have Vehicle::
  friend ostream& operator<<(ostream &out, Vehicle &myVehicle);
private:
  string m_color;      //Vehicle's color
  int m_price; //Vehicle price
};

#endif //Header guard
