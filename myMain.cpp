#include <allegro5/allegro.h>
#include <allegro5/allegro_native_dialog.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>
#include "Camera.h"
#include "Player.h"
#include "Battle.h"
#include "introScreen.h"
#include <sstream>
#include <iostream>
#include <stdlib.h>
#include <time.h>


#define ScreenWidth 800
#define ScreenHeight 600

int top, bottom, left, right;

bool Collision2(float x, float y, float ex, float ey, int width, int height)
{
  if(x+ width < ex || x > ex + width || y + height < ey || y > height + ey)
	{
		return false;
	}
	else
		return true;
}



int main(void)
{
	ALLEGRO_DISPLAY *display; 
	bool done = false, draw = true, active = false; //boolean for done and drawing
	int sourceX = 102, sourceY = 0;
	int state = NULL;
	const float FPS = 30.0;
	bool gameOn = true;
	bool introDone = false;
	bool howScreenOn = false;
	bool playGame = false;
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
	//
	al_init_font_addon();
	al_init_ttf_addon();
	al_init_primitives_addon();
	al_install_mouse();
	al_install_keyboard();
	al_init_image_addon();

	/*
	int value = al_show_native_message_box(display, "Call of Booty", "Start Menu", "Do you want to play Call of Booty?", NULL, ALLEGRO_MESSAGEBOX_YES_NO);
	if(value == 0)
	{
		done = true;
	}
	*/

	//INTRO SCREEN STUFF




	//ITRO SCREEN STUFF

	ALLEGRO_KEYBOARD_STATE keyState; //Gets the current state of keyboard
	player1.player = al_load_bitmap("Boat2.png");
	ALLEGRO_BITMAP *background = al_load_bitmap("Background.png"); //Load background picture
	ALLEGRO_BITMAP *Cuba = al_load_bitmap("Cuba.png");
	ALLEGRO_BITMAP *fader = al_load_bitmap("Fade.png");
	//ALLEGRO_BITMAP *player2 = al_load_bitmap("Boat.png");	
	//ALLEGRO_BITMAP *jamaica = al_load_bitmap("Jamaica.png");
	//al_convert_mask_to_alpha(player1.player, al_map_rgb(0,255,255)); //Makes sprite background transparent

	//al_convert_mask_to_alpha(player2, al_map_rgb(0,255,255));

	ALLEGRO_TIMER *timer = al_create_timer(1.0 / FPS);
	ALLEGRO_EVENT_QUEUE *event_queue = al_create_event_queue();  //Creates a Queue for keypresses
	al_register_event_source(event_queue, al_get_keyboard_event_source()); //Registers events from Keyboard
	al_register_event_source(event_queue, al_get_timer_event_source(timer));
	al_register_event_source(event_queue, al_get_display_event_source(display));


	al_start_timer(timer); //Starts the event timer
	//FADING TOOLS TO BE LATER IMPLEMENTED INTO A CLASS

	
	
	IntroScreen introScreen;
	HowToPlay howScreen;

	while(gameOn){
		while(!introDone){
			
			if(introScreen.getExists()){
				introScreen.makeIntroScreen(ScreenWidth,ScreenHeight);
				if (introScreen.getDone())
					introDone = true;
				if (introScreen.getPlayGo()){
					introDone = true;
					playGame = true;
					gameOn = false;
				}
				if(introScreen.getExit())
					gameOn = false;
				if(introScreen.getHowGo()){
					introDone = true;
					howScreenOn = true;
				}
			}
		
			if (gameOn == false){
				break;
			}


		}
	
		while(howScreenOn){
			while(introScreen.getHowGo()){
					if(howScreen.getActive()){
						howScreen.makeHowToPlayScreen();
						if(howScreen.getHowDone()){
							introScreen.setHowGo(false);
							introDone = false;
							howScreenOn = false;
							
						}
					}
			}
		}
	
	}


	//FADING TOOLS TO BE LATER IMPLEMENTED INTO A CLASS
	
	Battle battle;
	srand(time(NULL));
	battle.randomGenerator();
	
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
				battle.setRandomEncounter(battle.getRandomEncounterNum() - 2);
				std::cout << "NUM: " << battle.getRandomEncounterNum() << std::endl;
				
			}
			else if (al_key_down(&keyState, ALLEGRO_KEY_UP))
			{
				player1.y -= player1.moveSpeed;
				player1.dir	= player1.UP;
				battle.setRandomEncounter(battle.getRandomEncounterNum() - 2);
			
				std::cout << "NUM: " << battle.getRandomEncounterNum() << std::endl;
				
			}
			else if (al_key_down(&keyState, ALLEGRO_KEY_RIGHT))
			{
				player1.x += player1.moveSpeed;
				player1.dir = player1.RIGHT;
				battle.setRandomEncounter(battle.getRandomEncounterNum() - 2);
				
				std::cout << "NUM: " << battle.getRandomEncounterNum() << std::endl;
				
			}
			else if (al_key_down(&keyState, ALLEGRO_KEY_LEFT))
			{
				player1.x -= player1.moveSpeed;
				player1.dir = player1.LEFT;
				battle.setRandomEncounter(battle.getRandomEncounterNum() - 2);
				
				std::cout << "NUM: " << battle.getRandomEncounterNum() << std::endl;
			}
			//MOVEMENT WITH KEYBOARD
			else
			{
				active = false; //KEY IS NOT BEING PRESSED
				//std::cout << "X coordinate: " << player1.x << "," << "Y coordinate: " << player1.y << std::endl;
			}
			
			// BATTLE SYSTEM INITALIZATION
			if(battle.getRandomEncounterNum() <= -50)
			{
				battle.setBattleState(true);
				std::cout<<"Battle!"<<std::endl;
				if(battle.getRandomEncounterNum() <= -100)
				{
					battle.setBattleState(false);
					battle.randomGenerator();
				}
			}
		

			
		
			// BATTLE SYSTEM INTIALIZATION

			//COLLISION DETECTION

			//BOUNDING AREA COLLISION
			if(Collision2(player1.x, player1.y, -50, -50, 5, 800))
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
			if(Collision2(player1.x, player1.y, -50, -50, 1100, 5))
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
			if(Collision2(player1.x, player1.y, -40, 680, 1100, 5))
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
			if(Collision2(player1.x, player1.y, 1020, -40, 5, 800))
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
			//BOUNDING AREA COLLISION 
		

			if(Collision2(player1.x, player1.y, 515, 260, 42, 21))
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

			//std::cout << "cameraPositions: " << mainCamera.cameraPosition[0] << "," << mainCamera.cameraPosition[1] << std::endl;
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
			//al_draw_bitmap_region(player2, 0, 0, 161, 161, 200, 200, NULL);
			//al_draw_bitmap_region(jamaica, 0, 0, 173, 124, 483, 260, NULL);
			al_draw_bitmap_region(Cuba, 0, 0, 421, 199, 288, 109, NULL);
			al_draw_bitmap_region(player1.player, sourceX, sourceY*al_get_bitmap_height(player1.player) / 4, 102, 102,
				player1.x, player1.y, NULL);
			al_flip_display();
			al_clear_to_color(al_map_rgb(0,0,0));
		}

		

	}
	//END OF THE GAME LOOP
	
	al_destroy_display(display);//Destructor for Display
	al_destroy_timer(timer);
	al_destroy_bitmap(player1.player);
	//al_destroy_bitmap(player2);
	//al_destroy_bitmap(jamaica);
	al_destroy_bitmap(background);
	al_destroy_event_queue(event_queue);


	return 0;
}

