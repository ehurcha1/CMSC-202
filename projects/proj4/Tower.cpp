#include "Tower.h"
using namespace std;

Tower::Tower() {
  m_damage = 0;
  m_type = "";
  m_location = 0;
}

Tower::Tower(string type, int damage, int location) {
  m_type = type;
  m_damage = damage;
  m_location = location;
}

Tower::~Tower() {}

int Tower::GetDamage() { return m_damage; }

string Tower::GetType() { return m_type; }

int Tower::GetLocation() { return m_location; }

void Tower::SetDamage(int damage) { m_damage = damage; }

void Tower::SetType(string type) { m_type = type; }

void Tower::SetLocation(int location) { m_location = location; }

ostream &operator<<(ostream &out, Tower &myTower) {
  out << myTower.GetType() << " Tower: Location " << myTower.GetLocation()
      << " Damage: " << myTower.GetDamage() << endl;
  return out;
}