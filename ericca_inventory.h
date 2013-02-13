#ifndef INVENTORY_H
#define INVENTORY_H

#include "item.cpp"

class Inventory {

  	private:
		// want to be able to display so user can see how much space is left
		int filledSpace, emptySpace, foodSpace, weaponSpace, repairSpace;

		// using Item class to help create an array
		Item inventorySpace[MAX_SPACE];
	
	public:
		// sets filledSpace to 0
    		Inventory();
		~Inventory();

		// changes space values
		void addItem(Item item);
		
		// If return 0 print out on game, "Item doesn't exist in inventory."
		int useItem(string itemType);
		
		int getFilledSpace();
		void setFilledSpace(int space);
		
		int getEmptySpace();
		void setEmptySpace(int space);
		
		int getFoodSpace();
		void setFoodSpace(int space);
		
		int getWeaponSpace();
		void getWeaponSpace(int space);
		
		int getRepairSpace();
		void setRepairSpace(int space);
};

#endif
