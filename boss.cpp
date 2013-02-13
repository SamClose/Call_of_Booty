#include <stdlib.h>
#include <time.h>
#include "boss.h"
using namespace std;

#define MAX_HEALTH 1000
#define MAX_ATTACK 100
#define MIN_ATTACK 30
#define MAX_DEFEND 20
#define MIN_DEFEND 0
#define MAX_SPEED 20
#define MIN_SPEED 5

Boss::Boss() {
	health = MAX_HEALTH;
	attack = MAX_ATTACK;
}

int Boss::bossAttack() {
	// ensures that it will truly be a random value not the same
	srand(time(NULL));
	// returns a number between MIN_ATTACK and attack
	return MIN_ATTACK + rand()%(attack);
}

/* This attack slows down main character. */
int Boss::bossSlime() {
	srand(time(NULL));
	// returns a number between MIN_SPEED and MAX_SPEED
	return MIN_SPEED + rand()%(MAX_SPEED);
}

int Boss::fireBlast() {
	srand(time(NULL));
	return MIN_ATTACK + rand()%(attack*(2/3));
}

int Boss::waterBlast() {
	srand(time(NULL)):
	return MIN_ATTACK + rand()%(attack/3);
}

int Boss::defend() {
	srand(time(NULL));
	return MIN_DEF + rand()%(MAX_DEF);
}

void Boss::tidalWave() {
	if(health != MAX_HEALTH) {
		setBossHealth(health + 10);
	}
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
