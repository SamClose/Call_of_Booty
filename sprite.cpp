#include <allegro5/allegro5.h>
#include <allegro5/allegro_image.h>

#include <iostream>
#include "sprite.h"

Sprite::Sprite() {
  // fixed initial values
	x = 450;
	y = 30;
	current = 0;
	count = 0;
	delay = 5;
}

void Sprite::sprite(ALLEGRO_BITMAP *image, int max, int width, int height, int columns) {
	// custom values
	icon = image;
	this->max = max;
	this->width = width;
	this->height = height;
	this->columns = columns;
}

void Sprite::draw() {
	int row = current%columns*width;
	int col = current/columns*height;
	al_draw_bitmap_region(icon, row, col,
		width, height, x, y, NULL);
}

void Sprite::update() {
	if(++count >= delay) {
		if(++current >= max)
			current = 0;
		else if(current <= 0)
			current = max - 1;
		count = 0;
	}
}
