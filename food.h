#ifndef FOOD_H
#define FOOD_H

/* Food items: fruit, meat, water, bread, cheese */
class FoodItem : public Item {
	private:
		int healthBonus, attackBonus;

	public:	
		int getHealthBonus();
		void setHealthBonus(int bonus);
		
		int getAttackBonus();
		void setSpeedBonus(int bonus);
}
#endif
