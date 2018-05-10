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
    initBackground(fileName);
}

void Title::Draw(Player *_player)
{
    glTranslated(_player->getPosition().x,_player->getPosition().y,-2.0);
    drawBackground(20,10);
}

