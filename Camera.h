#ifndef CAMERA_H
#define CAMERA_H

#include <allegro5/allegro.h>

class Camera{

public:
  Camera(); //Constructor
	void CameraUpdate(float *cameraPosition, float x, float y, int width, int height, int ScreenWidth, int ScreenHeight); //updates camera position
	ALLEGRO_TRANSFORM camera;
	float cameraPosition[2];
private:
	float mapCameraWidth, mapCameraHeight;
};










#endif CAMERA_H
