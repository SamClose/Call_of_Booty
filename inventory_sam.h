#ifndef INVENTORY
#define INVENTORY

class Inventory{

public:
  Inventory();

	int getWood();
	void setWood(int value);

	int getFood();
	void setFood(int value);

	int getExplosiveCannonBalls();
	void setExplosiveCannonBalls(int value);

	int getChainShot();
	void setChainShot(int value);

	int getCannonBalls();
	void setCannonBalls(int value);

	int getScatterShot();
	void setScatterShot(int value);

	int getBooze();
	void setBooze(int value);

	int getFilledSpace();
	void setFilledSpace(int value);

	int getEmptySpace();
	void setEmptySpace(int value);


private:
	int wood;
	int food;
	int explosiveCannonBalls;
	int chainShot;
	int cannonBalls;
	int scatterShot;
	int booze;
	int filledSpace, emptySpace; //manage space in inventory

};

#endif 
