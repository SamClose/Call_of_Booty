#ifndef SHIP_H
#define SHIP_H

class Ship {
    // should  we create const numbers for maxHealth, maxSpeed, and maxAttack?
    #define MAX_HEALTH 100;
    #define MAX_SPEED 10;
    #define MAX_ATTACK 20;
 
    // Other ships can have these public functions
    public:
        Ship(); // initializes some private values;
        ~Ship(); // destructor sets everything to 0;

        string getShipName();
        void setShipName(string input);

        int getAttack();
        void setAttack(int shipAttack);
         
        int getHealth();
        void setHealth(int hitPoints);
         
        int getSpeed();
        void setSpeed(int agility);
         
        // cannonball, chainshot, scattershot, explosive cannonball
        // returns a number to attack an enemy
        int shipCannonball();
        int shipChainShot();
        int shipScatterShot();
        
        void shipUseItem(Item[]); // uses weapons and repair items
        void crewUseItem(Item[]); // uses food and booze

    private:
        // Exclusive only to this class
        int shipExplosiveCannonball();

      	// Same things?
        // I'm not sure what to write for these
	// parameter for ship to raid/loot on
	// should this be in inventory instead? since it adds to inventory.
        void raidShip();
	void lootShip();
	
	Inventory shipInventory;
	Crew shipCrew;
        string shipName;
        int attack, health, speed;
};

#endif
