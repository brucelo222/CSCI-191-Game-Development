#ifndef COLLIDER_H
#define COLLIDER_H
#include "platform.h"
#include<GL/gl.h>
#include "player.h"
#include "fallingObject.h"
class collider
{
    public:
        collider();
        virtual ~collider();

         bool checkCollision(player *,fallingObject  *);
         int platformCollision(player *,platform *);

    protected:

    private:
};

#endif // COLLIDER_H
