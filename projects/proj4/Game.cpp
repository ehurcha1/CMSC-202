/***********************************************************
 ** File:    Game.cpp
 ** Project: CMSC 202 - Project 4 (Kingdom Rush Edition)
 ** Author:  Elliot Hurchalla
 ** Date:    4/16/26
 ** Section: 14
 ** E-mail:  ehurcha1@umbc.edu
 ** This file manages the games components and logic.
 ***********************************************************/

#include "Game.h"
#include <iostream>
using namespace std;

Game::Game() { // defaults
  m_curRound = 1;
  m_curGold = 10;
  m_curLife = 100;
}

Game::~Game() { // deletes all towers and enemies
  int eSize = m_enemies.size();
  int tSize = m_towers.size();

  for (int i = 0; i < eSize; i++) {
    delete m_enemies[i];
  }

  for (int i = 0; i < tSize; i++) {
    delete m_towers[i];
  }
}

void Game::StartGame() { // starts the game and runs the main menu until the
                         // player quits or loses
  cout << "Welcome to UMBC Kingdom Rush!" << endl;
  cout << "Defend the realm against the Orc horde!" << endl;

  while (MainMenu() != 6 && m_curLife > 0) {
  }
}

int Game::MainMenu() { // displays the main menu and returns the player's choice
  int choice = 0;

  cout << "What would you like to do?" << endl;
  cout << "1. View Map" << endl;
  cout << "2. Build New Tower" << endl;
  cout << "3. Upgrade Existing Tower" << endl;
  cout << "4. Progress Round" << endl;
  cout << "5. Check Kingdom Status" << endl;
  cout << "6. Quit" << endl;
  cin >> choice;

  switch (choice) {
  case 1:
    PrintMap();
    break;
  case 2:
    BuyTower();
    break;
  case 3:
    UpgradeTower();
    break;
  case 4:
    PlayRound();
    break;
  case 5:
    Stats();
    break;
  case 6:
    cout << "The kingdom thanks you for your service!" << endl;
    break;
  default:
    cout << endl;
    break;
  }
  return choice;
}

void Game::PrintMap() {
  cout << endl;
  for (int i = 1; i <= PATH_LENGTH; i++) {
    cout << "** Location " << i << " **" << endl;
    cout << "-- Towers --" << endl;
    int tSize = m_towers.size();
    int count = 1;
    for (int j = 0; j < tSize; j++) {
      if (m_towers[j]->GetLocation() == i) {
        cout << count << ". " << *m_towers[j];
        count++;
      }
    }
    if (count == 1) {
      cout << "None" << endl;
    }

    cout << "<< Enemies >>" << endl;
    int eSize = m_enemies.size();
    count = 1;
    for (int k = 0; k < eSize; k++) {
      if (m_enemies[k]->GetLocation() == i) {
        cout << "Enemy: " << m_enemies[k]->GetTier()
             << " HP: " << m_enemies[k]->GetHealth() << endl;
        count++;
      }
    }
    if (count == 1) {
      cout << "None" << endl;
    }
    cout << endl;
  }
}

void Game::Stats() { // displays the current status of the kingdom
  cout << endl;
  cout << "** KINGDOM STATUS **" << endl;
  cout << "Current Round:      " << m_curRound << endl;
  cout << "Towers Deployed:    " << m_towers.size() << endl;
  cout << "Current Gold:       " << m_curGold << endl;
  cout << "Kingdom Health:     " << m_curLife << endl;
  cout << endl;
}

void Game::BuyTower() { // allows the player to buy a new tower and place it on
                        // the map
  int choice = 0;

  do {
    cout << endl;
    cout << "Which tower would you like to build?" << endl;
    cout << "1. Archer Tower  (Cost: " << COST_ARCHER << " gold)" << endl;
    cout << "2. Mage Tower    (Cost: " << COST_MAGE << " gold)" << endl;
    cout << "3. Artillery     (Cost: " << COST_ARTILLERY << " gold)" << endl;
    cout << "4. Cancel" << endl;
    cin >> choice;
  } while (choice < 1 || choice > 4);

  switch (choice) {
  case 1:
    PlaceTower(1);
    m_curGold -= COST_ARCHER;
    break;
  case 2:
    PlaceTower(2);
    m_curGold -= COST_MAGE;
    break;
  case 3:
    PlaceTower(3);
    m_curGold -= COST_ARTILLERY;
    break;
  case 4:
    break;
  }
}

