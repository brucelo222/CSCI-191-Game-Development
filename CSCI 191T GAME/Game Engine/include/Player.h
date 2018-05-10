#ifndef PLAYER_H
#define PLAYER_H

#include "Graphics.h"
#include "Physics.h"
#include "Vector.h"
#include "Agent.h"
#include "Texture.h"
#include "Timer.h"

class Player : public Agent
{

    public:
        Player();
        virtual ~Player();

        void Init();
        void Update();
        void actions();
        bool hasJump;
        bool isJump;
        bool isFalling;
        bool leftStop;
        bool rightStop;
        float maxMY;
        float falling;
    private:
        Gravity _gravity;
        //remove later
        Texture runRight[5];
        Texture runLeft[5];
        Texture standL[3];
        Texture standR[3];
        Texture atkR[3];
        Texture atkL[3];
        Texture jmpL[3];
        Texture jmpR[3];

};

#endif // PLAYER_H
