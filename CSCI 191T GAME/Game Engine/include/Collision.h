#ifndef COLLISION_H
#define COLLISION_H

#include <Vector.h>


class Collision
{
    public:
        Collision();
        virtual ~Collision();

        static bool AABB(const Rect, const Rect);

    private:
};

#endif // COLLISION_H
