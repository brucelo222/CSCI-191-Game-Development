#include "GLScene.h"
#include <GLLight.h>
#include <Model.h>
#include <Inputs.h>
//#include <parallax.h>
#include <player.h>
#include <skyBox.h>
//#include <fallingObject.h>
#include<sounds.h>

/**************************** New Creations ***************************/
Model *modelTeapot = new Model();
Inputs *KbMs = new Inputs();

player *ply = new player();
skyBox *sky = new skyBox;

sounds *music = new sounds();


int goSet = 0;
int setPro = 0;
/**********************************************************************/

GLScene::GLScene()
{
    //ctor
    screenHeight= GetSystemMetrics(SM_CYSCREEN);
    screenWidth = GetSystemMetrics(SM_CXSCREEN);


init = false;


}

GLScene::~GLScene()
{
    //dtor
}

GLint GLScene::initGL()
{
    glShadeModel(GL_SMOOTH);
    glClearColor(0.0f,0.0f,0.0f,0.0f);
    glClearDepth(1.0f);
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);

   // glEnable(GL_COLOR_MATERIAL);
    GLLight SetLight(GL_LIGHT0);
    GLLight Light(GL_LIGHT0);

    modelTeapot->modelInit("images/player/player0.png",true);

    ply->playerInit();
    //sky->loadTextures();


/*** Create Init ***/
    stg1->parallaxInit("images/stg1.png");
    fog->parallaxInit("images/fogscroll.png");
    stg1_1->parallaxInit("images/stg1-1.png");
    fog2->parallaxInit("images/fogscroll.png");
    stg1_2->parallaxInit("images/stg1-2.png");
    music->initSounds();
    music->playMusic("bgm/seisai.mp3");

    fRock->fallingObjectInit("images/rock.png");
    fRock1->fallingObjectInit("images/rock.png");
    fRock2->fallingObjectInit("images/rock.png");
    fRock3->fallingObjectInit("images/rock.png");
    fRock4->fallingObjectInit("images/rock.png");
    fRock5->fallingObjectInit("images/rock.png");



return true;
}//end GL init

/*****************--DRAW SCENES--********************************/
GLint GLScene::drawGLScene()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	// Clear Screen And Depth Buffer
	glLoadIdentity();									// Reset The Current Modelview Matrix


 /*   glPushMatrix();
        glDisable(GL_LIGHTING);
        glScaled(200,200,200);
        sky->drawBox();
        glEnable(GL_LIGHTING);
    glPopMatrix();   */


/******** Stage 1 ******/

switch(setPro){
case 0:
    glPushMatrix();
    glScaled(3.33,3.33,1.0);
    fog->drawSquare(screenWidth,screenHeight);
    fog->scroll(true,"right",0.005); //True = Scroll
    glPopMatrix();

  glPushMatrix();
    glScaled(3.33,3.33,1.0);
    stg1->drawSquare(screenWidth,screenHeight);
    //fog->scroll(false,"right",0.005); //True = Scroll
    glPopMatrix();

    //--Player
    glPushMatrix();
    glScaled(1.0,1.0,1.0);
            glTranslated(0,0,modelTeapot->Zoom);
        ply->actions(ply->actionTrigger);
    glPopMatrix();

        if(ply->mX >= 3.0){
            goSet = 1;
            setPro =1;
            ply->resetPos();
        }

        cout<<ply->mX<<endl;
        cout<<goSet<<endl;

break;





case 1:

    glPushMatrix();
    glScaled(3.33,3.33,1.0);
    fog2->drawSquare(screenWidth,screenHeight);
    fog2->scroll(true,"right",0.005); //True = Scroll
    //std::cout<<"made it"<<endl;
    glPopMatrix();

    glPushMatrix();
    glScaled(3.33,3.33,1.0);
    stg1_1->drawSquare(screenWidth,screenHeight);
    glPopMatrix();

    //--Player
    glPushMatrix();
    glTranslated(0,0,modelTeapot->Zoom);
    ply->actions(ply->actionTrigger);
    glPopMatrix();

    /*if(ply->mX == -5.0){
            goSet = 0;
            setPro =0;
             ply->resetPos();
        }*/


        if(ply->mX >= 3.0){
            goSet = 2;
            setPro =2;
            ply->resetPos();
        }

        cout<<ply->mX<<endl;
        cout<<goSet<<endl;

    break;

    case 2:


    glPushMatrix();
    glScaled(3.33,3.33,1.0);
    stg1_2->drawSquare(screenWidth,screenHeight);
    glPopMatrix();

    //--Player
    glPushMatrix();
    glTranslated(0,0,modelTeapot->Zoom);
    ply->actions(ply->actionTrigger);
    glPopMatrix();

    glPushMatrix();
      glScaled(0.33,0.33,1.0);
      fRock->fallingObjectUpdate();
      fRock1->fallingObjectUpdate();
      fRock2->fallingObjectUpdate();
      fRock3->fallingObjectUpdate();
      fRock4->fallingObjectUpdate();
      fRock5->fallingObjectUpdate();
      glPopMatrix();

    if(ply->mX == -5.0){
            goSet = 0;
            setPro =0;
             ply->resetPos();
        }

        cout<<ply->mX<<endl;
        cout<<goSet<<endl;

    break;




}

}//end GL draw


