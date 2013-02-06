// add other includes to this if needed
#include <iostream>
#include "ship.h"

using namespace std;

Ship::Ship() {
	health = MAX_HEALTH;
	attack = MAX_ATTACK;
	speed = MAX_SPEED;
}

virtual ~Ship::Ship() {
	health = 0;
	shipInventory.~Inventory();
	shipCrew.~Crew();
}

string Ship::getShipName() {
	return shipName;
}

void Ship::setShipName(string name) {
	shipName = name;
}

int Ship::getHealth() {
	return health;
}

void Ship::setHealth(int hitPoints) {
	if (hitPoints > MAX_HEALTH) {
		cout << "Error: Health cannot be greater than " << MAX_HEALTH << endl;
	}
	else if (hitPoints < 0) {
		cout << "Error: Health needs to be a positive integer." << endl;
	}
	else {
		health = hitPoints;
	}
}

int Ship::getAttack() {
	return attack;
}

void Ship::setAttack(int shipAttack) {
	// I don't even know if we should have these
	if (shipAttack > MAX_ATTACK) {
		cout << "Error: Attack needs to be less than or equal to " << MAX_ATTACK << endl;
	}
	else if (shipAttack < 0) {
		cout << "Error: Attack cannot be less than 0." << endl;
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
		cout << "Error: Speed needs to be less than or equal to " << MAX_SPEED << endl;
	}
	else if (agility < 0) {
		cout << "Error: Speed cannot be less than 0." << endl;
	}
	else {
		speed = agility;
	}
}

int Ship::shipCannonball() {
	// return a randomized num or set a value?
	return attack;
}

int Ship::shipChainShot() {
	return attack/speed;
}

int Ship::shipScatterShot() {
	return attack/4;
}

int Ship::shipExplosiveCannonball() {
	return health/2;
}

void Ship::shipAddItem(Item item) {
	shipInventory.addItem(item);
}

void Ship::shipUseItem(Item item) {
	shipInventory.useItem(item);
}

void Ship::crewUseItem(Item item) {
	shipCrew.crewUseItem(item);
}

/* End of ship.cpp */
