#include <allegro5/allegro.h>
#include <allegro5/allegro_native_dialog.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>
#include <sstream>

#define ScreenWidth 800
#define ScreenHeight 600

int main(void)
{
	ALLEGRO_DISPLAY *display; 
	enum Directions {DOWN, LEFT, RIGHT, UP};

	bool done = false, draw = true, active = false; //boolean for done and drawing
	int dir = DOWN, sourceX = 161, sourceY = 0;
	float x = 10, y = 10, moveSpeed = 5; //Coordinates
	int state = NULL;
	const float FPS = 30.0;

	if(!al_init()) //If allegro does not initialize, error			
	{
		al_show_native_message_box(NULL, NULL, NULL, "Could not initialize Allegro 5", NULL, NULL);
		return -1; //Program ended with an error
	}
	
	al_set_new_display_flags(ALLEGRO_WINDOWED | ALLEGRO_RESIZABLE); //Sets the game window to be Windowed and Resizable

	display = al_create_display(800,600); //initializes display
	al_set_window_title(display, "Call of Booty - Argh!"); //Sets the name of the game window

	if(!display)
	{
		al_show_native_message_box(display, "Call of Booty", "Display Settings", "Display window cannot be created", NULL, ALLEGRO_MESSAGEBOX_ERROR);
	}
	
	al_install_keyboard();
	
	al_init_image_addon();

	

	

	int value = al_show_native_message_box(display, "Call of Booty", "Start Menu", "Do you want to play Call of Booty?", NULL, ALLEGRO_MESSAGEBOX_YES_NO);
	if(value == 0)
	{
		done = true;
	}


	ALLEGRO_KEYBOARD_STATE keyState; //Gets the current state of keyboard
	ALLEGRO_BITMAP *player = al_load_bitmap("Boat.png"); //Loads picture
	//al_convert_mask_to_alpha(player, al_map_rgb(0,255,255)); //Makes sprite background transparent

	ALLEGRO_TIMER *timer = al_create_timer(1.0 / FPS);
	ALLEGRO_EVENT_QUEUE *event_queue = al_create_event_queue();  //Creates a Queue for keypresses
	al_register_event_source(event_queue, al_get_keyboard_event_source()); //Registers events from Keyboard
	al_register_event_source(event_queue, al_get_timer_event_source(timer));
	al_register_event_source(event_queue, al_get_display_event_source(display));


	al_start_timer(timer); //Starts the event timer

	while(!done)
	{
		ALLEGRO_EVENT events;
		al_wait_for_event(event_queue, &events);
		al_get_keyboard_state(&keyState);
	
		if (events.type == ALLEGRO_EVENT_KEY_DOWN) //If a key is being pressed
		 {
			switch(events.keyboard.keycode)
			{
				case ALLEGRO_KEY_ESCAPE:
				done = true;
			} 
		}
		
	else if(events.type == ALLEGRO_EVENT_TIMER)
	{
			active = true;
			if (al_key_down(&keyState, ALLEGRO_KEY_DOWN))
			{
				y+= moveSpeed;
				dir = DOWN;
			}
			else if (al_key_down(&keyState, ALLEGRO_KEY_UP))
			{
				y -= moveSpeed;
				dir	= UP;
			}
			else if (al_key_down(&keyState, ALLEGRO_KEY_RIGHT))
			{
				x += moveSpeed;
				dir = RIGHT;
			}
			else if (al_key_down(&keyState, ALLEGRO_KEY_LEFT))
			{
				x -= moveSpeed;
				dir = LEFT;
			}
			else
				active = false;
			if(active)
				sourceX += al_get_bitmap_width(player) / 4;
			else
				sourceX = 161;

			if(sourceX >= al_get_bitmap_width(player))
				sourceX = 0;

			sourceY = dir;
			draw = true;
			
	}
		 if (draw)
		 {
			al_draw_bitmap_region(player, sourceX, dir*al_get_bitmap_height(player) / 4, 161, 161, x, y, NULL);
			al_flip_display();
			al_clear_to_color(al_map_rgb(0,0,0));
		 }

		
	}
	

	al_destroy_display(display);//Destructor for Display
	al_destroy_timer(timer);
	al_destroy_bitmap(player);
	al_destroy_event_queue(event_queue);
	

	return 0;
}
