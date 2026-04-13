#include "Enemy.h"
using namespace std;

Enemy::Enemy(){
	m_health = 0;
	m_location = 0;
}

Enemy::Enemy(int health, int location){
	m_health = health;
	m_location = location;
}

Enemy::~Enemy(){
//not used
}

int Enemy::GetHealth(){
	return m_health;
}

void Enemy::SetHealth(int health){
	m_health = health;
}

int GetLocation(){
	return m_location;
}

void SetLocation(int location){
	m_location = location;
}

