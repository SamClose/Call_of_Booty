#ifndef HOW_TO_PLAY
#define HOW_TO_PLAY

#include <allegro5/allegro.h>
#include <allegro5/allegro_native_dialog.h>
#include<allegro5/allegro_ttf.h>
#include<allegro5/allegro_font.h>
#include <iostream>

class HowToPlay{

public:
	HowToPlay();
	void makeHowToPlayScreen();
	bool getHowDone();
	void setHowDone(bool doneValue);
	bool getActive();
	void setActive(bool activeValue);
private:
	bool howDone;
	bool active;
};
#endif //HOW_TO_PLAY
