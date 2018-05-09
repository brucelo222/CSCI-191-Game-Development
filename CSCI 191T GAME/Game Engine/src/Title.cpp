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

void Title::Init()
{
    _buttons[0].Init("images/titles/gameStart.png",0,-0.6);
    _buttons[1].Init("images/titles/help.png",0,-0.1);
    _buttons[2].Init("images/titles/exitGame.png",0,-0.2);

    initBackground("images/titles/title.png");
}

void Title::Draw(Player *_player)
{
    glTranslated(_player->getPosition().x,_player->getPosition().y,-2.0);
    drawBackground(20,10);
        _buttons[0].Draw(2,1);
        cout<<_buttons[0].getPos().x<<" "<<_buttons[0].getPos().y<<endl;
        _buttons[1].Draw(2,1);
        cout<<_buttons[1].getPos().x<<" "<<_buttons[1].getPos().y<<endl;
        _buttons[2].Draw(2,1);
        cout<<_buttons[2].getPos().x<<" "<<_buttons[2].getPos().y<<endl;
}

