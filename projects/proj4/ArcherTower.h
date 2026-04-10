/***********************************************************
 ** File:    ArcherTower.h
 ** Project: CMSC 202 - Project 4 (Kingdom Rush Edition)
 **
 ** Archer Tower — fires a single arrow at the first enemy
 ** in its location. Cheap and reliable.
 **********************************************************/

#ifndef ARCHER_TOWER_H //Header guards
#define ARCHER_TOWER_H //Header guards

#include "Tower.h"

class ArcherTower : public Tower {
public:
  // Name - ArcherTower
  // Desc - Default constructor. Creates an Archer Tower with default
  //        type "archer", damage 1, and location 0
  // Preconditions - None
  // Postconditions - ArcherTower initialized with default values
  ArcherTower();

  // Name - ArcherTower
  // Desc - Parameterized constructor. Creates an Archer Tower with
  //        the given type, damage, and path location
  // Preconditions - The damage >= 1. The location >= 1 and <= PATH_LENGTH.
  // Postconditions - ArcherTower initialized with provided values.
  ArcherTower(string type, int damage, int location);

  // Name - ~ArcherTower
  // Desc - Destructor for the ArcherTower class
  // Preconditions - ArcherTower object exists
  // Postconditions - ArcherTower object is deallocated
  ~ArcherTower();

  // Name - Attack
  // Desc - Fires one arrow at the first living enemy in the same
  //        location. Skips enemies with health <= 0.
  //        Returns gold earned (effective hits on the target).
  // Preconditions - Enemies vector exists; tower has a valid location
  // Postconditions - First matching enemy's health reduced by m_damage;
  //                  gold value returned; no other enemies affected
  //                  If there are no enemies, it returns 0.
  int Attack(vector<Enemy*> enemies);
};

#endif
