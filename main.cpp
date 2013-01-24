#include <allegro5/allegro.h>
#include <allegro5/allegro_native_dialog.h>
#include <iostream>

using namespace std;

int main(void)
{
  ALLEGRO_DISPLAY *display; 

	if(!al_init()) //If allegro window does not initialize, error
	{
		al_show_native_message_box(NULL, NULL, NULL, "Could not initialize Allegro 5", NULL, NULL);
		return -1; //Program ended with an error
	}
	
	al_set_new_display_flags(ALLEGRO_WINDOWED | ALLEGRO_RESIZABLE);

	display = al_create_display(800,600); //initializes display
	al_set_window_title(display, "Call of Booty - Argh!"); //Sets the name of the game window

	if(!display)
	{
		al_show_native_message_box(display, "Call of Booty", "Display Settings", "Display window cannot be created", NULL, ALLEGRO_MESSAGEBOX_ERROR);
	}

	//al_show_native_message_box(display, "MessageBox Title", "Error", "Display window could not be shown", NULL, ALLEGRO_MESSAGEBOX_ERROR);
	al_rest(10.0);
	al_destroy_display(display);//Destructor

	return 0;
}
