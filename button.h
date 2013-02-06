#ifndef BUTTON_H_
#define BUTTON_H_


#include <allegro5/allegro.h>
#include <allegro5/allegro_native_dialog.h>
#include<allegro5/allegro_ttf.h>
#include<allegro5/allegro_font.h>
#include <iostream>



//parent class should represent a button in a menu that will change color when selected(up/down)
//When clicked on by a mouse, should perform a certain action, determined by instance--not yet implemented

class Button{

public:
	Button();
	 void printText(int fontSize,const char *filename, int red, int green, int blue, float x, float y, int flags, const char *text);
};

#endif //BUTTON_H_
