#ifndef PLAYER_H
#define PLAYER_H
#include <allegro5/allegro.h>



class Player{

  public:

		Player(); //Player Constructor
		ALLEGRO_BITMAP *player; //Loads the player sprite
		enum Directions {DOWN, LEFT, RIGHT, UP};
		int moveSpeed, x, y;
		int dir;

	
	



};










#endif
