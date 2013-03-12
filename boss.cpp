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
	int newAttack = attack - 30;
	srand(time(NULL));
	return MIN_ATTACK + rand()%(newAttack);
}

int Boss::waterBlast() {
	int newAttack = attack - 60;
	srand(time(NULL));
	return MIN_ATTACK + rand()%(newAttack);
}

int Boss::defend(int attack) {
	srand(time(NULL));
	int def = MIN_DEFENSE + rand()%(MAX_DEFENSE);
	return attack - def;
}

int Boss::tidalWave() {
	if(health != MAX_HEALTH) 
		return 40;
}

const char *Boss::getBossName() { return bossName; }

int Boss::getHealth() { return health; }

int Boss::getAttack() { return attack; }

void Boss::setBossName(const char *name) { bossName = name; }

void Boss::setHealth(int num) { health = num; }

void Boss::setAttack(int num) { attack = num; }
