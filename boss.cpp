#include <stdlib.h>
#include <time.h>

#include "boss.h"

// Constructor
Boss::Boss() {
	health = MAX_HEALTH;
	attack = MAX_ATTACK;
}

// Basic attack
int Boss::bite() {
	srand(time(NULL));
	return MIN_ATTACK + rand()%(attack);
}

// Slows down enemy
int Boss::slime() {
	srand(time(NULL));
	return MIN_SPEED + rand()%(MAX_SPEED);
}

int Boss::fireBlast() {
	srand(time(NULL));
	return MIN_ATTACK + rand()%(attack*(2/3));
}

int Boss::waterBlast() {
	srand(time(NULL));
	return MIN_ATTACK + rand()%(attack/3);
}

void Boss::defend(int attack) {
	srand(time(NULL));
	int def = MIN_DEFENSE + rand()%(MAX_DEFENSE);
	setHealth(def - attack);
}

void Boss::tidalWave() {
	if(health != MAX_HEALTH) 
		setHealth(health + 10);
}

const char *Boss::getBossName() { return bossName; }

int Boss::getHealth() { return health; }

int Boss::getAttack() { return attack; }

void Boss::setBossName(const char *name) { bossName = name; }

void Boss::setHealth(int num) { health = num; }

void Boss::setAttack(int num) { attack = num; }
