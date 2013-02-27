#include <iostream>
#include "ship.h"
using namespace std;

Ship::Ship() : health(MAX_HEALTH), attack(MAX_ATTACK), speed(MAX_SPEED) {}

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

string Ship::getShipName() { return shipName; }

int Ship::getHealth() { return health; }

int Ship::getAttack() { return attack; }

int Ship::getSpeed() { return speed; }

void Ship::setShipName(string name) { shipName = name; }

void Ship::setHealth(int num) { health = num; }

void Ship::setAttack(int num) { attack = num; }

void Ship::setSpeed(int num) { speed = num; }
/* End of ship.cpp */
