
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
  bool introDone = false;
  bool gameOn = true;
  bool howScreenOn = false;
  bool playGame = false;


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
	}
	while (playGame){
		al_draw_filled_rectangle(0, 0,800,600,al_map_rgb(0,0,255)); //TEMPORARY filler for launch game~for now consider BlueScreen as the game
		al_flip_display();
	}

	al_destroy_display(display);//Destructor
	
	return 0;
}
