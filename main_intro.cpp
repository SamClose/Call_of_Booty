
#include <allegro5/allegro.h>
#include <allegro5/allegro_native_dialog.h>
#include<allegro5/allegro_ttf.h>
#include<allegro5/allegro_font.h>
#include<allegro5/allegro_primitives.h>
#include <iostream>
#include "introScreen.h"

using namespace std;

#define ScreenWidth 800
#define ScreenHeight 600

int main(void)
{
  ALLEGRO_DISPLAY *display; 
  //ALLEGRO_EVENT_QUEUE *event_queue = NULL;


	if(!al_init()) //If allegro window does not initialize, error
	{
		al_show_native_message_box(NULL, NULL, NULL, "Could not initialize Allegro 5", NULL, NULL);
		return -1; //Program ended with an error
	}
	
	al_set_new_display_flags(ALLEGRO_WINDOWED | ALLEGRO_RESIZABLE);

	display = al_create_display(ScreenWidth,ScreenHeight); //initializes display
	al_set_window_title(display, "Call of Booty - Argh!"); //Sets the name of the game window

	if(!display)
	{
		al_show_native_message_box(display, "Call of Booty", "Display Settings", "Display window cannot be created", NULL, ALLEGRO_MESSAGEBOX_ERROR);
		return -1;
	}

	al_init_font_addon();
	al_init_ttf_addon();
	al_init_primitives_addon();
	al_install_mouse();
	al_install_keyboard();

	//Trying out introScreen:
	IntroScreen introScreen;
	introScreen.makeIntroScreen(ScreenWidth, ScreenHeight);

	
	/*bool done= false;
	int pos_x = ScreenWidth/2;
	int pos_y = ScreenWidth/2;
	event_queue = al_create_event_queue();

	al_register_event_source(event_queue, al_get_display_event_source(display));
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
		al_draw_filled_rectangle(pos_x, pos_y,pos_x+30,pos_y+30,al_map_rgb(0,255,255));
		al_flip_display();
		al_clear_to_color(al_map_rgb(0,0,0));
	}
	*/
	/*
	ALLEGRO_FONT *font = al_load_font("Pirate.ttf", 36, NULL);
	al_draw_text(font, al_map_rgb(255, 255, 0), ScreenWidth/2, 20, ALLEGRO_ALIGN_CENTRE, "Call of Booty");
	al_draw_text(font, al_map_rgb(255,255,0), ScreenWidth/2, 200,ALLEGRO_ALIGN_CENTRE, "Play Game");
	*/
	////al_show_native_message_box(display, "MessageBox Title", "Error", "Display window could not be shown", NULL, ALLEGRO_MESSAGEBOX_ERROR);
	//al_flip_display();
	//al_rest(5.0);
	//al_destroy_font(font);
	al_destroy_display(display);//Destructor

	return 0;
}
