
#include <allegro5/allegro.h>
#include <allegro5/allegro_native_dialog.h>
#include <allegro5/allegro_image.h>
#include<allegro5/allegro_ttf.h>
#include<allegro5/allegro_font.h>
#include<allegro5/allegro_primitives.h>
//#include <iostream>
#include "Camera.h"
#include "Player.h"
#include "introScreen.h"
//#include "InventoryDisplay.h"

//using namespace std;

#define ScreenWidth 800
#define ScreenHeight 600

int top, bottom, left, right;

bool Collision(ALLEGRO_BITMAP *player, ALLEGRO_BITMAP *enemy, 
	float x, float y, float ex, float ey, int width, int height, float moveSpeed, int dir)
{
	if(x + width < ex || x > ex + width || y + height < ey || y > ey + height)
	{
		return false;
	}
	else
	{
		top = max(y,ey);
		bottom = min(y + height, ey + height); 
		left = max(x, ex);
		right = min(x + width, ex + width);

		for(int i = top; i < bottom; i++)
		{
			for(int j = left; j < right; j++)
			{
				al_lock_bitmap(player, al_get_bitmap_format(player), ALLEGRO_LOCK_READONLY);
				al_lock_bitmap(enemy, al_get_bitmap_format(enemy), ALLEGRO_LOCK_READONLY);
				ALLEGRO_COLOR color = al_get_pixel(player, j - x, i - y);
				ALLEGRO_COLOR color2 = al_get_pixel(enemy, j - ex, i - ey);

				if(color.a != 0 && color2.a != 0)
				{
					//std::cout << "1: " << color.a << "," << "2: " << color2.a << std::endl;
					if(dir == 0 || dir == 3)
						moveSpeed = (i-y);
					else
						moveSpeed = (j-x);
					return true;
				}
			}
		}
	}
	return false;
}

