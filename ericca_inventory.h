#ifndef INVENTORY_H
#define INVENTORY_H

#include "item.h"
using namespace std;

class Inventory {
private:
	const int MAX_SPACE = 100;
	int filledSpace, emptySpace, foodSpace, weaponSpace, repairSpace;
	Item inventorySpace[MAX_SPACE];

public:
	// initializes values
	Inventory();
	~Inventory();

	// adds or removes items from Item[]
	void addItem(Item);
	int useItem(string);
	
	int getFilledSpace();
	void setFilledSpace(int);

	int getEmptySpace();
	void setEmptySpace(int);

	int getFoodSpace();
	void setFoodSpace(int);

	int getWeaponSpace();
	void setWeaponSpace(int);

	int getRepairSpace();
	void setRepairSpace(int);
};
#endif
