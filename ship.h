#ifndef SHIP_H
#define SHIP_H

#include "inventory.h"
#include "crew.h"
using namespace std;

class Ship {
private:
	static const int MAX_HEALTH = 100;
	static const int MAX_ATTACK = 20;
	static const int MAX_SPEED = 10;

	Inventory *inventory;
	Crew crew;
	
	const char *shipName;

	// speed can be used for a wait time or increases attack
	int attack, health, speed;

public:
	Ship();
	virtual ~Ship();

	void setCrew();
	void setInventory();

	const char *getShipName();
	void setShipName(const char *name);

	int getAttack();
	void setAttack(int);

	int getHealth();
	void setHealth(int);

	int getSpeed();
	void setSpeed(int);

	int cannonball();
	int chainShot();
	int explosiveCannonball();
	int scatterShot();

	Inventory *getInventory();

	void addItem(Item);
	void useItem(Item);

};
#endif
