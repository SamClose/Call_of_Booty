#ifndef SHIP_H
#define SHIP_H

#include "inventory.h"
#include "crew.h"
using namespace std;
class Ship {
private:
	const int MAX_HEALTH = 100;
	const int MAX_ATTACK = 20;
	const int MAX_SPEED = 10;

	int explosiveCannonball();

	Inventory shipInventory;
	Crew shipCrew;

	string shipName;
	int attack, health, speed;

public:
	Ship();
	virtual ~Ship();

	void setShipCrew();
	void setShipInventory();

	string getShipName();
	void setShipName(string);
	
	int getAttack();
	void setAttack(int);

	int getHealth();
	void setHealth(int);

	int getSpeed();
	void setSpeed(int);

	int cannonball();
	int chainShot();
	int scatterShot();

	void addItem(Item);
	void useItem(Item);

};
#endif
