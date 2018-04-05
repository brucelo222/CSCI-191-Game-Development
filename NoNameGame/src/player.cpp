#include <player.h>
#include <timer.h>
#include <textureLoader.h>


timer *T = new timer();


textureLoader runRight[7];
textureLoader runLeft[7];
textureLoader standL;
textureLoader standR;
textureLoader stand;





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
   gravity = -0.6;
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
  //  glColor3f(1.0,0.0,0.0);
   // glPushMatrix();
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

 //   glPopMatrix();
}

void player::playerInit()
{
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);//trans
T->start();

   standR.bindTexture("images/temp/tile015.png");
    standL.bindTexture("images/temp/tile000.png");

    runLeft[0].bindTexture("images/temp/tile001.png");
    runLeft[1].bindTexture("images/temp/tile002.png");
   runLeft[2].bindTexture("images/temp/tile003.png");
   runLeft[3].bindTexture("images/temp/tile004.png");
   runLeft[4].bindTexture("images/temp/tile005.png");
   runLeft[5].bindTexture("images/temp/tile006.png");
   runLeft[6].bindTexture("images/temp/tile007.png");

    runRight[0].bindTexture("images/temp/tile014.png");
   runRight[1].bindTexture("images/temp/tile013.png");
   runRight[2].bindTexture("images/temp/tile012.png");
   runRight[3].bindTexture("images/temp/tile011.png");
   runRight[4].bindTexture("images/temp/tile010.png");
   runRight[5].bindTexture("images/temp/tile009.png");
   runRight[6].bindTexture("images/temp/tile008.png");

  /*stand.bindTexture("images/player/play.png");

    runRight[0].bindTexture("images/player/player0.png");
    runRight[1].bindTexture("images/player/player1.png");
    runRight[2].bindTexture("images/player/player2.png");
    runRight[3].bindTexture("images/player/player3.png");
    runRight[4].bindTexture("images/player/player4.png");
    runRight[5].bindTexture("images/player/player5.png");
    runRight[6].bindTexture("images/player/player6.png");
    runRight[7].bindTexture("images/player/player7.png");
    runRight[8].bindTexture("images/player/player8.png");
    runRight[9].bindTexture("images/player/player9.png");

    runLeft[0].bindTexture("images/player/Left0.png");
    runLeft[1].bindTexture("images/player/Left1.png");
    runLeft[2].bindTexture("images/player/Left2.png");
    runLeft[3].bindTexture("images/player/Left3.png");
    runLeft[4].bindTexture("images/player/Left4.png");
    runLeft[5].bindTexture("images/player/Left5.png");
    runLeft[6].bindTexture("images/player/Left6.png");
    runLeft[7].bindTexture("images/player/Left7.png");
    runLeft[8].bindTexture("images/player/Left8.png");
    runLeft[9].bindTexture("images/player/Left9.png");*/











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
   case 0:
       glPushMatrix();
       glTranslated(mX,mY,-1.0);
       standR.binder();
       //stand.binder();
      //  glutSolidTeapot(1.5);
       drawPlayer();
       glPopMatrix();
       break;

   case 1:
       glPushMatrix();
       glTranslated(mX,mY,-1.0);

       if(T->getTicks()>20){
        mX+=xSpeed;
        runspeed++;
        runspeed = runspeed %10;
        T->reset();
       }

       runRight[runspeed].binder();
       drawPlayer();

       glPopMatrix();
       break;

    case 2:
       glPushMatrix();
       glTranslated(mX,mY,-1.0);

       if(T->getTicks()>20){
        mX-=xSpeed;
        runspeed++;
        runspeed = runspeed %10;
        T->reset();
       }
       runLeft[runspeed].binder();
       drawPlayer();

       glPopMatrix();
       break;

   case 3:
       glPushMatrix();
       glTranslated(mX,mY,-1.0);
       standL.binder();
       drawPlayer();
       glPopMatrix();
       break;

   case 4: //jump

       glPushMatrix();
       glTranslated(mX,mY,-1.0);
        isJump = true;
       if(T->getTicks()>20 && isJump == true){

         mY+=jpVelo;

        T->reset();
       }





       // if((getPlyPosY() <jpGround) && (isJump = false))
              //  mY = gravity;

       standR.binder();
       drawPlayer();
       glPopMatrix();

break;
}
}

