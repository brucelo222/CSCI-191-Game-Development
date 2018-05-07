#include "Hitbox.h"

void Hitbox::init(Vec2 pos, float width, float height)
{
    collider.x = pos.x;
    collider.y = pos.y;
    collider.w = width;
    collider.h = height;
}

void Hitbox::update(Vec2 newPOS)
{
    collider.x = newPOS.x;
    collider.y = newPOS.y;
}
