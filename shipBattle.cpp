// include proper allegro5 libraries
#include <stdlib.h>
#include <time.h>
#incldue "shipBattle.h"

ShipBattle::ShipBattle(Ship mainShip, EnemyShip enemyShip) {
	this.main = mainShip;
	this.enemy = enemyShip;
	update();
}

void ShipBattle::shipBattle() {
	while(main.getHealth() != 0 || enemy.getHealth() != 0) {
		bool userTurn;
		// takes in user input event
		update(); // changes enemy stats on window

		// enemy's turn
		if (!userTurn) {
			srand(time(NULL));
			int attack = 1 + rand()%3;
			// enemy choices
			switch(attack) {
				case 1: main.setHealth(main.getHealth() - enemy.shipCannonball()); break;
				case 2: main.setHealth(main.getHealth() - enemy.shipScatterShot()); break;
				case 3: main.setSpeed(main.getSpeed() - enemy.shipChainShot());
			}
			update(); // changes mainShip stats on window
		}
	}
}

void ShipBattle::update() {
	// set new image
	// mainShip's information
	main.getShipName();
	main.getShipHealth();
	
	// EnemyShip's information
	enemy.getShipName();
	enemy.getShipHealth();	
}

/* End of shipBattle.cpp */
