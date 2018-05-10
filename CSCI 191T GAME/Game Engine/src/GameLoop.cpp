#include "GameLoop.h"

#include <iostream>

GameLoop::GameLoop()
{
    //ctor
    _screenHeight= GetSystemMetrics(SM_CYSCREEN);
    _screenWidth = GetSystemMetrics(SM_CXSCREEN);
    gameState = PLAY;
    _sceneManager->setScene(TITLE);
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

    stg1->initSounds();
    stg2->initSounds();
    stg3->initSounds();

    _title->Init("images/titles/title.png");
    _help->Init("images/help.png");
    _pause->Init("images/pause.png");

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

        _camera->updateCameraPosition(_player->getPosition().x, _player->getPosition().y);
        _camera->moveCamera();
    //render Camera
    //switch to model matrix
    glMatrixMode(GL_MODELVIEW);

    if(_sceneManager->getScene() == TITLE)
    {
        _title->Draw(_player);
    }
    else if(_sceneManager->getScene() == HELP)
    {
        _help->Draw(_player);
    }
    else if(_sceneManager->getScene() == PAUSE)
    {
        _pause->Draw(_player);
    }
    else if(_sceneManager->getScene() == RETRY)
    {
        _retry->Draw(_player);
    }
    else if(_sceneManager->getScene() == LEVEL1)
    {
        if(_level1->spawn)
        {
        stg1->playMusic("audio/bgm/stg1.bgm");
        _player->setPosition(-18,-5);
        _level1->spawn = false;
        }
        _level1->Draw(_player);
    }
    else if(_sceneManager->getScene() == LEVEL2)
    {
        if(_level2->spawn)
        {
        stg2->playMusic("audio/bgm/stg2.bgm");
        _player->setPosition(-12,6);
        _level2->spawn = false;
        }
        _level2->Draw(_player);
    }
    else if(_sceneManager->getScene() == LEVEL3)
    {
        if(_level3->spawn)
        {
        stg3->playMusic("audio/bgm/stg3.bgm");
        _player->setPosition(-11,-5);
        _level3->spawn = false;
        }
        _level3->Draw(_player);
    }

}

