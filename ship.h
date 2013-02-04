#ifndef SHIP_H
#define SHIP_H

#define MAX_HEALTH 100
#define MAX_SPEED 10
#define MAX_ATTACK 20

class Ship { 
	private:
    	// Exclusive only to this class
        int shipExplosiveCannonball();
        
        Inventory shipInventory;
        Crew shipCrew;
        
        string shipName;
        int attack = MAX_ATTACK, health = MAX_HEALTH, speed = MAX_SPEED;

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
        
        void shipAddItem(Item item); // adds item to inventory
        void shipUseItem(Item item); // uses weapons and repair items
        void crewUseItem(Item item); // uses food and booze        
};

#endif
