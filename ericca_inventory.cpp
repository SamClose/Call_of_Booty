#include "inventory.h"

#include <iostream>
#include <time.h>
#include <stdlib.h>

Inventory::Inventory() : filledSpace(0), emptySpace(MAX_SPACE) { setItems(); }

Inventory::~Inventory() {}

void Inventory::setItems() {
	// creating items
	food.setItemName("FOOD");
	food.setItemType("food");

	water.setItemName("WATER");
	water.setItemType("food");

	booze.setItemName("BOOZE");
	booze.setItemType("food");

	wood.setItemName("WOOD");
	wood.setItemType("repair");

	tools.setItemName("TOOLS");
	tools.setItemType("repair");

	rope.setItemName("ROPE");
	rope.setItemType("repair");

	cannonballItem.setItemName("CANNONBALL");
	cannonballItem.setItemType("weapon");

	chainShotItem.setItemName("CHAINSHOT");
	chainShotItem.setItemType("weapon");

	scatterShotItem.setItemName("SCATTERSHOT");
	scatterShotItem.setItemType("weapon");

	explosiveCannonballItem.setItemName("EXP. CANNONBALL");
	explosiveCannonballItem.setItemType("weapon");

	// setting bonuses
	food.setHealthBonus(15);
	food.setAttackBonus(0);
	food.setSpeedBonus(0);

	water.setHealthBonus(10);
	water.setAttackBonus(0);
	water.setSpeedBonus(0);

	booze.setHealthBonus(100);
	booze.setAttackBonus(20);
	booze.setSpeedBonus(0);

	wood.setHealthBonus(15);
	wood.setAttackBonus(0);
	wood.setSpeedBonus(0);

	tools.setHealthBonus(5);
	tools.setAttackBonus(5);
	tools.setSpeedBonus(0);

	rope.setHealthBonus(60);
	rope.setAttackBonus(0);
	rope.setSpeedBonus(0);

	cannonballItem.setHealthBonus(0);
	cannonballItem.setAttackBonus(10);
	cannonballItem.setSpeedBonus(0);

	chainShotItem.setHealthBonus(0);
	chainShotItem.setAttackBonus(5);
	chainShotItem.setSpeedBonus(5);

	scatterShotItem.setHealthBonus(3);
	scatterShotItem.setAttackBonus(7);
	scatterShotItem.setSpeedBonus(0);

	explosiveCannonballItem.setHealthBonus(0);
	explosiveCannonballItem.setAttackBonus(0);
	explosiveCannonballItem.setSpeedBonus(0);
}

void Inventory::addItem(Item item) {
	if(filledSpace != MAX_SPACE) {
		if(item.getItemType() == "repair") {
			if (item.getItemName() == "WOOD") {
				inventorySpace[0]++;
			}
			else if (item.getItemName() == "TOOLS") {
				inventorySpace[0]++;
			}
			else if (item.getItemName() == "ROPE") {
				inventorySpace[0]++;
			}
		}
		else if (item.getItemType() == "food") {
			if(item.getItemName() == "FOOD") {
				inventorySpace[1]++;
			}
			else if (item.getItemName() == "WATER") {
				inventorySpace[1]++;
			}
			else if (item.getItemName() == "BOOZE") {
				inventorySpace[1]++;
			}
		}
		else if (item.getItemType() == "weapon") {
			if(item.getItemName() == "CANNONBALL") {
				inventorySpace[2]++;
			}
			else if(item.getItemName() == "SCATTERSHOT") {
				inventorySpace[3]++;
			}
			else if(item.getItemName() == "CHAINSHOT") {
				inventorySpace[4]++;
			}
			else if(item.getItemName() == "EXP. CANNONBALL") {
				inventorySpace[5]++;
			}
		}
		for(int i = 0; i < 6; i++) {
			filledSpace += inventorySpace[i];
		}
		emptySpace = MAX_SPACE - filledSpace;
	}
	else
		std::cout << "Inventory is full!" << std::endl;
}

int Inventory::useItem(Item item) {
		if(item.getItemType() == "repair") {
			return item.getHealthBonus();
			inventorySpace[0]--;
		}
		else if (item.getItemType() == "food") {
			return item.getHealthBonus();
			inventorySpace[1]--;
		}
		else if (item.getItemType() == "weapon") {
			if (item.getItemName() == "CANNONBALL") {
				inventorySpace[2]--;
			}
			else if(item.getItemName() == "SCATTERSHOT") {
				inventorySpace[3]--;
			}
			else if (item.getItemName() == "CHAINSHOT") {
				inventorySpace[4]--;
			}
			else if (item.getItemName() == "EXP. CANNONBALL") {
				inventorySpace[5]--;
				return 0;
			}
			return item.getAttackBonus();
		}
		return item.getHealthBonus();
		filledSpace--;
		emptySpace++;
}

// Getters and setters for private attributes
Item Inventory::getBooze() { return booze; }

Item Inventory::getFood() { return food; }

Item Inventory::getWater() { return water; }

Item Inventory::getWood() { return wood; }

Item Inventory::getTools() { return tools; }

Item Inventory::getRope() { return rope; }

Item Inventory::getCannonballItem() { return cannonballItem; }

Item Inventory::getChainShotItem() { return chainShotItem; }

Item Inventory::getScatterShotItem() { return scatterShotItem; }

Item Inventory::getExplosiveCannonballItem() { return explosiveCannonballItem; }

int Inventory::getFilledSpace() { return filledSpace; }

int Inventory::getEmptySpace() { return emptySpace; }

void Inventory::setFilledSpace(int space) { filledSpace = space; }

void Inventory::setEmptySpace(int space) { emptySpace = space; }
/* End of inventory.cpp */
