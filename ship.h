#ifndef SHIP_H
#define SHIP_H

class Ship { 
	private:
    	// Exclusive only to this class
        int shipExplosiveCannonball();
        
        Inventory shipInventory;
        Crew shipCrew;
        
        string shipName;
        int attack, health, speed;

    // Other ships can have these public functions
    public:
        Ship(); // initializes some private values;
        virtual ~Ship(); // destructor deallocation

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
        
        void addItem(Item item); // adds item to inventory
        void useItem(Item item); // uses item from inventory   
};

#endif
