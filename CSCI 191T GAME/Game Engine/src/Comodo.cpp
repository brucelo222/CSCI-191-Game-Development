#include "Comodo.h"

Comodo::Comodo()
{
    //ctor
    setPosition(14.0,0.0);
    setAction(STANDL);
    runspeed = 0;
    width = 2;
    height = 2;
    setHealth(50);
    isObjectLive = true;

    setMaxSpeed(0.01,0.1);
    setVelocity(0.0,0.0);
}

Comodo::~Comodo()
{
    //dtor
}

void Comodo::chase(Vec2 playerPosition)
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

void Comodo::wander()
{

}

void Comodo::patrol()
{

}

void Comodo::idle()
{
    setAction(STANDL);
return;
}

void Comodo::attack(Vec2 playerPosition)
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

void Comodo::Init()
{
    _hitbox->init(getPosition(),0.75,0.75);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);//trans
    T->start();

    CatkR[0].bindTexture("images/enemy/bapho/ar1.png");
    CatkR[1].bindTexture("images/enemy/bapho/ar2.png");
    CatkR[2].bindTexture("images/enemy/bapho/ar3.png");
    CatkR[3].bindTexture("images/enemy/bapho/ar4.png");
    CatkR[4].bindTexture("images/enemy/bapho/ar5.png");
    CatkR[5].bindTexture("images/enemy/bapho/ar6.png");

    CatkL[0].bindTexture("images/enemy/bapho/al1.png");
    CatkL[1].bindTexture("images/enemy/bapho/al2.png");
    CatkL[2].bindTexture("images/enemy/bapho/al3.png");
    CatkL[3].bindTexture("images/enemy/bapho/al4.png");
    CatkL[4].bindTexture("images/enemy/bapho/al5.png");
    CatkL[5].bindTexture("images/enemy/bapho/al6.png");

    CstandR[0].bindTexture("images/enemy/bapho/ar1.png");

    CstandL[0].bindTexture("images/enemy/bapho/al1.png");

    CrunLeft[0].bindTexture("images/enemy/bapho/l1.PNG");
    CrunLeft[1].bindTexture("images/enemy/bapho/l2.png");
    CrunLeft[2].bindTexture("images/enemy/bapho/l3.png");
    CrunLeft[3].bindTexture("images/enemy/bapho/l4.png");

    CrunRight[0].bindTexture("images/enemy/bapho/r1.png");
    CrunRight[1].bindTexture("images/enemy/bapho/r2.png");
    CrunRight[2].bindTexture("images/enemy/bapho/r3.png");
    CrunRight[3].bindTexture("images/enemy/bapho/r4.png");
    return;
}

void Comodo::Update(Vec2 playerPOS)
{
if(isObjectLive)
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

    if(getPosition().y > -5)
    {
       float Y = _gravity->applyGravity(getPosition().y);
       setPosition(getPosition().x,Y);
    }
    //call switch of AI states the preform the logic
    aiManager(playerPOS, getPosition());
    //glTranslated(getPosition().x,getPosition().y, -1.0);
    }
}

void Comodo::actions()
{
    switch(getAction())
     {
       case STANDR://stdR

           glPushMatrix();
           //glTranslated(getPosition().x,getPosition().y,-1.0);
           if(T->getTicks()>200){

            runspeed++;
            runspeed = runspeed %1;
            T->reset();
          }
           CstandR[runspeed].binder();
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
                    runspeed = runspeed %4;
                    T->reset();
                }

               CrunRight[runspeed].binder();
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
                    runspeed = runspeed %4;
                    T->reset();
                }

               CrunLeft[runspeed].binder();
                    Draw(width,height);
           glPopMatrix();
        break;

       case STANDL://stdL
            glPushMatrix();
                //glTranslated(getPosition().x,getPosition().y,-1.0);

                if(T->getTicks()>300)
                {
                    runspeed++;
                    runspeed = runspeed %1;
                    T->reset();
                }

                CstandL[runspeed].binder();
                     Draw(width,height);
            glPopMatrix();
        break;

        case ATKR://stdL
            glPushMatrix();
                //glTranslated(getPosition().x,getPosition().y,-1.0);

                if(T->getTicks()>100)
                {
                    runspeed++;
                    runspeed = runspeed %5;
                    T->reset();
                }

                CatkR[runspeed].binder();
                     Draw(width,height);
            glPopMatrix();
        break;

        case ATKL://stdL
            glPushMatrix();
                //glTranslated(getPosition().x,getPosition().y,-1.0);

                if(T->getTicks()>100)
                {
                    runspeed++;
                    runspeed = runspeed %5;
                    T->reset();
                }

                CatkL[runspeed].binder();
                     Draw(width,height);
            glPopMatrix();
        break;
     }
}

