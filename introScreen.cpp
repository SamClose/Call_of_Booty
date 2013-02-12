
#include <iostream>
#include <allegro5/allegro.h>
#include <allegro5/allegro_native_dialog.h>
#include<allegro5/allegro_ttf.h>
#include<allegro5/allegro_font.h>
#include<allegro5/allegro_image.h>
#include<allegro5/allegro_primitives.h>
#include "introScreen.h"

using namespace std;

IntroScreen::IntroScreen(){
}

//draw "Call Of Booty" at top using a jpg or similar existing image
//currently only works with default screen size, full screen loses functionality 
void IntroScreen::makeIntroScreen(float ScreenWidth, float ScreenHeight){

	ALLEGRO_EVENT_QUEUE *event_queue = NULL;
	
	
	//create 3 buttons for introscreen
	//al_init_font_addon();
	al_init_ttf_addon();
	al_init_image_addon();
	al_init_primitives_addon();
	al_install_mouse();
	al_install_keyboard();

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

	HowToPlay runHow;

	bool done= false;
	int pos_x = ScreenWidth/2;
	int pos_y = ScreenWidth/2;
	event_queue = al_create_event_queue();

	//al_register_event_source(event_queue, al_get_display_event_source(display));
	al_register_event_source(event_queue,al_get_mouse_event_source());
	
	while (!done)
	{
		ALLEGRO_EVENT ev;
		al_wait_for_event(event_queue, &ev);

		if(ev.type ==ALLEGRO_EVENT_DISPLAY_CLOSE)
		{
			done= true;
		}
		
		else if(ev.type == ALLEGRO_EVENT_MOUSE_AXES)
		{
			pos_x = ev.mouse.x;
			pos_y = ev.mouse.y;
		}
		else if(ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN)
		{
			if (ev.mouse.button & 1)
			{
				//Play button~dimensions: x: 365 , y: 65
				if(pos_x >= 225 && pos_x <= 590 && pos_y >= 160 && pos_y<= 225)
				{
					al_draw_filled_rectangle(pos_x, pos_y,pos_x+15,pos_y+15,al_map_rgb(0,255,255));
				}
					//How button~dimensions: x: 430 , y: 63
				else if(pos_x >= 185 && pos_x <= 615 && pos_y >= 312 && pos_y<= 375)
				{
					al_draw_filled_rectangle(pos_x, pos_y,pos_x+15,pos_y+15,al_map_rgb(0,255,255));
					runHow.makeHowToPlayScreen();
				}
				//Exit button~dimensions: x:
				else if(pos_x >= 198 && pos_x <= 594 && pos_y >= 465 && pos_y<= 525)
				{
					done = true;
					al_draw_filled_rectangle(pos_x, pos_y,pos_x+15,pos_y+15,al_map_rgb(0,255,255));
				}
			}
			else if (ev.mouse.button & 2)
			{
			done = true;
			al_draw_filled_rectangle(pos_x, pos_y,pos_x+15,pos_y+15,al_map_rgb(255,0,0));
			}
		}
		//al_draw_filled_rectangle(pos_x, pos_y,pos_x+30,pos_y+30,al_map_rgb(0,255,255));
		al_flip_display();
		//al_clear_to_color(al_map_rgb(0,0,0));
	}
	
	//al_destroy_display(display);

}
