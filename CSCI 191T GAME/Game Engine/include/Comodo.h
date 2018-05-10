#ifndef COMODO_H
#define COMODO_H

#include "Texture.h"
#include "Vector.h"
#include "Agent.h"
#include "AI.h"
#include "Physics.h"



class Comodo : public Agent , public AI
{
    public:
        Comodo();
        virtual ~Comodo();

        void chase(Vec2);
        void wander();
        void patrol();
        void idle();
        void attack(Vec2);

        void Init();
        void draw();
        void Update(Vec2);
        void actions();

    private:
        float width;
        float height;
        Gravity *_gravity = new Gravity();

        Texture CrunRight[4];
        Texture CrunLeft[4];
        Texture CstandL[1];
        Texture CstandR[1];
        Texture CatkR[6];
        Texture CatkL[6];
};

#endif // COMODO_H
