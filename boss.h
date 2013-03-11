#ifndef BOSS_H
#define BOSS_H

class Boss {
private:
	static const int MAX_HEALTH = 1000;
	static const int MAX_ATTACK = 100;
	static const int MIN_ATTACK = 30;
	static const int MAX_DEFENSE = 20;
	static const int MIN_DEFENSE = 0;
	static const int MAX_SPEED = 20;
	static const int MIN_SPEED = 3;

	const char *bossName;
	int health, attack;

public:
	Boss();

	int bite();
	int slime();
	int fireBlast();
	int waterBlast();
	void defend(int);
	void tidalWave();

	const char *getBossName();
	int getHealth();
	int getAttack();

	void setBossName(const char *name);
	void setHealth(int);
	void setAttack(int);
};
#endif
