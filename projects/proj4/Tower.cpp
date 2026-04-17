/***********************************************************
 ** File:    Tower.cpp
 ** Project: CMSC 202 - Project 4 (Kingdom Rush Edition)
 ** Author:  Elliot Hurchalla
 ** Date:    4/16/26
 ** Section: 14
 ** E-mail:  ehurcha1@umbc.edu
 ** This file defines the Tower class and its member functions.
 ***********************************************************/

#include "Tower.h"
using namespace std;

Tower::Tower() { // defaults
  m_damage = 0;
  m_type = "";
  m_location = 0;
}

Tower::Tower(string type, int damage, int location) { // assigning members
  m_type = type;
  m_damage = damage;
  m_location = location;
}

Tower::~Tower() {} // destrutor

int Tower::GetDamage() { return m_damage; } // returns damage for towers

string Tower::GetType() { return m_type; } // returns type of tower

int Tower::GetLocation() { return m_location; } // returns location of tower

void Tower::SetDamage(int damage) {
  m_damage = damage;
} // sets damage for towers

void Tower::SetType(string type) { m_type = type; } // sets type of tower

void Tower::SetLocation(int location) {
  m_location = location;
} // sets location of tower

ostream &operator<<(ostream &out, Tower &myTower) {
  string type = myTower.GetType();

  /*
  After running the game the first time, I realized myTower.GetType() returns
  the name but lowercase. This made the "out" statement incorrect. I created
  this "if" statement below to fix that.
  */

  if (type == "archer") {
    type = "Archer";
  } else if (type == "mage") {
    type = "Mage";
  } else if (type == "artillery") {
    type = "Artillery";
  }

  out << type << " Tower: Location " << myTower.GetLocation()
      << " Damage: " << myTower.GetDamage() << endl;
  return out;
}