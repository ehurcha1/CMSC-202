#include <iostream>
#include <vector>
#include "ElectricCar.h"
#include "GasCar.h"
using namespace std;


int main() {
  vector<Car> garage;
  Car theCar;
  string active;

  while (active != "quit") {
    cout << "\nWhat is your first name? ";
    string name;
    cin >> name;

    cout << "\nWhat year is your car? ";
    int year;
    cin >> year;

    cout << "\nWhat make is your car? ";
    string make;
    cin >> make;

    cout << "\nWhat model is your car? ";
    string model;
    cin >> model;

    cout << "\nIs your car electric or gas powered?\n1 = Electric\n2 = Gas)\n";
    int engine;
    cin >> engine;
      if (engine == 1) {
        ElectricCar eCar;

        eCar.setOwner(name);
        eCar.setYear(year);
        eCar.setMake(make);
        eCar.setModel(model);

        cout << "\nWhat is the battery size in KWh? ";
        int battery;
        cin >> battery;
        eCar.setBatterySize(battery);

        cout << "\nWhat is the advertised range of your car? ";
        int range;
        cin >> range;
        eCar.setRange(range);

      }
      else {
        GasCar gCar;

        gCar.setOwner(name);
        gCar.setYear(year);
        gCar.setMake(make);
        gCar.setModel(model);

        cout << "\nWhat is the advertised MPG of your car? ";
        int mpg;
        cin >> mpg;
        gCar.setMPG(mpg);

        cout << "\nWhat size is your gas tank? ";
        int tankSize;
        cin >> tankSize;
        gCar.setTankSize(tankSize);
      }

    garage.push_back(theCar);

    cout << "\nWould you like to add another car? (type quit if finished) " << endl;
    cin >> active;
  
  }
  cout << "\n";
  
  for (int i = 0; i < garage.size(); i++) {
    cout <<
    garage[i].getOwner() << "\n" <<
    garage[i].getYear() << "\n" <<
    garage[i].getMake() << "\n" <<
    garage[i].getModel() << "\n" <<
    endl;
  }

  if (garage.size()>1) {
    if (garage[0] > garage[1]) {
    cout << garage[0].getOwner() << "'s car is newer!" << endl;
    }
  }
  return 0;
}