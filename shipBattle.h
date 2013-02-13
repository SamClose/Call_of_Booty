#ifndef SHIP_BATTLE_H
#define SHIP_BATTLE_H

class ShipBattle {

	private:
		Ship main;
		Ship enemy;

	public:
        // Creates a ship battle
        ShipBattle(Ship mainShip, EnemyShip enemyShip);
        
        // This is a method to allow mainShip to attack first and EnemyShip randomly decides what to do next.
        void shipBattle();
        
        // Draws both HP bars, names for both, attack menu, inventory menu, and flee.
       	void drawShipBattleFrame();
       	
        // Updates after each turn during battle.
       	void update();
        
        // Getters and Setters
        Ship getMainShip();
        void setMainShip(Ship newShip);
        
        EnemyShip getEnemyShip();
        void setEnemy(EnemyShip newEnemy);

}
#endif
