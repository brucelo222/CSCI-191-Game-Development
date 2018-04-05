#include "stageChange.h"
#include <GLLight.h>
#include <Model.h>
#include <Inputs.h>
#include <parallax.h>
#include <player.h>
#include <skyBox.h>
#include <fallingObject.h>
#include <GLScene.h>

stageChange::stageChange()
{
    stagePro = 0;
}

stageChange::~stageChange()
{

    if(ply->Xpos == stage1->Xmax)
        stagePro = 1;

     switch (stagePro){

case 1:
     glPushMatrix();
    glScaled(3.33,3.33,1.0);
    plx->drawSquare(screenWidth,screenHeight);
    plx->scroll(false,"right",0.005); //True = Scroll
    glPopMatrix();

    //--Player
    glPushMatrix();
        glTranslated(0,0,modelTeapot->Zoom);
        ply->actions(ply->actionTrigger);
    glPopMatrix();

    //--Rocks
      glPushMatrix();
      glScaled(0.33,0.33,1.0);
      fRock->fallingObjectUpdate();
      fRock1->fallingObjectUpdate();
      fRock2->fallingObjectUpdate();
      fRock3->fallingObjectUpdate();
      fRock4->fallingObjectUpdate();
      fRock5->fallingObjectUpdate();
      glPopMatrix();
      break;





    }



}
