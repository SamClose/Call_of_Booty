#ifndef SHIP_BATTLE_H
#define SHIP_BATTLE_H

class ShipBattle {

	private:
		Ship main;
		EnemyShip enemy;
		ALLEGRO_DISPLAY *display;

	public:
	        // Creates a ship battle
	        ShipBattle(Ship mainShip, EnemyShip enemyShip);
	        
	        // This is a method to allow mainShip to attack first and EnemyShip randomly decides what to do next.
	        void shipBattle();
	        
	        // Draws both HP bars, names for both, attack menu, inventory menu, and flee.
	        void drawShipBattle(ALLEGRO_DISPLAY *display);
	       	void update();
	        
	        // Getters and Setters
	        Ship getMainShip();
	        void setMainShip(Ship newShip);
	        
	        EnemyShip getEnemyShip();
	        void setEnemy(EnemyShip newEnemy);
	        
	        ALLEGRO_DISPLAY& getDisplay();
	        void setDisplay(ALLEGRO_DISPLAY *display);

}
#endif
