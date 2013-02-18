#include <allegro5/allegro.h>
#include <allegro5/allegro_native_dialog.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>
#include "Camera.h"
#include "Player.h"
#include <sstream>
#include <iostream>

#define ScreenWidth 800
#define ScreenHeight 600

bool Collision(float x, float y, float ex, float ey, int width, int height)
{
	if(x + width < ex || x > ex + width || y + height < ey || y > height + ey)
	{
		return false;
	}
	return true;

}



int main(void)
{
	ALLEGRO_DISPLAY *display; 
	bool done = false, draw = true, active = false; //boolean for done and drawing
	int sourceX = 161, sourceY = 0;
	int state = NULL;
	const float FPS = 30.0;

	Camera mainCamera;
	Player player1;
	

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
	player1.player = al_load_bitmap("Boat2.png");
	ALLEGRO_BITMAP *background = al_load_bitmap("Background.png"); //Load background picture
	ALLEGRO_BITMAP *player2 = al_load_bitmap("Boat.png");	
	//al_convert_mask_to_alpha(player, al_map_rgb(0,255,255)); //Makes sprite background transparent
	ALLEGRO_TIMER *timer = al_create_timer(1.0 / FPS);
	ALLEGRO_EVENT_QUEUE *event_queue = al_create_event_queue();  //Creates a Queue for keypresses
	al_register_event_source(event_queue, al_get_keyboard_event_source()); //Registers events from Keyboard
	al_register_event_source(event_queue, al_get_timer_event_source(timer));
	al_register_event_source(event_queue, al_get_display_event_source(display));


	al_start_timer(timer); //Starts the event timer


	//BEGINNING OF THE GAME LOOP
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
			active = true; //THERE IS A KEY BEING PRESSED

			//MOVEMENT WITH KEYBOARD
			if (al_key_down(&keyState, ALLEGRO_KEY_DOWN))
			{
				player1.y += player1.moveSpeed;
				player1.dir = player1.DOWN;
				//std::cout << "Y coordinate: " << player1.y << std::endl;
			}
			else if (al_key_down(&keyState, ALLEGRO_KEY_UP))
			{
				player1.y -= player1.moveSpeed;
				player1.dir	= player1.UP;
				//std::cout << "Y coordinate: " << player1.y << std::endl;
			}
			else if (al_key_down(&keyState, ALLEGRO_KEY_RIGHT))
			{
				player1.x += player1.moveSpeed;
				player1.dir = player1.RIGHT;
				//std::cout << "X coordinate: " << player1.x << std::endl;
			}
			else if (al_key_down(&keyState, ALLEGRO_KEY_LEFT))
			{
				player1.x -= player1.moveSpeed;
				player1.dir = player1.LEFT;
				//std::cout << "X coordinate: " << player1.x << std::endl;
			}
			//MOVEMENT WITH KEYBOARD
			else
			{
				active = false; //KEY IS NOT BEING PRESSED
				std::cout << player1.x << "," << player1.y << std::endl;
			}

			//COLLISION DETECTION
			if(Collision(player1.x, player1.y, 200, 300, 80.5, 80.5))
			{
				if(player1.dir == 0)
					player1.y -= player1.moveSpeed;
				else if (player1.dir == 1)
					player1.x += player1.moveSpeed;
				else if ( player1.dir == 2)
					player1.x -= player1.moveSpeed;
				else if (player1.dir == 3)
					player1.y += player1.moveSpeed;
			}
			
			else if(Collision(player1.x, player1.y, 515, 260, 42, 21))
			{
				if(player1.dir == 0)
					player1.y -= player1.moveSpeed;
				else if (player1.dir == 1)
					player1.x += player1.moveSpeed;
				else if ( player1.dir == 2)
					player1.x -= player1.moveSpeed;
				else if (player1.dir == 3)
					player1.y += player1.moveSpeed;
			}
			
			

			//COLLISION DETECTION

	   //SCREENSCROLLING
		//276,151
		
		std::cout << "cameraPositions: " << mainCamera.cameraPosition[0] << "," << mainCamera.cameraPosition[1] << std::endl;
		mainCamera.CameraUpdate(mainCamera.cameraPosition, player1.x, player1.y, 102, 102, ScreenWidth, ScreenHeight);
		al_identity_transform(&mainCamera.camera);
		al_translate_transform(&mainCamera.camera, -(mainCamera.cameraPosition[0]), -(mainCamera.cameraPosition[1]));
		al_use_transform(&mainCamera.camera);

	
	  //SCREENSCROLLING

	  //GETTING BITMAP LOCATION IF KEY IS BEING PRESSED TO MOVE BITMAP
			if(active)
				sourceX += al_get_bitmap_width(player1.player) / 4;
			else
				sourceX = 102;

			if(sourceX >= al_get_bitmap_width(player1.player))
				sourceX = 0;

			sourceY = player1.dir;
			draw = true;
			
		}

		//BITMAP DRAWING, IF DRAW = TRUE
		 if (draw)
		 {
			al_draw_bitmap(background, 0, 0, NULL);
			al_draw_bitmap_region(player2, 0, 0, 161, 161, 200, 300, NULL);
			al_draw_bitmap_region(player1.player, sourceX, player1.dir*al_get_bitmap_height(player1.player) / 4, 102, 102, player1.x, player1.y, NULL);
			
			al_flip_display();
			al_clear_to_color(al_map_rgb(0,0,0));
		 }

		
	}
	//END OF THE GAME LOOP

	al_destroy_display(display);//Destructor for Display
	al_destroy_timer(timer);
	al_destroy_bitmap(player1.player);
	al_destroy_bitmap(background);
	al_destroy_event_queue(event_queue);
	

	return 0;
}
