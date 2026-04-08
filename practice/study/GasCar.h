#ifndef GASCAR_H
#define GASCAR_H

#include "Car.h"
using namespace std;

class GasCar : public Car {
public:
    GasCar();

    void setMPG(int mpg);

    void setTankSize(int tankSize);

    int getMPG();

    int getTankSize();

    int estRange(int mpg, int tankSize);

private:
    int m_mpg;
    int m_tankSize;
    int m_range;
};

#endif