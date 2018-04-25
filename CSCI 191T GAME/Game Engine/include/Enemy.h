#ifndef ENEMY_H
#define ENEMY_H

#include "Player.h"
#include "Agent.h"
#include "AI.h"


class Enemy : public Agent, public AI
{
    public:
        Enemy();
        virtual ~Enemy();

        void chase(Vec2);
        void wander();
        void patrol();
        void idle();

        void Init();
        void Update(Vec2);
        void actions();

    private:
        Texture ErunRight[5];
        Texture ErunLeft[5];
        Texture EstandL[3];
        Texture EstandR[3];
};

#endif // ENEMY_H
