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


    _title->Init();

    _level1->Init(_player, "images/stg1-0/stg1.png");
    _level2->Init(_player,"images/stg1-1/stg1-1.png");
    _level3->Init(_player,"images/stg1-3/outside.png");

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
    _player->setPrevPosition(_player->getPosition().x,_player->getPosition().y);
    //render Camera
    //switch to model matrix
    glMatrixMode(GL_MODELVIEW);

    if(_sceneManager->getScene() == TITLE)
    {
        _camera->updateCameraPosition(_player->getPosition().x, _player->getPosition().y);
        _camera->moveCamera();
        _title->Draw(_player);
    }
    else if(_sceneManager->getScene() == LEVEL1)
    {
    _camera->updateCameraPosition(_player->getPosition().x+1, _player->getPosition().y+1);
    _camera->moveCamera();
        if(_level1->spawn)
        {
        _player->setPosition(-18,-5);
        _level1->spawn = false;
        }
        _level1->Draw(_player);
    }
    else if(_sceneManager->getScene() == LEVEL2)
    {
    _camera->updateCameraPosition(_player->getPosition().x+1, _player->getPosition().y+1);
    _camera->moveCamera();
        if(_level2->spawn)
        {
        _player->setPosition(-10,-5);
        cout<<_player->getPosition().x<<endl;
        _level2->spawn = false;
        }
        _level2->Draw(_player);
    }
    else if(_sceneManager->getScene() == LEVEL3)
    {
    _camera->updateCameraPosition(_player->getPosition().x+1, _player->getPosition().y+1);
    _camera->moveCamera();
        if(_level3->spawn)
        {
        _level3->startPOS.x = -18;
        _level3->startPOS.y = -5;
        _player->setPosition(-11,-5);
        _level3->spawn = false;
        }
        _level3->Draw(_player);
    }

//particles

    glPushMatrix();
    glDisable(GL_TEXTURE_2D);
    glTranslated(0.0,0.0,-1.0);
    p->generateParticles(_player->getPosition());
    p->draw();
    p->lifeTime();
    glColor3f(1.0,1.0,1.0);
    glEnable(GL_TEXTURE_2D);
    glPopMatrix();

}

