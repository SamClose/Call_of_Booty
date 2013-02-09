#ifndef BOSS_H
#define BOSS_H

#define MAX_HEALTH 1000
#define MAX_ATTACK 100

class Boss {
	private:
		string bossName;
		int health, attack;

	public:
		Boss();

		int bossAttack(); // use randomizer
		int bossInk(); // slows down player i.e. decreases speed
		
		string getBossName();
		int getHealth();
		int getAttack();
		
		void setBossName(string name);
		void setHealth(int value);
		void setAttack(int value);
}
#endif
