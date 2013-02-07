
#include <iostream>
#include <allegro5/allegro.h>
#include <allegro5/allegro_native_dialog.h>
#include<allegro5/allegro_ttf.h>
#include<allegro5/allegro_font.h>
#include<allegro5/allegro_image.h>
#include "introScreen.h"

using namespace std;

IntroScreen::IntroScreen(){
}

void IntroScreen::makeIntroScreen(float ScreenWidth){
	//draw "Call Of Booty" at top using a jpg or similar existing image
	
	//create 3 buttons for introscreen
	//al_init_font_addon();
	al_init_ttf_addon();
	al_init_image_addon();

	ALLEGRO_BITMAP *skull = al_load_bitmap("skull.png");
	al_draw_bitmap(skull,0,0,NULL);

	ALLEGRO_BITMAP *title = al_load_bitmap("Title.png");
	al_draw_bitmap( title,0,0,NULL); 

	Button playButton;
	playButton.printText(85, "Pirate.ttf",255,0,0,ScreenWidth/2,150, ALLEGRO_ALIGN_CENTRE,"Play Game");

	Button howButton;
	howButton.printText(85, "Pirate.ttf",255,0,0,ScreenWidth/2,300, ALLEGRO_ALIGN_CENTRE,"How to Play");

	Button exitButton;
	exitButton.printText(85, "Pirate.ttf",255,0,0,ScreenWidth/2,450, ALLEGRO_ALIGN_CENTRE,"Exit Game");



}
