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
        void attack(Vec2);

        void Init();
        void Update(Vec2);
        void actions();

    private:
        float width;
        float height;
        Texture ErunRight[5];
        Texture ErunLeft[5];
        Texture EstandL[6];
        Texture EstandR[6];
        Texture EatkR[6];
        Texture EatkL[6];
};

#endif // ENEMY_H
