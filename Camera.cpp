#include "Camera.h"
#include <allegro5/allegro.h>

Camera::Camera() {
  
	cameraPosition[0] = 0;
	cameraPosition[1] = 0;

}

void Camera::CameraUpdate(float *cameraPosition, float x, float y, int width, int height, int ScreenWidth, int ScreenHeight)
{ 
	mapCameraHeight = 451;
	mapCameraWidth = 676;

	cameraPosition[0] = -(ScreenWidth / 2) + (x + (width/2));
	cameraPosition[1] = -(ScreenHeight / 2 ) + (y + (height/2));

	if(cameraPosition[0] < 0)
		cameraPosition[0] = 0;
	//EDGE DETECTION
	if(cameraPosition[0] > (mapCameraWidth - (ScreenWidth/2)))
		cameraPosition[0] = mapCameraWidth - (ScreenWidth/2);
	if(cameraPosition[1] < 0)
		cameraPosition[1] = 0;
	//EDGE DETECTION
	if(cameraPosition[1] > (mapCameraHeight - (ScreenHeight/2)))
		cameraPosition[1] = mapCameraHeight - (ScreenHeight/2);
}
