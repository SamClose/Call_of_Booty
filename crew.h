#ifndef CREW_H
#define CREW_H

class Crew {
	private:
		int crewNumber, mutinyLevel, happinesLevel;

	public:
		Crew();
		~Crew();

		int getCrewNumber();
		void setCrewNumber(int number);

		int getMutinyLevel();
		void setMutinyLevel(int number);
		
		int getHappinessLevel();
		void setHappinessLevel(int number);
		
		// results would affect either the happinessLevel and/or mutinyLevel
		void useItem(Inventory inventory);

}
