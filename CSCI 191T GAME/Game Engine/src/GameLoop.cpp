#include "GameLoop.h"

#include <iostream>

GameLoop::GameLoop()
{
    //ctor
    _screenHeight= GetSystemMetrics(SM_CYSCREEN);
    _screenWidth = GetSystemMetrics(SM_CXSCREEN);
    gameState = PLAY;
}

GameLoop::~GameLoop()
{
    //dtor
}

GLint GameLoop::Initialize()
{
    glShadeModel(GL_SMOOTH);
    glClearColor(0.0f,0.0f,0.0f,0.0f);
    glClearDepth(1.0f);
    glEnable(GL_DEPTH_TEST);
    glDisable(GL_COLOR_MATERIAL);
    glDepthFunc(GL_LEQUAL);

    _backgroundTexture->bindTexture("images/bak.jpg");
    _player->Init();
    _enemy->Init();
    //_leftPlayer->bindTexture("images/volcano.jpg");
    return true;
}

GLvoid GameLoop::resizeScreen(GLsizei width, GLsizei height)
{
    GLfloat aspectRatio = (GLfloat)width/(GLfloat)height;
    glViewport(0,0,width,height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60.0,aspectRatio,0.1,1000);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}


void GameLoop::Render()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glLoadIdentity();

    //render Camera
    _camera->updateCameraPosition(_player->getPosition().x, _player->getPosition().y);
    _camera->moveCamera();

    //switch to model matrix
    glMatrixMode(GL_MODELVIEW);

    //draw Background
    glPushMatrix();
   // glDisable(GL_TEXTURE_2D);
    glColor3f(1.0,1.0,1.0);
    _backgroundTexture->binder();
    glTranslated(0.0,0.0,-2.0);
    _shape->drawQuad(50.0,15.0,-2.0,Color(1.0,1.0,1.0,1.0));
    glEnable(GL_TEXTURE_2D);
    glPopMatrix();

    //draw Player
    glPushMatrix();
    _player->actions();
    glPopMatrix();

    //draw Enemy
    glPushMatrix();
    _enemy->actions();
    glPopMatrix();

    glPushMatrix();
    glDisable(GL_TEXTURE_2D);
    glTranslated(0.0,0.0,-1.0);
    p->generateParticles();
    p->draw();
    p->lifeTime();
    glColor3f(1.0,1.0,1.0);
    glEnable(GL_TEXTURE_2D);
    glPopMatrix();

}

void GameLoop::Update()
{
    _player->Update();
    _enemy->Update(_player->getPosition());
}

void GameLoop::winInputs(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
     switch (uMsg)									// Check For Windows Messages
	{
        //check if key is down
	    case WM_KEYDOWN:
	        _input->setWPARAM(wParam);
            _input->keyPressed(_player);
	    break;

        //check if a key has been released
	    case WM_KEYUP:
		{
		    _input->setWPARAM(wParam);
            _input->keyReleased(_player);
		break;
        }

        case WM_LBUTTONDOWN:
        {
        //    _input->setWPARAM(wParam);
        //    _input->mouseEvent(_player,LOWORD(lParam),HIWORD(lParam));

        break;								// Jump Back
        }

        case WM_MOUSEMOVE:
        {
            std::cout<<LOWORD(lParam)<<" "<<HIWORD(lParam)<<std::endl;
            _input->setMouseCoords(_player,LOWORD(lParam),HIWORD(lParam));
        break;								// Jump Back
        }
	}
}

GLint GameLoop::gameLoop()
{
//start fps limiter
    //Input(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

    //update game objects
    //set camera on player
    //std::cout<<"x pos: "<< _player->getPosition().x<<std::endl<<"y pos: "<<_player->getPosition().y<<std::endl;

  //  glLoadIdentity();
    //update physics
    Update();
    //render game scene
    Render();
    //end fps limiter
}


