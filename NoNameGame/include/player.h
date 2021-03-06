#ifndef PLAYER_H
#define PLAYER_H

#include<Model.h>
#include<gl/gl.h>
#include<textureLoader.h>
#include <windows.h>

typedef struct
{
   float x;
   float y;
   float z;
}vec;

class player:Model
{
    public:
        player();
        virtual ~player();

        float scalesize[3]={1.0,1.0,1.0};
        vec verticies[4];

        int runspeed;
        int jumpspeed;
        int actionTrigger;

        void drawPlayer();
        void playerInit();
        void actions(int);
        void resetPos();

        float getPlyPosY();

        float mX,mY,maxMX,maxMY,falling;
        float xSpeed,ySpeed;
        const float gravity = -0.4;
        float jumppY;
        bool isJump;
        bool isFalling;
        bool rightLeft;
        void damaged();
float jpVelo;
float jpGround;



    protected:

    private:
};

#endif // PLAYER_H
