#ifndef FUNCTIONS_H
#define FUNCTIONS_H

void TitleScreen();
	void CallOfBooty();
		void CharacterScreen();
		void ShipScreen();
		void InventoryScreen();
	void AboutMenu();

string getInput(int x, int y, int w, int h);

// Win ending screen
void EndOfGame();

// Lose ending screen
void GameOver();

void StatScreen(); // should use the main game CallOfBooty() to calculate stats

#endif

-------------------------------------------------------------------------------

/* functions.cpp */

#include <allegro5.h> // or whatever the Allegro 5 thing is
#include <cstdio>
#include "functions.h"
#include // class.cpp files used in this

void TitleScreen() {
	BITMAP *title_screen = create_bitmap(screenWidth, screenHeight);

	bool END_GAME = false;
	int iterator = 0;
	while(!END_GAME) {
		//menu select
		if (keypressed()) {
			int k = readkey();
			switch(k >> 8) {
				case KEY_UP: iterator--;
					break;
				case KEY_DOWN: iterator++;
					break;
				case KEY_ENTER:
					switch(iterator) {
						case 0: CallOfBooty(); // Start Button
							break;
						case 1: AboutScreen(); // Help/About/HowTo Button
							break;
						case 2: END_GAME = true; // Exit Button
							break;
					}
			}
		}
		if (iterator == 0) { //change font color }
		if (iterator == 1) { //change font color }
		if (iterator == 2) { //change font color }
		// draw title screen here
	}
	destroy_bitmap(title_screen);
}

void CallOfBooty() {
	string characterName;
	CharacterScreen();
	// characterName = getInput(x, y, w, h);

	Ship mainShip;
	string shipName;
	ShipScreen();
	// shipName = getInput(x, y, w, h);
	mainShip.setName(shipName);
	
	InventoryScreen();

	// variables go here like shipSunkCounter, mutinyLevel, etc.
	// options go here
	// randomizer
}

void AboutMenu() {
	// print out paragraph about the game and how to play
	// Yarg yarg CALL OF BOOTY! YAARRRGGGG Hashtag YOHO MOFO
	// Options: go back to start menu
}

void CharacterScreen() {
	// draw character on left
	// 	x - position: screenWidth/4
	// 	y - position: screenHeight/4
	// draw string "What be the name of the captain of ye ship?"
	// 	x - position: screenWidth*(3/4)
	// 	y - position: screenWidth/2
}	

void ShipScreen() {
	// draw Ship on top
	// 	x - position: screenWidth/3
	// 	y - position: 0
	// draw string "Name ye fine vessel!"
	// 	x - position: screenWidth/2
	//	y - position: screenHeight/2
}

void InventoryScreen() {
	// draw a background if you want to have like board background with barrels or something
	// invoke inventory class
	// draw strings for options
	// use getInput
	// keywords: food, weapons, booze/alcohol, etc.
}

void EndOfGame() {
	// draw winning screen
	// Options: return to start menu or exit game (destroy_bitmap())
}

void GameOver() {
	// draw losing screen
	// "Yarrrrgg ye sunk ye Pirate Ship! Ye failed the Call of Booty!"
	// Options: return to start menu or exit game (destroy_bitmap())
}

void StatScreen() {
	// displays length of voyage
	// how many ships sunk
	// number of items
	// how many crewmembers died
}
