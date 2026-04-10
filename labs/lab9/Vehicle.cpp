#include "Vehicle.h"
#include <string>
using namespace std;

Vehicle::Vehicle() {
    m_color = "";
    m_price = 0;
}

Vehicle::Vehicle(string color, int price) {
    m_color = color;
    m_price = price;
}

void Vehicle::Description() {
    cout << "There is a " << m_color << " Vehicle that costs " << m_price << "." << endl;
}

string Vehicle::GetColor() {
    return m_color;
}
int Vehicle::GetPrice() {
    return m_price;
}

void Vehicle::SetColor(string color) {
    m_color = color;
}

void Vehicle::SetPrice(int price) {
    m_price = price;
}

ostream& operator<<(ostream &out, Vehicle &myVehicle) {
    out << "There is a " << myVehicle.m_color << " Vehicle which costs " << myVehicle.m_price << "." << endl;
    return out;
}