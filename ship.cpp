// add other includes to this if needed
#include <iostream>
#include "ship.h"

using namespace std;

Ship::Ship() {
	health = MAX_HEALTH;
}

~Ship::Ship() {
}

string Ship::getShipName() {
	return shipName;
}

void Ship::setShipName(string name) {
	shipName = name;
}

int Ship::getAttack() {
	return attack;
}

void Ship::setAttack(int shipAttack) {
	// I don't even know if we should have these
	if (shipAttack > MAX_ATTACK) {
		cout << "Error: Input needs to be less than or equal to " << MAX_ATTACK << endl;
	}
	else {
		attack = shipAttack;
	}
}

int Ship::getSpeed() {
	return speed;
}

void Ship::setSpeed(int agility) {
	if (agility > MAX_SPEED) {
		cout << "Error: Input needs to be lass than or equal to " << MAX_SPEED << endl;
	}
	else {
		speed = agility;
	}
}

int Ship::shipCannonball() {
	// return a randomized num or set a value?
}

int Ship::shipChainShot() {
	// ^
}

int Ship::shipScatterShot() {
	// ^
}

int Ship::shipExplosiveCannonball() {
	// ^
}
