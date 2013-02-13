#include <stdlib.h>
#include <time.h>
#include "bossBattle.h"

BossBattle::bossBattle(Ship mainShip, Boss Nessy) {
  while(mainShip.getHealth() != 0 || Nessy.getBossHealth() != 0) {
    // needs to do an event thing. Wait for user then Boss attacks.

    // Boss switch cases
    srand(time(NULL));
    int attack = 1 + rand()%6;
    switch(attack) {
      case 1: mainShip.setHealth(mainShip.gethealth() - Nessy.bossAttack()); break;
      case 2: mainShip.setHealth(mainShip.getHealth() - Nessy.fireBlast()); break;
      case 3: mainShip.setHealth(mainShip.getHealth() - Nessy.waterBlast()); break;
      case 4: mainShip.setSpeed(getSpeed() - Nessy.bossSlime()); break;
      case 5: mainShip.setAttack(abs(mainShip.getAttack() - Nessy.defend())); break;
      case 6: Nessy.tidalWave();
    }
  }
}

/* End of bossBattle.cpp */
