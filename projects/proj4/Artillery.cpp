/***********************************************************
 ** File:    Artillery.cpp
 ** Project: CMSC 202 - Project 4 (Kingdom Rush Edition)
 ** Author:  Elliot Hurchalla
 ** Date:    4/16/26
 ** Section: 14
 ** E-mail:  ehurcha1@umbc.edu
 ** This file defines the Artillery class and its member functions.
 ***********************************************************/

#include "Artillery.h"
using namespace std;

Artillery::Artillery() : Tower("artillery", 1, 0) { // defaults
  SetType("artillery");
  SetDamage(1);
  SetLocation(0);
}

Artillery::Artillery(string type, int damage, int location) // assigning members
    : Tower(type, damage, location) {
  SetType(type);
  SetDamage(damage);
  SetLocation(location);
}

int Artillery::Attack(vector<Enemy *> enemies) { // attacks all enemies in range
                                                 // and returns gold earned
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

Artillery::~Artillery() {} // destructor
