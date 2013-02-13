// Add more includes if needed
#include <iostream>
#include "inventory.h"

using namespace std;

Inventory::Inventory() {
	filledSpace = MIN_SPACE;
	foodSpace = MIN_SPACE;
	repairSpace = MIN_SPACE;
	weaponSpace = MIN_SPACE;
	emptySpace = MAX_SPACE;
}

Inventory::~Inventory() {
	// delete Item[]
	delete [] inventorySpace;
}

void Inventory::addItem(Item item) {
	if (filledSpace != MAX_SPACE) {
		if (item.getItemType() == "repair") {
			repairSpace++;
		}
		else if(item.getItemType() == "food") {
			foodSpace++;
		}
		else if (item.getItemType() == "weapon") {
			weaponSpace++;
		}
		for(int i = 0; i < filledSpace; i++) {
			inventorySpace[i] = item;
		}
		filledSpace++;
	}
	else {
		// System error print out: "Error: Inventory is full!"
	}
}

int Inventory::useItem(string itemType) {
	// need to find a way to accept Item subclasses instead of just item.
	if(filledSpace > MIN_SPACE) {
		for(int i = 0; i < filledSpace; i++) {
			if (inventorySpace[i].itemType == itemType) {
				if(itemType == "repair" && repairSpace > 0) { // 1 bonus
					Repair item;
					return item.healthBonus;
				}
				else if (itemType == "food" && foodSpace > 0) { // 2 bonuses
					Food item;
					srand(time(NULL));
					int n = 1 + rand()%2;
					switch(n) {
						case 1: return item.healthBonus;
						case 2: return item.attackBonus;
					}
				}
				else if (itemType == "weapon" && weaponSpace > 0) { // 2 bonuses
					Weapon item;
					srand(time(NULL));
					int n = 1 + rand()%2;
					switch(n) {
						case 1: return item.attackBonus;
						case 2: return item.speedBonus;
					}
				}
				// getting rid of item from inventorySpace array
				for(int index = i; index < filledSpace; index++) {
					inventorySpace[index] = inventorySpace[index++];
					inventorySpace[filledSpace - 1] = NULL;
				}
				filledSpace--;
				emptySpace++;
			}
			// when iterator reaches the last Item
			else if (inventorySpace[filledSpace - 1].itemType != itemType) {
				// Print out on game: Item doesn't exist in inventory.
				return 0;
			}
		}
	}
	if(itemType == "repair") {
		item[0]--;
	}
	else if (itemType == "food") {
		item[1]--;
	}
	else if (itemType == "weapon") {
		item[2]--;
	}
}

// Get and set methods for attributes
int Inventory::getFilledSpace() {
	return filledSpace;
}

void Inventory::setFilledSpace(int space) {
	filledSpace = space;
}

int Inventory::getFoodSpace() {
	return foodSpace;
}

void Inventory::setFoodSpace(int space) {
	foodSpace = space;
}

int Inventory::getReapairSpace() {
	return repairSpace;
}

void Inventory::setRepairSpace(int space) {
	repairSpace = space;
}

int Inventory::getWeaponsSpace() {
	return weaponSpace;
}

void Inventory::setWeaponSpace(int space) {
	weaponSpace = space;
}

int Inventory::getEmptySpace() {
	return emptySpace;
}

void Inventory::setEmptySpace(int space) {
	emptySpace = space;
}

/* End of inventory.cpp */
