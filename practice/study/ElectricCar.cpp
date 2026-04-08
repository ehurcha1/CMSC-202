#include "ElectricCar.h"

ElectricCar::ElectricCar() {
    m_batterySize = 0;
    m_range = 0;
}

void ElectricCar::setBatterySize(int battery) {
    m_batterySize = battery;
}

void ElectricCar::setRange(int range) {
    m_range = range;
}

int ElectricCar::getBatterySize() {
    return m_batterySize;
}

int ElectricCar::getRange() {
    return m_range;
}