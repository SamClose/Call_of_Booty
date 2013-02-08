#include <iostream>
#include "enemyShip.h"

using namespace std;

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
