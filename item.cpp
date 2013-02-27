#include "item.h"
using namespace std;

Item::Item() {}

Item::Item(string name, string type) {
	itemName = name;
	itemType = type;
}

// need to change this to const char * instead for allegro al_draw_text()
string Item::getItemName() { return itemName; }
// need to change string name to const char * name instead for allegro al_draw_text()
void Item::setItemName(string name) { itemName = name; }

string Item::getItemType() { return itemType; }

void Item::setItemType(string type) { itemType = type; }

int Item::getAttackBonus() { return attackBonus; }

void Item::setAttackBonus(int bonus) { attackBonus = bonus; }

int Item::getHealthBonus() { return healthBonus; }

void Item::setHealthBonus(int bonus) { healthBonus = bonus; }

int Item::getSpeedBonus() { return speedBonus; }

void Item::setSpeedBonus(int bonus) { speedBonus = bonus; }
/* End of item.cpp */