/*
glPushMatrix();
//glDisable(GL_TEXTURE_2D);
glTranslated();
//glEnable(GL_TEXTURE_2D);
glPopMatrix();

*/

/**********--Window Resize--************************************/
GLvoid GLScene::resizeGLScene(GLsizei width, GLsizei height)
{
   GLfloat aspectRatio = (GLfloat)width/(GLfloat)height;
   glViewport(0,0,width,height);
   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   gluPerspective(45.0,aspectRatio,0.1,1000);

   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();
}

/*****************--Window Msgs--********************************************/
int GLScene::windMsg(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch (uMsg)									// Check For Windows Messages
	{

	    case WM_KEYDOWN:
	        KbMs->wParam = wParam;
	        KbMs->keyPressed(modelTeapot);
	        KbMs->keyEnv(stg1, 0.005);
	        KbMs->keyPressed(ply);
	        KbMs->keyPressed(sky);
	        KbMs->keySound(music);

	    break;

	    case WM_KEYUP:								// Has A Key Been Released?
		{
			KbMs->wParam = wParam;
			KbMs->keyUP();
			KbMs->keyUp(ply);
		break;								// Jump Back
		}

		case WM_LBUTTONDOWN:
        {
            KbMs->wParam = wParam;
            KbMs->mouseEventDown(modelTeapot,LOWORD(lParam),HIWORD(lParam));
        break;								// Jump Back
        }

   		case WM_RBUTTONDOWN:
        {
            KbMs->wParam = wParam;
            KbMs->mouseEventDown(modelTeapot,LOWORD(lParam),HIWORD(lParam));
        break;								// Jump Back
        }

          case WM_MBUTTONDOWN:
        {
            KbMs->wParam = wParam;
            KbMs->mouseEventDown(modelTeapot,LOWORD(lParam),HIWORD(lParam));
        break;								// Jump Back
        }

        case WM_LBUTTONUP:
        case WM_RBUTTONUP:
        case WM_MBUTTONUP:
        {
            KbMs->mouseEventUp();
        break;								// Jump Back
        }

        case WM_MOUSEMOVE:
        {
             KbMs->mouseMove(modelTeapot, LOWORD(lParam),HIWORD(lParam));
             KbMs->mouseMove(sky,LOWORD(lParam),HIWORD(lParam));
        break;								// Jump Back
        }

        case WM_MOUSEWHEEL:
        {
            KbMs->mouseWheel(modelTeapot,(double)GET_WHEEL_DELTA_WPARAM(wParam));
        break;								// Jump Back
        }
}
}