void GameLoop::Update()
{

    if(_sceneManager->getScene() == LEVEL1)
    {
        if(_collision->AABB(_player->_hitbox->collider, _level1->_goal->_hitbox->collider))
        {
            cout<<"collided goal 1\n";
            _sceneManager->setScene(LEVEL2);
        }

        for(int i = 0; i < _level1->getComodos().size(); i++)
        {
            if(_level1->getComodos().at(i)->getHealth() == 0)
            {
                _level1->getComodos().at(i)->isObjectLive = false;
            }
        }
        if(_player->getHealth() <= 0)
        {
            _player->isObjectLive = false;
            gameState = QUIT;
        }

        //add collision checks in update function for environment projectiles and enemies;
        for(int i = 0; i < _level1->getComodos().size(); i++)
        {
            if(_level1->getComodos()[i]->isObjectLive && _player->_hurtbox->active == true && _collision->AABB(_player->_hurtbox->collider,_level1->getComodos()[i]->_hitbox->collider))
            {
                cout<<"enemy hit"<<endl;
                if(_level1->getComodos()[i]->getDirection() == LEFT)
                {
                 _level1->getComodos()[i]->setVelocity(-1.0,0);
                }
                else{
                _level1->getComodos()[i]->setVelocity(1.0,0);
                }
                _level1->getComodos()[i]->setHealth(_level1->getComodos()[i]->getHealth() - 25);
            }
            if(_level1->getComodos()[i]->isObjectLive == true && _collision->AABB(_player->_hitbox->collider,_level1->getComodos()[i]->_hitbox->collider))
            {
                if(_level1->getComodos()[i]->getDirection() == LEFT)
                {
                    _player->setVelocity(0.0,5.0);
                }
                else
                {
                    _player->setVelocity(1.0,1.0);
                }
                _player->setHealth(_player->getHealth() - 10);
                cout<<_player->getHealth()<<endl;
            }
        }
        _level1->Update(_player);
    }

    if(_sceneManager->getScene() == LEVEL2)
    {
        if(_collision->AABB(_player->_hitbox->collider, _level2->_goal->_hitbox->collider))
        {
            cout<<"collided goal 2\n";
            _sceneManager->setScene(LEVEL3);
        }
        if(_level2->getComodos().size() > 0)
        {
            //check for comodos
            for(int i = 0; i < _level2->getComodos().size(); i++)
            {
                if(_level2->getComodos().at(i)->getHealth() == 0)
                {
                    _level2->getComodos().at(i)->isObjectLive = false;
                }

                       //add collision checks in update function for environment projectiles and enemies;
            if(_level2->getComodos()[i]->isObjectLive && _player->_hurtbox->active == true && _collision->AABB(_player->_hurtbox->collider,_level2->getComodos()[i]->_hitbox->collider))
            {
                cout<<"enemy hit"<<endl;
                if(_level2->getComodos()[i]->getDirection() == LEFT)
                {
                 _level2->getComodos()[i]->setVelocity(-1.0,0);
                }
                else{
                _level2->getComodos()[i]->setVelocity(1.0,0);
                }
                _level2->getComodos()[i]->setHealth(_level2->getComodos()[i]->getHealth() - 25);
            }
            if(_level2->getComodos()[i]->isObjectLive == true && _collision->AABB(_player->_hitbox->collider,_level2->getComodos()[i]->_hitbox->collider))
            {
                if(_level2->getComodos()[i]->getDirection() == LEFT)
                {
                    _player->setVelocity(0.0,5.0);
                }
                else
                {
                    _player->setVelocity(1.0,1.0);
                }
                _player->setHealth(_player->getHealth() - 50);
            }
        }
    }
            if(_level2->getHellHounds().size() > 0)
            {
            //check for hounds
            for(int i = 0; i < _level2->getHellHounds().size(); i++)
            {
                if(_level2->getHellHounds().at(i)->getHealth() == 0)
                {
                    _level2->getHellHounds().at(i)->isObjectLive = false;
                }

                //add collision checks in update function for environment projectiles and enemies;
                if(_level2->getHellHounds()[i]->isObjectLive && _player->_hurtbox->active == true && _collision->AABB(_player->_hurtbox->collider,_level2->getHellHounds()[i]->_hitbox->collider))
                {
                    if(_level2->getHellHounds()[i]->getDirection() == LEFT)
                    {
                     _level2->getHellHounds()[i]->setVelocity(-1.0,0);
                    }
                    else{
                    _level2->getHellHounds()[i]->setVelocity(1.0,0);
                    }
                    _level2->getHellHounds()[i]->setHealth(_level2->getHellHounds()[i]->getHealth() - 25);
                }
                if(_level2->getHellHounds()[i]->isObjectLive == true && _collision->AABB(_player->_hitbox->collider,_level2->getHellHounds()[i]->_hitbox->collider))
                {
                    if(_level2->getHellHounds()[i]->getDirection() == LEFT)
                    {
                        _player->setVelocity(0.0,5.0);
                    }
                    else
                    {
                        _player->setVelocity(1.0,1.0);
                    }
                    _player->setHealth(_player->getHealth() - 50);
                }
            }
        }

        //check if player dies
        if(_player->getHealth() <= 0)
        {
            _player->isObjectLive = false;
            gameState = QUIT;
        }
        _level2->Update(_player);
    }

    if(_sceneManager->getScene() == LEVEL3)
    {
        for(int i = 0; i < _level3->getComodos().size(); i++)
        {
            if(_level3->getComodos().at(i)->getHealth() == 0)
            {
                _level3->getComodos().at(i)->isObjectLive = false;
            }
        }
        if(_player->getHealth() <= 0)
        {
            _player->isObjectLive = false;
            gameState = QUIT;
        }

        //add collision checks in update function for environment projectiles and enemies;
        for(int i = 0; i < _level3->getComodos().size(); i++)
        {
            if(_level3->getComodos()[i]->isObjectLive && _player->_hurtbox->active == true && _collision->AABB(_player->_hurtbox->collider,_level3->getComodos()[i]->_hitbox->collider))
            {
                cout<<"enemy hit"<<endl;
                if(_level3->getComodos()[i]->getDirection() == LEFT)
                {
                 _level3->getComodos()[i]->setVelocity(-1.0,0);
                }
                else{
                _level3->getComodos()[i]->setVelocity(1.0,0);
                }
                _level3->getComodos()[i]->setHealth(_level3->getComodos()[i]->getHealth() - 25);
            }
            if(_level3->getComodos()[i]->isObjectLive == true && _collision->AABB(_player->_hitbox->collider,_level3->getComodos()[i]->_hitbox->collider))
            {
                cout<<"collide with player"<<endl;
                if(_level3->getComodos()[i]->getDirection() == LEFT)
                {
                    cout<<"collide on right"<<endl;
                    _player->setVelocity(0.0,5.0);
                }
                else
                {
                    _player->setVelocity(1.0,1.0);
                }
                _player->setHealth(_player->getHealth() - 50);
                cout<<_player->getHealth()<<endl;
            }
        }
        _level3->Update(_player);
    }
}

void GameLoop::winInputs(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
     switch (uMsg)									// Check For Windows Messages
	{
        //check if key is down
	    case WM_KEYDOWN:
	        _input->setWPARAM(wParam);
            _input->keyPressed(_player, _sceneManager);
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
        break;								// Jump Back
        }

        case WM_MOUSEMOVE:
        {
            _input->setMouseCoords(_player,LOWORD(lParam),HIWORD(lParam));
        break;								// Jump Back
        }
	}
}

GLint GameLoop::gameLoop()
{
//start fps limiter
frameStart = _fpsTimer->getTicks();
    //update game objects
    Render();
    //update physics
    Update();
    //render game scene
//end fps limiter
frameTime = _fpsTimer->getTicks() - frameStart;
    if(frameDelay > frameTime)
    {
        Sleep(frameDelay - frameTime);
    }
}


