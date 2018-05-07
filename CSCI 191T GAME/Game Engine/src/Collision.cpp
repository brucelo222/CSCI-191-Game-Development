#include "Collision.h"
#include <iostream>

Collision::Collision()
{
    //ctor
}

Collision::~Collision()
{
    //dtor
}

bool Collision::AABB(const Rect recA, const Rect recB)
{
    if(recA.x + recA.w >= recB.x &&
       recB.x + recB.w >= recA.x &&
       recA.y + recA.h >= recB.y &&
       recB.y + recB.h >= recA.y)
    {
        return true;
    }

    return false;
}
