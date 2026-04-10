/***********************************************************
 ** File:    Orc.h
 ** Project: CMSC 202 - Project 4 (Kingdom Rush Edition)
 ** This file contains the header file of the Orc class
 **
 ** Orc enemies march down the path in increasing armor tiers.
 ** Each tier represents heavier armor that requires more damage to strip.
 **
 **  HP 1  = Orc         (leather scraps — goes down in one hit)
 **  HP 2  = Strong Orc  (light chainmail)
 **  HP 3  = Orc Warrior (heavy plate)
 **  HP 4  = Orc Captain (regenerating hide)
 **  HP 5  = Orc Knight  (enchanted armor)
 **  HP 6+ = Orc Lord    (infernal plating)
 **
 ** When an Orc takes damage its tier downgrades accordingly.
 ** e.g. a Orc Knight hit for 2 damage becomes an Orc Warrior.
 **********************************************************/

#ifndef ORC_H // Header Guard
#define ORC_H // Header Guard

#include "Enemy.h"

class Orc : public Enemy {
public:
  // Name - Orc
  // Desc - Default constructor. Creates an Orc (HP 1) at location 0
  // Preconditions - None
  // Postconditions - Orc initialized as an "Orc"  with health 1 at location 0
  Orc();

  // Name - Orc
  // Desc - Parameterized constructor. Creates an Orc enemy at the given
  //        armor tier (health) and path location
  // Preconditions - health >= 1, location >= 0
  // Postconditions - Orc initialized with given health; tier set accordingly
  Orc(int health, int location);

  // Name - ~Orc
  // Desc - Destructor for the Orc class
  // Preconditions - Orc object exists
  // Postconditions - Orc object is deallocated
  ~Orc();

  // Name - TakeDamage
  // Desc - Reduces health by the damage amount and prints the result.
  //        Returns the number of effective hits landed
  //        (lesser of current health and incoming damage).
  //        Updates the displayed tier after damage is applied.
  //        If health drops to 0 or below, the enemy is destroyed.
  // Preconditions - Requires damage > 0 and Orc health >= 0
  // Postconditions - m_health reduced; m_tier updated to match new health
  int TakeDamage(int damage);

  // Name - GetTier
  // Desc - Returns the current tier name based on remaining health:
  //        1=Orc, 2=Strong Orc, 3=Orc Warrior, 4=Orc Captain,
  //        5=Orc Knight, 6+=Orc Lord
  // Preconditions - Orc object exists
  // Postconditions - No changes; returns m_tier string
  string GetTier();

private:
  // Name - UpdateTier
  // Desc - Helper function. Keeps m_tier in sync with current health value.
  //        Called internally after any health change.
  // Preconditions - m_health has been updated
  // Postconditions - m_tier set to the name matching the current health value
  void UpdateTier();

  string m_tier; // Name of the type of orc (based on health)
};

#endif
