#ifndef ITEM_H
#define ITEM_H

#include <string>
using namespace std;

class Item {
private:
	// need to change this to const char * instead for allegro al_draw_text()
	string itemName;
	string itemType;
	int attackBonus, healthBonus, speedBonus;

public:
	Item();
	Item(string name, string type);

	// need to change this to const char * instead for allegro al_draw_text()
	string getItemName();
	void setItemName(string);

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
