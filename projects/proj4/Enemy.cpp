/***********************************************************
 ** File:    Enemy.cpp
 ** Project: CMSC 202 - Project 4 (Kingdom Rush Edition)
 ** Author:  Elliot Hurchalla
 ** Date:    4/16/26
 ** Section: 14
 ** E-mail:  ehurcha1@umbc.edu
 ** This file defines the Enemy class and its member functions.
 ***********************************************************/

#include "Enemy.h"
using namespace std;

Enemy::Enemy() { // defaults
  m_health = 0;
  m_location = 0;
}

Enemy::Enemy(int health, int location) { // assigning members
  m_health = health;
  m_location = location;
}

Enemy::~Enemy() {} // destructor

int Enemy::GetHealth() { return m_health; } // returns health of enemy

void Enemy::SetHealth(int health) { m_health = health; } // sets health of enemy

int Enemy::GetLocation() { return m_location; } // returns location of enemy

void Enemy::SetLocation(int location) {
  m_location = location;
} // sets location of enemy

ostream &operator<<(ostream &out,
                    Enemy &myEnemy) { // overload operator to print enemy info
  out << "Enemy: " << myEnemy.GetTier() << " HP: " << myEnemy.GetHealth()
      << endl;
  return out;
}