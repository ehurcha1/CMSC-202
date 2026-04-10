/***********************************************************
 ** File:    MageTower.h
 ** Project: CMSC 202 - Project 4 (Kingdom Rush Edition)
 **
 ** Mage Tower — channels arcane energy that surges through
 ** every enemy at its location TWICE (once for the cast,
 ** once for the arcane echo).
 **********************************************************/

#ifndef MAGE_TOWER_H // Header Guard
#define MAGE_TOWER_H // Header Guard

#include "Tower.h"

class MageTower : public Tower {
public:
  // Name - MageTower
  // Desc - Default constructor. Creates a Mage Tower with default
  //        type "mage", damage 1, and location 0
  // Preconditions - None
  // Postconditions - MageTower initialized with default values
  MageTower();

  // Name - MageTower
  // Desc - Parameterized constructor. Creates a Mage Tower with
  //        the given type, damage, and path location
  // Preconditions - The damage >= 1. The location >= 1 and <= PATH_LENGTH.
  // Postconditions - MageTower initialized with provided values
  MageTower(string type, int damage, int location);

  // Name - ~MageTower
  // Desc - Destructor for the MageTower class
  // Preconditions - MageTower object exists
  // Postconditions - MageTower object is deallocated
  ~MageTower();

  // Name - Attack
  // Desc - Hits every living enemy at this location twice:
  //        once for the arcane bolt and once for the arcane echo.
  //        Only targets enemies with health > 0.
  //        Returns total gold earned (sum of hits across both passes).
  // Preconditions - enemies vector exists; tower has a valid location
  // Postconditions - All matching enemies' health reduced by m_damage twice;
  //                  total gold value returned. If no enemies, return 0.
  int Attack(vector<Enemy*> enemies);
};

#endif
