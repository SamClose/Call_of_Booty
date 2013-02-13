#ifndef INVENTORY_H
#define INVENTORY_H

#include "item.cpp"

#define MAX_SPACE 100
#define MIN_SPACE 0

class Inventory {

  	private:
		// want to be able to display so user can see how much space is left
		int filledSpace, emptySpace, foodSpace, weaponSpace, repairSpace;

		// using Item class to help create an array
		int item[3];
		Item inventorySpace[MAX_SPACE];
	
	public:
		// sets filledSpace to 0
    		Inventory();
		~Inventory();

		// changes space values
		void addItem(Item item);
		void useItem(Item item);
		
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
