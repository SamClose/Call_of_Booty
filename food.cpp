#include <iostream>
#include "food.h"

using namespace std;

int Food::getHealthBonus() {
	return healthBonus;
}

void Food::setHealthBonus(int bonus) {
	healthBonus = bonus;
}

int Food::getAttackBonus() {
	return attackBonus;
}

void Food::setAttackBonus(int bonus) {
	attackBonus = bonus;
}
/* End of food.cpp */
