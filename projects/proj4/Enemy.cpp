#include "Enemy.h"
using namespace std;

Enemy::Enemy() {
  m_health = 0;
  m_location = 0;
}

Enemy::Enemy(int health, int location) {
  m_health = health;
  m_location = location;
}

Enemy::~Enemy() {
  // not used
}

int Enemy::GetHealth() { return m_health; }

void Enemy::SetHealth(int health) { m_health = health; }

int Enemy::GetLocation() { return m_location; }

void Enemy::SetLocation(int location) { m_location = location; }

ostream &operator<<(ostream &out, Enemy &myEnemy) {
  out << "Enemy: " << myEnemy.GetTier() << " HP: " << myEnemy.GetHealth()
      << endl;
  return out;
}