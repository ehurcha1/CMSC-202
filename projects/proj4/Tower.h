/***********************************************************
 ** File:    Tower.h
 ** Project: CMSC 202 - Project 4 (Kingdom Rush Edition)
 ** This file contains the header file of the Tower class
 **********************************************************/

#ifndef TOWER_H // Header guards
#define TOWER_H // Header guards

#include "Enemy.h"
#include <string>
#include <vector>
#include <iostream>
#include <iomanip>
using namespace std;

// Abstract base class for all defensive towers placed on the path.
// Each tower subclass defines its own Attack() behavior.
class Tower {
public:
  // Name - Tower
  // Desc - Default constructor. Creates a Tower with empty type,
  //        0 damage, and location 0
  // Preconditions - None
  // Postconditions - Tower initialized with default values
  Tower();

  // Name - Tower
  // Desc - Parameterized constructor. Creates a Tower with the given
  //        type string, damage value, and path location
  // Preconditions -  Must have damage >= 0, location >= 1 and <= PATH_LENGTH
  // Postconditions - Tower initialized with provided type, damage, and location
  Tower(string type, int damage, int location);

  // Name - ~Tower
  // Desc - Virtual destructor to ensure correct cleanup in derived classes
  // Preconditions - Tower object exists
  // Postconditions - Tower object is deallocated
  virtual ~Tower();

  // Name - GetDamage
  // Desc - Returns the tower's current damage value
  // Preconditions - Tower object exists
  // Postconditions - No changes; returns m_damage
  int GetDamage();

  // Name - GetType
  // Desc - Returns the tower's type string (e.g. "archer", "mage", "artillery")
  // Preconditions - Tower object exists
  // Postconditions - No changes; returns m_type
  string GetType();

  // Name - GetLocation
  // Desc - Returns the tower's current position on the path
  // Preconditions - Tower object exists. Must be <= PATH_LENGTH
  // Postconditions - No changes; returns m_location
  int GetLocation();

  // Name - SetDamage
  // Desc - Sets the tower's damage to the provided value
  // Preconditions - Tower object exists
  // Postconditions - m_damage updated to the given value
  void SetDamage(int);

  // Name - SetType
  // Desc - Sets the tower's type string to the provided value
  // Preconditions - Tower object exists
  // Postconditions - m_type updated to the given string
  void SetType(string);

  // Name - SetLocation
  // Desc - Sets the tower's position on the path to the provided value
  // Preconditions - Tower object exists
  // Postconditions - m_location updated to the given value
  void SetLocation(int);

  // Name - Attack
  // Desc - Pure virtual. Attacks enemies in the tower's location.
  //        Returns total gold earned from effective hits.
  // Preconditions - Enemies vector is populated; tower has valid location
  // Postconditions - Affected enemies have reduced health; gold value returned
  virtual int Attack(vector<Enemy*> enemies) = 0;

  // Name - operator<<
  // Desc - Overloaded output operator. Prints the tower's type, location,
  //        and damage in the format:
  //        "<Type> Tower: Location <loc> Damage: <dmg>"
  // Preconditions - Tower object exists
  // Postconditions - No changes to Tower; output written to stream
  friend ostream& operator<<(ostream&, Tower&);

private:
  int m_damage; // Damage per attack by this tower
  string m_type; // Name of the type of tower (Archer, Mage, or Artillery)
  int m_location; // Location of the tower (1 - 3)
};

#endif
