
#include "enemyShip.h"
using namespace std;

EnemyShip::~EnemyShip() { inventory.~Inventory(); }

void EnemyShip::setShipInventory() {
	inventory.setEmptySpace(MAX_SPACE);
}

void EnemyShip::addItem(Item item) {
	if(inventory.getFilledSpace() < inventory.getEmptySpace() && inventory.getFilledSpace() >= 0)
		Ship::addItem(item);
}

void EnemyShip::useItem(Item item) {
	Ship::useItem(item);
}
