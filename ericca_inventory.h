#ifndef INVENTORY_H
#define INVENTORY_H

class Inventory {
	#define MAX_SPACE 100;
	#define MIN_SPACE 0;
  	private:
		// want to be able to display so user can see how much space is left
		int filledSpace, emptySpace, foodSpace, ammoSpace, repairSpace;

		// using Item class to help create an array
		Item inventorySpace[MAX_SPACE];
	
	public:
		// sets filledSpace to 0
    		Inventory();
		~Inventory();

		// returns an integer value to change the space values
		// takes an Item array
		int addItem(Item inventorySpace[]);
		int getItem(Item inventorySpace[]);
		int useItem(Item inventorySpace[]);
		
		int getFilledSpace();
		void setFilledSpace(int space);
		
		int getEmptySpace();
		void setEmptySpace(int space);
		
		int getFoodSpace();
		void setFoodSpace(int space);
		
		int getAmmoSpace();
		void setAmmoSpace(int space);
		
		int getRepairSpace();
		void setRepairSpace(int space);
		
		bool check();
};

#endif 
