#include "Player.h"

#include <GL/gl.h>

Player::Player()
{
    //ctor
    setPosition(10.0,0.0);
    hasJump = true;
    setAction(STANDR);
}

Player::~Player()
{
    //dtor
}

void Player::Init()
{
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);//trans
    T->start();

    standR[0].bindTexture("images/hero/tile005.png");
    standR[1].bindTexture("images/hero/tile004.png");
    standR[2].bindTexture("images/hero/tile003.png");

    standL[0].bindTexture("images/hero/tile000.png");
    standL[1].bindTexture("images/hero/tile001.png");
    standL[2].bindTexture("images/hero/tile002.png");

    runLeft[0].bindTexture("images/hero/tile018.png");
    runLeft[1].bindTexture("images/hero/tile019.png");
    runLeft[2].bindTexture("images/hero/tile020.png");
    runLeft[3].bindTexture("images/hero/tile021.png");
    runLeft[4].bindTexture("images/hero/tile022.png");

    runRight[0].bindTexture("images/hero/tile028.png");
    runRight[1].bindTexture("images/hero/tile027.png");
    runRight[2].bindTexture("images/hero/tile026.png");
    runRight[3].bindTexture("images/hero/tile025.png");
    runRight[4].bindTexture("images/hero/tile024.png");
}

void Player::Update()
{
//    _tex->binder();
    glTranslated(getPosition().x,getPosition().y,-1.0);
    //apply physics
    if(getPosition().y > 0)
    {
       float Y = _gravity.applyGravity(getPosition().y);
       setPosition(getPosition().x,Y);
    }
}

void Player::actions()
{
     switch(getAction())
     {
       case STANDR://stdR

           glPushMatrix();
           //glTranslated(getPosition().x,getPosition().y,-1.0);
           if(T->getTicks()>200){

            runspeed++;
            runspeed = runspeed %2;
            T->reset();
          }
           standR[runspeed].binder();
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
                    runspeed = runspeed %2;
                    T->reset();
                }

               runRight[runspeed].binder();
               Draw();

           glPopMatrix();
        break;

        case RUNL:
           glPushMatrix();
               //glTranslated(getPosition().x,getPosition().y,-1.0);

               if(T->getTicks()>90)
                {
                    //mX-=xSpeed;
                    runspeed++;
                    runspeed = runspeed %2;
                    T->reset();
                }

               runLeft[runspeed].binder();
               Draw();
           glPopMatrix();
        break;

       case STANDL://stdL
            glPushMatrix();
                //glTranslated(getPosition().x,getPosition().y,-1.0);

                if(T->getTicks()>200)
                {
                    runspeed++;
                    runspeed = runspeed %2;
                    T->reset();
                }

                standL[runspeed].binder();
                Draw();
            glPopMatrix();
        break;
     }
}


