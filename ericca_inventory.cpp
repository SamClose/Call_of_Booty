#include "inventory.h"
#include <time.h>
#include <stdlib.h>

using namespace std;

Inventory::Inventory() : filledSpace(0), emptySpace(MAX_SPACE),
	foodSpace(0), weaponSpace(0), repairSpace(0) {}

Inventory::~Inventory() { delete [] inventorySpace; }

void Inventory::addItem(Item item) {
	if(filledSpace == 0) {
		inventorySpace[filledSpace] = item;
	}
	else if(filledSpace != MAX_SPACE) {
		if(item.getItemType() == "repair") {
			repairSpace++;
		}
		else if (item.getItemType() == "food") {
			foodSpace++;
		}
		else if (item.getItemType() == "weapon") {
			weaponSpace++;
		}
		inventorySpace[filledSpace + 1] = item;
		filledSpace++;
	}
}

int Inventory::useItem(string itemType) {
	if (filledSpace > 0) {
		for(int i = 0; i < filledSpace; i++) {
			if(inventorySpace[i].getItemType() == itemType) {
				if(itemType == "repair" && repairSpace > 0) {
					return inventorySpace[i].getHealthBonus();
				}
				else if (itemType == "food" && foodSpace > 0) {
					srand(time(NULL));
					int n = 1 + rand()%2;
					switch(n) {
					case 1: return inventorySpace[i].getHealthBonus();
					case 2: return inventorySpace[i].getAttackBonus();
					}
				}
				else if (itemType == "weapon" && weaponSpace > 0) {
					srand(time(NULL));
					int n = 1 + rand()%2;
					switch(n) {
					case 1: return inventorySpace[i].getAttackBonus();
					case 2: return inventorySpace[i].getSpeedBonus();
					}
				}
				for(int index = i; index < filledSpace; index++) {
					inventorySpace[index] = inventorySpace[index++];
					inventorySpace[filledSpace - 1] = NULL;
				}
				filledSpace--;
				emptySpace++;
			}
			else if (inventorySpace[filledSpace - 1].getItemType() != itemType) {
				return 0;
			}
		}
	}
}

// Getters and setters for private attributes
int Inventory::getFilledSpace() { return filledSpace; }

void Inventory::setFilledSpace(int space) { filledSpace = space; }

int Inventory::getEmptySpace() { return emptySpace; }

void Inventory::setEmptySpace(int space) { emptySpace = space; }

int Inventory::getFoodSpace() { return foodSpace; }

void Inventory:: setFoodSpace(int space) { foodSpace = space; }

int Inventory::getRepairSpace() { return repairSpace; }

void Inventory::setRepairSpace(int space) { repairSpace = space; }

int Inventory::getWeaponSpace() { return weaponSpace; }

void Inventory::setWeaponSpace(int space) { weaponSpace = space; }