void GameLoop::Update()
{
    if(_sceneManager->getScene() != TITLE || _sceneManager->getScene() != RETRY || _sceneManager->getScene() != HELP || _sceneManager->getScene() != PAUSE){
    if(_sceneManager->getScene() == LEVEL1)
    {
        collideSum=0;
            for(int i=0;i < 8;i++){
                collideSum+=collision->collision(_player,_level1->platforms[i]);
                //cout<<_level1->platforms[i]->yTop<<" "<<_level1->platforms[i]->yBottom<<endl;
            }

        //player level collision
        if(_collision->AABB(_player->_hitbox->collider, _level1->_goal->_hitbox->collider))
        {
            //cout<<"collided goal 1\n";
            _sceneManager->setScene(LEVEL2);
        }

        for(int i = 0; i < _level1->getComodos().size(); i++)
        {
            if(_level1->getComodos().at(i)->getHealth() == 0)
            {
                _level1->getComodos().at(i)->isObjectLive = false;
            }
        }

        //add collision checks in update function for environment projectiles and enemies;
        for(int i = 0; i < _level1->getComodos().size(); i++)
        {
            if(_level1->getComodos()[i]->isObjectLive && _player->_hurtbox->active == true && _collision->AABB(_player->_hurtbox->collider,_level1->getComodos()[i]->_hitbox->collider))
            {
                if(_level1->getComodos()[i]->getDirection() == LEFT)
                {
                 _level1->getComodos()[i]->setVelocity(-1.0,0);
                }
                else{
                _level1->getComodos()[i]->setVelocity(1.0,0);
                }
                _level1->getComodos()[i]->setHealth(_level1->getComodos()[i]->getHealth() - 25);
                //particles
                    glPushMatrix();
                    glDisable(GL_TEXTURE_2D);
                    glTranslated(0.0,0.0,-1.0);
                    p->generateParticles(_level1->getComodos()[i]->getPosition());
                    p->draw();
                    p->lifeTime();
                    glColor3f(1.0,1.0,1.0);
                    glEnable(GL_TEXTURE_2D);
                    glPopMatrix();
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
            }
        }
        _level1->Update(_player);
    }

    else if(_sceneManager->getScene() == LEVEL2)
    {
                collideSum=0;
            for(int i=0;i < 8;i++){
                collideSum+=collision->collision(_player,_level1->platforms[i]);
               // cout<<collideSum<<endl;
            }
        if(_collision->AABB(_player->_hitbox->collider, _level2->_goal->_hitbox->collider))
        {
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
                if(_level2->getComodos()[i]->getDirection() == LEFT)
                {
                 _level2->getComodos()[i]->setVelocity(-1.0,0);
                }
                else{
                _level2->getComodos()[i]->setVelocity(1.0,0);
                }
                _level2->getComodos()[i]->setHealth(_level2->getComodos()[i]->getHealth() - 25);
                                    glPushMatrix();
                    glDisable(GL_TEXTURE_2D);
                    glTranslated(0.0,0.0,-1.0);
                    p->generateParticles(_level1->getComodos()[i]->getPosition());
                    p->draw();
                    p->lifeTime();
                    glColor3f(1.0,1.0,1.0);
                    glEnable(GL_TEXTURE_2D);
                    glPopMatrix();
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
                                        glPushMatrix();
                    glDisable(GL_TEXTURE_2D);
                    glTranslated(0.0,0.0,-1.0);
                    p->generateParticles(_level1->getComodos()[i]->getPosition());
                    p->draw();
                    p->lifeTime();
                    glColor3f(1.0,1.0,1.0);
                    glEnable(GL_TEXTURE_2D);
                    glPopMatrix();
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
        _level2->Update(_player);
    }

    else if(_sceneManager->getScene() == LEVEL3)
    {
        collideSum=0;
            for(int i=0;i < 8;i++){
                collideSum+=collision->collision(_player,_level1->platforms[i]);
               // cout<<collideSum<<endl;
            }
        for(int i = 0; i < _level3->getComodos().size(); i++)
        {
            if(_level3->getComodos().at(i)->getHealth() == 0)
            {
                _level3->getComodos().at(i)->isObjectLive = false;
            }
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

            if(_player->getHealth() <= 0||_player->getPosition().y < -8)
        {
            _player->isObjectLive = false;
            _sceneManager->setScene(RETRY);
        }

  //wall collision
        glPushMatrix();
    glScaled(1.0,1.0,0.0);
        if((collideSum==0||collideSum==2||collideSum==4)&&_player->isJump==false){
            _player->isJump=true;
            _player->isFalling=true;
            _player->setAction(JUMP);
			_player->actions();
			//cout<<"adfasdfasdf"<<endl;

        }

        else if(_player->isJump==true){
         if(collideSum>=1&&_player->isFalling==true){
                //cout<<"enter Here"<<endl;
                _player->isJump=false;

            if(_player->getDirection() == LEFT){
            _player->setAction(STANDL);
            }
            else{
            _player->setAction(STANDR);
            }

            }
         else if(_player->getAction()==JUMPRIGHT){
         _player->actions();
        }
         else if(_player->getAction()==JUMPLEFT){
         _player->actions();
        }
         else
        {
			_player->setAction(JUMP);
			_player->actions();
			}
    }
    else{

        if(collideSum==1){
                cout<<collideSum<<endl;
                _player->leftStop=false;
                _player->rightStop=false;

        }

         if((collideSum==2||collideSum==3)&&(_player->getAction()==RUNR)){
            cout<<collideSum<<endl;
            _player->rightStop=true;
            if(_player->getDirection() == LEFT){
            _player->setAction(STANDL);
            }
            else{
            _player->setAction(STANDR);
            }
        }
        else if((collideSum==4||collideSum==5)&&(_player->getAction()==RUNL)){
            cout<<collideSum<<endl;
            _player->leftStop=true;
         if(_player->getDirection() == LEFT){
             _player->setAction(STANDL);
            }
            else{
            _player->setAction(STANDR);
            }
        }
        _player->actions();

    }
    glPopMatrix();
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


