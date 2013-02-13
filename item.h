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
		string itemType;

	public:	
		string getItemType();
		void setItemType();
}

#endif
