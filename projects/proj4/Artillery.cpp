#include "Artillery.h"
using namespace std;

Artillery::Artillery() : Tower("artillery", 1, 0) {
  SetType("artillery");
  SetDamage(1);
  SetLocation(0);
}

Artillery::Artillery(string type, int damage, int location)
    : Tower(type, damage, location) {
  SetType(type);
  SetDamage(damage);
  SetLocation(location);
}

int Artillery::Attack(vector<Enemy *> enemies) {
  int gold = 0;
  int size = enemies.size();

  cout << "The Artillery Tower launches a boulder! BOOM!" << endl;
  for (int i = 0; i < size; i++) {
    int loc = enemies[i]->GetLocation();
    if (loc == GetLocation() && enemies[i]->GetHealth() > 0) {
      int dam = enemies[i]->TakeDamage(GetDamage());
      gold += dam;
    }
  }
  return gold;
}

Artillery::~Artillery() {}
