/***********************************************************
 ** File:    Game.h
 ** Project: CMSC 202 - Project 4 (Kingdom Rush Edition)
 ** This file contains the header file of the Game class
 **********************************************************/

#ifndef GAME_H //Header Guards
#define GAME_H //Header Guards

#include "Tower.h" //Parent class of all towers
#include "ArcherTower.h" //Child class of tower
#include "Artillery.h" //Child class of tower
#include "MageTower.h" //Child class of tower
#include "Enemy.h" //Parent class of all enemies
#include "Orc.h" //Child class of enemy

#include <iostream>
#include <ctime>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;

// ===================== Game Constants =====================

// Starting values
const int START_ROUND = 1; // Starting number of the round
const int START_LIFE = 100; // Starting life of the kingdom
const int START_GOLD = 10; // Starting gold of the kingdom

// Path
const int PATH_LENGTH = 3;  // Number of locations on the road
const int START_ENEMY = -1; // Enemies spawn just before location 0

// Tower costs
const int COST_ARCHER = 2; // Cost for a base archer tower
const int COST_MAGE = 4; // Cost for a base mage tower
const int COST_ARTILLERY = 6; // Cost for a base artillery tower
const int COST_UPGRADE = 2; // Cost to upgrade any tower

// Starting damage per tower type
const int DAMAGE_ARCHER = 1; // Initial damage of an archer tower
const int DAMAGE_MAGE = 1; // Initial damage of a mage tower
const int DAMAGE_ARTILLERY = 1; // Initial damage of an artillery tower

// Economy
const int EARN_PER_HIT = 1; // Gold per effective hit on an enemy
const int UPGRADE_VALUE = 2; // Damage increase per upgrade

// ==========================================================

class Game {
public:
  // Name - Game
  // Desc - Default constructor. Initializes the game state with starting
  //        gold, lives, and round number. Vectors begin empty.
  // Preconditions - None
  // Postconditions - Game ready to begin; m_curRound, m_curGold, and
  //                  m_curLife set to their starting constants
  Game();

  // Name - ~Game
  // Desc - Destructor. Deallocates all dynamically allocated Tower and
  //        Enemy objects stored in m_towers and m_enemies.
  // Preconditions - Game object exists
  // Postconditions - All heap memory freed; no memory leaks
  ~Game();

  // Name - StartGame
  // Desc - Entry point for the game loop. Prints the welcome banner and
  //        repeatedly calls MainMenu until the player chooses to quit.
  // Preconditions - Game object constructed
  // Postconditions - Game has run to completion; player has exited
  void StartGame();

  // Name - MainMenu
  // Desc - Displays the main menu and prompts the player for a choice.
  //        Validates input and dispatches to the appropriate function.
  //        Returns the player's validated menu selection.
  // Preconditions - Game is in a valid state
  // Postconditions - One menu action executed; game state may be updated
  int  MainMenu();

  // Name - PrintMap
  // Desc - Prints each location on the path showing the towers stationed
  //        there and the enemies currently at that position.
  //        Displays "None" when a location has no towers or enemies.
  // Preconditions - Game object exists; m_towers and m_enemies may be empty
  // Postconditions - No changes to game state; map printed to cout
  void PrintMap();

  // Name - Stats
  // Desc - Prints the current game statistics: round number, number of
  //        towers deployed, current gold, and current lives remaining.
  // Preconditions - Game object exists
  // Postconditions - No changes to game state; stats printed to cout
  void Stats();

  // Name - BuyTower
  // Desc - Displays the tower purchase menu and prompts the player to
  //        choose a tower type or cancel. Validates the player has enough
  //        gold before purchasing. Calls PlaceTower on success.
  // Preconditions - Game is in a valid state
  // Postconditions - New tower added to m_towers and gold deducted, or
  //                  no change if player cancels or has insufficient gold
  void BuyTower();

  // Name - PlaceTower
  // Desc - Prompts the player to choose a path location (1 to PATH_LENGTH)
  //        and dynamically allocates the tower type indicated by choice,
  //        placing it at the selected location.
  // Preconditions - Choice is a valid type (1=Archer, 2=Mage, 3=Artillery)
  // Postconditions - New tower added to m_towers at the chosen location
  void PlaceTower(int choice);

  // Name - UpgradeTower
  // Desc - Lists all deployed towers and prompts the player to select one
  //        to upgrade. Deducts COST_UPGRADE gold and increases the tower's
  //        damage by UPGRADE_VALUE. Validates player has enough gold.
  // Preconditions - At least one tower in m_towers; player has enough gold
  // Postconditions - Selected tower's damage increased; gold deducted
  void UpgradeTower();

  // Name - PlayRound
  // Desc - Runs one full round of the game: spawns enemies, resolves combat
  //        between towers and enemies, removes defeated enemies, moves
  //        remaining enemies forward, then checks if any reached the exit.
  //        Increments m_curRound on completion.
  // Preconditions - Game is in a valid state with life > 0
  // Postconditions - m_curRound incremented; enemies moved or removed;
  //                  m_curLife reduced for any enemies that reached the exit
  void PlayRound();

  // Name - SpawnEnemies
  // Desc - Spawns m_curRound enemies at START_ENEMY, each with health
  //        equal to their spawn index (1 through m_curRound).
  //        Prints the name of each enemy as it appears.
  // Preconditions - Called at the start of PlayRound
  // Postconditions - m_curRound new Orc enemies added to m_enemies
  void SpawnEnemies();

  // Name - ResolveCombat
  // Desc - Iterates over all towers and calls Attack() on each, passing
  //        the full m_enemies vector. Accumulates gold earned from hits
  //        and adds it to m_curGold.
  // Preconditions - m_towers and m_enemies may be empty
  // Postconditions - Enemies' health reduced per tower attacks;
  //                  m_curGold increased by total gold earned
  void ResolveCombat();

  // Name - RemoveDefeated
  // Desc - Scans m_enemies and removes any enemy with health <= 0.
  //        Deallocates the enemy object and erases it from the vector.
  //        Runs up to 5 times to ensure all defeated enemies are cleared.
  // Preconditions - m_enemies may contain enemies with health <= 0
  // Postconditions - All enemies with health <= 0 removed and deallocated
  void RemoveDefeated();

  // Name - MoveEnemies
  // Desc - Increments the location of every enemy in m_enemies by 1,
  //        advancing them one step closer to the exit. Prints a message
  //        indicating the enemies are moving.
  // Preconditions - m_enemies may be empty
  // Postconditions - All enemies' m_location increased by 1
  void MoveEnemies();

  // Name - CheckPath
  // Desc - Scans m_enemies for any enemy that has reached or passed
  //        PATH_LENGTH (the exit). For each such enemy, reduces m_curLife
  //        by the orc's health, prints a warning,
  //        and removes it from the vector.
  //        Runs up to 5 times to ensure all escapees are processed.
  //        Ends the game if m_curLife drops to 0 or below.
  // Preconditions - m_enemies may be empty; m_curLife >= 0
  // Postconditions - Escaped enemies removed; m_curLife reduced accordingly
  void CheckPath();

private:
  vector<Enemy*> m_enemies; // All active enemies on the path
  vector<Tower*> m_towers;  // All placed towers
  int m_curRound; // Current Round (starts a 1)
  int m_curGold; // Current Gold (starts at 10)
  int m_curLife; // Current Kingdom Life (starts at 100)
};

#endif
