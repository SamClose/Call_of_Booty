#ifndef INTRO_SCREEN
#define INTRO_SCREEN

#include "button.h"
#include "howToPlay.h"

class IntroScreen{

public:
	IntroScreen();
	void makeIntroScreen(float ScreenWidth, float ScreenHeight);
	bool getDone();
	void setDone(bool doneValue);
	bool getExists();
	void setExists(bool existsValue);
	bool getPlayGo();
	void setPlayGo(bool playGoValue);
	bool getHowGo();
	void setHowGo(bool howGoValue);
	bool getExit();
	void setExit(bool exitValue);

private:
	bool done;
	bool exists;
	bool playGo;
	bool howGo;
	bool exit;
	
};
#endif //INTRO_SCREEN
