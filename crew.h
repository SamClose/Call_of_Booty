#ifndef CREW_H
#define CREW_H

class Crew {
private:
	// subject to change
	static const int MAX_CREW = 25;
	static const int MAX_HEALTH = 50;
	int health, crewNumber, mutinyLevel;
	
public:
	Crew(); // initializing attributes

	int getHealth();
	void setHealth(int);

	int getCrewNumber();
	void setCrewNumber(int);

	int getMutinyLevel();
	void setMutinyLevel(int);
};
#endif
