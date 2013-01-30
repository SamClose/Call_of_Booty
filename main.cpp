#include <button.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_native_dialog.h>
#include<allegro5/allegro_ttf.h>//this added
#include<allegro5/allegro_font.h>//this added
#include <iostream>


using namespace std;

#define ScreenWidth 800
#define ScreenHeight 600

int main(void)
{
  ALLEGRO_DISPLAY *display; 

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
	}

	Button titleButton;
	titleButton.printText(36, "Pirate.ttf",255,255,255,ScreenWidth/2,20, ALLEGRO_ALIGN_CENTRE,"Play Game");

	Button playButton;
	playButton.printText(36, "Pirate.ttf",255,255,255,ScreenWidth/2,200, ALLEGRO_ALIGN_CENTRE,"Play Game");

	Button howButton;
	howButton.printText(36, "Pirate.ttf",255,255,255,ScreenWidth/2,300, ALLEGRO_ALIGN_CENTRE,"How to Play");

	Button exitButton;
	exitButton.printText(36, "Pirate.ttf",255,255,255,ScreenWidth/2,400, ALLEGRO_ALIGN_CENTRE,"Exit Game");
	//The commented code below works when run without using the Button class
	/*
	al_init_font_addon();
	al_init_ttf_addon();

	ALLEGRO_FONT *font = al_load_font("Pirate.ttf", 36, NULL);
	al_draw_text(font, al_map_rgb(255, 255, 0), ScreenWidth/2, 20, ALLEGRO_ALIGN_CENTRE, "Call of Booty");
	*/
	////al_show_native_message_box(display, "MessageBox Title", "Error", "Display window could not be shown", NULL, ALLEGRO_MESSAGEBOX_ERROR);
	//al_flip_display();
	al_rest(10.0);
	//al_destroy_font(font);
	al_destroy_display(display);//Destructor

	return 0;
}
