#ifndef SHIP_BATTLE_H
#define SHIP_BATTLE_H

class ShipBattle {

    public:
        // This is a method to allow mainShip to attack first and EnemyShip randomly decides what to do next.
        ShipBattle(Ship mainShip, EnemyShip ship);
        // Draws both HP bars, names for both, attack menu, inventory menu, and flee.
       	void drawShipBattleFrame();
       	// Updates after each turn during battle.
       	void update();

}
#endif
