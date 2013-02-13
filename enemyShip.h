#ifndef ENEMY_SHIP_H
#define ENEMY_SHIP_H

class EnemyShip : public Ship {
	// Same useItem addItem as Ship
	// No crew and no explosive cannonbal
	// Fills up 51 - 60 inventory spaces multiples of 3
	// 17 spaces for each attack item (minimum)
	// 10 spaces for ship repair? or less
    	public:
        	EnemyShip();
        	virtual ~EnemyShip(); // deallocates inventory

	        // cannonball, chainshot, scattershot
	        int shipCannonball();
	        int shipChainShot();
	        int shipScatterShot();	
};

#endif
