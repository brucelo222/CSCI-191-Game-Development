
#include "Player.h"

#include <GL/gl.h>
#include <iostream>
Player::Player()
{
    //ctor
    setPosition(-6.0,-4.5);
    //setPosition(-19.5,0);

    hasJump = true;
    setAction(STANDR);
    bool isAttacking = false;
    isJump=false;
    leftStop=false;
    rightStop=false;
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
   isJump=false;
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

        case ATKR://stdL
            glPushMatrix();
                //glTranslated(getPosition().x,getPosition().y,-1.0);

                if(T->getTicks()>200)
                {
                    runspeed++;
                    if (runspeed == 3)
                    {
                        setAttacking(false);
                    }
                    runspeed = runspeed %3;
                    T->reset();
                }
                atkR[runspeed].binder();
                Draw();
            glPopMatrix();
        break;

        case ATKL://stdL
            glPushMatrix();
                //glTranslated(getPosition().x,getPosition().y,-1.0);

                if(T->getTicks()>200)
                {
                    if (runspeed == 3)
                    {
                        setAttacking(false);
                    }

                    runspeed++;
                    runspeed = runspeed %3;
                    T->reset();
                }

                atkL[runspeed].binder();
                Draw();
            glPopMatrix();
        break;

    case JUMP:

     glPushMatrix();
        if(isJump==false){

            maxMY=this->getPosition().y+1.5;
            falling=this->getPosition().y;
            isJump=true;
            isFalling=false;
        }
        //glTranslated(mX,mY,-1.0);
        if(isJump==true&&this->getPosition().y<=maxMY&&isFalling==false){


            this->setPosition(this->getPosition().x,this->getPosition().y+0.04);

            if(this->getPosition().y>=maxMY){
                this->isFalling=true;
                            }
        }
        else if(isJump==true){

            this->setPosition(this->getPosition().x,this->getPosition().y-0.04);

        }
        else{

             this->setPosition(this->getPosition().x,falling);
             isJump=false;
            }



        if(this->getPosition().y<=falling+0.13&&isFalling==false){
            if(this->getDirection()==0){
            jmpL[0].binder();
            }
            else{
            jmpR[0].binder();
            }
        }
        else if(this->getPosition().y<=falling+0.40&&isFalling==false){
            if(this->getDirection()==0){
            jmpL[1].binder();
            }
            else{
            jmpR[1].binder();
            }

        }
        else{
             if(this->getDirection()==0){
            jmpL[2].binder();
            }
            else{
            jmpR[2].binder();
            }
        }

       Draw();

       glPopMatrix();

    break;
    case JUMPLEFT:
        glPushMatrix();

        //glTranslated(mX,mY,-1.0);
        if(isJump==true&&this->getPosition().y<=maxMY&&isFalling==false){


            this->setPosition(this->getPosition().x-0.03,this->getPosition().y+0.04);

            if(this->getPosition().y>=maxMY){
                isFalling=true;
                            }
        }
       // else if(isJump==true&&this->getPosition().y>=falling){
    else if(isJump==true){
            this->setPosition(this->getPosition().x-0.03,this->getPosition().y-0.04);

        }
        /*else{

             this->setPosition(this->getPosition().x,falling);
             isJump=false;
            }*/
        if(this->getPosition().y<=falling+0.13&&isFalling==false){
            if(this->getDirection()==0){
            jmpL[0].binder();
            }
            else{
            jmpR[0].binder();
            }
        }
        else if(this->getPosition().y<=falling+0.40&&isFalling==false){
            if(this->getDirection()==0){
            jmpL[1].binder();
            }
            else{
            jmpR[1].binder();
            }

        }
        else{
             if(this->getDirection()==0){
            jmpL[2].binder();
            }
            else{
            jmpR[2].binder();
            }
        }

       Draw();

       glPopMatrix();

    break;
    case JUMPRIGHT:
        glPushMatrix();

        //glTranslated(mX,mY,-1.0);
        if(isJump==true&&this->getPosition().y<=maxMY&&isFalling==false){


            this->setPosition(this->getPosition().x+0.03,this->getPosition().y+0.04);

            if(this->getPosition().y>=maxMY){
                isFalling=true;
                            }
        }
        //else if(isJump==true&&this->getPosition().y>=falling){
                 else if(isJump==true){


            this->setPosition(this->getPosition().x+0.03,this->getPosition().y-0.04);

        }
        /*
        else{

             this->setPosition(this->getPosition().x,falling);
             isJump=false;
            }*/
        if(this->getPosition().y<=falling+0.13&&isFalling==false){
            if(this->getDirection()==0){
            jmpL[0].binder();
            }
            else{
            jmpR[0].binder();
            }
        }
        else if(this->getPosition().y<=falling+0.40&&isFalling==false){
            if(this->getDirection()==0){
            jmpL[1].binder();
            }
            else{
            jmpR[1].binder();
            }

        }
        else{
             if(this->getDirection()==0){
            jmpL[2].binder();
            }
            else{
            jmpR[2].binder();
            }
        }

       Draw();

       glPopMatrix();

    break;
    case FREEFALL:
     glPushMatrix();

    if(this->getPosition().y<=falling+0.13&&isFalling==false){
            if(this->getDirection()==0){
            jmpL[0].binder();
            }
            else{
            jmpR[0].binder();
            }

        }
        else if(this->getPosition().y<=falling+0.40&&isFalling==false){

            if(this->getDirection()==0){
            jmpL[1].binder();
            }
            else{
            jmpR[1].binder();
            }
        }
        else{

          if(this->getDirection()==0){
            jmpL[2].binder();
            }
            else{
            jmpR[2].binder();
            }
        }

       Draw();

       glPopMatrix();


    break;
    case UP:

    break;
}

}
