#ifndef BOSS_H
#define BOSS_H

class Boss {
	private:
		string bossName;
		int health, attack;

	public:
		Boss();

		// randomizer to return values
		int bossAttack(); // bite animation
		int bossSlime(); // slows down enemy can just turn dragon greener and do bite attack
		int fireBlast(); // Fire attack animation
		int waterBlast(); // change color of fire attack animation
		// Comes up with a value to decrease an incoming attack.
		int defend(int shipAttack); // boss just curls back its head or something
		void tidalWave(); // regenerates health do a water animation
		
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
