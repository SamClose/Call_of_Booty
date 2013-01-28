#ifndef BUTTON_H_
#define BUTTON_H_

//parent class should represent a button in a menu that will change color when selected(up/down)
//When "Enter" is pressed, should perform a certain action, determined by child class

class Button {

#define DEFAULT_COLOR black; //come back to this
#define SELECTED_COLOR red;


public:
  string getColor();
	void setColor()
	bool getSelected;
	void setSelected();



private:
	string color; //might be better to do color as an int 0-255 corresponding to a color value(r,g,b)
	bool selected;


};

#endif /* BUTTON_H_ */
