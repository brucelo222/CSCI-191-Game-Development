#ifndef PLAYER_H
#define PLAYER_H

#include "Graphics.h"
#include "Physics.h"
#include "Vector.h"
#include "Agent.h"
#include "Texture.h"
#include "Timer.h"
#include "sounds.h"

class Player : public Agent
{

    public:
        Player();
        virtual ~Player();

        void Init();
        void Update();
        void actions();
        sounds * sfx = new sounds();

    private:
        Gravity _gravity;
        //remove later
        Texture runRight[5];
        Texture runLeft[5];
        Texture standL[3];
        Texture standR[3];
        Texture atkR[3];
        Texture atkL[3];
        Texture jmpR[3];
        Texture jmpL[3];

        bool hasJump;
};

#endif // PLAYER_H
