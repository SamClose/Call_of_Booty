#ifndef CREW_H
#define CREW_H

using namespace std;
class Crew {
private:
	// subject to change
	const int MAX_CREW = 25;
	int crewNumber, mutinyLevel;
	
public:
	Crew(); // initializing attributes

	int getCrewNumber();
	void setCrewNumber(int);

	int getMutinyLevel();
	void setMutinyLevel(int);
};
#endif
