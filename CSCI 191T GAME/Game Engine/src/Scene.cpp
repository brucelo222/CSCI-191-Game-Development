#include "Scene.h"

Scene::Scene()
{
    //ctor
}

Scene::~Scene()
{
    //dtor
}

void Scene::Init(Player* _player)
{
    initBackground();
    initPlayer(_player);
    initEnemies();
}

void Scene::Draw(Player* _player)
{
    drawBackground();
    drawPlayer(_player);
    drawEnemies();
}

void Scene::Update(Player *_player)
{
    _player->Update();
    for(int i = 0; i < numEnemies; i++)
    {
        _enemies[i].Update(_player->getPosition());
    }
}

void Scene::drawBackground()
{
    glPushMatrix();
    glColor3f(1.0,1.0,1.0);
    _backgroundTexture->binder();
    glTranslated(0.0,0.0,-2.0);
    _shape->drawQuad(50.0,15.0,-2.0,Color(1.0,1.0,1.0,1.0));
    glEnable(GL_TEXTURE_2D);
    glPopMatrix();
}

void Scene::initBackground()
{
    _backgroundTexture->bindTexture("images/bak.jpg");
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
    for(int i = 0; i < 100; i++){
        _enemies[i].Init();
        _enemies[i].setPosition(((14) + (i*0.25)),0.0);
    }
}

void Scene::drawEnemies()
{
    glPushMatrix();
    for (int i = 0; i < 100; i ++)
    {
        if(_enemies[i].isObjectLive)
        {
        _enemies[i].actions();
        }
    }
    glPopMatrix();
}

