#ifndef ITEM_H
#define ITEM_H

#include <string>
using namespace std;

// Create subclasses i.e.
//		food: fruit, water, meat, bread, cheese
//		weapons: cannonballs, scattershot, chainballs, explosive cannonballs
//		booze: wine, beer, rum, whiskey
//	Modifications: can make formulas to create certain items like mast, sails, chassy
//			this is the simplest form to finish game
//		repair: tools, wood (1 tool + 1 wood = % shipHealth)

class Item {
private:
	const char *itemName;
	string itemType;
	int attackBonus, healthBonus, speedBonus;

public:
	Item();
	virtual ~Item();

	const char *getItemName();
	void setItemName(const char *name);

	string getItemType();
	void setItemType(string);

	int getAttackBonus();
	void setAttackBonus(int);
	
	int getHealthBonus();
	void setHealthBonus(int);

	int getSpeedBonus();
	void setSpeedBonus(int);
};
#endif
