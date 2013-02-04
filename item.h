#ifndef ITEM_H
#define ITEM_H

// Create subclasses i.e.
//		food: fruit, water, meat, bread, cheese
//		weapons: cannonballs, scattershot, chainballs, explosive cannonballs
//		booze: wine, beer, rum, whiskey
//	Modifications: can make formulas to create certain items like mast, sails, chassy
//			this is the simplest form to finish game
//		repair: tools, wood (1 tool + 1 wood = % shipHealth)
class Item {

	private:
		string itemName, itemType;

	public:
		string getItemName();
		void setItemName();
		
		string getItemType();
		void setItemType();

		// Checks to see if item is in array and compares itemType
		// is there a more efficient way of doing this?
		bool isThere(Item[] itemArray, Item item);

}

#endif
