#include "Car.h"
using namespace std;

Car::Car() : Vehicle() {
    RandStyle();
}

Car::Car(string color, int price) : Vehicle(color, price) {
    RandStyle();
}

void Car::RandStyle() {
    m_style = STYLES[rand() % STYLE_SIZE];
}

string Car::GetStyle() {
    return m_style;
}

void Car::SetStyle(string style){
    m_style = style;
}

void Car::Park() {
    cout << "The " << "(" << m_style << ")" << " is parked." << endl;
}
