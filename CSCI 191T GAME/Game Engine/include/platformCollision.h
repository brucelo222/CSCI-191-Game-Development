#ifndef PLATFORMCOLLISION_H
#define PLATFORMCOLLISION_H

#include "Player.h"
#include "platform.h"

class platformCollision
{
    public:
        platformCollision();
        virtual ~platformCollision();
        int collision(Player *,platform *);
    protected:

    private:
};

#endif // PLATFORMCOLLISION_H
