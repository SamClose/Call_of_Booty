#ifndef ENEMY_SHIP_H
#define ENEMY_SHIP_H

#include "ship.h"
#include "inventory.h"
using namespace std;
class EnemyShip : public Ship {
private:
	static const int MAX_ATTACK = 25;
	static const int MAX_HEALTH = 130;
	static const int MAX_SPACE = 60;
	static const int MAX_SPEED = 7;

	const char *shipName;
	int attack, health, speed;

	Inventory *inventory;

public:
	// sets attributes using parent
	EnemyShip() : Ship(){
		attack = MAX_ATTACK;
		health = MAX_HEALTH;
		speed = MAX_SPEED;
	};
	// deallocates space
	~EnemyShip();

	// set emptySpace as 60
	// allocate inventory for weapons (cannonballs, small balls, chain balls) and health (wood, tools, rope)
	// 51 (17 each) for weapons 9 (3 each) for health
	void setShipInventory();

	// condition: don't add/use if filledSpace is >= emptySpace
	// then use parent function to add
	void addItem(Item);
};
#endif
