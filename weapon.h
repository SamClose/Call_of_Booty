#ifndef WEAPON_H
#define WEAPON_H

/* Weapon items: cannonball, metal ball, chain ball, explosive cannonball */
class Weapon : public Item {
	private:
		int attackBonus, speedBonus;

	public:
		int getAttackBonus();
		void setAttackBonus(int bonus);

		int setSpeedBonus();
		void setSpeedBonus(int bonus);
}
#endif
