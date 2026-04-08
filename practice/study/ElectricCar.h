#ifndef ELECTRICCAR_H
#define ELECTRICCAR_H

#include "Car.h"
using namespace std;

class ElectricCar : public Car {
public:
    ElectricCar();

    void setBatterySize(int battery);

    void setRange(int range);

    int getBatterySize();

    int getRange();

private:
    int m_batterySize;
    int m_range;
};

#endif