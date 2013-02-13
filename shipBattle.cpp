// include proper allegro5 libraries
#include <stdlib.h>
#include <time.h>
#incldue "shipBattle.h"

ShipBattle::shipBattle(Ship mainShip, EnemyShip enemy) {
	while(mainShip.getHealth() != 0 || enemy.getHealth() != 0) {
		bool userTurn;
		// takes in user input event
		update(); // changes enemy stats on window

		// enemy's turn
		if (!userTurn) {
			srand(time(NULL));
			int attack = 1 + rand()%3;
			// enemy choices
			switch(attack) {
				case 1: mainShip.setHealth(mainShip.getHealth() - enemy.shipCannonball()); break;
				case 2: mainShip.setHealth(mainShip.getHealth() - enemy.shipScatterShot()); break;
				case 3: mainShip.setSpeed(mainShip.getSpeed() - enemy.shipChainShot());
			}
			update(); // changes mainShip stats on window
		}
	}
}

void ShipBattle::drawShipBattleFrame() {
	// set new image
}

void ShipBattle::update() {
	// redraws information displayed on frame.
}

/* End of shipBattle.cpp */
