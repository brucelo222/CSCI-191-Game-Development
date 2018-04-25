#include "Inputs.h"
#include <iostream>

Inputs::Inputs()
{
    //ctor
    _mouseCoords.x = 0.0;
    _mouseCoords.y = 0.0;
}

Inputs::~Inputs()
{
    //dtor
}

void Inputs::keyPressed(Player* player)
{
    switch(_wParam)
    {
    case VK_LEFT:
        player->setAction(RUNL);
        player->setDirection(LEFT);
        player->setPosition(player->getPosition().x -0.1, player->getPosition().y);
    break;
    case VK_RIGHT:
        player->setAction(RUNR);
        player->setDirection(RIGHT);
        player->setPosition(player->getPosition().x + 0.1, player->getPosition().y);
    break;
    case 0x58:
        if (player->getDirection() == RIGHT)
        {
            player->setAction(ATKR);
        }
        else
        {
            player->setAction(ATKL);
            player->setAttacking(true);
        }
    break;
    case VK_SPACE:
        player->setAction(STANDR);
        player->setAttacking(true);
    break;
       default:break;
    }
}

void Inputs::keyReleased(Player* player)
{
    if(player->getAttacking()==true)
    {

    }
    else if(player->getDirection() == RIGHT)
    {
        player->setAction(STANDR);
    }
    else if(player->getDirection() == LEFT)
    {
        player->setAction(STANDL);
    }
    else
    {
       player->setAction(STANDR);
    }

    switch(_wParam)
    {
       default:break;
    }
}


void Inputs::setMouseCoords(Player* player, float x, float y)
{
   		_mouseCoords.x = x;
		_mouseCoords.y = y;
}

void Inputs::mouseEvent(Player* player, float x, float y)
{
    _mouseCoords.x = x;
    _mouseCoords.y = y;

        switch(_wParam)
        {
            case MK_LBUTTON:
               // player->setPosition(x,y);
                std::cout<<"left mouse button"<<std::endl;
            break;


        }
}

