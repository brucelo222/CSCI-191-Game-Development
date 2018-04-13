#include <player.h>
#include <timer.h>
#include <textureLoader.h>
#include <iostream>
using namespace std;


timer *T = new timer();


textureLoader runRight[5];
textureLoader runLeft[5];
textureLoader standL[3];
textureLoader standR[3];
textureLoader atkR[3];
textureLoader atkL[3];
textureLoader jmpR[3];
textureLoader jmpL[3];





player::player()
{
    //ctor
    verticies[0].x = 0.0;verticies[0].y = 0.0;verticies[0].z = -1.0;
    verticies[1].x = 1.0;verticies[1].y = 0.0;verticies[1].z = -1.0;
    verticies[2].x = 1.0;verticies[2].y = 1.0;verticies[2].z = -1.0;
    verticies[3].x = 0.0;verticies[3].y = 1.0;verticies[3].z = -1.0;

    runspeed  = 0;
    jumpspeed = 0;
    actionTrigger = 0;

    mX = -4.48;
    mY = -2.05;
    maxMX= 1.0;
    maxMY = 1.0;
    xSpeed = 0.08;
    ySpeed = 0.0;

    //Jump Phys
   gravity;
 jpVelo = 0.2;
 jpGround = -2.0;
 isJump = false;


}

player::~player()
{
    //dtor
}
void player::drawPlayer()
{
    //glColor3f(1.0,0.0,0.0);
   // glPushMatrix();
   glScaled(3.3,3.3,1.0);
  glBegin(GL_QUADS);

    glTexCoord2f(0.0,1.0);
    glVertex3f(verticies[0].x,verticies[0].y,verticies[0].z);

    glTexCoord2f(1.0,1.0);
    glVertex3f(verticies[1].x,verticies[1].y,verticies[1].z);

    glTexCoord2f(1.0,0.0);
    glVertex3f(verticies[2].x,verticies[2].y,verticies[2].z);

    glTexCoord2f(0.0,0.0);
    glVertex3f(verticies[3].x,verticies[3].y,verticies[3].z);

    glEnd();

    //glPopMatrix();
}

void player::playerInit()
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

   atkL[0].bindTexture("images/hero/tile006.png");
   atkL[1].bindTexture("images/hero/tile007.png");
   atkL[2].bindTexture("images/hero/tile008.png");

   atkR[0].bindTexture("images/hero/tile011.png");
   atkR[1].bindTexture("images/hero/tile010.png");
   atkR[2].bindTexture("images/hero/tile009.png");

   jmpR[0].bindTexture("images/hero/tile012.png");
   jmpR[1].bindTexture("images/hero/tile013.png");
   jmpR[2].bindTexture("images/hero/tile014.png");

   jmpL[0].bindTexture("images/hero/tile017.png");
   jmpL[1].bindTexture("images/hero/tile016.png");
   jmpL[2].bindTexture("images/hero/tile015.png");







}


void player::resetPos()
{
    mX = -4.48;
}
float player::getPlyPosY()
{
    return mY;
}
void player::actions(int action)
{
   switch(action){
   case 0://stdR

       glPushMatrix();
       glTranslated(mX,mY,-1.0);
       if(T->getTicks()>200){

        runspeed++;
        runspeed = runspeed %2;
        T->reset();
      }
       standR[runspeed].binder();
       drawPlayer();

       glPopMatrix();
       break;

   case 1:
       glPushMatrix();
       glTranslated(mX,mY,-1.0);

       if(T->getTicks()>90){
        mX+=xSpeed;
        runspeed++;
        runspeed = runspeed %2;
        T->reset();
       }

       runRight[runspeed].binder();
       drawPlayer();

       glPopMatrix();
       break;

    case 2:
       glPushMatrix();
       glTranslated(mX,mY,-1.0);

       if(T->getTicks()>90){
        mX-=xSpeed;
        runspeed++;
        runspeed = runspeed %2;
        T->reset();
       }
       runLeft[runspeed].binder();
       drawPlayer();

       glPopMatrix();
       break;

   case 3://stdL
      glPushMatrix();
       glTranslated(mX,mY,-1.0);
       if(T->getTicks()>200){

        runspeed++;
        runspeed = runspeed %2;
        T->reset();
      }
       standL[runspeed].binder();
       drawPlayer();

       glPopMatrix();
       break;


   case 4: //jump

       glPushMatrix();
       glTranslated(mX,mY,-1.0);
        isJump = true;
       if(T->getTicks()>20 && isJump == true){

         mY += jpVelo;

        T->reset();
       }

        if(mY >= 0.90){

                jpVelo += gravity;
        }

        if( mY <= jpGround){
           jpVelo = 0.0;
            mY = jpGround;

         //   cout<<isJump<<endl;
        }
        isJump = false;



       standR[3].binder();
       drawPlayer();
       glPopMatrix();

break;

 case 5://atkR
       glPushMatrix();
       glTranslated(mX,mY,-1.0);

       //if(T->getTicks()>100){

        runspeed++;
        runspeed = runspeed %2;

        //T->reset();
       //}

       atkR[runspeed].binder();
       drawPlayer();

       glPopMatrix();
       break;
 case 6://atkL
       glPushMatrix();
       glTranslated(mX,mY,-1.0);

       if(T->getTicks()>20){

        runspeed++;
        runspeed = runspeed %2;

        T->reset();
       }

       atkL[runspeed].binder();
       drawPlayer();

       glPopMatrix();
       break;
}
}

