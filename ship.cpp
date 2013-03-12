#include <iostream>
#include <time.h>
#include <stdlib.h>

#include "ship.h"

// assigns attribute values subject to change
Ship::Ship() : health(MAX_HEALTH), attack(MAX_ATTACK), speed(MAX_SPEED) {}

// deallocates array memory
Ship::~Ship() { inventory->~Inventory(); }

Inventory *Ship::getInventory() { return inventory; }

void Ship::addItem(Item item) { inventory->addItem(item); }

int Ship::useItem(Item item) {
	if(item.getItemType() == "food") 
		return inventory->useItem(item);
	if(item.getItemType() == "repair") 
		return inventory->useItem(item);
	if(item.getItemType() == "weapon") 
		return MAX_ATTACK + inventory->useItem(item);
}

void Ship::setCrew() {
	crew = Crew();
}

void Ship::setInventory() {
	inventory = new Inventory();	
}
// gives the most damage to enemy
int Ship::explosiveCannonball() { 
	// picks a number between MAX_ATTACK and half of ship's health
	int n = attack + rand()%(218/2);
	return n;
}

// designed to give extensive damage to enemy
int Ship::cannonball() {
	// randomly picks a number between 10 and the attack
	int n = 10 + rand()%attack;
	return n;
}

// reduces enemy's speed
int Ship::chainShot() {
	// randomly picks a number between 1 and the speed
	int n = 1 + rand()%speed;
	return n;
}

// 60% attack 30% speed reduction
int Ship::scatterShot() {
	// probably be around 5 to 10
	int a = 5 + rand()%(attack/2);
	// be around 1 to 7
	int b = 1 + rand()%(speed - 3);
	return (a + b);
}

// Getters and Setters
// need to change this to const char * instead for allegro al_draw_text()
const char *Ship::getShipName() { return shipName; }

int Ship::getHealth() { return health; }

int Ship::getAttack() { return attack; }

int Ship::getSpeed() { return speed; }

void Ship::setShipName(const char *name) { shipName = name; }

void Ship::setHealth(int num) { health = num; }

void Ship::setAttack(int num) { attack = num; }

void Ship::setSpeed(int num) { speed = num; }
/* End of ship.cpp */
