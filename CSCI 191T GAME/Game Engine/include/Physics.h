#ifndef PHYSICS_H_INCLUDED
#define PHYSICS_H_INCLUDED

#include "Vector.h"

class Gravity{
public:
    float applyGravity(float yVelocity){ return yVelocity += gravity;};
private:
    const float gravity = -.091;
};


#endif // PHYSICS_H_INCLUDED
