// Add other invludes if need be
#include <iostream>
#include "crew.h"

using namespace std;

Crew::Crew() {
	mutinyLevel = MIN_MUTINY_LEVEL;
	happinessLevel = MAX_HAPPY_LEVEL;
	crewNumber = MAX_CREW_NUMBER;
}

virtual Crew::~Crew() { }

void Crew::crewUseItem(Item item) {
}

int Crew::getCrewNumber() {
	return crewNumber;
}

void Crew::setCrewNumber(int number) {
	crewNumber = number;
}

int Crew::getMutinyLevel() {
	return mutinyLevel;
}

void Crew::setMutinylevel(int level) {
	mutinyLevel = level;
}

int Crew::getHappinessLevel() {
	return happinessLevel;
}

void Crew::setHappinessLevel(int level) {
	happinessLevel = level;
}

/* End of Crew.cpp */
