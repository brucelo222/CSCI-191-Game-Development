#include "Enemy.h"
#include "Player.h"

#include <GL/gl.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

Enemy::Enemy()
{
    //ctor
    setPosition(14.0,0.0);
    setAction(STANDL);
    runspeed = 0;
    width = 0.9;
    height = 0.9;
    setHealth(50);
    isObjectLive = true;

    setMaxSpeed(0.01,0.1);
    setVelocity(0.0,0.0);
}

Enemy::~Enemy()
{
    //dtor
}

void Enemy::chase(Vec2 playerPosition)
{
        if (getPosition().x <= playerPosition.x)
        {
            setAction(RUNR);
            setPosition(getPosition().x + Accelerate()*(playerPosition.x - getPosition().x),getPosition().y);
        }
        else
        {
            setAction(RUNL);
            setPosition(getPosition().x + Accelerate()*(playerPosition.x - getPosition().x),getPosition().y);
        }
}

void Enemy::wander()
{

}

void Enemy::patrol()
{

}

void Enemy::idle()
{
    setAction(STANDL);
return;
}

void Enemy::attack(Vec2 playerPosition)
{
        if (getPosition().x <= playerPosition.x)
        {
            setAction(ATKR);
        }
        else
        {
            setAction(ATKL);
        }
    return;
}


void Enemy::Init()
{
    _hitbox->init(getPosition(),0.75,0.75);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);//trans
    T->start();

    EatkR[0].bindTexture("images/enemy/hellhound/jump06.png");
    EatkR[1].bindTexture("images/enemy/hellhound/jump07.png");
    EatkR[2].bindTexture("images/enemy/hellhound/jump08.png");
    EatkR[3].bindTexture("images/enemy/hellhound/jump09.png");
    EatkR[4].bindTexture("images/enemy/hellhound/jump10.png");
    EatkR[5].bindTexture("images/enemy/hellhound/jump11.png");

    EatkL[0].bindTexture("images/enemy/hellhound/jump00.png");
    EatkL[1].bindTexture("images/enemy/hellhound/jump01.png");
    EatkL[2].bindTexture("images/enemy/hellhound/jump02.png");
    EatkL[3].bindTexture("images/enemy/hellhound/jump03.png");
    EatkL[4].bindTexture("images/enemy/hellhound/jump04.png");
    EatkL[5].bindTexture("images/enemy/hellhound/jump05.png");

    EstandR[0].bindTexture("images/enemy/hellhound/idle06.png");
    EstandR[1].bindTexture("images/enemy/hellhound/idle07.png");
    EstandR[2].bindTexture("images/enemy/hellhound/idle08.png");
    EstandR[3].bindTexture("images/enemy/hellhound/idle09.png");
    EstandR[4].bindTexture("images/enemy/hellhound/idle10.png");
    EstandR[5].bindTexture("images/enemy/hellhound/idle11.png");

    EstandL[0].bindTexture("images/enemy/hellhound/idle00.png");
    EstandL[1].bindTexture("images/enemy/hellhound/idle01.png");
    EstandL[2].bindTexture("images/enemy/hellhound/idle02.png");
    EstandL[3].bindTexture("images/enemy/hellhound/idle03.png");
    EstandL[4].bindTexture("images/enemy/hellhound/idle04.png");
    EstandL[5].bindTexture("images/enemy/hellhound/idle05.png");

    ErunLeft[0].bindTexture("images/enemy/hellhound/run00.png");
    ErunLeft[1].bindTexture("images/enemy/hellhound/run01.png");
    ErunLeft[2].bindTexture("images/enemy/hellhound/run02.png");
    ErunLeft[3].bindTexture("images/enemy/hellhound/run03.png");
    ErunLeft[4].bindTexture("images/enemy/hellhound/run04.png");

    ErunRight[0].bindTexture("images/enemy/hellhound/run05.png");
    ErunRight[1].bindTexture("images/enemy/hellhound/run06.png");
    ErunRight[2].bindTexture("images/enemy/hellhound/run07.png");
    ErunRight[3].bindTexture("images/enemy/hellhound/run08.png");
    ErunRight[4].bindTexture("images/enemy/hellhound/run09.png");
    return;
}

void Enemy::Update(Vec2 playerPOS)
{
    _hitbox->update(getPosition());
    aiManager(playerPOS, getPosition());
    switch (getState())
    {
        case CHASE:
            chase(playerPOS);
        break;
        case IDLE:
            idle();
        break;
        case ATTACK:
            attack(playerPOS);
        break;
        default:
        break;
    }
return;
    //call switch of AI states the preform the logic
    aiManager(playerPOS, getPosition());
    glTranslated(getPosition().x,getPosition().y, -1.0);
}


void Enemy::actions()
{
    switch(getAction())
     {
       case STANDR://stdR

           glPushMatrix();
           //glTranslated(getPosition().x,getPosition().y,-1.0);
           if(T->getTicks()>200){

            runspeed++;
            runspeed = runspeed %6;
            T->reset();
          }
           EstandR[runspeed].binder();
           Draw(width,height);

           glPopMatrix();
           break;

       case RUNR:
           glPushMatrix();
               //glTranslated(getPosition().x,getPosition().y,-1.0);

               if(T->getTicks()>70)
                {
                  //  mX+=xSpeed;
                    runspeed++;
                    runspeed = runspeed %5;
                    T->reset();
                }

               ErunRight[runspeed].binder();
               Draw(width,height);
           glPopMatrix();
        break;

        case RUNL:
           glPushMatrix();
               //glTranslated(getPosition().x,getPosition().y,-1.0);

               if(T->getTicks()>70)
                {
                    //mX-=xSpeed;
                    runspeed++;
                    runspeed = runspeed %5;
                    T->reset();
                }

               ErunLeft[runspeed].binder();
               Draw(width,height);
           glPopMatrix();
        break;

       case STANDL://stdL
            glPushMatrix();
                //glTranslated(getPosition().x,getPosition().y,-1.0);

                if(T->getTicks()>300)
                {
                    runspeed++;
                    runspeed = runspeed %6;
                    T->reset();
                }

                EstandL[runspeed].binder();
                Draw(width,height);
            glPopMatrix();
        break;

        case ATKR://stdL
            glPushMatrix();
                //glTranslated(getPosition().x,getPosition().y,-1.0);

                if(T->getTicks()>100)
                {
                    runspeed++;
                    runspeed = runspeed %6;
                    T->reset();
                }

                EatkR[runspeed].binder();
                Draw(width,height);
            glPopMatrix();
        break;

        case ATKL://stdL
            glPushMatrix();
                //glTranslated(getPosition().x,getPosition().y,-1.0);

                if(T->getTicks()>100)
                {
                    runspeed++;
                    runspeed = runspeed %6;
                    T->reset();
                }

                EatkL[runspeed].binder();
                Draw(width,height);
            glPopMatrix();
        break;
     }
}
