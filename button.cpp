

#include <iostream>
#include <allegro5/allegro.h>
#include <allegro5/allegro_native_dialog.h>
#include<allegro5/allegro_ttf.h>
#include<allegro5/allegro_font.h>
#include "button.h"

using namespace std;

Button::Button(){
}

void Button::printText(int fontSize,const char *filename, int red, int green, int blue, float x, float y, int flags, const char *text){
	//al_init_font_addon();
	//al_init_ttf_addon();

	ALLEGRO_FONT *font = al_load_font(filename, fontSize, NULL);
	al_draw_text(font, al_map_rgb(red, green, blue), x, y, ALLEGRO_ALIGN_CENTRE, text);
	
	al_flip_display();
	//al_rest(10.0);
	al_destroy_font(font);
}
