/*
* Truck.h - 
* Implement Truck.cpp
* Child class of Vehicle
*/

#ifndef TRUCK_H //Header Guard
#define TRUCK_H //Header Guard
#include "Vehicle.h" //Parent class
#include <iostream>
#include <string>
using namespace std;

class Truck : public Vehicle {
public:
  Truck(); // Default constructor
  Truck(string, int, int);// Color, Price, and Towing Capacity
  void Description(); // Using m_towingCapacity, displays Truck desc
                      //   to match the sample output
                      // Replacing parent class function
  int GetTowingCapacity();     // Getter for m_towingCapacity
  void SetTowingCapacity(int); // Setter for m_towingCapacity
private:
  int m_towingCapacity; // Int holds towing capacity of the truck
};
#endif
