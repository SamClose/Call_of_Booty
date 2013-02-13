// include necessary allegro5 libraries here
#include <stdlib.h>
#include <time.h>
#include "bossBattle.h"

// BossBattle finalBattle = new BossBattle(mainShip, Nessy);
// finalBattle.bossBattle();
BossBattle::BossBattle(Ship mainShip, Boss boss) {
	this.main = mainShip;
	this.boss = boss;
	update();
}

void BossBattle::bossBattle() {
	while(main.getHealth() != 0 || boss.getBossHealth() != 0) {
		bool userTurn;
		// takes in user input event
		update(); // changes Boss stats
	    // Boss attack
	    if(!userTurn) {
			srand(time(NULL));
			int attack = 1 + rand()%6;
			switch(attack) {
				case 1: main.setHealth(main.gethealth() - boss.bossAttack()); break;
				case 2: main.setHealth(main.getHealth() - boss.fireBlast()); break;
				case 3: main.setHealth(main.getHealth() - boss.waterBlast()); break;
				case 4: main.setSpeed(getSpeed() - boss.bossSlime()); break;
				case 5: main.setAttack(abs(main.getAttack() - boss.defend())); break;
				case 6: boss.tidalWave();
			}
	    }
	}
}

void BossBattle::update() {
	// sets image in window
	// mainShip's information
	main.getShipName();
	main.getHealth();

	// Boss's information
	boss.getBossName();
	boss.getBossHealth();
}

/* End of bossBattle.cpp */
