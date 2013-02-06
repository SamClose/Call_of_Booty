#ifndef REPAIR_H
#define REPAIR_H

/* Repair items: tools, wood */
class Repair : public Item {
	private:
		int healthBonus;

	public:
		int getHealthBonus();
		void setHealthBonus(int bonus);
}
#endif
