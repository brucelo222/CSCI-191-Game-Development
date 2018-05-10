#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <Graphics.h>
#include <Texture.h>
#include <Vector.h>
#include "Hitbox.h"

class GameObject
{
    public:
        GameObject();
        virtual ~GameObject();

        void Init(char*,float,float);
        void Draw(float,float);

        void setPOS(float x,float y){_Position.x = x; _Position.y = y;};
        Vec2 getPos(){return _Position;};
        Hitbox *_hitbox = new Hitbox();
    private:
        Texture *_object = new Texture();
        Graphics *_shape = new Graphics();
        Vec2 _Position;
};

#endif // GAMEOBJECT_H
