#include "Truck.h"
using namespace std;

Truck::Truck() : Vehicle() {
    m_towingCapacity = 0;
}

Truck::Truck(string color, int price, int towingCapacity) : Vehicle(color, price) {
    m_towingCapacity = towingCapacity;
}

void Truck::Description() {
    cout << "The Truck can tow " << m_towingCapacity << " lbs." << endl;
}

int Truck::GetTowingCapacity() {
    return m_towingCapacity;
}

void Truck::SetTowingCapacity(int towingCapacity) {
    m_towingCapacity = towingCapacity;
}