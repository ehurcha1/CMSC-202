#include "MageTower.h"
using namespace std;

MageTower::MageTower() : Tower("mage", 1, 0) {
    SetType("mage");
    SetDamage(1);
    SetLocation(0);
}

MageTower::MageTower(string type, int damage, int location) : Tower(type, damage, location) {
    SetType(type);
    SetDamage(damage);
    SetLocation(location);
}