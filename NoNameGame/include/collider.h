#ifndef COLLIDER_H
#define COLLIDER_H

#include<GL/gl.h>
#include "player.h"
#include "fallingObject.h"
class collider
{
    public:
        collider();
        virtual ~collider();

         bool checkCollision(player *,fallingObject  *);


    protected:

    private:
};

#endif // COLLIDER_H
