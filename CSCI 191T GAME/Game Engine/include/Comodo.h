#ifndef COMODO_H
#define COMODO_H

#include "Texture.h"
#include "Vector.h"
#include "Agent.h"
#include "AI.h"



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

        Texture CrunRight[6];
        Texture CrunLeft[6];
        Texture CstandL[2];
        Texture CstandR[2];
        Texture CatkR[6];
        Texture CatkL[6];
};

#endif // COMODO_H
