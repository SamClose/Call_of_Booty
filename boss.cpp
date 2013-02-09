#include <stdlib.h>
#include <time.h>

#include "boss.h"
using namespace std;

Boss::Boss() {
	health = MAX_HEALTH;
	attack = MAX_ATTACK;
}

Boss::bossAttack() {
	// ensures that it will truly be a random value not the same
	srand(time(NULL));
	// returns a number between MIN_ATTACK and attack
	return MIN_ATTACK + rand()%(attack);
}

/* This attack slows down main character. */
Boss::bossInk() {
	srand(time(NULL));
	// returns a number between MIN_SPEED and MAX_SPEED
	return MIN_SPEED + rand()%(MAX_SPEED);
}

string getBossName() {
	return bossName;
}

void setBossName(string name) {
	bossName = name;
}

int getHealth() {
	return health;
}

void setHealth(int value) {
	health = value;
}

int getAttack() {
	return attack;
}

void setAttack(int value) {
	attack = value;
}
/* End of boss.cpp */
