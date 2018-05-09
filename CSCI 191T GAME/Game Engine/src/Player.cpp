#include "Player.h"

#include <GL/gl.h>
#include <iostream>

using namespace std;

Player::Player()
{
    //ctor
    setPosition(10.0,0.0);
    hasJump = true;
    setAction(STANDR);
    bool isAttacking = false;
    width = 2.5;
    height = 2.5;
    setHealth(100);
    isObjectLive = true;

    _hitbox->active = true;
    _hurtbox->active = false;
    atkDistance = 1;

    setVelocity(0,0);
    setMaxSpeed(.3,.2);
}

Player::~Player()
{
    //dtor
}

void Player::Init()
{
    _hitbox->init(getPosition(),0.25,0.25);
    _hurtbox->init(getPosition(), 0.25,0.25);

    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);//trans
    T->start();

    atkR[0].bindTexture("images/hero/tile011.png");
    atkR[1].bindTexture("images/hero/tile010.png");
    atkR[2].bindTexture("images/hero/tile009.png");

    atkL[0].bindTexture("images/hero/tile006.png");
    atkL[1].bindTexture("images/hero/tile007.png");
    atkL[2].bindTexture("images/hero/tile008.png");

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

    jmpL[0].bindTexture("images/hero/tile012.png");
    jmpL[1].bindTexture("images/hero/tile013.png");
    jmpL[2].bindTexture("images/hero/tile014.png");

    jmpR[0].bindTexture("images/hero/tile017.png");
    jmpR[1].bindTexture("images/hero/tile016.png");
    jmpR[2].bindTexture("images/hero/tile015.png");
}

void Player::Update()
{
    _hitbox->update(getPosition());

    if(getAttacking())
    {
    //    actions();
    }
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
            runspeed = runspeed %3;
            T->reset();
          }
           standR[runspeed].binder();
           glPopMatrix();
           break;

       case RUNR:
           glPushMatrix();

               if(T->getTicks()>90)
                {
                    //move pos
                    setPosition(getPosition().x + Accelerate(), getPosition().y);
                    runspeed++;
                    runspeed = runspeed %2;
                    T->reset();
                }

               runRight[runspeed].binder();
           glPopMatrix();
        break;

        case RUNL:
           glPushMatrix();
               //glTranslated(getPosition().x,getPosition().y,-1.0);

               if(T->getTicks()>90)
                {
                    //move pos
                    setPosition(getPosition().x - Accelerate(), getPosition().y);
                    runspeed++;
                    runspeed = runspeed %2;
                    T->reset();
                }

               runLeft[runspeed].binder();
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

                standL[runspeed].binder();
            glPopMatrix();
        break;

        case ATKR://stdL
            glPushMatrix();
                //glTranslated(getPosition().x,getPosition().y,-1.0);
                if(T->getTicks()>175)
                {
            _hurtbox->collider.x += 0.75;
            _hurtbox->active = true;
                    runspeed++;
                    if (runspeed == 3)
                    {
                        _hurtbox->collider.x = getPosition().x;
                        _hurtbox->active = false;
                        setAttacking(false);
                        setAction(STANDR);
                    }
                    runspeed = runspeed %3;
                    T->reset();
                }
                atkR[runspeed].binder();
            glPopMatrix();
        break;

        case ATKL://stdL
            glPushMatrix();
                //glTranslated(getPosition().x,getPosition().y,-1.0);
                if(T->getTicks()>175)
                {
                    _hurtbox->collider.x -= 0.75;
                    _hurtbox->active = true;
                    runspeed++;
                    if (runspeed == 3)
                    {
                        _hurtbox->collider.x = getPosition().x;
                        _hurtbox->active = false;
                        setAttacking(false);
                        setAction(STANDL);
                    }

                    runspeed = runspeed %3;

                    T->reset();
                }

                atkL[runspeed].binder();
            glPopMatrix();
        break;

    case JMPR:
        glPushMatrix();
            if(T->getTicks()>200)
            {
                runspeed++;
                runspeed = runspeed %3;
                T->reset();
            }

            jmpR[runspeed].binder();
        glPopMatrix();
    break;

    case JMPL:
        glPushMatrix();
            if(T->getTicks()>200)
            {
                runspeed++;
                runspeed = runspeed %3;
                T->reset();
            }

            jmpL[runspeed].binder();
        glPopMatrix();
    break;
    }
Draw(width,height);
}


