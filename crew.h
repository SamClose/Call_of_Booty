#ifndef CREW_H
#define CREW_H

class Crew {
	
	private:
		int crewNumber, mutinyLevel, happinessLevel;

	public:
		Crew(); // initializing attributes randomize crew number
		virtual ~Crew();

		int getCrewNumber();
		void setCrewNumber(int number);

		int getMutinyLevel();
		void setMutinyLevel(int number);
		
		int getHappinessLevel();
		void setHappinessLevel(int number);
};

#endif
