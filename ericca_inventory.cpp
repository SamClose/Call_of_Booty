// Add more includes if needed
#include <iostream>
#include "inventory.h"

using namespace std;

Inventory::Inventory() {
	filledSpace = MIN_SPACE;
	foodSpace = MIN_SPACE;
	ammoSpace = MIN_SPACE;
	weaponSpace = MIN_SPACE;
	emptySpace = MAX_SPACE;
}

Inventory::~Inventory() {
	// delete Item[]
	delete [] inventorySpace;
}

void Inventory::addItem(Item item) {
	if (filledSpace != MAX_SPACE) {
		for(int i = 0; i < filledSpace; i++) {
			inventorySpace[i] = item;
		}
	}
	else {
		// System error print out
		cout << "Error: Inventory is full!" << endl;
	}
}

void Inventory::useItem(Item item) {
	Item temp;
	temp.deleteItem(inventorySpace, item);
	setFilledSpace(getFilledSpace()--);
	setEmptySpace(getEmptySpace()++);
	if(item.getItemType() == "food") {
		setFoodSpace(getFoodSpace()--);
	}
	else if (item.getItemType() == "weapon") {
		setWeaponSpace(getWeaponSpace()--);
	}
	else if (item.getItemType() == "repair") {
		setRepairSpace(getRepairSpace()--);
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
