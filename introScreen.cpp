
#include <iostream>
#include <allegro5/allegro.h>
#include <allegro5/allegro_native_dialog.h>
#include<allegro5/allegro_ttf.h>
#include<allegro5/allegro_font.h>
#include "introScreen.h"

using namespace std;

IntroScreen::IntroScreen(){
}

void IntroScreen::makeIntroScreen(float ScreenWidth){
  //draw "Call Of Booty" at top using a jpg or similar existing image
	
	//create 3 buttons for introscreen
	//al_init_font_addon();
	//al_init_ttf_addon();

	Button playButton;
	playButton.printText(36, "Pirate.ttf",255,255,255,ScreenWidth/2,200, ALLEGRO_ALIGN_CENTRE,"Play Game");

	Button howButton;
	howButton.printText(36, "Pirate.ttf",255,255,255,ScreenWidth/2,300, ALLEGRO_ALIGN_CENTRE,"How to Play");

	Button exitButton;
	exitButton.printText(36, "Pirate.ttf",255,255,255,ScreenWidth/2,400, ALLEGRO_ALIGN_CENTRE,"Exit Game");



}
