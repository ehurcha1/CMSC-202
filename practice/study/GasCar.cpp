#include "GasCar.h"
using namespace std;

GasCar::GasCar() {
    m_mpg = 0;
    m_tankSize = 0;
    m_range = 0;
}

void GasCar::setMPG(int mpg) {
    m_mpg = mpg;
}

void GasCar::setTankSize(int tankSize) {
    m_tankSize = tankSize;
}

int GasCar::getMPG() {
    return m_mpg;
}

int GasCar::getTankSize() {
    return m_tankSize;
}

int GasCar::estRange(int mpg, int tankSize) {
    return mpg * tankSize;
}