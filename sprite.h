#ifndef SPRITE_H
#define SPRITE_H

#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>

class Sprite {
private:
  // position of sprite
	// always gonna be in the same spot
	float x, y;

	// Bitmap Region description
	int max, current, count, delay, width, height, columns;

	// sprite sheet but only see a region
	ALLEGRO_BITMAP *icon;

public:
	// initialize attributes:
	//     x, y, current, count, and delay already have specific values.
	//     width, height, columns, and max are independent
	Sprite();
	void sprite(ALLEGRO_BITMAP *image, int max,
		int width, int height, int columns);
	void draw();
	void update();
};
#endif
