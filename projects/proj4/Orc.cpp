#include "Orc.h"
using namespace std;

Orc::Orc() : Enemy(1, 0) { UpdateTier(); }

Orc::Orc(int health, int location) : Enemy(health, location) { UpdateTier(); }

Orc::~Orc() {}

int Orc::TakeDamage(int damage) {
  string oldTier;
  oldTier = GetTier();
  int health = GetHealth();
  SetHealth(health - damage);
  UpdateTier();

  if (health > damage) {
    cout << "The " << oldTier << " takes " << damage << " damage!" << endl;
    if (oldTier != GetTier()) {
      cout << "The " << oldTier << " was stripped down to a " << GetTier()
           << endl;
    }
    return damage;
  } else {
    cout << "The " << oldTier << " takes " << damage << " damage!" << endl;
    cout << "The " << oldTier << " has been defeated" << endl;
    return health;
  }
}

string Orc::GetTier() { return m_tier; }

void Orc::UpdateTier() {
  int health;
  health = GetHealth();

  if (health == 1) {
    m_tier = "Orc";
  } else if (health == 2) {
    m_tier = "Strong Orc";
  } else if (health == 3) {
    m_tier = "Orc Warrior";
  } else if (health == 4) {
    m_tier = "Orc Captain";
  } else if (health == 5) {
    m_tier = "Orc Knight";
  } else if (health >= 6) {
    m_tier = "Orc Lord";
  } else {
    m_tier = "";
  }
}