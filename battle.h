#ifndef BATTLE_H
#define BATTLE_H

#include "ship.h"
using namespace std;

class Battle {
private:
	// default display size
	static const int SCREEN_WIDTH = 800;
	static const int SCREEN_HEIGHT = 600;

	// Ship's side view sprite
	ALLEGRO_BITMAP *player;
	ALLEGRO_BITMAP *battleBG;
	ALLEGRO_FONT *font;

	ALLEGRO_COLOR black;
	ALLEGRO_COLOR white;
	ALLEGRO_COLOR red;
	ALLEGRO_COLOR lime;

	// pixels of HP bars they're technically the same length
	int userHP, enemyHP;

	// bool to keep track of attacks
	// if userTurn let user pick attack
	// else deactivate iterators and let enemy attack
	bool userTurn;

	// draws battle screen for Ship and an Enemy
	void draw(Ship, const char *name);

public:
	// sets private attributes
	Battle();

	// randomly creates enemy
	// takes in a premade Ship class
	// user gets to attack first
	// switch if it's user turn or enemy's turn
	// use randomizer to select attacks
	void shipBattle(Ship); 
	void bossBattle(Ship);
};
#endif
