#include "ArcherTower.h"
using namespace std;

ArcherTower::ArcherTower() : Tower("archer", 1, 0) {
  SetType("archer");
  SetDamage(1);
  SetLocation(0);
}

ArcherTower::ArcherTower(string type, int damage, int location)
    : Tower(type, damage, location) {
  SetType(type);
  SetDamage(damage);
  SetLocation(location);
}

int ArcherTower::Attack(vector<Enemy *> enemies) {
  int gold = 0;
  int i = 0;
  int size = enemies.size();
  bool found = false;
  while (i < size && found == false) {
    int hp = enemies[i]->GetHealth();
    int loc = enemies[i]->GetLocation();
    if (hp > 0 && loc == GetLocation()) {
      cout << "The Archer Tower fires an arrow!" << endl;
      int dam = enemies[i]->TakeDamage(GetDamage());
      gold += dam;
      found = true;
    }
    i++;
  }
  return gold;
}

ArcherTower::~ArcherTower() {}
