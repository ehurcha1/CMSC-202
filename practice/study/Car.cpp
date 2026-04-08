#include "Car.h"
#include <string>
using namespace std;



Car::Car() {
    m_owner = "";
    m_year = 0;
    m_make = "";
    m_model = "";
  }

void Car::setOwner(string owner) { m_owner = owner; }

void Car::setYear(int year) { m_year = year; }

void Car::setMake(string make) { m_make = make; }

void Car::setModel(string model) { m_model = model; }

string Car::getOwner() { return m_owner; }

int Car::getYear() { return m_year; }

string Car::getMake() { return m_make; }

string Car::getModel() { return m_model; }

bool Car::operator>(const Car& other) {
  return m_year > other.m_year;
}