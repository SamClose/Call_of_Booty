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
	void setFood(Item);

	Item getWater();
	void setWater(Item);

	Item getBooze();
	void setBooze(Item);

	Item getWood();
	void setWood(Item);

	Item getTools();
	void setTools(Item);

	Item getRope();
	void setRope(Item);

	Item getCannonballItem();
	void setCannonballItem(Item);

	Item getScatterShotItem();
	void setScatterShotItem(Item);

	Item getChainShotItem();
	void setChainShotItem(Item);

	Item getExplosiveCannonballItem();
	void setExplosiveCannonballItem(Item);

	int getFilledSpace();
	void setFilledSpace(int);

	int getEmptySpace();
	void setEmptySpace(int);
};
#endif
