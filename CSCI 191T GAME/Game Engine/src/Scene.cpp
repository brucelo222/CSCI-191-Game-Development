#include "Scene.h"
#include <iostream>
Scene::Scene()
{
    //ctor
}

Scene::~Scene()
{
    //dtor
}

void Scene::Init(Player* _player, char* fileName)
{
    std::cout<<"scene init\n";
    initBackground(fileName);
    std::cout<<"init background"<<std::endl;
    initPlayer(_player);
    std::cout<<"init players"<<std::endl;
    initEnemies();
    std::cout<<"init enemies"<<std::endl;
}

void Scene::Draw(Player* _player, int width, int height)
{
    drawBackground(width, height);
    drawPlayer(_player);
    drawEnemies();
}

void Scene::Update(Player *_player)
{
    _player->Update();
    for(int i = 0; i < numComodos; i++)
    {
        _Comodo[i]->Update(_player->getPosition());
    }
}

void Scene::drawBackground(int width, int height)
{
    glPushMatrix();
    glColor3f(1.0,1.0,1.0);
    _backgroundTexture->binder();
    glTranslated(0.0,0.0,-2.0);
    _shape->drawQuad(width,height,-2.0,Color(1.0,1.0,1.0,1.0));
    glEnable(GL_TEXTURE_2D);
    glPopMatrix();
}

void Scene::initBackground(char* fileName)
{
    _backgroundTexture->bindTexture(fileName);
}

void Scene::initPlayer(Player* _player)
{
    _player->Init();
}

void Scene::drawPlayer(Player* _player)
{
    glPushMatrix();
    if(_player->isObjectLive == true)
    {
        _player->actions();
    }
    glPopMatrix();
}

void Scene::initEnemies()
{
    /*
    for(int i = 0; i < numHellHounds; i++){
        _enemies[i]->Init();
        _enemies[i]->setPosition(((14) + (i*0.25)),0.0);
    } */
    for (int i = 0; i < numComodos; i++)
    {
        _Comodo[i]->Init();
        _Comodo[i]->setPosition(((14) + (i*0.25)),0.0);
    }
}

void Scene::drawEnemies()
{
    /*
    glPushMatrix();
    for (int i = 0; i < numComodos; i ++)
    {
        if(_Comodo[i]->isObjectLive)
        {
        _Comodo[i]->actions();
        }
    }
    glPopMatrix();
    */
    glPushMatrix();
    for (int i = 0; i < numComodos; i ++)
    {
        if(_Comodo[i]->isObjectLive)
        {
        _Comodo[i]->actions();
        }
    }
    glPopMatrix();
}

