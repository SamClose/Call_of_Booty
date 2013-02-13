#ifndef BOSS_H
#define BOSS_H

#define MAX_HEALTH 1000
#define MAX_ATTACK 100
#define MIN_ATTACK 30
#define MAX_SPEED 20
#define MIN_SPEED 5

class Boss {
	private:
		string bossName;
		int health, attack;

	public:
		Boss();

		// randomizer to return values
		int bossAttack(); // bite animation
		int bossSlime(); // slows down enemy can just turn dragon greener and do bite attack
		int tidalWave(); // regenerates health do a water animation
		int fireBlast(); // Fire attack animation
		int waterBlast(); // change color of fire attack animation
		// Comes up with a value to decrease an incoming attack.
		int defend(int shipAttack); // boss just curls back its head or something
		
		// Getters
		string getBossName();
		int getHealth();
		int getAttack();
		
		// Setters
		void setBossName(string name);
		void setHealth(int value);
		void setAttack(int value);
}
#endif
