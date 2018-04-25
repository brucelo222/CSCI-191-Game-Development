#ifndef CAMERA2D_H
#define CAMERA2D_H

#include "Vector.h"

class Camera2D
{
    public:
        Camera2D();
        virtual ~Camera2D();
        void moveCamera();
        void updateCameraPosition(float,float);

    private:
        Vec2 _cameraPosition;
};

#endif // CAMERA2D_H
