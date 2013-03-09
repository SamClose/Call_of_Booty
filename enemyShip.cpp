
#include "enemyShip.h"
using namespace std;

EnemyShip::~EnemyShip() { inventory->~Inventory(); }

void EnemyShip::setShipInventory() {
	inventory->setEmptySpace(MAX_SPACE);
	for(int i = 0; i < 17; i++) {
		addItem(inventory->getCannonballItem());
		addItem(inventory->getChainShotItem());
		addItem(inventory->getScatterShotItem());
	}
	for(int i = 0; i < 3; i++) {
		addItem(inventory->getWood());
		addItem(inventory->getTools());
		addItem(inventory->getRope());
	}
}

void EnemyShip::addItem(Item item) {
	// hypothetically fills spaces 60
	if(inventory->getFilledSpace() < inventory->getEmptySpace() && inventory->getFilledSpace() >= 0)
		Ship::addItem(item);
}
