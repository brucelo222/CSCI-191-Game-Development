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

    CatkR[0].bindTexture("images/enemy/lizard/ar1.png");
    CatkR[1].bindTexture("images/enemy/lizard/ar2.png");
    CatkR[2].bindTexture("images/enemy/lizard/ar3.png");
    CatkR[3].bindTexture("images/enemy/lizard/ar4.png");
    CatkR[4].bindTexture("images/enemy/lizard/ar5.png");
    CatkR[5].bindTexture("images/enemy/lizard/ar6.png");

    CatkL[0].bindTexture("images/enemy/lizard/atkl01.PNG");
    CatkL[1].bindTexture("images/enemy/lizard/al2.png");
    CatkL[2].bindTexture("images/enemy/lizard/al3.png");
    CatkL[3].bindTexture("images/enemy/lizard/al4.png");
    CatkL[4].bindTexture("images/enemy/lizard/al5.png");
    CatkL[5].bindTexture("images/enemy/lizard/al6.png");

    CstandR[0].bindTexture("images/enemy/lizard/ir1.png");
    CstandR[1].bindTexture("images/enemy/lizard/ir2.png");

    CstandL[0].bindTexture("images/enemy/lizard/il1.png");
    CstandL[1].bindTexture("images/enemy/lizard/il2.png");

    CrunLeft[0].bindTexture("images/enemy/lizard/l1.PNG");
    CrunLeft[1].bindTexture("images/enemy/lizard/l2.png");
    CrunLeft[2].bindTexture("images/enemy/lizard/l3.png");
    CrunLeft[3].bindTexture("images/enemy/lizard/l4.png");
    CrunLeft[4].bindTexture("images/enemy/lizard/l5.png");
    CrunLeft[5].bindTexture("images/enemy/lizard/l6.png");

    CrunRight[0].bindTexture("images/enemy/lizard/r1.png");
    CrunRight[1].bindTexture("images/enemy/lizard/r2.png");
    CrunRight[2].bindTexture("images/enemy/lizard/r3.png");
    CrunRight[3].bindTexture("images/enemy/lizard/r4.png");
    CrunRight[4].bindTexture("images/enemy/lizard/r5.png");
    CrunRight[5].bindTexture("images/enemy/lizard/r6.png");
    return;
}

void Comodo::Update(Vec2 playerPOS)
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


void Comodo::actions()
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
                    runspeed = runspeed %6;
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
                    runspeed = runspeed %6;
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
                    runspeed = runspeed %2;
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
                    runspeed = runspeed %6;
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
                    runspeed = runspeed %6;
                    T->reset();
                }

                CatkL[runspeed].binder();
                     Draw(width,height);
            glPopMatrix();
        break;
     }
}

