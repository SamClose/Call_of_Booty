#include <iostream>
#include "enemyShip.h"

using namespace std;

// Values subject to change
#define MAX_ENEMY_HEALTH 100
#define MAX_ENEMY_ATTACK 20
#define MAX_ENEMY_SPEED 10

EnemyShip::EnemyShip() {
	health = MAX_ENEMY_HEALTH;
	attack = MAX_ENEMY_ATTACK;
	speed = MAX_ENEMY_SPEED;
}

int EnemyShip::shipCannonBall() {
	return attack;
}

int EnemyShip::shipScatterShot() {
	return attack/4;
}

int EnemyShip::shipChainShot() {
	return attack/speed;
}

/* End of enemyShip.cpp */
