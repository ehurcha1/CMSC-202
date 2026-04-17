/***********************************************************
 ** File:    MageTower.cpp
 ** Project: CMSC 202 - Project 4 (Kingdom Rush Edition)
 ** Author:  Elliot Hurchalla
 ** Date:    4/16/26
 ** Section: 14
 ** E-mail:  ehurcha1@umbc.edu
 ** This file defines the MageTower class and its member functions.
 ***********************************************************/

#include "MageTower.h"
using namespace std;

MageTower::MageTower() : Tower("mage", 1, 0) { // defaults
  SetType("mage");
  SetDamage(1);
  SetLocation(0);
}

MageTower::MageTower(string type, int damage, int location) // assigning members
    : Tower(type, damage, location) {
  SetType(type);
  SetDamage(damage);
  SetLocation(location);
}

int MageTower::Attack(
    vector<Enemy *>
        enemies) { // attacks all enemies in range twice and returns gold earned
  int gold = 0;
  int size = enemies.size();

  cout << "The Mage Tower launches an arcane bolt!" << endl;
  for (int i = 0; i < size; i++) {
    int loc = enemies[i]->GetLocation();
    if (loc == GetLocation() && enemies[i]->GetHealth() > 0) {
      int dam = enemies[i]->TakeDamage(GetDamage());
      gold += dam;
    }
  }

  cout << "The arcane energy echoes back!" << endl;
  for (int i = 0; i < size; i++) {
    int loc = enemies[i]->GetLocation();
    if (loc == GetLocation() && enemies[i]->GetHealth() > 0) {
      int dam = enemies[i]->TakeDamage(GetDamage());
      gold += dam;
    }
  }
  return gold;
}

MageTower::~MageTower() {} // destructor
