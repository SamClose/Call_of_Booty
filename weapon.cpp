#include "weapon.h"

using namespace std;

int Weapon::getAttackBonus() {
	return attackBonus;
}

void Weapon::setAttackBonus(int bonus) {
	attackBonus = bonus;
}

int Weapon::getSpeedBonus() {
	return speedBonus;
}

void Weapon::setSpeedBonus(int bonus) {
	speedBonus = bonus;
}
/* End of weapon.cpp */
