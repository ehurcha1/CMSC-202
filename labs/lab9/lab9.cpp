#include "Vehicle.h" //Parent class
#include "Car.h" //Child class 1
#include "Truck.h" //Child class 2
#include <time.h> //For seeding random number
#include <cstdlib> //For srand and rand
#include <iostream> //For cout
using namespace std;

int main() {
  srand(time(NULL)); //Seeds random number generator
  
  //Parent class example
  cout << "Parent Class Example" << endl;
  Vehicle myVehicle("Blue", 14000); //Creates Vehicle
  cout << myVehicle; //Calls overloaded operator
  cout << "****END****" << endl << endl;

  //Child class example 1	
  cout << "Child Class Example (Car)" << endl;
  Car myCar("Red", 9000);
  myCar.Description(); //Calls parent class function (use)
  myCar.Park(); //Calls child class function (extend)
  cout << "****END****" << endl << endl;

  //Child class example 2
  cout << "Child Class Example (Truck)" << endl;
  Truck myTruck("Black", 20000, 3500);
  myTruck.Description(); //Calls child class function (replace)
  myTruck.Vehicle::Description(); //calls parent class function (use)
  cout << "****END****" << endl << endl;
  
  return 0;
}


