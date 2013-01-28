#ifndef PORT_H_
#define PORT_H_
//Can only be accessed when the ship is right on top of(in) the port
//Should have it's own inventory associated with it
//items in port's inventory could slowly accumulate as time goes on in the game

class Port{

  public:
	//create a port which has some inventory
	Port();
	~Port();

	//display port's inventory on screen
	//allow player to exchange goods in inventory for goods in port's inventory
	void trade();
	//Allow player to purchase goods in port's inventory in exchange for currency
	void buy();
	//Allow player to sell goods from inventory to port in exchange for currency
	void sell();
	//Allow player to make repairs on ship, requires wood
	//check ship inventory for wood
	//ask player how much they want to repair the ship, based on current amount of wood and ship health
	//missing ship health is max amount that can be repaired, unless there is less wood than that amount. 1wood=1health
	void repair();
	//Allow player to upgrade ship, increasing max health, crew space, inventory space, requires wood
	void upgrade();



  private:



#endif /* PORT_H_ */
