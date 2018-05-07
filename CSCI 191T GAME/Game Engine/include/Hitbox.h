#ifndef HITBOX_H
#define HITBOX_H

#include <Vector.h>
#include <Graphics.h>
#include <string>


class Hitbox
{
    public:
        std::string tag;
        Rect collider;
        bool active;

        void init(Vec2,float,float);
        void update(Vec2);

    private:
};

#endif // HITBOX_H
