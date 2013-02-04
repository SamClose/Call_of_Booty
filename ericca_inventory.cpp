#include "inventory.h"

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
		cout << "Error: Inventory is full!" << endl;
	}
}

void Inventory::useItem(Item item) {
	
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

int Inventory::getAmmoSpace() {
	return ammoSpace;
}

void Inventory::setAmmoSpace(int space) {
	ammoSpace = space;
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
