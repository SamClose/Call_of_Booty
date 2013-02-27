
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
	howDone = false;
}

void HowToPlay::makeHowToPlayScreen(){
	//when activated, show the "how to play" screen
	//when a button/key is clicked/pressed : erase this to show the introscreen again
	//the click/button settings from introscreen might still be active, so might have to handle this differently
	//i.e. by killing introscreen, loading "how to play" screen, then killing it and reloading introscreen upon action.
	ALLEGRO_EVENT_QUEUE *event_queueH = NULL;

	//al_init_font_addon();
	//al_init_ttf_addon();
	//al_init_image_addon();
	al_install_mouse();
	al_install_keyboard();
	al_init_primitives_addon();

	event_queueH = al_create_event_queue();
	al_register_event_source(event_queueH,al_get_mouse_event_source());

	
	ALLEGRO_BITMAP *skull = al_load_bitmap("skull.png");
	al_draw_bitmap(skull,0,0,NULL);

	ALLEGRO_FONT *font = al_load_font("Pirate.ttf", 45, NULL);
	al_draw_text(font, al_map_rgb(255,0,0),400,75,ALLEGRO_ALIGN_CENTER,"Use the arrow keys to move around the map");
	al_draw_text(font, al_map_rgb(255,0,0),400,175,ALLEGRO_ALIGN_CENTER,"Filler text, hopefully something else can be added");
	al_draw_text(font, al_map_rgb(255,0,0),400,500,ALLEGRO_ALIGN_CENTER,"Click anywhere to go back");
	al_flip_display();

	setHowDone(false);

	while(!getHowDone())
	{
		ALLEGRO_EVENT evH;
		al_wait_for_event(event_queueH, &evH);
		if(evH.type ==ALLEGRO_EVENT_DISPLAY_CLOSE)
		{
			setHowDone(true);
		}
		else if(evH.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN)
		{
			if (evH.mouse.button & 1)
			{

				//al_draw_filled_rectangle(400, 300,415,315,al_map_rgb(255,255,0));
				setHowDone(true);

			}
		}
		al_flip_display();
	}

	


	//al_flip_display();
	al_destroy_font(font);
}

bool HowToPlay::getHowDone(){
	return howDone;
}

void HowToPlay::setHowDone(bool doneValue){
	howDone = doneValue;
}

bool HowToPlay::getActive(){
	return active;
}

void HowToPlay::setActive(bool activeValue){
	active = activeValue;
}