int main(void)
{
	ALLEGRO_DISPLAY *display; 
	bool gameOn = true; //bool for whether to keep the window open(game is running on any level)~basically Vinh's done variable
	//booleans interacting with IntroScreen
	bool introDone = false;//bool for whether introScreen is on
	bool howScreenOn = false; //bool for whether to display the how to play screen
	bool playGame = false; //bool to turn on the actual playable part of the game(ship movement)

	//bool showInventory = false;

	bool draw = true; // bool for drawing ship
	bool active = false;

	int sourceX = 161, sourceY = 0; //points on bitmap
	int state = NULL;
	const float FPS = 30.0;

	Camera mainCamera;
	Player player1;

	if(!al_init()) //If allegro window does not initialize, error
	{
		al_show_native_message_box(NULL, NULL, NULL, "Could not initialize Allegro 5", NULL, NULL);
		return -1; //Program ended with an error
	}
	
	al_set_new_display_flags(ALLEGRO_WINDOWED);

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
	al_init_image_addon();

	ALLEGRO_KEYBOARD_STATE keyState; //Gets the current state of keyboard
	player1.player = al_load_bitmap("Boat2.png");
	ALLEGRO_BITMAP *background = al_load_bitmap("Background.png"); //Load background picture
	ALLEGRO_BITMAP *player2 = al_load_bitmap("Boat.png");

	ALLEGRO_TIMER *timer = al_create_timer(1.0 / FPS);
	ALLEGRO_EVENT_QUEUE *event_queue = al_create_event_queue();  //Creates a Queue for keypresses
	al_register_event_source(event_queue, al_get_keyboard_event_source()); //Registers events from Keyboard
	al_register_event_source(event_queue, al_get_timer_event_source(timer));
	al_register_event_source(event_queue, al_get_display_event_source(display));

	al_start_timer(timer); //Starts the event timer

	IntroScreen introScreen;
	HowToPlay howScreen;

	while (gameOn){
		while(!introDone){ // introscreen is active
		

			if(introScreen.getExists()){
				introScreen.makeIntroScreen(ScreenWidth, ScreenHeight);
				if (introScreen.getDone())//introscreen has been told to close(play or exit)
					introDone = true; //stops dealing with introScreen
				if (introScreen.getPlayGo()){
					introDone = true;
					playGame = true;
					gameOn = false;
				}
				if(introScreen.getExit())//exit has been clicked
					gameOn = false;
				if (introScreen.getHowGo()){//HowToPlay has been clicked
					introDone = true;
					howScreenOn = true;
				}
			}
			if (gameOn == false){ //if exit has been clicked, end the program
				break;
			}
			
			
		}
		while(howScreenOn){ //loop for howScreen
			while(introScreen.getHowGo()){
						if (howScreen.getActive()){
							howScreen.makeHowToPlayScreen();
							if(howScreen.getHowDone()){
								introScreen.setHowGo(false);
								introDone = false;
								howScreenOn = false;
							}
						}
			}
		}
	//al_draw_filled_rectangle(0, 0,800,600,al_map_rgb(0,0,255)); //TEMPORARY filler for launch game~for now consider BlueScreen as the game
	//al_flip_display();
	//al_show_native_message_box(display, "MessageBox Title", "Error", "Display window could not be shown", NULL, ALLEGRO_MESSAGEBOX_ERROR);
	
	//Inventory playerInventory;
	//InventoryDisplay playerInventoryDisplay;

	while (playGame){
		ALLEGRO_EVENT events;
		al_wait_for_event(event_queue, &events);
		al_get_keyboard_state(&keyState);

		
	
		if (events.type == ALLEGRO_EVENT_KEY_DOWN) //If a key is being pressed
		 {
			switch(events.keyboard.keycode)
			{
				case ALLEGRO_KEY_ESCAPE:
					{
					playGame = false;
					}
					/*
				case ALLEGRO_KEY_1:
					{
				//add in inventory and display here to test~should go somewhere else later
					//Inventory playerInventory;
					//InventoryDisplay playerInventoryDisplay;
					/*if(!showInventory){
						showInventory = true;
						playerInventoryDisplay.setShowDisplay(true);
						al_flip_display();*//*
						if(!showInventory){
							showInventory = true;
							playerInventoryDisplay.setActive(true);
						}
						else if (showInventory){
							showInventory = false;
							playerInventoryDisplay.setActive(false);
						}
						//playerInventoryDisplay.setShowDisplay(true);
						//playerInventoryDisplay.displayScreen(playerInventory);

						/*while(showInventory){
							playerInventoryDisplay.displayScreen(playerInventory);
							/*if (events.type == ALLEGRO_EVENT_KEY_DOWN){
								switch(events.keyboard.keycode){
								case ALLEGRO_KEY_1:
									showInventory = false;
								}
							}	
						}
					}*//*
					} */
			}
	/*	
			while (showInventory){
				playerInventoryDisplay.setShowDisplay(true);
				//while(playerInventoryDisplay.getShowDisplay()){
					//if (playerInventoryDisplay.getActive()){
						playerInventoryDisplay.displayScreen(playerInventory);
						if(!playerInventoryDisplay.getShowDisplay()){
							playerInventoryDisplay.setShowDisplay(false);
							showInventory = false;
						}
					//}
				//}
			}
			*/
		}
	else if(events.type == ALLEGRO_EVENT_TIMER)
	{
			active = true; //THERE IS A KEY BEING PRESSED

			//MOVEMENT WITH KEYBOARD
			if (al_key_down(&keyState, ALLEGRO_KEY_DOWN))
			{
				player1.y += player1.moveSpeed;
				player1.dir = player1.DOWN;
				//std::cout << "DOWN: " << player1.DOWN << std::endl;
			}
			else if (al_key_down(&keyState, ALLEGRO_KEY_UP))
			{
				player1.y -= player1.moveSpeed;
				player1.dir	= player1.UP;
				//std::cout << "UP: " << player1.UP << std::endl;
			}
			else if (al_key_down(&keyState, ALLEGRO_KEY_RIGHT))
			{
				player1.x += player1.moveSpeed;
				player1.dir = player1.RIGHT;
				//std::cout << "RIGHT: " << player1.RIGHT << std::endl;
			}
			else if (al_key_down(&keyState, ALLEGRO_KEY_LEFT))
			{
				player1.x -= player1.moveSpeed;
				player1.dir = player1.LEFT;
				//std::cout << "LEFT: " << player1.LEFT << std::endl;
			}
			//MOVEMENT WITH KEYBOARD
			else
			{
				active = false; //KEY IS NOT BEING PRESSED
				//std::cout << "X coordinate: " << player1.x << "," << "Y coordinate: " << player1.y << std::endl;
			}
			
			//COLLISION DETECTION
			
			if(Collision(player1.player, player2,player1.x, player1.y, 200, 200, 100, 100, player1.moveSpeed, player1.dir))
			{
				if(player1.dir == 0)
					player1.y -= player1.moveSpeed;
				else if (player1.dir == 1)
					player1.x += player1.moveSpeed;
				else if ( player1.dir == 2)
					player1.x -= player1.moveSpeed;
				else if (player1.dir == 3)
					player1.y += player1.moveSpeed;

				player1.moveSpeed = 5;
				
			}
			
			/*
			if(Collision(player1.x, player1.y, 515, 260, 42, 21))
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
			*/
			

			//COLLISION DETECTION

	   //SCREENSCROLLING
		//276,151
		
		//std::cout << "cameraPositions: " << mainCamera.cameraPosition[0] << "," << mainCamera.cameraPosition[1] << std::endl;
		mainCamera.CameraUpdate(mainCamera.cameraPosition, player1.x, player1.y, 161, 161, ScreenWidth, ScreenHeight);
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
			al_draw_bitmap_region(player2, 0, 0, 161, 161, 200, 200, NULL);
			al_draw_bitmap_region(player1.player, sourceX, sourceY*al_get_bitmap_height(player1.player) / 4, 102, 102,
				player1.x, player1.y, NULL);
			al_flip_display();
			al_clear_to_color(al_map_rgb(0,0,0));
		 }

		
	}
	//END OF THE GAME LOOP
	}

	al_destroy_display(display);//Destructor
	al_destroy_timer(timer);
	al_destroy_bitmap(player1.player);
	al_destroy_bitmap(player2);
	al_destroy_bitmap(background);
	al_destroy_event_queue(event_queue);
	return 0;
}
