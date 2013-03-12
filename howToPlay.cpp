
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

	ALLEGRO_FONT *font = al_load_font("Pirate.ttf", 57, NULL);
	al_draw_text(font, al_map_rgb(255,0,0),400,30,ALLEGRO_ALIGN_CENTER,"Use the arrow keys to move around the map");

	al_draw_text(font, al_map_rgb(255,0,0),400,115,ALLEGRO_ALIGN_CENTER,"When in battle,");
	al_draw_text(font, al_map_rgb(255,0,0),400,155,ALLEGRO_ALIGN_CENTER,"use the arrow keys to select an action");

	al_draw_text(font, al_map_rgb(255,0,0),400,240,ALLEGRO_ALIGN_CENTER,"Capture a port by defeating its defenses");

	al_draw_text(font, al_map_rgb(255,0,0),400,325,ALLEGRO_ALIGN_CENTER,"Capture all ports to discover the location");
	al_draw_text(font, al_map_rgb(255,0,0),400,370,ALLEGRO_ALIGN_CENTER,"of the hidden treasure");

	al_draw_text(font, al_map_rgb(255,0,0),400,500,ALLEGRO_ALIGN_CENTER,"Click anywhere to return to the main menu");
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
