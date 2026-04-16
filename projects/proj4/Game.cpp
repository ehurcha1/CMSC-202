#include "Game.h"
using namespace std;

Game::Game() {
  m_curRound = 1;
  m_curGold = 10;
  m_curLife = 100;
}

Game::~Game() {
  int eSize = m_enemies.size();
  int tSize = m_towers.size();

  for (int i = 0; i < eSize; i++) {
    delete m_enemies[i];
  }

  for (int i = 0; i < tSize; i++) {
    delete m_towers[i];
  }
}

void Game::StartGame() {
  cout << "Welcome to UMBC Kingdom Rush!" << endl;
  cout << "Defend the realm against the Orc horde!" << endl;
}
