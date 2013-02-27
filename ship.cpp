#include <iostream>
#include <time.h>
#include <stdlib.h>

#include "ship.h"
using namespace std;

// assigns attribute values subject to change
Ship::Ship() : health(MAX_HEALTH), attack(MAX_ATTACK), speed(MAX_SPEED) {}

// deallocates array memory
Ship::~Ship() { shipInventory.~Inventory(); }

void Ship::addItem(Item item) { shipInventory.addItem(item); }

void Ship::useItem(Item item) { shipInventory.useItem(item.getItemType()); }

void Ship::setShipCrew() {
	Crew newCrew = Crew();
	shipCrew = newCrew;
}

void Ship::setShipInventory() {
	Inventory newInventory = Inventory();
	shipInventory = newInventory;
}
// gives the most damage to enemy
int Ship::explosiveCannonball() { 
	// picks a number between MAX_ATTACK and half of ship's health
	srand(time(NULL));
	int n = attack + rand()%(health/2);
	return n;
}

// designed to give extensive damage to enemy
int Ship::cannonball() {
	// randomly picks a number between 10 and the attack
	srand(time(NULL));
	int n = 10 + rand()%attack;
	return n;
}

// reduces enemy's speed
int Ship::chainShot() {
	// randomly picks a number between 1 and the speed
	srand(time(NULL));
	int n = 1 + rand()%speed;
	return n;
}

// 60% attack 30% speed reduction
int Ship::scatterShot() {
	srand(time(NULL));
	// probably be around 5 to 10
	int a = 5 + rand()%(attack/2);
	// be around 1 to 7
	int b = 1 + rand()%(speed - 3);
	return (a + b);
}

// Getters and Setters
// need to change this to const char * instead for allegro al_draw_text()
string Ship::getShipName() { return shipName; }

int Ship::getHealth() { return health; }

int Ship::getAttack() { return attack; }

int Ship::getSpeed() { return speed; }

void Ship::setShipName(string name) { shipName = name; }

void Ship::setHealth(int num) { health = num; }

void Ship::setAttack(int num) { attack = num; }

void Ship::setSpeed(int num) { speed = num; }
