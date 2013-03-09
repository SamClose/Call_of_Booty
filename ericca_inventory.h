#ifndef INVENTORY_H
#define INVENTORY_H

#include "item.h"
using namespace std;

class Inventory {
private:
	static const int MAX_SPACE = 100;
	int filledSpace, emptySpace;
	// 0: repair
	// 1: food
	// 2: cannonballs
	// 3: small balls
	// 4: chain balls
	// 5: explosive cannonballs limit 3
	int inventorySpace[6];

	Item food, water, booze,
		wood, tools, rope, 
		cannonballItem, scatterShotItem, 
		chainShotItem, explosiveCannonballItem;

public:
	// initializes values
	Inventory();
	~Inventory();

	// adds or removes items from Item[]
	void addItem(Item);
	// depends on itemType
	int useItem(Item);

	Item getFood();
	Item getWater();
	Item getBooze();
	Item getWood();
	Item getTools();
	Item getRope();
	Item getCannonballItem();
	Item getScatterShotItem();
	Item getChainShotItem();
	Item getExplosiveCannonballItem();

	int getFilledSpace();
	void setFilledSpace(int);

	int getEmptySpace();
	void setEmptySpace(int);
};
#endif
