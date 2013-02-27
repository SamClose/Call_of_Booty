#include "crew.h"
#include <time.h>
#include <stdlib.h>

using namespace std;

Crew::Crew() {
	srand(time(NULL));
	int n = 10 + rand()%MAX_CREW;
	crewNumber = n;
	mutinyLevel = 0;
}

int Crew::getCrewNumber() { return crewNumber; }

void Crew::setCrewNumber(int num) { crewNumber = num; }

int Crew::getMutinyLevel() { return mutinyLevel; }

void Crew::setMutinyLevel(int num) { mutinyLevel = num; }
