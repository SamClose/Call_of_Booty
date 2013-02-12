
#include <iostream>
#include <allegro5/allegro.h>
#include <allegro5/allegro_native_dialog.h>
#include<allegro5/allegro_ttf.h>
#include<allegro5/allegro_font.h>
#include<allegro5/allegro_image.h>
#include<allegro5/allegro_primitives.h>
#include "howToPlay.h"

using namespace std;

HowToPlay::HowToPlay(){
}

void HowToPlay::makeHowToPlayScreen(){
  //when activated, show the "how to play" screen
	//when a button/key is clicked/pressed : erase this to show the introscreen again
	//the click/button settings from introscreen might still be active, so might have to handle this differently
	//i.e. by killing introscreen, loading "how to play" screen, then killing it and reloading introscreen upon action.
	ALLEGRO_EVENT_QUEUE *event_queue = NULL;

	//al_init_font_addon();
	//al_init_ttf_addon();
	//al_init_image_addon();
	al_install_mouse();
	al_install_keyboard();
	al_init_primitives_addon();


	ALLEGRO_FONT *font = al_load_font("Pirate.ttf", 45, NULL);
	al_draw_text(font, al_map_rgb(255,0,0),0,0,NULL,"Temp filler text");

	al_flip_display();
	al_destroy_font(font);
}
