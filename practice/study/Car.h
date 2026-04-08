#ifndef CAR_H
#define CAR_H

#include <string>
using namespace std;

class Car {
public:
  Car();

  void setOwner(string owner);

  void setYear(int year);

  void setMake(string make);

  void setModel(string model);

  string getOwner();

  int getYear();

  string getMake();

  string getModel();

  bool operator>(const Car& other);

private:
  string m_owner;
  int m_year;
  string m_make;
  string m_model;
};
#endif