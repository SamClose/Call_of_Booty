#ifndef CREW_H
#define CREW_H

#define MAX_MUTINY_LEVEL 100
#define MIN_MUTINY_LEVEL 0
#define MAX_HAPPY_LEVEL 100
#define MAX_CREW_NUMBER 20 // not sure what number to put here
#define MIN_CREW_NUMBER 5

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
		
		// results would affect either the happinessLevel and/or mutinyLevel
		// uses set functions for mutiny and happiness levels with a ratio of crewNumber/MAX_something_LEVEL
		// uses ship's inventory object
		void crewUseItem(Inventory inventory);
};

#endif
