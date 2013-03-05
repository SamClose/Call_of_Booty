#include "inventory.h"

#define START_MAX_SPACE 100 //At instantiation, serves simply as maximum space, but allows for inventory space to become bigger
#define MIN_SPACE 0 //This should not be changed ever, even when MAX_SPACE is altered/removed

//Should Gold(money) be included in inventory and just not take up any space? probably the best way to handle it.
Inventory::Inventory(){
  filledSpace = MIN_SPACE;
	emptySpace = START_MAX_SPACE;
	wood = 0;
	food = 0;
	explosiveCannonBalls = 0;
	chainShot = 0;
	cannonBalls = 0;
	scatterShot = 0;
	booze;
	
}

	int Inventory::getWood(){
		return wood;
	}
	void Inventory::setWood(int value){
		wood = value;
	}

	int Inventory::getFood(){
		return food;
	}
	void Inventory::setFood(int value){
		food = value;
	}

	int Inventory::getExplosiveCannonBalls(){
		return explosiveCannonBalls;
	}
	void Inventory::setExplosiveCannonBalls(int value){
		explosiveCannonBalls = value;
	}

	int Inventory::getChainShot(){
		return chainShot;
	}
	void Inventory::setChainShot(int value){ 
		chainShot = value;
	}

	int Inventory::getCannonBalls(){
		return cannonBalls;
	}
	void Inventory::setCannonBalls(int value){
		cannonBalls = value;
	}

	int Inventory::getScatterShot(){
		return scatterShot;
	}
	void Inventory::setScatterShot(int value){
		scatterShot = value;
	}

	int Inventory::getBooze(){
		return booze;
	}
	void Inventory::setBooze(int value){
		booze = value;
	}

	int Inventory::getFilledSpace(){
		return filledSpace;
	}
	void Inventory::setFilledSpace(int value){
		filledSpace = value;
	}
	int Inventory::getEmptySpace(){
		return emptySpace;
	}
	void Inventory::setEmptySpace(int value){
		emptySpace = value;
	}

