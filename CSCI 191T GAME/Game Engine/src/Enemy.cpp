#include "Enemy.h"
#include "Player.h"

#include <GL/gl.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

Enemy::Enemy()
{
    //ctor
    setPosition(10.0,0.0);
    setAction(STANDL);
    runspeed = 0;
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
            setPosition(getPosition().x + .001*(playerPosition.x - getPosition().x),getPosition().y);
        }
        else
        {
            setAction(RUNL);
            setPosition(getPosition().x + .001*(playerPosition.x - getPosition().x),getPosition().y);
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
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);//trans
    T->start();

    EatkR[0].bindTexture("images/hero/tile011.png");
    EatkR[1].bindTexture("images/hero/tile010.png");
    EatkR[2].bindTexture("images/hero/tile009.png");

    EatkL[0].bindTexture("images/hero/tile006.png");
    EatkL[1].bindTexture("images/hero/tile007.png");
    EatkL[2].bindTexture("images/hero/tile008.png");

    EstandR[0].bindTexture("images/hero/tile005.png");
    EstandR[1].bindTexture("images/hero/tile004.png");
    EstandR[2].bindTexture("images/hero/tile003.png");

    EstandL[0].bindTexture("images/hero/tile000.png");
    EstandL[1].bindTexture("images/hero/tile001.png");
    EstandL[2].bindTexture("images/hero/tile002.png");

    ErunLeft[0].bindTexture("images/hero/tile018.png");
    ErunLeft[1].bindTexture("images/hero/tile019.png");
    ErunLeft[2].bindTexture("images/hero/tile020.png");
    ErunLeft[3].bindTexture("images/hero/tile021.png");
    ErunLeft[4].bindTexture("images/hero/tile022.png");

    ErunRight[0].bindTexture("images/hero/tile028.png");
    ErunRight[1].bindTexture("images/hero/tile027.png");
    ErunRight[2].bindTexture("images/hero/tile026.png");
    ErunRight[3].bindTexture("images/hero/tile025.png");
    ErunRight[4].bindTexture("images/hero/tile024.png");
    return;
}

void Enemy::Update(Vec2 playerPOS)
{
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
   // cout<<getAction()<<endl;
    switch(getAction())
     {
       case STANDR://stdR

           glPushMatrix();
           //glTranslated(getPosition().x,getPosition().y,-1.0);
           if(T->getTicks()>200){

            runspeed++;
            runspeed = runspeed %4;
            T->reset();
          }
           EstandR[runspeed].binder();
           Draw();

           glPopMatrix();
           break;

       case RUNR:
           glPushMatrix();
               //glTranslated(getPosition().x,getPosition().y,-1.0);

               if(T->getTicks()>90)
                {
                  //  mX+=xSpeed;
                    runspeed++;
                    runspeed = runspeed %4;
                    T->reset();
                }

               ErunRight[runspeed].binder();
               Draw();
                cout<<"made it\n";
           glPopMatrix();
        break;

        case RUNL:
           glPushMatrix();
               //glTranslated(getPosition().x,getPosition().y,-1.0);

               if(T->getTicks()>90)
                {
                    //mX-=xSpeed;
                    runspeed++;
                    runspeed = runspeed %3;
                    T->reset();
                }

               ErunLeft[runspeed].binder();
               Draw();
           glPopMatrix();
        break;

       case STANDL://stdL
            glPushMatrix();
                //glTranslated(getPosition().x,getPosition().y,-1.0);

                if(T->getTicks()>200)
                {
                    runspeed++;
                    runspeed = runspeed %3;
                    T->reset();
                }

                EstandL[runspeed].binder();
                Draw();
            glPopMatrix();
        break;

        case ATKR://stdL
            glPushMatrix();
                //glTranslated(getPosition().x,getPosition().y,-1.0);

                if(T->getTicks()>200)
                {
                    runspeed++;
                    runspeed = runspeed %3;
                    T->reset();
                }

                EatkR[runspeed].binder();
                Draw();
            glPopMatrix();
        break;

        case ATKL://stdL
            glPushMatrix();
                //glTranslated(getPosition().x,getPosition().y,-1.0);

                if(T->getTicks()>200)
                {
                    runspeed++;
                    runspeed = runspeed %3;
                    T->reset();
                }

                EatkL[runspeed].binder();
                Draw();
            glPopMatrix();
        break;
     }
}
