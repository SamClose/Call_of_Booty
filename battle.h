#ifndef BATTLE_SCREEN_H
#define BATTLE_SCREEN_H

#include "allegro5\allegro.h"
#include "allegro5\allegro_font.h"
#include "allegro5\allegro_ttf.h"

#include "ship.h"
#include "sprite.h"

class BattleScreen {
private:
	// Custom classes
	Ship *ship;
	Sprite *idleNessy;

	// default display size
	static const int SCREEN_WIDTH = 800;
	static const int SCREEN_HEIGHT = 600;
	static const int FPS = 20;
	static const int FPS2 = 25;

	// Ship's side view sprite
	ALLEGRO_BITMAP *player;
	// Enemy ship's side view sprite
	ALLEGRO_BITMAP *pirate;
	// Boss sprite
	ALLEGRO_BITMAP *serpent;

	// water background
	// buffer drawing onto this
	ALLEGRO_BITMAP *battleBG;

	ALLEGRO_COLOR black;
	ALLEGRO_COLOR white;
	ALLEGRO_COLOR red;
	ALLEGRO_COLOR lime;

	ALLEGRO_EVENT_QUEUE *eventQueue;

	ALLEGRO_FONT *font;

	ALLEGRO_TIMER *timer;
	ALLEGRO_TIMER *timer2;

	// pixels of HP bars they're technically the same length
	float userHP, enemyHP;

	const char *enemyName, *userName;

	// draw or don't draw
	bool attackMenu;
	bool done;
	bool drawn;
	bool enemyTurn;
	bool entered;
	bool redraw;
	bool repairMenu;
	bool userTurn;

	// Switch cases
	int attkIter;
	int iter;
	int repaIter;

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
	int shipBattle(); 
	int bossBattle();

	// if 1 main.cpp
	// if 0 close display
	// if -1 gameOver()
};
#endif
