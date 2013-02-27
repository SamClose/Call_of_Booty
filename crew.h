#ifndef CREW_H
#define CREW_H

using namespace std;
class Crew {
private:
	int crewNumber, mutinyLevel;
	
public:
	Crew(); // initializing attributes

	int getCrewNumber();
	void setCrewNumber(int);

	int getMutinyLevel();
	void setMutinyLevel(int);
};
#endif
