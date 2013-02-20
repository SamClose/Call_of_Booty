#ifndef PORT_H
#define PORT_H
//Can only be accessed when the ship is right on top of(in) the port
//Should have it's own inventory associated with it
//items in port's inventory could slowly accumulate as time goes on in the game
#include "Inventory.h"
#include <allegro5/allegro.h>

class Port {

	private:
	  	string traderName; // do we need this?
		Inventory portInventory;
		ALLEGRO_DISPLAY *display;
	
	public:
		// randomly creates a port which has some inventory
		Port();
		
		// deallocated the inventory space
		// especially needed when port isn't drawn on screen.
		~Port();
		
		// draws the port screen with trader
		void drawPort(ALLEGRO_DISPLAY *display);
	
		//display port's inventory on screen
		//allow player to exchange goods in inventory for goods in port's inventory
		void trade();
		
		//Allow player to make repairs on ship, requires repair item
		//check ship inventory for repair item
		//ask player how much they want to repair the ship, based on inventory amount
		//missing ship health is max amount that can be repaired, unless there is less wood than that amount.
		//1repairItem = 1health
		void repair();
		
		//Allow player to upgrade ship, increasing max health, crew space, inventory space, requires wood
		void upgrade();
		
		string getTraderName();
		void setTraderName(string name);

};

#endif /* PORT_H_ */
