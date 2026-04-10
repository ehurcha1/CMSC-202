/***********************************************************
 ** File:    Enemy.h
 ** Project: CMSC 202 - Project 4 (Kingdom Rush Edition)
 ** This file contains the header file of the Enemy class
 **********************************************************/

#ifndef ENEMY_H // Header Guards
#define ENEMY_H // Header Guards

#include <string>
#include <iostream>
#include <iomanip>
using namespace std;

// Abstract base class for all enemies that march down the path.
// Enemies have health (armor tiers) and a location on the path.
class Enemy {
public:
  // Name - Enemy
  // Desc - Default constructor. Creates an Enemy with health 0 at location 0.
  // Preconditions - None
  // Postconditions - Enemy object initialized with default values
  Enemy();

  // Name - Enemy
  // Desc - Parameterized constructor. Creates an Enemy with the given health
  //        and starting location on the path.
  // Preconditions - Requires health >= 0, location >= 0 and <= PATH_LENGTH
  // Postconditions - Enemy initialized with provided health and location
  Enemy(int health, int location);

  // Name - ~Enemy
  // Desc - Virtual destructor to ensure correct cleanup in derived classes
  // Preconditions - Enemy object exists
  // Postconditions - Enemy object is deallocated
  virtual ~Enemy();

  // Name - GetHealth
  // Desc - Returns the enemy's current health value
  // Preconditions - Enemy object exists
  // Postconditions - No changes; returns m_health
  int GetHealth();

  // Name - SetHealth
  // Desc - Sets the enemy's health to the provided value
  // Preconditions - Enemy object exists
  // Postconditions - m_health updated to the given value
  void SetHealth(int);

  // Name - GetLocation
  // Desc - Returns the enemy's current position on the path
  // Preconditions - Enemy object exists
  // Postconditions - No changes; returns m_location
  int GetLocation();

  // Name - SetLocation
  // Desc - Sets the enemy's position on the path to the provided value
  // Preconditions - Enemy object exists
  // Postconditions - m_location updated to the given value
  void SetLocation(int);

  // Name - TakeDamage
  // Desc - Pure virtual. Applies damage to the enemy and returns
  //        the number of effective hits (used to calculate gold earned).
  // Preconditions - Requires damage > 0; enemy health >= 0
  // Postconditions - Enemy health reduced; tier updated in derived class
  virtual int TakeDamage(int damage) = 0;

  // Name - GetTier
  // Desc - Pure virtual. Returns the descriptive tier name of the enemy
  //        based on its current health.
  // Preconditions - Enemy object exists
  // Postconditions - No changes; returns tier name string
  virtual string GetTier() = 0;

  // Name - operator<<
  // Desc - Overloaded output operator. Prints the enemy's tier and health
  //        in the format: "Enemy: <tier> Health: <health>"
  // Preconditions - Enemy object exists
  // Postconditions - No changes to Enemy; output stream returned
  friend ostream& operator<<(ostream&, Enemy&);

private:
  int m_health;   // Current health / armor tier
  int m_location; // Position on the path (0 = entrance)
};

#endif
