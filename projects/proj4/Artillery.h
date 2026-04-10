/***********************************************************
 ** File:    Artillery.h
 ** Project: CMSC 202 - Project 4 (Kingdom Rush Edition)
 **
 ** Artillery Tower — hurls a massive boulder that deals
 ** area damage to ALL enemies at its location simultaneously.
 ** Expensive but devastating against clusters.
 **********************************************************/

#ifndef ARTILLERY_H // Header Guards
#define ARTILLERY_H // Header Guards

#include "Tower.h"

class Artillery : public Tower {
public:
  // Name - Artillery
  // Desc - Default constructor. Creates an Artillery Tower with default
  //        type "artillery", damage 1, and location 0
  // Preconditions - None
  // Postconditions - Artillery initialized with default values
  Artillery();

  // Name - Artillery
  // Desc - Parameterized constructor. Creates an Artillery Tower with
  //        the given type, damage, and path location
  // Preconditions - The damage >= 1. The location >= 1 and <= PATH_LENGTH.
  // Postconditions - Artillery initialized with provided values
  Artillery(string type, int damage, int location);

  // Name - ~Artillery
  // Desc - Destructor for the Artillery class
  // Preconditions - Artillery object exists
  // Postconditions - Artillery object is deallocated
  ~Artillery();

  // Name - Attack
  // Desc - Launches a boulder to damages ALL living enemies at this location.
  //        Only targets enemies with health > 0.
  //        Returns total gold earned (sum of hits across all targets).
  // Preconditions - Enemies vector exists; tower has a valid location
  // Postconditions - All matching enemies' health reduced by m_damage;
  //                  total gold value returned. If no enemies, returns 0.
  int Attack(vector<Enemy*> enemies);
};

#endif
