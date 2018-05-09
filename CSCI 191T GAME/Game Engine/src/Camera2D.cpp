#include "Camera2D.h"

#include <GL/glu.h>

Camera2D::Camera2D()
{
    //ctor
    _cameraPosition.x = 0;
    _cameraPosition.y = 0;
}

Camera2D::~Camera2D()
{
    //dtor
}

void Camera2D::moveCamera()
{
    //first three are cameras size, next three are the used to center the camera, next three apply a rotation to the camera;
    gluLookAt(_cameraPosition.x,_cameraPosition.y,3.0,_cameraPosition.x,_cameraPosition.y,-1.0,0.0,1.0,0.0);
}
//pass in a x and y value to center the camera to;
void Camera2D::updateCameraPosition(float x, float y)
{
    this->_cameraPosition.x = x;
    this->_cameraPosition.y = y;
}