void Game::PlaceTower(int choice) { // places the tower on the map based on the
                                    // player's choice and location input
  int loc;
  cout << "Where would you like to place the tower? (1-3)" << endl;
  cin >> loc;

  Tower *t = nullptr;

  switch (choice) {
  case 1:
    t = new ArcherTower("archer", DAMAGE_ARCHER, loc);
    cout << "Archer Tower built at location " << loc << "!" << endl;
    break;
  case 2:
    t = new MageTower("mage", DAMAGE_MAGE, loc);
    cout << "Mage Tower built at location " << loc << "!" << endl;
    break;
  case 3:
    t = new Artillery("artillery", DAMAGE_ARTILLERY, loc);
    cout << "Artillery built at location " << loc << "!" << endl;
    break;
  }
  m_towers.push_back(t);
}

void Game::UpgradeTower() { // allows the player to upgrade an existing tower
  int tSize = m_towers.size();

  if (tSize == 0) {
    return;
  }

  cout << "Which tower would you like to upgrade? (1-" << tSize << ")" << endl;

  for (int i = 0; i < tSize; i++) {
    cout << i + 1 << ". " << *m_towers[i] << endl;
  }
  int choice = 0;
  cin >> choice;

  while (choice < 1 || choice > tSize) { // input validatin
    for (int i = 0; i < tSize; i++) {
      cout << i + 1 << ". " << *m_towers[i] << endl;
    }
    cin >> choice;
  }

  if (m_curGold >= COST_UPGRADE) {
    Tower *t = m_towers[choice - 1];
    int newDamage = t->GetDamage() + UPGRADE_VALUE;
    t->SetDamage(newDamage);
    m_curGold -= COST_UPGRADE;
    cout << t->GetType() << " Tower at location " << t->GetLocation()
         << " upgraded!" << endl;
  } else {
    cout << "Not Enough Gold" << endl;
  }
}

void Game::PlayRound() { // plays a round of the game and cycles through all
                         // phases of the round
  cout << endl;
  cout << "=== Wave " << m_curRound << " begins! ===" << endl;
  SpawnEnemies();
  MoveEnemies();
  ResolveCombat();
  RemoveDefeated();
  CheckPath();
  cout << "=== Wave " << m_curRound << " complete! ===" << endl;
  cout << endl;
  m_curRound++;
}

void Game::SpawnEnemies() { // spawns enemies based on the current round
  for (int i = 1; i <= m_curRound; i++) {
    Orc *orc = new Orc(i, START_ENEMY);
    m_enemies.push_back(orc);
    cout << "A " << orc->GetTier() << " marches toward the kingdom!" << endl;
  }
}

void Game::ResolveCombat() { // resolves combat between towers and enemies
  int tSize = m_towers.size();
  for (int i = 0; i < tSize; i++) {
    m_curGold += m_towers[i]->Attack(m_enemies); // gold earned from attacks
  }
}

void Game::RemoveDefeated() { // removes defeated enemies from the game
  for (int pass = 0; pass < 5;
       pass++) { // runs 5 times to ensure all dead orccs are deleated
    for (int i = 0; i < (int)m_enemies.size(); i++) {
      if (m_enemies[i]->GetHealth() <= 0) {
        delete m_enemies[i];
        m_enemies.erase(m_enemies.begin() + i);
      }
    }
  }
}

void Game::MoveEnemies() { // moves all enemies forward on the path
  int eSize = m_enemies.size();
  for (int i = 0; i < eSize; i++) {
    int newLoc = m_enemies[i]->GetLocation() + 1;
    m_enemies[i]->SetLocation(newLoc);
  }
  cout << "The enemy horde advances!" << endl;
}

void Game::CheckPath() { // checks if any enemies have reached the end of the
                         // path
  for (int i = 0; i < (int)m_enemies.size(); i++) {
    if (m_enemies[i]->GetLocation() >= PATH_LENGTH) {
      m_curLife -= m_enemies[i]->GetHealth();
      delete m_enemies[i];
      m_enemies.erase(m_enemies.begin() + i);
    }
  }
}
