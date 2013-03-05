#include "inventory.h"
#include <iostream>
#include <time.h>
#include <stdlib.h>

using namespace std;

Inventory::Inventory() : filledSpace(0), emptySpace(MAX_SPACE) {
	// creating items
	food = new Item("FOOD", "food");
	water = new Item("WATER", "food");
	booze = new Item("BOOZE", "food");
	wood = new Item("WOOD", "repair");
	tools = new Item("TOOLS", "repair");
	rope = new Item("ROPE", "repair");
	cannonBallItem = new Item("CANNONBALL", "weapon");
	chainShotItem = new Item("CHAINSHOT", "weapon");
	scatterShotItem = new Item("SCATTERSHOT", "weapon");
	explosiveCannonballItem = new Item("EXP. CANNONBALL", "weapon");
	// setting bonuses
	food->setHealthBonus(5);
	water->setHealthBonus(5);
	booze->setSpeedBonus(10);
	wood->setHealthBonus(10);
	tools->setAttackBonus(5);
	rope->setHealthBonus(3);
	cannonBallItem->setAttackBonus(10);
	chainShotItem->setSpeedBonus(5);
	scatterShotItem->setAttackBonus(7);

}

Inventory::~Inventory() {
	delete [] inventorySpace;
	// Deleteing items
	delete food, water, booze,
		tools, wood, rope,
		cannonBallItem, chainShotItem,
		scatterShotItem, explosiveCannonballItem;
}

void Inventory::addItem(Item item) {
	if(filledSpace != MAX_SPACE) {
		if(item.getItemType() == "repair") {
			if (item.getItemName() == "WOOD") {
				inventorySpace[0]++;
				filledSpace++;
				emptySpace--;
			}
			else if (item.getItemName() == "TOOLS") {
				inventorySpace[0]++;
				filledSpace++;
				emptySpace--;
			}
			else if (item.getItemName() == "ROPE") {
				inventorySpace[0]++;
				filledSpace++;
				emptySpace--;
			}
		}
		else if (item.getItemType() == "food") {
			if(item.getItemName() == "FOOD") {
				inventorySpace[1]++;
				filledSpace++;
				emptySpace--;
			}
			else if (item.getItemName() == "WATER") {
				inventorySpace[1]++;
				filledSpace++;
				emptySpace--;
			}
			else if (item.getItemName() == "BOOZE") {
				inventorySpace[1]++;
				filledSpace++;
				emptySpace--;
			}
		}
		else if (item.getItemType() == "weapon") {
			if(item.getItemName() == "CANNONBALL") {
				inventorySpace[2]++;
				filledSpace++;
				emptySpace--;
			}
			else if(item.getItemName() == "SCATTERSHOT") {
				inventorySpace[3]++;
				filledSpace++;
				emptySpace--;
			}
			else if(item.getItemName() == "CHAINSHOT") {
				inventorySpace[4]++;
				filledSpace++;
				emptySpace--;
			}
			else if(item.getItemName() == "EXP. CANNONBALL") {
				inventorySpace[5]++;
				filledSpace++;
				emptySpace--;
			}
		}
	}
	else
		cout << "Inventory is full!" << endl;
}

int Inventory::useItem(Item item) {
	if (filledSpace > 0) {
		if(item.getItemType() == "repair") {
			if (item.getItemName() == "WOOD")
				return item.getHealthBonus();
			else if (item.getItemName() == "TOOLS")
				return item.getHealthBonus();
			else if (item.getItemName() == "ROPE")
				return item.getHealthBonus();
			inventorySpace[0]--;
			filledSpace--;
			emptySpace++;
		}
		else if (item.getItemType() == "food") {
			if(item.getItemName() == "FOOD")
				return item.getHealthBonus();
			else if (item.getItemName() == "WATER")
				return item.getHealthBonus();
			else if (item.getItemName() == "BOOZE")
				return item.getHealthBonus();
			inventorySpace[1]--;
			filledSpace--;
			emptySpace++;
		}
		else if (item.getItemType() == "weapon") {
			if (item.getItemName() == "CANNONBALL")
				return item.getAttackBonus();
			else if(item.getItemName() == "SCATTERSHOT")
				return item.getAttackBonus();
			else if (item.getItemName() == "CHAINSHOT")
				return item.getSpeedBonus();
			inventorySpace[2]--;
			filledSpace--;
			emptySpace++;
		}
	}
}

// Getters and setters for private attributes
int Inventory::getFilledSpace() { return filledSpace; }

void Inventory::setFilledSpace(int space) { filledSpace = space; }

int Inventory::getEmptySpace() { return emptySpace; }

void Inventory::setEmptySpace(int space) { emptySpace = space; }
/* End of inventory.cpp */
