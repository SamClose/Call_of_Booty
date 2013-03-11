#ifndef BATTLE_SCREEN_H
#define BATTLE_SCREEN_H

#include "allegro5\allegro.h"
#include "allegro5\allegro_font.h"
#include "allegro5\allegro_ttf.h"

#include "ship.h"

class BattleScreen {
private:
	Ship *ship;
	// default display size
	static const int SCREEN_WIDTH = 800;
	static const int SCREEN_HEIGHT = 600;
	static const int FPS = 30;

	// Ship's side view sprite
	ALLEGRO_BITMAP *player;
	ALLEGRO_BITMAP *battleBG;

	ALLEGRO_COLOR black;
	ALLEGRO_COLOR white;
	ALLEGRO_COLOR red;
	ALLEGRO_COLOR lime;

	ALLEGRO_EVENT_QUEUE *eventQueue;

	ALLEGRO_FONT *font;

	ALLEGRO_TIMER *timer;

	// pixels of HP bars they're technically the same length
	int userHP, enemyHP;

	const char *enemyName, *userName;

	// draws battle screen
	void draw();
	// updates HP bars
	void update();

public:
	// sets private attributes
	BattleScreen(Ship*);
	// destroys timer and eventQueue
	~BattleScreen();

	// creates an enemy
	// takes in a premade Ship class
	// user gets to attack first
	// switch if it's user turn or enemy's turn
	// use randomizer to select attacks
	bool shipBattle(); 
	bool bossBattle();

	// If return true -> user won go to Map
	// If return false -> user lost go to GameOver	
};
#endif
