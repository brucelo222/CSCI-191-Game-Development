#include "GameLoop.h"

#include <iostream>


using namespace std;
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

    stg1->stagesInit("images/lowest platform/level1_8.png",-21.5,-7.1,3.0,2.5);
    platform2->stagesInit("images/lowest platform/level1_9.png",-17.5,-7.1,2.0,2.5);
    platform3->stagesInit("images/blocks/block2.png",-14.2,-11.1,1.0,6.5);
    platform4->stagesInit("images/blocks/block2.png",-11.8,-11.1,1.0,6.5);
    platform5->stagesInit("images/blocks/block2.png",-9.4,-11.1,1.0,6.5);
    platform6->stagesInit("images/lowest platform/level1_9.png",12.0,-7.1,2.0,2.5);

    background->stagesInit("images/platform1.png",-23.8,-5.6,2.3,4.0);
    background2->stagesInit("images/platform1.png",-17.5,-5.4,2.0,3.0);
    background3->stagesInit("images/platform1.png",-7.0,-6.4,2.0,3.0);
    background4->stagesInit("images/platform1.png",-5.7,-7.7,2.0,3.0);
    background5->stagesInit("images/platform1.png",-2.4,-7.0,2.0,3.0);
    background6->stagesInit("images/platform1.png",20.3,-6.7,4.0,5.0);

    p1->stagesInit("images/platforms/platform1.png",0.7,-5.5,1.0,0.6);
    p2->stagesInit("images/platforms/platform1.png",1.0,-3.0,1.0,0.6);
    p3->stagesInit("images/platforms/platform1.png",2.0,-4.2,1.0,0.6);
    p4->stagesInit("images/platforms/platform1_2.png",4.5,-4.0,2.0,0.6);
    p5->stagesInit("images/platforms/platform1.png",3.0,-2.5,1.0,0.6);
    p6->stagesInit("images/platforms/platform1.png",8.0,-5.0,1.0,0.6);
    p7->stagesInit("images/platforms/platform1.png",15.0,-5.0,1.0,0.6);
    p8->stagesInit("images/platforms/platform1.png",17.0,-5.0,1.0,0.6);
    p9->stagesInit("images/platforms/platform1.png",19.0,-5.0,1.0,0.6);
    bridge1->stagesInit("images/bridges/bridge4.png",10.0,-5.1,2.0,0.6);

    /////
    p10->stagesInit("images/platforms/platform2.png",17.4,-2.5,2.0,1.0);
    block->stagesInit("images/blocks/block9.png",16.4,-2.5,1.0,2.0);
    block1->stagesInit("images/blocks/block9.png",15.0,-1.4,1.0,2.2);
    p11->stagesInit("images/platforms/platform1.png",15.0,-2.6,1.0,0.6);
     bridge2->stagesInit("images/bridges/bridge4.png",11.0,-2.3,2.0,0.6);
     bridge3->stagesInit("images/bridges/bridge6.png",6.7,-0.7,0.9,0.6);
     platform8->stagesInit("images/lowest platform1.png",3.0,0.2,3.0,0.5);
     p12->stagesInit("images/platforms/platform1.png",8.0,-1.6,2.0,0.6);

     allPlatforms[0]= background;
    allPlatforms[1]=background2;
    allPlatforms[2]=background3;
    allPlatforms[3]=background5;
    allPlatforms[4]=background4;
    allPlatforms[5]=background6;
    allPlatforms[6]= p1;
    allPlatforms[7]= p2;
    allPlatforms[8]= p3;
    allPlatforms[9]= p4;
    allPlatforms[10]= p5;
    allPlatforms[11]= p6;
    allPlatforms[12]= p7;
    allPlatforms[13]= p8;
    allPlatforms[14]= p9;
    allPlatforms[15]= p10;
    allPlatforms[16]=block1;
    allPlatforms[17]=p11;
    allPlatforms[18]=bridge2;
    allPlatforms[19]= platform8;
    allPlatforms[20]=bridge3;
    allPlatforms[21]=p12;
    allPlatforms[22]=bridge1;
    allPlatforms[23]=platform2;
    allPlatforms[24]=platform3;
    allPlatforms[25]=platform4;
    allPlatforms[26]=platform5;
    allPlatforms[27]=platform6;
    allPlatforms[28]=stg1;

    stage1->stagesInit("images/stg1-0/stg1.png",-11.0,-5.0,20.40,6.4);
    stg1_platform1->initPlatform(-3.8,-4.5,-9.0,-13.0);
    stg1_platform2->initPlatform(-4.4,-5.0,0.399997,-9.0);
    stg1_platform3->initPlatform(-1.9,-20.0,-6.3,-8.7);
    stg1_platform4->initPlatform(-2.7,-5.0,-3.3,-5.3);
    stg1_platform5->initPlatform(-0.4,-20.0,-3.3,-5.3);

    stg1_platform6->initPlatform(-2.1,-20.0,-1.0,-3.3);

    stg1_platform7->initPlatform(-2.7,-8.0,3.2,1.2);
    stg1_platform8->initPlatform(-3.7,-8.0,5.79999,3.9);


    platforms[0]= stg1_platform1;
    platforms[1]=  stg1_platform2;
    platforms[2]= stg1_platform3;
    platforms[3]=  stg1_platform4;
    platforms[4]= stg1_platform5;
    platforms[5]=  stg1_platform6;
    platforms[6]= stg1_platform7;
    platforms[7]=  stg1_platform8;
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

    /*for(i=0;i<29;i++){
        glPushMatrix();
      allPlatforms[i]->draw();
    glPopMatrix();

    }*/
    collideSum=0;
        for(i=0;i<8;i++){
     collideSum+=collision->collision(_player,platforms[i]);
    }

    glPushMatrix();
    stage1->draw();
    glPopMatrix();

    //draw Player
    //cout<<"x: "<<_player->getPosition().x<<endl;
   // cout<<"y: "<<_player->getPosition().y<<endl;

/*
    glPushMatrix();
    //std::cout<<_player->getDirection()<<std::endl;


    glScaled(1.0,1.0,0.0);

    _player->actions();

    //cout<<_player->getPosition().x<<endl;
    glPopMatrix();
    */



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
                _player->leftStop=false;
                _player->rightStop=false;

        }

         if((collideSum==2||collideSum==3)&&(_player->getAction()==RUNR)){

            _player->rightStop=true;
            if(_player->getDirection() == LEFT){
            _player->setAction(STANDL);
            }
            else{
            _player->setAction(STANDR);
            }
        }
        else if((collideSum==4||collideSum==5)&&(_player->getAction()==RUNL)){

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

    //draw Enemy

    //glPushMatrix();
    //_enemy->actions();
    //glPopMatrix();
    /*

    glPushMatrix();
    glDisable(GL_TEXTURE_2D);
    glTranslated(0.0,0.0,-1.0);
    p->generateParticles();
    p->draw();
    p->lifeTime();
    glColor3f(1.0,1.0,1.0);
    glEnable(GL_TEXTURE_2D);
    glPopMatrix();
    */
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
            //std::cout<<LOWORD(lParam)<<" "<<HIWORD(lParam)<<std::endl;
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


