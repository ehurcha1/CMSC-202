#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Car {
public:
  Car() {
    m_owner = "";
    m_year = 0;
    m_make = "";
    m_model = "";
  }

  void setOwner(string owner) { m_owner = owner; }

  void setYear(int year) { m_year = year; }

  void setMake(string make) { m_make = make; }

  void setModel(string model) { m_model = model; }

  string getOwner() { return m_owner; }

  int getYear() { return m_year; }

  string getMake() { return m_make; }

  string getModel() { return m_model; }

private:
  string m_owner;
  int m_year;
  string m_make;
  string m_model;
};

int main() {
  vector<Car> garage;
  Car theCar;
  string active;

  while (active != "quit") {
    cout << "\nWhat is your first name? ";
    string name;
    cin >> name;
    theCar.setOwner(name);

    cout << "\nWhat year is your car? ";
    int year;
    cin >> year;
    theCar.setYear(year);

    cout << "\nWhat make is your car? ";
    string make;
    cin >> make;
    theCar.setMake(make);

    cout << "\nWhat model is your car? ";
    string model;
    cin >> model;
    theCar.setModel(model);

    garage.push_back(theCar);

    cout << "\nWould you like to add another car? (type quit if finished) "
         << endl;
    cin >> active;
  }

  for (int i = 0; i < garage.size(); i++) {
    cout << garage[i].getOwner() <<
  }
  return 0;
}
