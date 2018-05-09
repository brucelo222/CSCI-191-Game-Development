#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <Graphics.h>
#include <Texture.h>
#include <Vector.h>

class GameObject
{
    public:
        GameObject();
        virtual ~GameObject();

        void Init(char*,float,float);
        void Draw(float,float);

        Vec2 getPos(){return _Position;};

    private:
        Texture *_object = new Texture();
        Graphics *_shape = new Graphics();
        Vec2 _Position;
};

#endif // GAMEOBJECT_H
