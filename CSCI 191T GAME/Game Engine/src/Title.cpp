#include "Title.h"
#include <iostream>
Title::Title()
{
    //ctor
}

Title::~Title()
{
    //dtor
}

void Title::Init(char* fileName)
{
    _play->Init("images/titles/gameStart.png",0,-0.25);
    _help->Init("images/titles/help.png",0,-0.75);
    _exit->Init("images/titles/exitGame.png",0,-1.25);

    initBackground(fileName);
}

void Title::Draw(Player *_player)
{
    glTranslated(_player->getPosition().x,_player->getPosition().y,-2.0);
    drawBackground(20,10);
    _play->Draw(1,0.5);
    _help->Draw(1,0.5);
    _exit->Draw(1,0.5);

}

